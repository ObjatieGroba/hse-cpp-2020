#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <deque>

template <class T, class Deleter=std::default_delete<T>>
class UniquePtr {
public:
    UniquePtr() {}
    UniquePtr(T* data) : data_(data) {}
    UniquePtr(T* data, Deleter deleter) : data_(data), deleter_(deleter) {}

    ~UniquePtr() {
        delete data_;
    }

    UniquePtr(UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other) {
        data_ = other.data_;
        other.data_ = nullptr;
        tuple_ = std::move(other.tuple_);
        other.get_get() = nullptr;
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

    T*& get_get() {
        return std::get<T*>(tuple_);
    }

private:
    std::tuple<T*, Deleter> tuple_;
    T * data_ = nullptr;
    Deleter deleter_;
};


// template <class T, class ...Args>
// UniquePtr<T> make_unique(Args... args) {
//     try {
//         return UniquePtr<T>(new T(args...));
//     } catch (...) {
//         return UniquePtr<T>{};
//     }
// }

//template <class T>
//class ListTemplated {
//private:
//    struct Node {
//        Node * prev;
//        Node * next;
//        T data;
//    };
//
//    struct Iterator {
//    private:
//        // List * list;
//        Node * node;
//
//    public:
//        Iterator operator++() {
//            node = node->next;
//            return *this;
//        }
//    };
//
//public:
//    void push_front(const T& t) {
//        Node* node = new Node(nullptr, begin_, t);
//        ++size_;
//        if (begin_ != nullptr) {
//            begin_->prev = node;
//        } else {
//            end_ = begin_ = node;
//        }
//    }
//
//    void pop_front() {
//        if (size_ == 0) {
//            throw std::out_of_range("list is empty");
//        }
//        --size_;
//        auto next = begin_->next;
//        delete begin;
//        begin_ = next;
//        if (begin_ == nullptr) {
//            end_ = nullptr;
//        } else {
//            begin_->prev = nullptr;
//        }
//    }
//
//    Iterator begin() const {
//        return {begin_};
//    }
//
//    // using iterator = Iterator;
//
//private:
//    Node * begin_ = nullptr;
//    Node * end_ = nullptr;
//    size_t size_ = 0;
//};

//using List = ListTemplated<int>;
//
//template <class T = int>
//using ListExample = ListTemplated<T>;

int main() {
//    UniquePtr<int> ptr{new int(10)};
//    auto x = std::move(ptr);
//    x = UniquePtr<int>(new int(20));

    // auto ptr1 = make_unique<int>();
    // auto ptr2 = make_unique<int>(2);
    // auto ptr3 = make_unique<std::string>("awdwada", 3);
//    List list;
//    list.push_front(1);
//    list.pop_front();

    // List::iterator;

//    std::deque<int> v = {2, 12, 85, 0, 6};
//    std::sort(v.end(), v.begin());
////    std::sort(v.begin(), v.end());
//
//    while (!v.empty()) {
//        std::cout << *v.begin() << std::endl;
//        v.pop_front();
//    }
//    {
//        size_t z = 0;
//        size_t zz = 0;
//        int long long x = 42;
//        std::shared_ptr<int long long> sp1(&x);
//        auto sp2 = sp1;
//        std::cout << *sp2 << "\n";
//    }

    int str[11];
    std::cout << sizeof(str) << "\n";

}
