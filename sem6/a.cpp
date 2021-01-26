#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

struct Node {
    int x;
    int y;

    bool operator==(const Node & other) const {
        return this->x == other.x && y == other.y;
    }
};



bool operator<(const Node &lhs, const Node &rhs) {
    std::cout << "X" << std::endl;
    return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
}

namespace std {
    template<> struct hash<Node> {
        std::size_t operator()(const Node& s) const {
            return std::hash<int>()(s.x);
        }
    };
}

int main() {
    auto compare = [](const Node &lhs, const Node &rhs) -> bool {
        std::cout << "Y" << std::endl;
        return std::tie(lhs.x, lhs.y) > std::tie(rhs.x, rhs.y);
    };

    std::map map({
        std::pair<Node, int>{Node{1, 2}, static_cast<int>(3ll)},
        std::pair{Node{3, 4}, static_cast<int>(6ll)}
        }, compare);

    std::unordered_map<Node, int> umap;

    umap[Node{3, 4}] = 6;
    umap[Node{3, 5}] = 7;
}
