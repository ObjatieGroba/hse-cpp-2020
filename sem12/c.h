#pragma once

#include <iostream>

class D {
public:
    static int counter;
    const int id;
    std::vector<int> v{1};

public:
    D(): id(++counter) {
        std::cout << "constructor D() " << id << "\n";
    }

    D(const D& other): id(++counter) {
        std::cout << "constructor D(const D&) " << id << " " << other.id << "\n";
    }

//    D(const C& other): id(++counter) {
//        std::cout << "constructor D(const C&) " << id << " " << other.id << "\n";
//    }

    D(D&& other): id(++counter) {
        std::cout << "constructor D(const D&&) " << id << " " << other.id << "\n";
    }

    D& operator = (const D& other) {
        std::cout << "operator = (const D&) " << id << " " << other.id << "\n";
        return *this;
    }

    D& operator = (D&& other) {
        std::cout << "operator = (const D&&) " << id << " " << other.id << "\n";
        return *this;
    }

    ~D() {
        std::cout << "destructor D() " << id << "\n";
    }
};

class C {
public:
    static int counter;
    const int id;

public:
    C(): id(++counter) {
        std::cout << "constructor C() " << id << "\n";
    }

    C(const C& other): id(++counter) {
        std::cout << "constructor C(const C&) " << id << " " << other.id << "\n";
    }

    C(const D& other): id(++counter) {
        std::cout << "constructor C(const D&) " << id << " " << other.id << "\n";
        std::cout << "constructor C(const D&) " << other.v[0] << "\n";
    }

    C(C&& other): id(++counter) {
        std::cout << "constructor C(const C&&) " << id << " " << other.id << "\n";
    }

    C& operator = (const C& other) {
        std::cout << "operator = (const C&) " << id << " " << other.id << "\n";
        return *this;
    }

    C& operator = (C&& other) {
        std::cout << "operator = (const C&&) " << id << " " << other.id << "\n";
        return *this;
    }

    ~C() {
        std::cout << "destructor C() " << id << "\n";
    }
};

int C::counter = 0;
int D::counter = 0;