#include <vector>
#include <iostream>

class C {
public:
    C() : data_(5, 2) {};

    C(const C & c) : data_(c.data_) {}

    C(C && c) noexcept : data_(std::move(c.data_)) { }

    C& operator=(C &&c) {
        // data_.clear();  /// free(v);
        data_ = std::move(c.data_); /// v = c.v_; c.v_ = nullptr;
        return *this;
    }

    void print() const {
        int k;
        for (auto &&elem : data_) {
            k = std::move(elem);
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }

    void incx() {
        ++x_;
    }

private:
    int x_ = 0;
    std::vector<int> data_;

//    int * v;
};


int main() {
    C c1;
    const C &c2 = c1;
    c1.print();
    c2.print();

    c1.incx();
    {
        C c_copy(c1);

        c1.print();
        c_copy.print();
    }
}
