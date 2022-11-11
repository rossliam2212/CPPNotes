//
// Created by Liam Ross on 10/10/2022.
//

#include "Account.h"

Account::Account() { }

Account::~Account() { }

void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}
