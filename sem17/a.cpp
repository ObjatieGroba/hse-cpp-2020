#include <string>
#include <iostream>
#include <stdexcept>

struct S {
    std::string x;
    std::string y;
};

S create() {
    return {};
}

enum class Error {
    kSuccess,
    kParsingError,
};


Error create_google(int x, S *s) noexcept {
    return Error::kParsingError;
}

void process(const S &s) {
    throw std::runtime_error("Not implemented");
}

void process2(const S &s) {
    S s2;
    process(s2);

    S s3;
    // ...
}

int main() {
    S s1{"x", "y"};
    S s2{
        .x = "x",
        .y = "y"
    };
    S s3{
        .x = "x",
    };

//    process(create());
    S s;
    int x = 0;
    create_google(x, &s);
    S * sptr = new S;
    create_google(x, sptr);
    delete sptr;


    try {
        process(s);
        exit(1);  // return 1;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << " re" << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
