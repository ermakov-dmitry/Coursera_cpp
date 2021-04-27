#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() {
        elements = nullptr;
        end_ = nullptr;
        capacity = 0u;
    }
    explicit SimpleVector(size_t size) {
        capacity = size;
        elements = new T[capacity];
        end_ = elements + size;
    }
    ~SimpleVector() {
        if (elements != nullptr) {
            delete[] elements;
        }
    }

    T& operator[](size_t index) {
        return elements[index];
    }

    T* begin() {return elements;}
    T* end() {return end_;}

    const T* begin() const {return elements;}
    const T* end() const {return end_;}

    size_t Size() const {
        return end_ - elements;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(const T& value) {
        if (elements == nullptr) {
            elements = new T[1];
            end_ = elements + 1;
            *elements = value;
            capacity = 1u;
        } else if (Capacity() == Size()) {
            auto extended_elements = new T[Capacity() * 2];


        }
    }

private:
    // Добавьте поля для хранения данных вектора
    T* elements;
    T* end_;
    size_t capacity;
};