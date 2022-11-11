//
// Created by Liam Ross on 10/10/2022.
//
#include "Account.h"
#include "SavingsAccount.h"

int main() {
    std::cout << "\n=== Account ===========================" << std::endl;
    Account acc{};
    acc.deposit(100);
    acc.withdraw(100);

    std::cout << std::endl;

    Account* pAcc{nullptr};
    pAcc = new Account();
    pAcc->deposit(100);
    pAcc->withdraw(200);
    delete pAcc;


    std::cout << "\n=== Savings Account ===========================" << std::endl;

    SavingsAccount acc1{};
    acc1.deposit(100);
    acc1.withdraw(100);

    std::cout << std::endl;

    SavingsAccount* pAcc1{nullptr};
    pAcc1 = new SavingsAccount();
    pAcc1->deposit(100);
    pAcc1->withdraw(200);
    delete pAcc1;

    return 0;
}
