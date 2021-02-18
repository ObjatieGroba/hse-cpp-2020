#include <vector>
#include <set>
#include <forward_list>
#include <iostream>
#include <algorithm>
#include <numeric>

#include "c.h"


struct F {
    int x = 5;

//    F() = default;

//    F() = delete;

//private:
//    F() {}

    F(int z) : x(z) {

    }

//    F(int z) {
//        x = z;
//    }
};

class Test {
public:
    C c;
    D d;

//    Test() : c(std::move(C())) { // : c() {
//        std::cout << std::endl;
//        c = C();
//    }
    Test() : c(d),
             d() {
//        c = C();
    }
};

int main() {
//    F f;
//
//    std::cout << f.x << std::endl;

    Test test;

//    C c;
//    D d;

//    int x;
//    int y();

//    std::vector<int> v;
//    v.emplace_back();
//
//    std::cout << v.back() << std::endl;

//    C c1;
////    C c3();
//
//    {
//        C c2;
//    }
}
