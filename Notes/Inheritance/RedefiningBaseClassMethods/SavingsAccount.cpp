//
// Created by Liam Ross on 12/10/2022.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
    : SavingsAccount(0.0, 0.0 ) { }

SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account{balance},
      interestRate{interestRate} { }

void SavingsAccount::deposit(double amount) {
    amount += (amount * interestRate / 100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &savingsAccount) {
    os << "Savings Account Balance: " << savingsAccount.balance
       << "\nSavings Account Interest Rate: " << savingsAccount.interestRate;
    return os;
}
