
#include <list>
#include <iostream>
#include <string>

template <class T>
class V {
public:
    V(size_t size, const T& t) {
        while (size-- > 0) {
            data_.push_back(t);
        }
    }

    V() = default;

    V(const V &v) : data_(v.data_) {}

    V& operator=(const V& v) {
        data_ = v.data_;
        return *this;
    }

    bool operator==(const V<T>other) const {
        return false;
    }

    T& operator[](size_t ind) {
        if (data_.size() <= ind) {
            throw std::runtime_error("Out of range");
        }
        auto it = data_.begin();
        while (ind-- > 0) {
            ++it;
        }
        return *it;
    }

    const T& operator[](size_t ind) const {
        if (data_.size() <= ind) {
            throw std::runtime_error("Out of range");
        }
        auto it = data_.begin();
        while (ind-- > 0) {
            ++it;
        }
        return *it;
    }

    void * operator new(size_t s) = delete;

    void push_back(const T &t) {
        data_.push_back(t);
    }

    template <class ...Args>
    void emplace_back(Args ...args) {
        data_.emplace_back(args...);
    }

    size_t size() const {
        return data_.size();
    }

private:
    std::list<T> data_;
};

//template <class T>
//V<T>& operator=(V<T> & vorig, const V<T>& v) {
//    vorig.data_ = v.data_;
//    return vorig;
//}

int main() {
    V<int> v(5, 3);

    v[3] = 10;

    std::cout << v[3] << std::endl;
    std::cout << v[2] << std::endl;

    std::cout << v.size() << std::endl;
    v.emplace_back(1);
    std::cout << v.size() << std::endl;

    {
        const V<int>& v2 = v;
        std::cout << v2[2] << std::endl;
    }

    V<std::string> v4;

    v4.emplace_back("x");

    V<int> vcopy(v);

    V<int> vcopy2;
    vcopy = vcopy2 = v;

    while (true) {
        V<int> v;
        int * ptr = new int;
        if (true) {
            break;
        }
        delete ptr;
    }
}
