#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class PriorityCollection {
public:
    using priory = int;
    using time = int;
    using Idx = pair<typename list<T>::iterator, priory>;
    using Id = time;
    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    PriorityCollection() : data(), priorities({}), references(vector<Idx>(1'000'000, {data.end(), -1})), container_time(0) {}
    Id Add(T object) {
        priory cur_priory = 0;
        auto idx = data.insert(data.end(), move(object));
        references[container_time] = make_pair(idx, cur_priory);  // iter and priory in this time
        priorities[cur_priory].insert(container_time);
        return container_time++;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,
             IdOutputIt ids_begin) {
        priory cur_priory = 0;
        for (auto it = range_begin; it != range_end; it++) {
            auto idx = data.insert(data.end(), move(*it));
            references[container_time] = make_pair(idx, cur_priory);
            priorities[cur_priory].insert(container_time);
            *(ids_begin++) = container_time++;
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    [[nodiscard]] bool IsValid(Id id) const {
        return references[id].second > -1;  //in this time not exist object
    }

    // Получить объект по идентификатору
    [[nodiscard]] const T& Get(Id id) const {  // id its time
        auto idx = references[id].first;
        return *idx;

    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id) {
        priory obj_priory = references[id].second;
        priorities[obj_priory].erase(id);
        references[id].second++;
        CheckEmptyPriory(obj_priory);
        priorities[++obj_priory].insert(id);
    }

    // Получить объект с максимальным приоритетом и его приоритет
    [[nodiscard]] pair<const T&, int> GetMax() const {
        time max_last_time = *(priorities.rbegin()->second).rbegin();
        Idx max_value = references[max_last_time];
        auto it = max_value.first;
        priory elem_priory = max_value.second;
        return {*it, elem_priory};
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax() {
        priory max_priory = priorities.rbegin()->first;
        time max_last_time = *(priorities.rbegin()->second).rbegin();
        Idx max_value = references[max_last_time];
        auto it = max_value.first;
        priory elem_priory = max_value.second;
        T return_object = move(*it);
        priorities[max_priory].erase(max_last_time);
        CheckEmptyPriory(max_priory);
        references[max_last_time] = {data.end(), -1};
        data.erase(it);
        return make_pair(move(return_object), elem_priory);
    }

private:
    // Приватные поля и методы
    list<T> data;
    map<priory, set<time>> priorities;
    vector<Idx> references; // time - idx,
    time container_time;
    void CheckEmptyPriory(const priory& _priory) {
        if (priorities.at(_priory).empty()) {
            priorities.erase(priorities.find(_priory));
        }
    }
};


class StringNonCopyable : public string {
public:
    using string::string;  // Позволяет использовать конструкторы строки
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
    PriorityCollection<StringNonCopyable> strings;
    const auto white_id = strings.Add("white");
    const auto yellow_id = strings.Add("yellow");
    const auto red_id = strings.Add("red");

    strings.Promote(yellow_id);
    for (int i = 0; i < 2; ++i) {
        strings.Promote(red_id);
    }
    strings.Promote(yellow_id);
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "yellow");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "white");
        ASSERT_EQUAL(item.second, 0);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestNoCopy);
    return 0;
}

