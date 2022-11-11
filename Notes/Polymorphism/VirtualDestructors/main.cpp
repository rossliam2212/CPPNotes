//
// Created by Liam Ross on 29/10/2022.
//

#include <iostream>

class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw\n";
    }

    virtual ~Account() {
        std::cout << "Account:: destructor\n";
    }
};

class Savings : public Account {
    void withdraw(double amount) override {
        std::cout << "In Savings::withdraw\n";
    }

    ~Savings() override {
        std::cout << "Savings:: destructor\n";
    }
};


int main() {
    Account* p1 = new Account();
    Account* p2 = new Savings();

    p1->withdraw(1000);
    p2->withdraw(1000);

    std::cout << "\n==== Clean Up ====\n";
    delete p1;
    delete p2;
    return 0;
}