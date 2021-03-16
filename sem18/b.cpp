#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;


class ConstExpr: public Expression {
private:
    int val_;

public:
    ConstExpr(int val): val_(val) {}

    int Evaluate() const override {
        return val_;
    }

    std::string ToString() const override {
        return std::to_string(val_);
    }
};


class ProductExpr: public Expression {
private:
    ExpressionPtr left;
    ExpressionPtr right;

public:
    ProductExpr(ExpressionPtr left, ExpressionPtr right):left(left), right(right) {

    }

    int Evaluate() const override {
        return left->Evaluate() * right->Evaluate();
    }
    std::string ToString() const override {
        /// @TODO Check is const with dynamic_cast
        std::string rstr;
        auto * res = dynamic_cast<ConstExpr*>(right.get());
        if (res) {
            rstr = right->ToString();
        } else {
            rstr = "(" + right->ToString() + ")";
        }
        return left->ToString() + " * " + rstr;
    }

};

ExpressionPtr Const(int x) {
    return ExpressionPtr(new ConstExpr(x));
}

ExpressionPtr Product(ExpressionPtr l, ExpressionPtr r) {
    return ExpressionPtr(new ProductExpr(l, r));
}

int main() {
    ExpressionPtr ex1 = Product(Const(3), Const(4));
    std::cout << ex1->ToString() << "\n";  // 3 * 4
    std::cout << ex1->Evaluate() << "\n";  // 12

    ExpressionPtr ex2 = Product(Const(6), ex1);
    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4)
    std::cout << ex2->Evaluate() << "\n";  // 72
}
