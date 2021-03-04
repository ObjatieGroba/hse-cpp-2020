#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <mutex>


template <class T>
class Polynomial {
public:
    Polynomial() = default;

    template <class It>
    Polynomial(It begin, It end)
            : coefficients_(begin, end) {}

    Polynomial(const std::vector<T> &v)
            : Polynomial(v.cbegin(), v.cend()) {}
    // : coefficients_(v) {}

    Polynomial(T t) {} /// @TODO

    // typename std::vector<T>::iterator begin() {
    auto begin() {
        return coefficients_.begin();
    }

    typename std::vector<T>::iterator end();

    template <class ResT>
    ResT getZeroCoeff();

    bool operator==(const Polynomial<T> &other) const  {
        return coefficients_ == other.coefficients_;
    }

    Polynomial<T> operator+(const Polynomial<T> &other) const {
        Polynomial copy = *this;
        copy.IncreaseDegree(std::max(copy.Degree(), other.Degree()));
        for (size_t i = 0; i != std::max(copy.Degree(), other.Degree()) + 1; ++i) {
            copy.GetAt(i) += other[i];
        }
        copy.DecreaseDegree();
        return copy;
    }

    friend Polynomial operator-(const Polynomial &l, const Polynomial &r) {
//        l.coefficients_[0] = 2;
        return l;
    }

    int Degree() const {
        return coefficients_.size() - 1;
    }

    void IncreaseDegree(size_t degree) {
        /// Resize vector
    }

    void DecreaseDegree() {
        while (!coefficients_.empty() && coefficients_.back() == 0) {
            coefficients_.pop_back();
        }
    }

    auto operator[](size_t point) const {
        // if (...)
        return coefficients_[point];
    }

    auto& GetAt(size_t point) {
        return coefficients_[point];
    }

    auto operator()(T x) const {
        ///...
    }

    auto& operator<<(std::ostream &f) const {
        for (auto elem : coefficients_) {
            f << elem;
        }
        return f;
    }

private:
    std::vector<T> coefficients_;
};

template <class T>
int operator+(Polynomial<T> &l, Polynomial<T> &r) {
    return 1;
}

template <class T>
typename std::vector<T>::iterator Polynomial<T>::end() {
    return coefficients_.end();
}

template <class T>
template <class ResT>
ResT Polynomial<T>::getZeroCoeff() {
    return coefficients_[0];
}

int main() {
    std::vector<int> v{1, 2, 3};
    Polynomial<int> p1(v.begin(), v.end());
    Polynomial<int> p2(v);

    p2.getZeroCoeff<double>();

    p1 == p2;

    p1 == 2;

    p1 + 2;

//    2 + p1;

    p1 - 2;

    2 - p1;
}
