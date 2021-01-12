#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v;
    for (int i = 0; i != n; ++i) {

//        int x;
//        int y;
//        int z = x * y;

        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

//    std::vector<std::string> arr{"a", "b", "c"};

//    for (auto it = v.begin(); it != v.end(); ++it) {
//
//    }

//    for (auto && elem : v) {
//        std::cout << elem << std::endl;
//    }

    int m;
    std::cin >> m;

    int sum = 0;

    for (int i = 0; i != m; ++i) {
        int index;
        std::cin >> index;
        sum += v[index - 1];
    }

    for (size_t i = 0; i != v.size(); ++i) {
        ///
    }

    std::cout << sum << std::endl;

    int x = 10;
    (unsigned)x; /// BAN
    static_cast<unsigned>(x); /// NICE
}
