#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>

bool IsIn(std::map<int, bool> &map, int i) {
    std::cout << "x" << std::endl;
    return map[i];
}

bool IsIn(const std::map<int, bool> &map, int i) {
    std::cout << "y" << std::endl;
    auto it = map.find(i);
    return it != map.end();
//    if (it != map.end()) {
//        return true;
//    }
//    return false;
}

int main() {
    int x;
    std::map<int, bool> map;

    while (std::cin >> x) {
        if (IsIn(static_cast<const std::map<int, bool>&>(map), x)) {
            ///
        }
        map[x] = true;
    }
}
