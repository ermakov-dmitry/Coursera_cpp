#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
/*template <typename T>
class Table {
public:
    explicit Table(const size_t& rows, const size_t& cols) {
        rows_ = rows;
        cols_ = cols;
        table.assign(rows_, vector<int>(cols_));
    }
    vector<T>& operator[](int idx) {
        return table[idx];
    }

    const vector<T>& operator[](size_t idx) const {
        return table[idx];
    }

    void Resize(const size_t& new_rows, const size_t& new_cols) {
        table.resize(new_rows);
        for (auto& v : table) {
            v.resize(new_cols);
        }
        rows_ = new_rows;
        cols_ = new_cols;
    }

    [[nodiscard]] pair<size_t, size_t> Size() const {
        if (rows_ == 0 && cols_ == 0) {
            return {0, 0};
        }
        return {rows_, cols_};
    }
private:
    vector<vector<T>> table;
    size_t rows_;
    size_t cols_;
};*/

template <typename T>
class Table {
private:
    vector<vector<T>> data;

public:
    Table(size_t rows, size_t columns) {
        Resize(rows, columns);
    }

    const vector<T>& operator [] (size_t idx) const {
        return data[idx];
    }

    vector<T>& operator [] (size_t idx) {
        return data[idx];
    }

    void Resize(size_t rows, size_t columns) {
        data.resize(rows);
        for (auto& item : data) {
            item.resize(columns);
        }
    }

    pair<size_t, size_t> Size() const {
        if (!data.empty() && !data[0].empty()) {
            return {data.size(), data[0].size()};
        }

        return  {0, 0};
    }

};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}