#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

template <class T>
class Deque {
private:
    vector<T> front_;
    vector<T> back_;
    size_t sz;
public:
    Deque() {
        front_ = {};
        back_ = {};
    }

    bool Empty() const {
        if (front_.empty() && back_.empty()) {
            return true;
        } else {
            return false;
        }
    }

    size_t Size() const {
        return front_.size() + back_.size();
    }


    T& operator[](size_t index) {
        if (static_cast<int>(index) > (static_cast<int>(front_.size()) - 1)) {
            return back_[index - front_.size()];
        } else {
            return front_[front_.size() - index - 1];
        }
    }

    const T& operator[](size_t index) const {
        if (static_cast<int>(index) > (static_cast<int>(front_.size()) - 1)) {
            return back_[index - front_.size()];
        } else {
            return front_[front_.size() - index - 1];
        }
    }

    // At
    T& At(size_t index) {
        if (index >= front_.size() + back_.size()) {
            throw out_of_range("out of range");
        } else if (static_cast<int>(index) > (static_cast<int>(front_.size()) - 1)) {
            return back_[index - front_.size()];
        } else {
            return front_[front_.size() - index - 1];
        }
    }

    const T& At(size_t index) const {
        if (index >= front_.size() + back_.size()) {
            throw out_of_range("out of range");
        } else if (static_cast<int>(index) > (static_cast<int>(front_.size()) - 1)) {
            return back_[index - front_.size()];
        } else {
            return front_[front_.size() - index - 1];
        }
    }


    T& Front() {
        if (front_.empty()) {
            return *back_.begin();
        } else {
            return *prev(front_.end());
        }
    }

    const T& Front() const {
        if (front_.empty()) {
            return *back_.begin();
        } else {
            return *prev(front_.end());
        }
    }

    T& Back() {
        if (back_.empty()) {
            return *front_.begin();
        } else {
            return *prev(back_.end());
        }
    }

     const T& Back() const {
         if (back_.empty()) {
             return *front_.begin();
         } else {
             return *prev(back_.end());
         }
    }

    void PushFront(const T& x) {
        front_.push_back(x);
    }

    void PushBack(const T& x) {
        back_.push_back(x);
    }



};


int main() {
    std::cout << "Hello, World!" << std::endl;
    Deque<int> dq;
    cout << boolalpha << dq.Empty() << endl << dq.Size() << endl;
    dq.PushFront(2);
    dq.PushBack(3);
    dq.PushFront(1);
    dq.PushBack(4);
    dq.PushBack(77);
    dq.PushFront(-4);
    for (size_t i = 0; i < dq.Size(); i++) {
        cout << dq[i] << ' ' << dq.At(i) << " : " << dq.Front() << ' ' << dq.Back() << endl;
    }
    cout << dq.Front() << ' ' << dq.Back() << endl;

    return 0;
}
