//
// Created by Liam Ross on 07/07/2022.
//

#include <iostream>
#include <string>
#include <cctype>
#include <deque>

bool isPalindrome(const std::string& str);

int main() {
    // /**=============**/
    // === Challenge 1 ===
    // /**=============**/

    // Palindrome Checker using a Deque
    std::cout << "/**==============================**/" << std::endl;
    std::cout << "===== Challenge 1 - Palindrome =====" << std::endl;
    std::cout << "/**==============================**/" << std::endl;

    std::cout << std::boolalpha << isPalindrome(std::string{"racecar"}) << std::endl;
    return 0;
}


bool isPalindrome(const std::string& str) {
    std::deque<char> d;
    for (const auto& c : str) {
        // only adding string characters that are alpha to the deque
        if (std::isalpha(c))
            d.push_back(std::toupper(c));
    }
    char c1, c2;
    while (d.size() > 1) {
        c1 = d.front();
        c2 = d.back();

        if (c1 == c2) {
            d.pop_front();
            d.pop_back();
        } else
            return false;
    }
    return true;
}


