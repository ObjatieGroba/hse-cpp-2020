#include <vector>
#include <iostream>

std::vector<int> *ptr;

int func(const std::vector<int> &v) {
    ptr = const_cast<std::vector<int> *>(&v);

//    v.push_back(2);
    return v.back();
}

//#define NUMBER 1;  -- BAN
//#define ULL unsigned long long

//using ULL = unsigned long long;  -- BAN

//uint64_t;

enum {
    kMyNumber = 1,
    kOtherNum = 2
};

int main() {
    const std::vector<int> v1{1, 2, 3, 4};

    std::cout << func(v1) << std::endl;
    std::cout << (*ptr)[0] << std::endl;

    std::cout << 1 << std::endl;

    ptr->push_back(2);

    std::cout << v1.back() << std::endl;

//    std::vector<int> v2();  // Empty
//    std::vector<int> v2{};  // Empty
    std::vector<int> v2;  // Empty

    std::vector<int> v3(3, 4);  // {4, 4, 4, 4}

    std::vector<std::string> vs{"abcde",
                                "fghi",
                                "next"};

    long long x;
//    std::cin >> x;
    x % 10; // 10LL - BAN

    1ll; // 111

    int size;

    size = v2.size();

    const int z = 10;

    'a'; '\0xFF';

    'a' + 1 == 'b';

    auto xx = static_cast<int>(8ULL);

//    dynamic_cast



}
