#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

template <class T>
class ObjectPool {
public:
    ObjectPool() {
        used_objects = new set<T*>;
        free_objects = new queue<T*>;
    }
    T* Allocate() {
        if (!free_objects->empty()) {
            used_objects->insert(free_objects->front());
            auto result = free_objects->front();
            free_objects->pop();
            return result;
        } else {
            T* pT = new T;
            used_objects->insert(pT);
            return pT;
        }
    }
    T* TryAllocate() {
        if (!free_objects->empty()) {
            used_objects->insert(free_objects->front());
            auto result = free_objects->front();
            free_objects->pop();
            return result;
        } else {
            return nullptr;
        }
    }

    void Deallocate(T* object) {
        auto it_find = used_objects->find(object);
        if (it_find == used_objects->end()) {
            throw invalid_argument("");
        } else {
            free_objects->push(*it_find);
            used_objects->erase(it_find);
        }
    }

    ~ObjectPool() {
        for (const auto& x : *used_objects) {
            delete x;
        }
        while (!free_objects->empty()) {
            T* p = free_objects->front();
            free_objects->pop();
            delete p;
        } // tut
        delete used_objects;
        delete free_objects;
    }

private:
    // Добавьте сюда поля
    set<T*>* used_objects;
    queue<T*>* free_objects;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}