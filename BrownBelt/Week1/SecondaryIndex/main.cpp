#include "test_runner.h"

#include <iostream>
#include <map>
#include <list>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Record {
    string id;
    string title;
    string user;
    int timestamp;
    int karma;
};

bool operator==(const Record& lhs, const Record& rhs) {
    return tie(lhs.id, lhs.title, lhs.user, lhs.timestamp, lhs.karma) == tie(rhs.id, rhs.title, rhs.user, rhs.timestamp, rhs.karma);
}

bool operator<(const Record& lhs, const Record& rhs) {
    return tie(lhs.id, lhs.title, lhs.user, lhs.timestamp, lhs.karma) < tie(rhs.id, rhs.title, rhs.user, rhs.timestamp, rhs.karma);
}


// Реализуйте этот класс
class Database {
public:
    bool Put(const Record& record) {
        size_t size_id = s_hash(record.id);
        auto pair = main_data.insert({size_id, record});  // first --- iterator, second --- bool
        if (!pair.second) {return false;}
        timestamp_data[record.timestamp].insert(size_id);
        karma_data[record.karma].insert(size_id);
        user_data[record.user].insert(size_id);
        return true;
    }

    const Record* GetById(const string& id) const {
        auto it = main_data.find(s_hash(id));
        return (it != main_data.end()) ? &(it->second) : nullptr;
    }

    bool Erase(const string& id) {
        size_t size_id = s_hash(id);
        auto it = main_data.find(size_id);
        if (it == main_data.end()) {return false;}
        if (timestamp_data.at(it->second.timestamp).size() > 1) {
            timestamp_data.at(it->second.timestamp).erase(size_id);
        } else {
            timestamp_data.erase(it->second.timestamp);
        }
        if (karma_data.at(it->second.karma).size() > 1) {
            karma_data.at(it->second.karma).erase(size_id);
        } else {
            karma_data.erase(it->second.karma);
        }
        if (user_data.at(it->second.user).size() > 1) {
            user_data.at(it->second.user).erase(size_id);
        } else {
            user_data.erase(it->second.user);
        }
        main_data.erase(it);
        return true;
    }

    template <typename Callback>
    void RangeByTimestamp(const int& low, const int& high, Callback callback) const {
        RangeByContainer(low, high, callback, timestamp_data);
    }

    template <typename Callback>
    void RangeByKarma(const int& low, const int& high, Callback callback) const {
        RangeByContainer(low, high, callback, karma_data);
    }

    template <typename Callback>
    void AllByUser(const string& user, Callback callback) const {
        try {
            for (const auto& key : user_data.at(user)) {
                if (!callback(main_data.at(key))) {return;}
            }
        } catch (out_of_range&) {
            return;
        }
    }

private:
    unordered_map<size_t, Record> main_data;  // id to record data
    map<int, unordered_set<size_t>> timestamp_data;  // ts to key
    map<int, unordered_set<size_t>> karma_data;  // karma to key
    unordered_map<string, unordered_set<size_t>> user_data;  // user to key
    hash<string> s_hash;

    template <typename Callback>
    void RangeByContainer(const int& low,
                          const int& high,
                          Callback callback,
                          const map<int, unordered_set<size_t>>& data) const {
        for (auto it = data.lower_bound(low); it != data.upper_bound(high); it++) {
            for (const auto& key_it : it->second) {
                try {
                    if (!callback(main_data.at(key_it))) {return;}
                } catch (out_of_range&) {
                    continue;
                }
            }
        }
    }
};

void TestRangeBoundaries() {
    const int good_karma = 1000;
    const int bad_karma = -10;

    Database db;
    db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
    db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

    int count = 0;
    db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
        ++count;
        return true;
    });

    ASSERT_EQUAL(2, count);
}

void TestSameUser() {
    Database db;
    db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
    db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

    int count = 0;
    db.AllByUser("master", [&count](const Record&) {
        ++count;
        return true;
    });

    ASSERT_EQUAL(2, count);
}

void TestReplacement() {
    const string final_body = "Feeling sad";

    Database db;
    db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
    db.Erase("id");
    db.Put({"id", final_body, "not-master", 1536107260, -10});

    auto record = db.GetById("id");
    ASSERT(record != nullptr);
    ASSERT_EQUAL(final_body, record->title);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestRangeBoundaries);
    RUN_TEST(tr, TestSameUser);
    RUN_TEST(tr, TestReplacement);
    return 0;
}