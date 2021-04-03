#include <iostream>
#include <queue>
#include <tuple>
#include <map>
#include <cstdint>
#include "test_runner.h"

using namespace std;

struct Hotel {
    map<uint32_t, size_t> clients;
    uint32_t rooms;

};

class HotelManager {
public:
    void book(const int64_t& time,
              const string& hotel_name,
              const uint32_t& client_id,
              const uint32_t& room_count) {
        current_time_ = time;
        statistics.push(tie(time, hotel_name, client_id, room_count));
        auto& hotel = hotels[hotel_name];
        hotel.clients[client_id]++;
        hotel.rooms += room_count;
        UpdateDay();

    }
    [[nodiscard]] size_t clients(const string& hotel_name) const {
        if (hotels.count(hotel_name) == 0) {
            return 0u;
        } else {
            return hotels.at(hotel_name).clients.size();
        }
    }
    [[nodiscard]] size_t rooms(const string& hotel_name) const {
        if (hotels.count(hotel_name) == 0) {
            return 0u;
        } else {
            return hotels.at(hotel_name).rooms;
        }
    }

private:
    static const int64_t day = 86400;
    int64_t current_time_{};
    map<string, Hotel> hotels;
    queue<tuple<int64_t, string, uint32_t, uint32_t>> statistics;

    void UpdateDay() {
        while (!statistics.empty()) {
            if (current_time_ - get<0>(statistics.front()) < day) {
                break;
            }
            auto& hotel_name = get<1>(statistics.front());
            auto& client = get<2>(statistics.front());
            auto& room_count = get<3>(statistics.front());
            auto& hotel = hotels.at(hotel_name);
            hotel.rooms -= room_count;
            if (--hotel.clients.at(client) == 0u) {
                hotel.clients.erase(client);
            }
            statistics.pop();
        }
    }
};

