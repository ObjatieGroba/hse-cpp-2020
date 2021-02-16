#include <vector>
#include <set>
#include <forward_list>
#include <iostream>
#include <algorithm>
#include <numeric>

template <class Container>
void func(const Container &c) {
    if (c.size() == 0) {

    }
    if (c.empty()) {

    }
}

void func3(const std::forward_list<int> &c) {
    c.empty();
//    c.size();
}

void func2(const std::vector<int> &c) {
    c.empty();
}

/// BAD
#define DEF_CONST 10
const int x = 10;
/// GOOD
constexpr int y = 10;
enum class Constants {
    kEnumConst = 10,
};

constexpr int sum(int x_l, int y_l) {
    return x_l + y_l;
}

//Constants::kEnumConst;

void f(int x, int y) {}

#define FUNC(arg) f(0, arg)

template<typename Iterator, typename T, typename BinaryOp>
T Reduce(Iterator first, Iterator last, T init, BinaryOp op) {
    for (; first != last; ++first) {
        init = op(init, *first);
    }
//    first + 1;
//    auto &ref = *first;
//    ++first;
//    while (first != last) {
//        ++first;
//    }
    return init;
}

template <class It1, class It2>
size_t CountSubsegments(It1 b1, It1 e1, It2 b2, It2 e2) {
//    std::search()...
    size_t num_of_not_found;
    size_t all_elems = e1 - b1;
    for (; b1 != e1; ++b1) {
        for (auto it2 = b2, it1 = b1; it2 != e2 && it1 != e1; ++it2, ++it1) {
            if (*it2 != *b1) {
                ++num_of_not_found;
                break;
            }
        }
    }
    ///     size_t   - size_t
    return all_elems - num_of_not_found;
}

int f1() {
    std::cout << "f1" << std::endl;
    return 0;
}

size_t f2() {
    std::cout << "f2" << std::endl;
    return 1;
}

auto f3() {
    auto z = (f1(), f2(), 10);
    return z;
}

template <class C1, class C2>
C2 same_as(const C1 &c1, const C2 &c2) {
    return c2;
}

int main() {
    func(std::vector<int>());

    func(std::set<int>());

    func2({1, 2, 3});

    FUNC(5);  // f(0, 5);

    constexpr auto res = sum(1, 5);

    int num;
    std::cin >> num;
    auto res2 = sum(num, 5);


    auto res3 = sum(1, 5);

    std::vector<int> xx(5, int());

    std::cout << "res " << f3() << std::endl;
}
