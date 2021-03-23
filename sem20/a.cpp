#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <class T>
class UniquePtr {
public:
    UniquePtr() {}
    UniquePtr(T* data) : data_(data) {}

    ~UniquePtr() {
        delete data_;
    }

    UniquePtr(UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other) {
        data_ = other.data_;
        other.data_ = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) {
//        UniquePtr tmp(data_);
        data_ = other.data_;
        other.data_ = nullptr;
        return *this;
    }

    T* get() const {
        return data_;
    }

    explicit operator bool() const {
        return data_ == nullptr;
    }

    T& operator*() const {
        return *data_;
    }

    T* operator->() const {
        return data_;
    }

private:
    T * data_ = nullptr;
};


// template <class T, class ...Args>
// UniquePtr<T> make_unique(Args... args) {
//     try {
//         return UniquePtr<T>(new T(args...));
//     } catch (...) {
//         return UniquePtr<T>{};
//     }
// }

template <class T>
class ListTemplated {
private:
    struct Node {
        Node * prev;
        Node * next;
        T data;
    };

    struct Iterator {
    private:
        // List * list;
        Node * node;

    public:
        Iterator operator++() {
            node = node->next;
            return *this;
        }
    };

public:
    void push_front(const T& t) {
        Node* node = new Node(nullptr, begin_, t);
        ++size_;
        if (begin_ != nullptr) {
            begin_->prev = node;
        } else {
            end_ = begin_ = node;
        }
    }

    void pop_front() {
        if (size_ == 0) {
            throw std::out_of_range("list is empty");
        }
        --size_;
        auto next = begin_->next;
        delete begin;
        begin_ = next;
        if (begin_ == nullptr) {
            end_ = nullptr;
        } else {
            begin_->prev = nullptr;
        }
    }

    Iterator begin() const {
        return {begin_};
    }

    // using iterator = Iterator;

private:
    Node * begin_ = nullptr;
    Node * end_ = nullptr;
    size_t size_ = 0;
};

using List = ListTemplated<int>;

template <class T = int>
using ListExample = ListTemplated<T>;

int main() {
    UniquePtr<int> ptr{new int(10)};
    auto x = std::move(ptr);
    x = UniquePtr<int>(new int(20));

    // auto ptr1 = make_unique<int>();
    // auto ptr2 = make_unique<int>(2);
    // auto ptr3 = make_unique<std::string>("awdwada", 3);
    List list;
    list.push_front(1);
    list.pop_front();

    // List::iterator;
}
