//
// Created by Liam Ross on 12/10/2022.
//

#include <iostream>
#include "SavingsAccount.h"

int main() {
    std::cout << "========== Account Class ==========\n";

    Account a1{1000.0};
    std::cout << a1 << "\n";    // Account Balance: 1000

    a1.deposit(500.0);
    std::cout << a1 << "\n";    // Account Balance: 1500

    a1.withdraw(1000.0);
    std::cout << a1 << "\n";    // Account Balance: 500

    a1.withdraw(5000.0); // Insufficient Funds
    std::cout << a1 << "\n";    // Account Balance: 500



    std::cout << "\n========== Savings Account Class ==========\n";

    SavingsAccount s1{1000.0, 5.0};
    std::cout << s1 << "\n";

    s1.deposit(1000.0);
    std::cout << s1 << "\n";

    s1.withdraw(2000.0);
    std::cout << s1 << "\n";

    s1.withdraw(1000.0);
    std::cout << s1 << "\n";


    return 0;
}
