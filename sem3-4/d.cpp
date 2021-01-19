#include <iostream>
#include <limits>
#include <vector>

int min(const std::vector<std::vector<int>> & v) {
    int res = std::numeric_limits<int>::max();
    for (auto && row : v) {  // for (const? std::vector<int> &row : v)
        for (auto && elem : row) {
            res = std::min(res, elem);
        }
    }
    return res;
}

std::istream& operator>>(std::istream& is, std::vector<int> &v) {
  int tmp;
  while (is >> tmp) {
    v.push_back(tmp);
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int> &v) {
  for (auto && elem : v) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return os;
}

int main() {
//    int x;
//    std::cin >> x;
//    std::string s;
//    while (std::getline(std::cin, s)) {
//      ;
//    }

//    int x, y, z;
//    ((std::cin >> x) >> y) >> z;

//    std::vector<int> x;
//    if (std::cin >> x); /// if (std::cin)
//    if (bool(std::cin))
//      if (std::cin.good())
//    std::cout << x;



    std::cout << std::numeric_limits<unsigned>::min();
}
