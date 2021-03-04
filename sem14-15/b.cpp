#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <mutex>
#include <array>
#include <ranges>

constexpr size_t ComputeSize(size_t n, size_t m) {
    if (n == 0 || m == 0) {
        return 1;
    }
    return n * m;
}

template <class T, size_t N, size_t M>
class Matrix {
    std::array<T, ComputeSize(N, M)> matrix;
};

namespace Our {

template<class T>
class Polynomial {
public:
    Polynomial() = default;

    template<class It>
    Polynomial(It begin, It end)
            : coefficients_(begin, end) {}

    Polynomial(const std::vector<T> &v)
            : Polynomial(v.cbegin(), v.cend()) {}
    // : coefficients_(v) {}

    Polynomial(T t) {} /// @TODO

    class iterator {
    public:
        iterator(Polynomial &p, size_t idx) : p_(p), idx_(idx) { }

        iterator& operator++() {
            ++idx_;
            return *this;
        }

        bool operator==(const iterator& other) const {
            return &this->p_ == &other.p_ && idx_ == other.idx_;
        }

        T& operator*() {
            return p_.coefficients_[idx_];
        }

        auto operator<=>(const iterator &other) const {
            return idx_ <=> other.idx_;
        }

    private:
        Polynomial &p_;
        size_t idx_;
    };

    // typename std::vector<T>::iterator begin() {
    iterator begin() {
        return iterator(*this, 0);
    }

    iterator end();

private:
    std::vector<T> coefficients_;
};

} // Namespace Our

//template <class T>
//typename Our::Polynomial<T>::iterator Our::Polynomial<T>::end() {
//
//}

namespace Our {
    template <class T>
    typename Polynomial<T>::iterator Polynomial<T>::end() {
        return iterator(*this, coefficients_.size());
    }
}

template <class C, class It=typename C::iterator>
void f(C c, It it) {

}


int main() {
    std::array<int, 8> a;
    Matrix<int, 3, 4> m;
//    Matrix<int, 5, 6> &m_ref = m;
    Our::Polynomial<int> x{std::vector<int>{1, 2, 3}};

    for (auto elem : x) {
        std::cout << elem;
    }

    std::vector<int> v{5, 1, 2, 3};
    std::sort(v.begin(), v.end());
    std::ranges::sort(v);
}
