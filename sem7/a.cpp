#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <stdexcept>

int main() {
    std::string s;
    std::set<char> set;
    std::map<char, size_t> map;
    ++map['a'];
    while (std::cin >> s) {
        try {
            size_t& d = map.at('b');
            ++d;
        } catch (const std::out_of_range &e) {
            std::cout << "OHOH";
            throw;
        }
        set = std::set<char>(s.begin(), s.end());
        char c = s[0];
    }
    std::cout << "F" << std::endl;

}
