//
// Created by Liam Ross on 10/10/2022.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() { }

SavingsAccount::~SavingsAccount() { }

void SavingsAccount::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void SavingsAccount::withdraw(double amount) {
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}
