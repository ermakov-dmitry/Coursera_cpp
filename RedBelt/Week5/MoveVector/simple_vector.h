#include <cstdint>
#include <iterator>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size) {
        capacity = size;
        size_ = size;
        data = new T[capacity];
    }


    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return *(data + index);
    }

    T* begin() {
        return data;
    }
    T* end() {
        return data + size_;
    }

    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity;
    }

    void PushBack(T value) {
        if (capacity == 0) {
            data = new T[1];
            *data = move(value);
            capacity++;
            size_++;
        } else if (size_ < capacity) {
            *(data + size_++) = move(value);
        } else if (size_ == capacity) {
            auto extended = new T[capacity * 2];
            move(data, data + size_, extended);
            delete[] data;
            data = extended;
            *(data + size_++) = move(value);
            capacity *= 2;
        }
    }

    // При необходимости перегрузите
    // существующие публичные методы

private:
    T* data = nullptr;
    size_t size_ = 0u;
    size_t capacity = 0u;

};