void Test1() {
    HotelManager hm;
    ASSERT_EQUAL(hm.clients("M"), 0);
    ASSERT_EQUAL(hm.rooms("M"), 0);
    hm.book( 10,"F",1,2 );
    hm.book( 10,"M",1,1 );
    hm.book( 86409,"F",2,1 );
    ASSERT_EQUAL(hm.clients("F"), 2);
    ASSERT_EQUAL(hm.rooms("F"), 3);
    ASSERT_EQUAL(hm.clients("M"), 1);
    hm.book( 86410,"M",2,10 );
    ASSERT_EQUAL(hm.rooms("F"), 1);
    ASSERT_EQUAL(hm.rooms("M"), 10);
}
void Test2() {
    HotelManager hm;

    ASSERT_EQUAL(hm.rooms("a"), 0);
    ASSERT_EQUAL(hm.clients("a"), 0);
    hm.book( -100000, "a", 100000, 1000 );
    hm.book( -100000, "a", 100003, 1000 );
    hm.book( -100000, "b", 100002, 1000 );
    ASSERT_EQUAL(hm.rooms("a"), 2000);
    ASSERT_EQUAL(hm.clients("a"), 2);
    hm.book( -10000, "a", 100002, 1000 );
    ASSERT_EQUAL(hm.rooms("a"), 1000);
    ASSERT_EQUAL(hm.clients("a"), 1);
    ASSERT_EQUAL(hm.rooms("b"), 0);
    ASSERT_EQUAL(hm.clients("b"), 0);  // 1
}
void Test3() {
    HotelManager manager;

    // Test empty bookings
    ASSERT_EQUAL(manager.clients("mariott"), 0);
    ASSERT_EQUAL(manager.rooms("mariott"), 0);

    manager.book( 0, "mariott", 1, 10);
    manager.book( 0, "mariott", 2, 1);
    manager.book( 0, "mariott", 3, 1);
    manager.book( 0, "mariott", 4, 1);
    manager.book( 0, "hilton", 1, 1 );
    manager.book( 1, "hilton", 2, 1 );

    // Test correctness
    ASSERT_EQUAL(manager.clients("mariott"), 4);
    ASSERT_EQUAL(manager.rooms("mariott"), 13);
    ASSERT_EQUAL(manager.clients("hilton"), 2);
    ASSERT_EQUAL(manager.rooms("hilton"), 2);

    // Test event past 1 day resets statics
    manager.book(86400, "mariott", 1, 1 );
    ASSERT_EQUAL(manager.clients("mariott"), 1);
    ASSERT_EQUAL(manager.rooms("mariott"), 1);
    ASSERT_EQUAL(manager.clients("hilton"), 1);
    ASSERT_EQUAL(manager.rooms("hilton"), 1);

    // Test no clients and room for the last day
    manager.book( 86401, "mariott", 5, 1 );
    ASSERT_EQUAL(manager.clients("mariott"), 2);
    ASSERT_EQUAL(manager.rooms("mariott"), 2);
    ASSERT_EQUAL(manager.clients("hilton"), 0);
    ASSERT_EQUAL(manager.rooms("hilton"), 0);
}
void Test4() {
    HotelManager b;

    ASSERT_EQUAL(b.rooms("a"),0);
    ASSERT_EQUAL(b.clients("a"),0);

    ASSERT_EQUAL(b.rooms("b"),0);
    ASSERT_EQUAL(b.clients("c"),0);

    b.book( -100000,"a",100000,1000 );
    b.book( -100000,"a",100003,1000 );
    b.book( -100000,"b",100002,1000 );
    ASSERT_EQUAL(b.rooms("a"),2000);
    ASSERT_EQUAL(b.clients("a"),2);

    b.book( -10000,"a",100002,1000 );
    ASSERT_EQUAL(b.rooms("a"),1000);
    ASSERT_EQUAL(b.clients("a"),1);
    ASSERT_EQUAL(b.rooms("b"),0);
    ASSERT_EQUAL(b.clients("b"),0);
}
void Test5() {
    HotelManager b;

    b.book( 0, "a", 0, 1 );
    b.book( 1, "a", 1, 2 );
    b.book( 86400, "a", 1, 3 );
    ASSERT_EQUAL(b.clients("a"), 1);
    ASSERT_EQUAL(b.rooms("a"), 5);
}
void Test6() {
    HotelManager b;

    b.book( -86400, "a", 2, 2 );
    b.book( 0, "a", 1, 5 );
    ASSERT_EQUAL(b.clients("a"), 1);
    ASSERT_EQUAL(b.rooms("a"), 5);
}
void Test7() {
    HotelManager b;

    b.book( 1, "a", 11, 4 );
    b.book( 50000, "a", 11, 5 );
    b.book( 90000, "a", 22, 2 );
    ASSERT_EQUAL(b.clients("a"), 2);
    ASSERT_EQUAL(b.rooms("a"), 7);
}
void Test8() {
    HotelManager b;

    b.book( 2147483647, "a", 1, 3 );
    b.book( 2147483648, "a", 2, 11 );
    b.book( 4147483648, "a", 3, 13 );
    ASSERT_EQUAL(b.clients("a"), 1);
    ASSERT_EQUAL(b.rooms("a"), 13);
}


void AllTests() {
    TestRunner tr;
    RUN_TEST(tr, Test1);
    RUN_TEST(tr, Test2);
    RUN_TEST(tr, Test3);
    RUN_TEST(tr, Test4);
    RUN_TEST(tr, Test5);
    RUN_TEST(tr, Test6);
    RUN_TEST(tr, Test7);
    RUN_TEST(tr, Test8);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AllTests();

    HotelManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; query_id++) {
        string query_type;
        cin >> query_type;
        if (query_type == "BOOK") {
            long long int time;
            string hotel;
            unsigned int client_id;
            unsigned short int rooms;
            cin >> time >> hotel >> client_id >> rooms;
            manager.book(time, hotel, client_id, rooms);
        } else if (query_type == "CLIENTS") {
            string hotel;
            cin >> hotel;
            cout << manager.clients(hotel) << endl;
        } else if (query_type == "ROOMS") {
            string hotel;
            cin >> hotel;
            cout << manager.rooms(hotel) << endl;
        } else {
            throw runtime_error("Unknown command");
        }
    }

    return 0;
}
