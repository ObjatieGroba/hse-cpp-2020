#include <iostream>
#include <tuple>
#include <vector>
#include <set>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v) {
    for (auto && elem : v) {
        os << elem << ' ';
    }
    os << '\n';
    return os;
}


int main() {
    std::vector v1{1, 2, 3, 4, 4, -1, 2, 1, 1, 1};
//    std::reverse(v1.begin() + 1, v1.end());

    std::vector<int> v2;

//    std::reverse_copy(v1.rbegin(), v1.rend(), std::inserter(v1, v1.begin()));

    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));

//    int x;
//    std::cin >> x;
//
//    std::cout << v2;
//
//    auto last_written = std::remove_if(v2.begin(), v2.end(), [x](int cur) -> bool {
//        return cur == x;
//    });
//    std::cout << v2;
//    v2.erase(last_written, v2.end());

    /// Should not work
//    std::set<int> s{1, 2, 3, 4, 5};
//    std::remove_if(s.begin(), s.end(), [](int cur) -> bool {
//        return cur % 2 == 0;
//    });

//    std::cout << v2;

    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

//    std::cout << v2;

    std::sort(v2.begin(), v2.end());

//    std::cout << v2;

    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

//    std::cout << v2;

    std::transform(v2.begin(), v2.end(), v2.begin(), [](int &x) -> int {
        return x * x;
    });

    std::cout << v2;

    std::for_each(v2.begin() + 1, v2.end(), [](int& x) -> void {
        x = -x;
    });

    std::cout << v2;

    std::vector v3{1, 3, 4, 7, 4};
    std::vector v4{1, 2, 6, 3, 4, 5, 6};
    std::vector<int> v5;

    std::merge(v3.begin(), v3.end(), v4.begin(), v4.end(), std::back_inserter(v5));

    std::cout << v3 << v4 << v5;

    auto it2 = v5.begin();
    auto it3 = v5.begin();
    ++it2;


    std::vector<size_t> v10{1, 2, 3};
    std::cout << *std::prev(v10.begin(), 10) << std::endl;

//    void * vx = malloc(1024);
//    auto * sx = static_cast<size_t *>(vx);
//    std::cout << *(sx - 1) << std::endl;
//
//    free(vx);
}
