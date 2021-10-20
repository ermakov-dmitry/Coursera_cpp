#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    // Напишите реализацию функции,
    // не копируя сортируемые элементы
    auto distance = range_end - range_begin;
    if (distance < 2) {
        return;
    } else {
        vector<typename RandomIt::value_type> full(make_move_iterator(range_begin), make_move_iterator(range_end));
        MergeSort(full.begin(), full.begin() + distance / 3);
        MergeSort(full.begin() + distance / 3, full.end() - distance / 3);
        MergeSort(full.end() - distance / 3, full.end());
        vector<typename RandomIt::value_type> temporary{};
        merge(make_move_iterator(full.begin()),
              make_move_iterator(full.begin() + distance / 3),
              make_move_iterator(full.begin() + distance / 3),
              make_move_iterator(full.end() - distance / 3),
              back_inserter(temporary));
        merge(make_move_iterator(temporary.begin()),
              make_move_iterator(temporary.end()),
              make_move_iterator(full.end() - distance / 3),
              make_move_iterator(full.end()),
              range_begin);
    }

}

void TestIntVector() {
    vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
    MergeSort(begin(numbers), end(numbers));
    ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestIntVector);
    return 0;
}