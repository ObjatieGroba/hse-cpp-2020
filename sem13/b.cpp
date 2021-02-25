#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <mutex>

struct Z {
    int x;
    int y;
};

class Rational {
public:
    // Rational() = default;

    // Rational(int numerator) : Rational(numerator, 1) { }

    Rational(int numerator = 0, int denominator = 1)
            : numerator_(numerator)
            , denominator_(denominator) {}

    // Rational(const Rational & r) = delete;

    void Print() const {
        std::cout << numerator_ << '/' << denominator_ << std::endl;
    }

    Rational operator+(const Rational& other) const {
        Rational copy = *this;
        return copy += other;
    }

    bool operator==(const Rational& other) const {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }

    Rational& operator+=(const Rational& other) {
        /// return *this = (*this + other);
        numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        denominator_ = denominator_ * other.denominator_;
        return *this;
    }

    [[nodiscard]] bool IsEmpty() const {
        return numerator_ == 0;
    }

    [[nodiscard]] size_t Size() const {
        /// O(N)
        return 0;
    }

    [[nodiscard]] bool Div(Rational other) const {
        if (other.IsEmpty()) {
            return false;
        }
        // *this /= other;
        return true;
    }

    /// Prefix
    Rational& operator++() {
        ++numerator_;
        return *this;
    }

    /// Postfix
    Rational operator++(int) {
        // std::cout << x << std::endl;
        Rational copy = *this;
        ++(*this);
        // this->operator++();
        return copy;
    }

private:
    int numerator_; //  = 0;
    int denominator_; // = 1;
    // std::mutex mx;
};

int main() {
    Rational r1(3);
    Rational r2;

    Rational r3(r1);
    Rational r4 = r2;

    r3.Print();
    r4.Print();

    (r3 + r4).Print();

    r3 += r4 += 5;

    r3.Print();

    r3.IsEmpty();

    ++r3;
    r3++;
}
