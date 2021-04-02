#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include "test_runner.h"

using namespace std;

/*class ReadingManager {
public:
    ReadingManager()
            : user_page_counts_(MAX_USER_COUNT_ + 1, 0),
              sorted_users_(),
              user_positions_(MAX_USER_COUNT_ + 1, -1) {}

    void Read(int user_id, int page_count) {
        if (user_page_counts_[user_id] == 0) {
            AddUser(user_id);
        }
        user_page_counts_[user_id] = page_count;
        int& position = user_positions_[user_id];
        while (position > 0 && page_count > user_page_counts_[sorted_users_[position - 1]]) {
            SwapUsers(position, position - 1);
        }
    }

    double Cheer(int user_id) const {
        if (user_page_counts_[user_id] == 0) {
            return 0;
        }
        const int user_count = GetUserCount();
        if (user_count == 1) {
            return 1;
        }
        const int page_count = user_page_counts_[user_id];
        int position = user_positions_[user_id];
        while (position < user_count &&
               user_page_counts_[sorted_users_[position]] == page_count) {
            ++position;
        }
        if (position == user_count) {
            return 0;
        }
        // По умолчанию деление целочисленное, поэтому
        // нужно привести числитель к типу double.
        // Простой способ сделать это — умножить его на 1.0.
        return (user_count - position) * 1.0 / (user_count - 1);
    }

private:
    // Статическое поле не принадлежит какому-то конкретному
    // объекту класса. По сути это глобальная переменная,
    // в данном случае константная.
    // Будь она публичной, к ней можно было бы обратиться снаружи
    // следующим образом: ReadingManager::MAX_USER_COUNT.
    static const int MAX_USER_COUNT_ = 100'000;

    vector<int> user_page_counts_;
    vector<int> sorted_users_;   // отсортированы по убыванию количества страниц
    vector<int> user_positions_; // позиции в векторе sorted_users_

    int GetUserCount() const {
        return sorted_users_.size();
    }
    void AddUser(int user_id) {
        sorted_users_.push_back(user_id);
        user_positions_[user_id] = sorted_users_.size() - 1;
    }
    void SwapUsers(int lhs_position, int rhs_position) {
        const int lhs_id = sorted_users_[lhs_position];
        const int rhs_id = sorted_users_[rhs_position];
        swap(sorted_users_[lhs_position], sorted_users_[rhs_position]);
        swap(user_positions_[lhs_id], user_positions_[rhs_id]);
    }
};*/

/*class ReadingManager {
public:
    void Read(const int& user_id, const int& page) {
        if (users.find(user_id) != users.end()) {
            pages.erase(pages.lower_bound(users.at(user_id)));
        }
        users[user_id] = page;
        pages.insert(page);
    }
    double Cheer(const int& user_id) {
        try {
            auto current_pages = users.at(user_id);
            if (users.size() == 1u) {
                return 1;
            }
            multiset<int> result_set_pages = {pages.begin(), pages.lower_bound(current_pages)};
            return static_cast<double>(result_set_pages.size()) / static_cast<double>(pages.size() - 1);
        } catch (out_of_range& ex) {
            return 0;
        }
    }

private:
    multiset<int> pages;
    map<int, int> users;
};*/

class ReadingManager {
public:
    ReadingManager() : users(MAX_USER_COUNT_ + 1, 0),
                       rating_of_pages(MAX_PAGES_COUNT_ + 1, 0),
                       using_pages(MAX_PAGES_COUNT_ + 1, 0),
                       size_database(0u) {}

    void Read(const int& user_id, const int& page) {
        if (users[user_id] == 0) {
            size_database++;
        } else {
            using_pages[users[user_id]]--;
        }
        users[user_id] = page;
        using_pages[page]++;
        CalcRating();
    }
    double Cheer(const int& user_id) const {
        if (size_database == 1u && users[user_id] != 0) {
            return 1;
        } else if (users[user_id] == 0) {
            return 0;
        } else {
            return rating_of_pages[users[user_id]];
        }
    }

private:
    static const int MAX_USER_COUNT_ = 100'000;
    static const int MAX_PAGES_COUNT_ = 1000;
    vector<int> users;  // user[user_id] == page  пользователи
    vector<double> rating_of_pages;  // rating_of_pages[page] == current_rating рейтинг каждой страницы
    vector<int> using_pages;  // число юзеров у каждой страницы
    size_t size_database;

