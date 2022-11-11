//
// Created by Liam Ross on 15/07/2022.
//

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <iomanip>
#include <vector>

bool isPalindrome(const std::string& str);

int main() {
    // /**===============================================**/
    // ===== Challenge 4 - Palindrome w/ Stack & Queue =====
    // /**===============================================**/

    std::vector<std::string> tests {
        "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", "avid diva", "Amore Roma",
        "A Toyota's a Toyota", "A Santa at NASA", "C++", "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "This is a Palindrome", "palindrome"
    };

    std::cout << std::boolalpha;
    std::cout << std::setw(66) << std::left << "Result" << "String" << std::endl;
    std::cout << std::setfill('-') << std::setw(72) << "" << std::setfill(' ') << std::endl;

    for (const auto& s : tests)
        std::cout << std::setw(66) << std::left << s << isPalindrome(s) << "\n";
    return 0;
}

bool isPalindrome(const std::string& str) {
    std::queue<char> q;
    std::stack<char> s;

    for (const auto& c : str) {
        if (std::isalpha(c)) {
            q.push(std::toupper(c));
            s.push(std::toupper(c));
        }
    }

    while (!q.empty()) {
        if (q.front() == s.top()) {
            q.pop();
            s.pop();
        } else
            return false;
    }
    return true;
}

