#pragma once

#include <cstdlib>
#include <algorithm>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() {
        elements = nullptr;
        capacity = 0u;
        size = 0u;
    }
    explicit SimpleVector(size_t size_) {
        capacity = size_;
        size = size_;
        elements = new T[capacity];
    }

    SimpleVector(const SimpleVector<T>& other) : elements(new T[other.capacity]), capacity(other.capacity), size(other.size) {
        std::copy(other.begin(), other.end(), begin());
    }

    ~SimpleVector() {
        if (elements != nullptr) {
            delete[] elements;
        }
    }

    void operator=(const SimpleVector& other) {
        if (other.size <= capacity) {
            std::copy(other.begin(), other.end(), begin());
            size = other.size;
        } else {
            SimpleVector<T> tmp(other);
            std::swap(tmp.elements, elements);
            std::swap(tmp.size, size);
            std::swap(tmp.capacity, capacity);
        }
    }

    T& operator[](size_t index) {
        return elements[index];
    }

    T* begin() {return elements;}
    T* end() {return elements + size;}

    const T* begin() const {return elements;}
    const T* end() const {return elements + size;}

    size_t Size() const {
        return size;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(const T& value) {
        if (elements == nullptr) {
            elements = new T[1];
            *elements = value;
            capacity = 1u;
            size = 1u;
        } else if (Capacity() > Size()) {
            *(elements + size++) = value;
        } else if (Capacity() == Size()) {
            auto extended = new T[Capacity() * 2];
            std::copy(elements, elements + size, extended);
            delete[] elements;
            elements = extended;
            *(elements + size++) = value;
            capacity *= 2;
        }
    }

private:
    // Добавьте поля для хранения данных вектора
    T* elements;
    size_t capacity;
    size_t size{};
};