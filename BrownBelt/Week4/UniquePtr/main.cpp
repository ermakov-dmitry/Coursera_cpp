#include "test_runner.h"

#include <cstddef>  // нужно для nullptr_t
#include <algorithm>
#include <cassert>

using namespace std;

// Реализуйте шаблон класса UniquePtr
template <typename T>
class UniquePtr {
private:
    T* data;
public:
    UniquePtr();
    UniquePtr(T * ptr);
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other);
    UniquePtr& operator = (const UniquePtr&) = delete;
    UniquePtr& operator = (nullptr_t);
    UniquePtr& operator = (UniquePtr&& other);
    ~UniquePtr();

    T& operator * () const;

    T * operator -> () const;

    T * Release();

    void Reset(T * ptr);

    void Swap(UniquePtr& other);

    T* Get() const;
};

template<typename T>
UniquePtr<T>::UniquePtr() : data(nullptr) {}

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) : data(ptr) {}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T> &&other) : data(other.data) {
    other.data = nullptr;
}

template<typename T>
UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr<T> &&other) {
    if (this != &other) {
        Reset(other.data);
        other.data = nullptr;
    }
    return *this;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(nullptr_t) {
    delete data;
    data = nullptr;
    return *this;
}

template <typename T>
UniquePtr<T>::~UniquePtr() {
    delete data;
}

template<typename T>
T &UniquePtr<T>::operator*() const {
    return *data;
}

template<typename T>
T *UniquePtr<T>::operator->() const {
    return data;
}

template<typename T>
T *UniquePtr<T>::Release() {
    auto tmp = data;
    data = nullptr;
    return tmp;
}

template<typename T>
void UniquePtr<T>::Reset(T *ptr) {
    delete data;
    data = ptr;
}

template<typename T>
T* UniquePtr<T>::Get() const {
    return data;
}

template<typename T>
void UniquePtr<T>::Swap(UniquePtr<T> &other) {
    swap(*this, other);
}


struct Item {
    static int counter;
    int value;
    Item(int v = 0): value(v) {
        ++counter;
    }
    Item(const Item& other): value(other.value) {
        ++counter;
    }
    ~Item() {
        --counter;
    }
};

int Item::counter = 0;


void TestLifetime() {
    Item::counter = 0;
    {
        UniquePtr<Item> ptr(new Item);
        ASSERT_EQUAL(Item::counter, 1);

        ptr.Reset(new Item);
        ASSERT_EQUAL(Item::counter, 1);
    }
    ASSERT_EQUAL(Item::counter, 0);

    {
        UniquePtr<Item> ptr(new Item);
        ASSERT_EQUAL(Item::counter, 1);

        auto rawPtr = ptr.Release();
        ASSERT_EQUAL(Item::counter, 1);

        delete rawPtr;
        ASSERT_EQUAL(Item::counter, 0);
    }
    ASSERT_EQUAL(Item::counter, 0);
}

void TestGetters() {
    UniquePtr<Item> ptr(new Item(42));
    ASSERT_EQUAL(ptr.Get()->value, 42);
    ASSERT_EQUAL((*ptr).value, 42);
    ASSERT_EQUAL(ptr->value, 42);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestLifetime);
    RUN_TEST(tr, TestGetters);
}