//
// Created by Liam Ross on 10/10/2022.
//

#include <iostream>

class Base {
    // Note - friends of Base access to all
public:
    int a{};
    void display() { std::cout << a << ", " << b << ", " << c << std::endl; }

protected:
    int b{};

private:
    int c{};
};

class Derived : public Base {
    // Note - friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will not be accessible

public:
    void accessBaseMembers() {
        a = 100; // Works
        b = 200; // Works
//        c = 300; // Not Accessible
    }
};

int main() {
    Base base;
    base.a = 100; // Works
//    base.b = 200; // Compiler Error - protected
//    base.c = 300; // Compiler Error - private


    Derived derived;
    derived.a = 100; // Works
//    derived.b = 200; // Compiler Error - protected
//    derived.c = 300; // Compiler Error - private

    return 0;
}
