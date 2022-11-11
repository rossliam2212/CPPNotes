//
// Created by Liam Ross on 10/10/2022.
//

#ifndef RANDOMPRACTICE_SAVINGSACCOUNT_H
#define RANDOMPRACTICE_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount();
    ~SavingsAccount();
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //RANDOMPRACTICE_SAVINGSACCOUNT_H
