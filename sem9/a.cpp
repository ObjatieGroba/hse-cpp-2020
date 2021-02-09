#include <iostream>
#include <tuple>

struct S {
    unsigned long long b : 1;
    unsigned long long x : 63;
};

int main() {
    int i;

    std::tuple<int, std::string> t;
    auto &[x, y] = t;

    int &i_ref = i;

//    auto func = [&]() -> int {
//        return x;
//    };
//
//    func();

    S s{};

    auto &[sb, sx] = s;

    s.x = 5;

//    for (auto [key, val] : map)

    std::string str;
    std::cin >> str;
}