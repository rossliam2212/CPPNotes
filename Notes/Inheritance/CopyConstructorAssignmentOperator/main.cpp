//
// Created by Liam Ross on 12/10/2022.
//

#include <iostream>

class Base {
private:
    int value;

public:
    Base() : value{} {
        std::cout << "Base no-args constructor\n";
    }

    Base(int x) : value{x} {
        std::cout << "Base (int) overloaded constructor\n";
    }

    Base(const Base& other) : value{other.value} {
        std::cout << "Base copy constructor\n";
    }

    Base& operator=(const Base& rhs) {
        std::cout << "Base operator=\n";

        if (this == &rhs)
            return *this;

        value = rhs.value;
        return *this;
    }

    ~Base() {
        std::cout << "Base destructor\n";
    }
};


class Derived : public Base {
private:
    int doubledValue;

public:
    Derived() : Base{}, doubledValue{} {
        std::cout << "Derived no-args constructor\n";
    }

    Derived(int x) : Base{x}, doubledValue{x*2} {
        std::cout << "Derived (int) overloaded constructor\n";
    }

    Derived(const Derived& other) : Base{other}, doubledValue{other.doubledValue} {
        std::cout << "Derived copy constructor\n";
    }

    Derived& operator=(const Derived& rhs) {
        std::cout << "Derived operator=\n";

        if (this == &rhs)
            return *this;

        Base::operator=(rhs);
        doubledValue = rhs.doubledValue;
        return *this;
    }

    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

int main() {
//    Base b{100}; // Overloaded Constructor
//    Base b1{b};     // Copy Constructor
//    b = b1;         // Copy Assignment

    Derived d{100};  // Overloaded Constructor
    Derived d1{d};      // Copy Constructor
    d = d1;             // Copy Assignment

    return 0;
}
