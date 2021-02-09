#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>

std::vector<std::string_view> path_iterator(std::string_view s) {
    std::vector<std::string_view> res;
    // for (size_t i = 1; i != s.size(); ++i) {
    //   if (s[i] == '/') {
    //     res.push_back(s.substr(0, i - 1));
    //   }
    // }

    while (!s.empty()) {
        res.push_back(s);
        auto pos = s.rfind('/');
        if (pos != std::string::npos) {
            // throw 1;
            throw std::runtime_error("Invalid string");
        }
        s = s.substr(0, pos - 1);
    }

    return res;
}

union U {
    int x;
    unsigned y;
    int64_t k;
};

struct MyString {
    char * data;

    union {
        struct BigString {
            size_t size;
            size_t capacity;
        } bs;

        struct LittleString {
            char buf[24] = "abcde";
        } ls;
    } u;

};

struct MyStringUnix {
    char * data;
    size_t size;

    union {
        struct BigString {
            size_t capacity;
        } bs;

        struct LittleString {
            char buf[16] = "abcde";
        } ls;
    } u;

};

struct MyStringView {
    char * data;
    size_t size;
};

void func() {
    std::unordered_set<std::string_view> x;

    std::string s, cmd;

    while (std::cin >> cmd >> s) {
        if (cmd == "check") {
            std::cout << (x.find(s) == x.end()) << std::endl;
        } else {
            x.insert(s);
        }
    }
}


int main() {
    std::string s = "abc/ef";
    // path_iterator(s);


    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(std::vector<char>) << std::endl;
    std::cout << sizeof(MyString) << std::endl;

    MyString ms{};
    ms.data = ms.u.ls.buf;

    std::vector<char> z(10);
    ms.data = z.data();




}

