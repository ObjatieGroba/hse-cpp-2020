#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>

#include <cmath> /// BAN
// #include "math.h" -- same as upper

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

//    abs()

//    std::abs()

    if (x1 == x2 || y1 == y2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO" << std::endl;
    }


}
