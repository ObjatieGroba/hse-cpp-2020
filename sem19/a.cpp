#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class A {
public:
    void metohd1() {
        A::method2();
        this->method2();
    }

    static void method2() {
    }

    static A& singleton() {
        static A a;
        return a;
    }
};


void func() {
    A::singleton().metohd1();

    char * ptr = 0;
    ptr + 2;

    int * ptr_int = 0;
    ptr_int + 2; // GOOD
    // &(ptr_int[2]);
}


// Для простых примитивных типов (int, bool, char и т. д.) и plain old data
template <typename T>
void Serialize(T pod, std::ostream& out) {
//    std::cout << sizeof(pod) << std::endl;
    out.write(reinterpret_cast<const char*>(&pod), sizeof(pod));
}

void Serialize(const std::string& str, std::ostream& out) {
    // str.c_str();
    // str.data();
    // out << str;
    Serialize(str.size(), out);
    out.write(str.data(), str.size());
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);



template <typename T>
void Deserialize(std::istream& in, T& pod) {
//    std::cout << sizeof(pod) << std::endl;
    in.read(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void Deserialize(std::istream& in, std::string& str) {
    size_t sz;
    Deserialize(in, sz);
    str.resize(sz);
    in.read(str.data(), sz);
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);


int main() {
    std::stringstream ss;
    Serialize(-1, ss);
    unsigned x;
    Deserialize(ss, x);
    std::cout << x << std::endl;
//    Deserialize(ss, x);
//    std::cout << x << std::endl;
}