    void CalcRating() {
        int sum_pages = 0;
        for (size_t i = 1; i <= MAX_PAGES_COUNT_; i++) {
            sum_pages += using_pages[i - 1];
            rating_of_pages[i] = static_cast<double>(sum_pages) / static_cast<double>(size_database - 1u);
        }
    }
};

void TestRead() {
    {
        ReadingManager manager;
        ASSERT_EQUAL( 0, manager.Cheer( 5 ) );
        manager.Read( 1, 10 );
        ASSERT_EQUAL( 1, manager.Cheer( 1 ) );
        manager.Read( 2, 5 );
        manager.Read( 3, 7 );
        ASSERT_EQUAL( 0, manager.Cheer( 2 ) );
        ASSERT_EQUAL( 0.5, manager.Cheer( 3 ) );
        manager.Read( 3, 10 );
        ASSERT_EQUAL( 0.5, manager.Cheer( 3 ) );
        manager.Read( 3, 11 );
        ASSERT_EQUAL( 1, manager.Cheer( 3 ) );
        ASSERT_EQUAL( 0.5, manager.Cheer( 1 ) );
        manager.Read( 2, 11 );
        ASSERT_EQUAL( 0.5, manager.Cheer( 3 ) );
        ASSERT_EQUAL( 0.5, manager.Cheer( 2 ) );
        manager.Read( 2, 12 );
        ASSERT_EQUAL( 0.5, manager.Cheer( 3 ) );
        ASSERT_EQUAL( 1, manager.Cheer( 2 ) );
        manager.Read( 1, 13 );
        manager.Read( 2, 13 );
        manager.Read( 3, 13 );
        ASSERT_EQUAL( 0, manager.Cheer( 1 ) );
        ASSERT_EQUAL( 0, manager.Cheer( 2 ) );
        ASSERT_EQUAL( 0, manager.Cheer( 3 ) );
    }
    {
        ReadingManager manager;
        ASSERT_EQUAL(0, manager.Cheer(5));
        manager.Read(1, 10);
        ASSERT_EQUAL(1, manager.Cheer(1));
        manager.Read(2, 5);
        manager.Read(3, 7);
        ASSERT_EQUAL(0, manager.Cheer(2));
        ASSERT_EQUAL(0.5, manager.Cheer(3));
        manager.Read(3, 10);
        ASSERT_EQUAL(0.5, manager.Cheer(3));
        manager.Read(3, 11);
        ASSERT_EQUAL(1, manager.Cheer(3));
        ASSERT_EQUAL(0.5, manager.Cheer(1));
        manager.Read(2, 11);
        ASSERT_EQUAL(0.5, manager.Cheer(3));
        ASSERT_EQUAL(0.5, manager.Cheer(2));
        manager.Read(2, 12);
        ASSERT_EQUAL(0.5, manager.Cheer(3));
        ASSERT_EQUAL(1, manager.Cheer(2));
        manager.Read(1, 13);
        manager.Read(2, 13);
        manager.Read(3, 13);
        ASSERT_EQUAL(0, manager.Cheer(1));
        ASSERT_EQUAL(0, manager.Cheer(2));
        ASSERT_EQUAL(0, manager.Cheer(3));
    }

    {// add user
        ReadingManager manager;
        ASSERT_EQUAL(manager.Cheer(1), 0.0);
        manager.Read(1, 1);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);
    }
    {// add user but cheer not existed
        ReadingManager manager;
        ASSERT_EQUAL(manager.Cheer(1), 0.0);
        manager.Read(1, 1);
        ASSERT_EQUAL(manager.Cheer(2), 0.0);
    }
    {// read twice
        ReadingManager manager;
        manager.Read(1, 1);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);
        manager.Read(1, 2);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);
    }
    {// better than third
        ReadingManager manager;
        manager.Read(1, 1);
        manager.Read(2, 2);
        manager.Read(3, 3);
        ASSERT_EQUAL(manager.Cheer(2), 0.5);
        manager.Read(4, 4);
        ASSERT_EQUAL(manager.Cheer(2), 1.0 / 3.0);
    }
    {// better than 2 third
        ReadingManager manager;
        manager.Read(1, 1);
        manager.Read(2, 2);
        manager.Read(3, 3);
        ASSERT_EQUAL(manager.Cheer(2), 0.5);
        manager.Read(4, 4);
        ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
    }
    {// read zero
        ReadingManager manager;
        manager.Read(1, 0);
        manager.Read(2, 0);
        manager.Read(3, 1);
        manager.Read(4, 2);
        ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
    }
    {// all read the same
        ReadingManager manager;
        manager.Read(1, 5);
        manager.Read(2, 5);
        manager.Read(3, 5);
        manager.Read(4, 5);
        ASSERT_EQUAL(manager.Cheer(3), 0.0);
    }
    {// reverse order
        ReadingManager manager;
        manager.Read(4, 5);
        manager.Read(3, 4);
        manager.Read(2, 3);
        manager.Read(1, 2);
        ASSERT_EQUAL(manager.Cheer(3), 2.0 / 3.0);
    }
    {// two users read two times
        ReadingManager manager;
        manager.Read(4, 5);
        manager.Read(3, 4);
        manager.Read(4, 6);
        manager.Read(3, 5);
        ASSERT_EQUAL(manager.Cheer(4), 1.0);
        ASSERT_EQUAL(manager.Cheer(3), 0.0);
        manager.Read(10, 2);
        ASSERT_EQUAL(manager.Cheer(3), 0.5);
        ASSERT_EQUAL(manager.Cheer(4), 1.0);
    }
    {// only one user
        ReadingManager manager;
        manager.Read(4, 5);
        ASSERT_EQUAL(manager.Cheer(4), 1.0);
        manager.Read(4, 6);
        ASSERT_EQUAL(manager.Cheer(4), 1.0);
        manager.Read(4, 100);
        ASSERT_EQUAL(manager.Cheer(4), 1.0);
        ASSERT_EQUAL(manager.Cheer(3), 0.0);
        ASSERT_EQUAL(manager.Cheer(5), 0.0);
    }
    {// ten users
        ReadingManager manager;
        manager.Read(1, 1);
        manager.Read(2, 2);
        manager.Read(3, 3);
        manager.Read(4, 4);
        manager.Read(5, 5);
        manager.Read(6, 6);
        manager.Read(7, 7);
        manager.Read(8, 8);
        manager.Read(9, 9);
        manager.Read(100, 10);
        manager.Read(111, 11);

        ASSERT_EQUAL(manager.Cheer(1), 0.0);
        ASSERT_EQUAL(manager.Cheer(2), 0.1);
        ASSERT_EQUAL(manager.Cheer(3), 0.2);
        ASSERT_EQUAL(manager.Cheer(4), 0.3);
        ASSERT_EQUAL(manager.Cheer(5), 0.4);
        ASSERT_EQUAL(manager.Cheer(6), 0.5);
        ASSERT_EQUAL(manager.Cheer(7), 0.6);
        ASSERT_EQUAL(manager.Cheer(8), 0.7);
        ASSERT_EQUAL(manager.Cheer(9), 0.8);
        ASSERT_EQUAL(manager.Cheer(100), 0.9);
        ASSERT_EQUAL(manager.Cheer(111), 1.0);
        ASSERT_EQUAL(manager.Cheer(12), 0.0);
    }
    {// cheer twice
        ReadingManager manager;

        ASSERT_EQUAL(manager.Cheer(1), 0.0);
        ASSERT_EQUAL(manager.Cheer(1), 0.0);
        manager.Read(1, 1);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);

        ASSERT_EQUAL(manager.Cheer(2), 0);
    }
    {// max ID
        const int MAX_USER_COUNT = 100'000;
        ReadingManager manager;
        ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 0.0);
        manager.Read(MAX_USER_COUNT, 1);
        ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 1.0);
    }
    {// max page
        ReadingManager manager;
        ASSERT_EQUAL(manager.Cheer(1), 0.0);
        manager.Read(1, 1000);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);
    }
    {// max ID and max page
        const int MAX_USER_COUNT = 100'000;
        ReadingManager manager;
        ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 0.0);
        manager.Read(MAX_USER_COUNT, 1000);
        ASSERT_EQUAL(manager.Cheer(MAX_USER_COUNT), 1.0);
    }
    {// zero ID
        ReadingManager manager;
        ASSERT_EQUAL(manager.Cheer(0), 0.0);
        manager.Read(0, 1000);
        ASSERT_EQUAL(manager.Cheer(0), 1.0);
    }
    {// from coursera (https://www.coursera.org/learn/c-plus-plus-red/programming/e72ST/eliektronnaia-knigha/discussions/threads/hLK3cT0AEemHtRKqiMW_lA)
        ReadingManager manager;
        manager.Read(1, 1);
        manager.Read(1, 3);
        manager.Read(2, 2);
        ASSERT_EQUAL(manager.Cheer(1), 1.0);
        ASSERT_EQUAL(manager.Cheer(2), 0.0);
    }
}

int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TestRunner tr;
    RUN_TEST(tr, TestRead);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << endl;
        }
    }

    return 0;
}