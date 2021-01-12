#include <iostream>
#include <vector>
#include <cmath>

int fuc1(int x) {
    int y;
    if (x == 5) {
        y = 42;
    }
    return y;
}

int func2() {
    bool b;
    if (b) {
        std::cout << "1" << std::endl;
    }
    if (!b) {
        std::cout << "2" << std::endl;
    }
    return 0;
}

int func3() {
    double x;
    x = 1 / 2;
    x = 0.1;
    x = 2;

    x = 1. / 2;
    return 0;
}

int func4() {
    char c;
    c = '.';
    "adwwadad";  /// String
    'a';  //// Symbol

    char c2 = 38;
    ++c2;

    int z = 2;
    c2 = static_cast<char>(z);

    for (char c3 = 0; c3 != 10; ++c3) {

    }

    return 0;
}

int func5() {
    std::string s; // ПОЧТИ КАК same as vector<char>
    std::cin >> s;

    s[1] = 'a';

    return s.size();
}

int main() {
//    int n;
//    std::cin >> n;
//
//    std::vector<int> v;
//    v.reserve(n);
//
////    std::vector<int> v2(n);
//
//    for (int i = 0; i != n; ++i) {
//        v.push_back(i);
////        v2[i] = i;
//    }
//
//    int m;
//    std::cin >> m;
//
//    std::cout << v[v[m]] << std::endl;


}
