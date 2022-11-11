//
// Created by Liam Ross on 12/10/2022.
//

#ifndef RANDOMPRACTICE_ACCOUNT_H
#define RANDOMPRACTICE_ACCOUNT_H

#include <iostream>

class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);

protected:
    double balance;

public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //RANDOMPRACTICE_ACCOUNT_H
