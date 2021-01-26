#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

struct Point {
    int x;
    int y;
};

template <class Func>
size_t Find(std::string_view sv, Func func) {
    for (size_t i = 0; i != sv.size(); ++i) {
        if (func(sv[i])) {
            return i;
        }
    }
    return std::string::npos;
}

std::string_view Substr(std::string_view sv, size_t pos) {
    if (pos == std::string::npos) {
        return {};
    }
    return sv.substr(pos);
}

template <class Func>
std::vector<std::string> Split(const std::string& str, Func func) {
    std::string_view sv(str);
    std::vector<std::string> res;

    while (!sv.empty()) {
        auto non_delim_pos = Find(sv, [&](char c) {
            return !func(c);
        });
        sv = Substr(sv, non_delim_pos);

        if (sv.empty()) {
            break;
        }

        auto delim_pos = Find(sv, func);
        std::string_view token = sv.substr(0, delim_pos);
        res.emplace_back(token);
        sv = Substr(sv, delim_pos);
    }

    return res;
}

std::vector<std::string> Split(const std::string& str, char delimiter) {
    return Split(str, [=](char c){
        return c == delimiter;
    });
}

int main() {
    std::vector<Point> points{{1, 1}, {1, 2}, {2, 2}};

    std::sort(points.begin(), points.end(), [](Point p1, Point p2) -> bool {
        return std::tie(p1.x, p2.y) < std::tie(p2.x, p1.y);
    });

    auto res = Split("__abcd21_adhwjk_", isalpha);
    std::cout << std::endl;
}
