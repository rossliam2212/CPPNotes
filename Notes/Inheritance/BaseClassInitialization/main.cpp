//
// Created by Liam Ross on 11/10/2022.
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

    ~Base() {
        std::cout << "Base Destructor\n";
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

    ~Derived() {
        std::cout << "Derived Destructor\n";
    }
};

int main() {
//    Base b;
//    Base b{100};

//    Derived d;
    Derived d{100};
    return 0;
}
