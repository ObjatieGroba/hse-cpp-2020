#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>

class BaseWrong {
public:
    void Save() {

    }
    void Load() {

    }

    void Check() const {
        std::cout << "OK\n";
    }

    int z;
    int f;
};

class StringWrong : public BaseWrong {
public:
    void Save() {
        std::cout << data << std::endl;
    }
    void Load() {
        std::cin >> data;
    }

    std::string data;
};

class Base {
public:
    virtual void Save() {

    }
    virtual void Load() {

    }

    void Check() const {
        std::cout << "OK\n";
    }

    int x;
    int y;
};

class String : public Base, public BaseWrong {
public:
    void Save() override {
        std::cout << data << std::endl;
    }
    void Load() override {
        std::cin >> data;
    }

    void Test() {
        std::cout << "Test\n";
    }

    std::string data;
};

void func(BaseWrong &base) {
    base.Load();
}

void func(Base &base) {
//    base.Load();
    auto * base_ptr = &base;
    String * str_ptr = dynamic_cast<String *>(base_ptr);
    std::cout << str_ptr << ' ' << base_ptr << std::endl;
    if (str_ptr != nullptr) {
        str_ptr->Test();
    }
}

int main() {
//    std::cout << sizeof(StringWrong) << std::endl;
//    std::cout << sizeof(String) << std::endl;

//    std::unique_ptr<BaseWrong> ptr_wrong = std::make_unique<StringWrong>();
//    func(*ptr_wrong);

//    ptr_wrong->Load();
//    ptr_wrong->Save();

//    std::cout << "----\n";

    std::unique_ptr<Base> ptr = std::make_unique<String>();
    func(*ptr);

//    ptr->Load();
//    ptr->Save();

//    String x;
//    x.Load();
//    x.Save();
//
//    x.Check();
}

