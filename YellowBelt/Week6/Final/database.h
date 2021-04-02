//
// Created by dmitry on 04.01.2021.
//

#pragma once
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <stack>
#include <algorithm>
#include "date.h"
#include "node.h"
#include "test_runner.h"
#include "overloaded_operators.h"

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& stream) const;

    template <class Predicate>
    int RemoveIf(Predicate predicate) {
        int N = 0;
        auto it = unsort_storage.begin();
        storage.clear();
        while (it != unsort_storage.end()) {
            const auto &date = it->first;
            // storage.at(date).clear();
            auto rm_v = remove_if(it->second.begin(), it->second.end(), [predicate, date](const string& event){return predicate(date, event);});
            N += static_cast<int>(it->second.end() - rm_v);
            it->second.erase(rm_v, it->second.end());
            // storage.at(date).insert(it->second.begin(), it->second.end());
            if (it->second.empty()) {
                it++;
                unsort_storage.erase(prev(it)->first);
                // storage.erase(prev(it)->first);
            } else {
                storage[date].insert(it->second.begin(), it->second.end());
                it++;
            }
        }
        return N;
    }

    template <class Predicate>
    vector<pair<Date, string>> FindIf(Predicate predicate) const {
        vector<pair<Date, string>> output;
        for (const auto & it : unsort_storage) {
            const auto &date = it.first;
            vector<string> current_events;
            copy_if(begin(it.second), end(it.second), back_inserter(current_events), [predicate, date](const string& event){return predicate(date, event);});
            for (const auto& ev : current_events) {
                output.emplace_back(date, ev);
            }
        }
        return output;
    }

    [[nodiscard]] pair<Date, string> Last(const Date& date) const;  // пусть пока будет стринг

private:
    map<Date, set<string>> storage;
    map<Date, vector<string>> unsort_storage;
};

