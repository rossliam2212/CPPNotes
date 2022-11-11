//
// Created by Liam Ross on 10/10/2022.
//

#ifndef RANDOMPRACTICE_ACCOUNT_H
#define RANDOMPRACTICE_ACCOUNT_H

#include <iostream>

class Account {
public:
    Account();
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //RANDOMPRACTICE_ACCOUNT_H
