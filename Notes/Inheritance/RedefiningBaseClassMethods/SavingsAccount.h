//
// Created by Liam Ross on 12/10/2022.
//

#ifndef RANDOMPRACTICE_SAVINGSACCOUNT_H
#define RANDOMPRACTICE_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
    friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& savingsAccount);

protected:
    double interestRate;

public:
    SavingsAccount();
    SavingsAccount(double balance, double interestRate);
    void deposit(double amount);

    // void withdraw(double amount) is inherited
};


#endif //RANDOMPRACTICE_SAVINGSACCOUNT_H
