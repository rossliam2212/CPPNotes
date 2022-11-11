//
// Created by Liam Ross on 30/10/2022.
//

#include <iostream>

class Base {
public:
    virtual void sayHello() const {
        std::cout << "Hello I am a Base class object\n";
    }

    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void sayHello() const override {
        std::cout << "Hello I am a Derived class object\n";
    }

    ~Derived() override = default;
};

int main() {
    Base* p1 = new Base();
    Base* p2 = new Derived();

    p1->sayHello();
    p2->sayHello();

    delete p1;
    delete p2;

    return 0;
}