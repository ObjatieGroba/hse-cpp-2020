#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <stdexcept>

template <class F, class S>
struct Pair {
    F first;
    S second;
};

template <class F, class S>
bool operator==(const Pair<F, S> &f, const Pair<F, S> &s) {
    return f.first == s.first;
}

//template <class F1, class S1, class F2, class S2, std::enable_if_t<...>>
//bool operator==(const Pair<F1, S1> &f, const Pair<F2, S2> &s) {
//    return f.first == s.first;
//}
//
//template <class F1, class S1, class F2, class S2>
//bool operator==(const Pair<F1, S1> &f, const Pair<F2, S2> &s) {
//    return std::to_string(f.first) == std::to_string(s.first);
//}


struct Stat {
    int64_t score;
    size_t num;
};

template <class T>
struct Pair<T, T> {
    T first;
    T second;
};

template <>
struct Pair<int64_t, size_t> {
    int64_t first;
    size_t second;
};

Pair<int64_t, size_t> p;
Stat s;

void process() {
    std::map<int, Pair<int64_t, size_t>> m{{3, {3, 3}}};
    auto it = m.find(3);
    it->second.second; // ??? WHY

    std::map<int, Pair<int64_t, size_t>>::iterator::value_type;
}

int main() {

}
