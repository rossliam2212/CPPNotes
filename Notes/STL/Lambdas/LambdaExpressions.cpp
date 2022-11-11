//
// Created by Liam Ross on 05/07/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <functional>

std::function<void(int)> foo();
void (*foo1()) (int);
auto foo2();

void printIf(std::vector<int> nums, bool (*predicate)(int));

int main() {

    // /**========================**/
    // ===== Lambda Expressions =====
    // /**========================**/

    // === Structure of a Lambda Expression ===
    // [] () -> return_type specifiers { };

    // []           : Capture List - Defines the start of the lambda
    // ()           : Parameter List - Comma separated list of parameters
    // return_type  : Return type - Can be omitted and the compiler will try to deduce it
    // specifiers   : Optional specifiers - mutable and constexpr
    // { };         : Body - Where your write your code


    // Simple Lambda Expression:
    // []() { std::cout << "Hi\n"; };

    // To run this Lambda, add () to the end to instantiate a function object from the lambda
    // and call the function object. (Not typically used this way)
    []() { std::cout << "Hi\n"; }();



    // === Assigning a Lambda Expression to a variable ===
    auto l = []() { std::cout << "Hi :)\n"; };
    l();

    auto l1 = [](int x) { std::cout << x << "\n"; };
    l1(10);
    l1(100);

    std::cout << "\n";



    // === Returning a value from a Lambda Expression ===
    auto lreturn1 = [](int x, int y) -> int { return x + y; };
    // or
    auto lreturn2 = [](int x, int y) { return x + y; };

    // The "-> int" is often left out because the compiler can deduce the return type

    std::cout << lreturn1(2, 3) << std::endl;
    std::cout << lreturn2(20, 10) << std::endl;

    std::cout << "\n";


    // /**==================================**/
    // ===== Stateless Lambda Expressions =====
    // /**==================================**/

    // A stateless lambda expression is when the expression has an empty capture list.

    // An empty capture list means that the lambda doesn't capture an information from
    // its environment.

    []() { std::cout << "Hi\n"; }; // Displays Hi

    int x{10};
    [](int x) { std::cout << x << "\n";};(100); // Displays 100 - the lambda knows nothing about the int x defined above


    // Example:
    const int n{3};
    int nums[n] {10, 20, 30};

    auto sum = [](const int nums[], int n) {
        int sum{};
        for (auto i = 0; i < n; ++i)
            sum += nums[i];
        return sum;
    };

    std::cout << sum(nums, 3) << std::endl; // Displays 60
    std::cout << "\n";



    // === Using values and references as lambda parameters ===
    int testScore1{88};
    int testScore2{75};

    auto bonus = [](int& score1, int& score2, int bonusPoints) {
        score1 += bonusPoints;
        score2 += bonusPoints;
    };
    bonus(testScore1, testScore2, 5);
    std::cout << "testScore1: " << testScore1 << std::endl; // 93
    std::cout << "testScore2: " << testScore2 << std::endl; // 80

    std::cout << "\n";



    // === Using pointers as lambda parameters ===
    int k{100};
    auto lp = [](const int* ptr) {
        std::cout << "Address: " << ptr << std::endl;
        std::cout << "Value: " << *ptr << std::endl;
    };
    lp(&k);



    int testScore3{88};
    int testScore4{75};
    auto bonus1 = [](int* score1, int* score2, int bonusPoints) {
        *score1 += bonusPoints;
        *score2 += bonusPoints;
    };
    bonus1(&testScore3, &testScore4, 5);
    std::cout << "\ntestScore3: " << testScore1 << std::endl; // 93
    std::cout << "testScore4: " << testScore2 << std::endl; // 80

    std::cout << "\n";



    // === Using arrays and vectors as lambda parameters ===
    std::vector<int> testScores5 {93, 88, 75, 68, 65};
    auto bonus5 = [](std::vector<int>& testScores, int bonusPoints) {
        for (auto& score : testScores)
            score += bonusPoints;
    };
    bonus5(testScores5, 5);
    for (auto i = 0; i < testScores5.size(); i++)
        std::cout << "testScores5[" << i << "]: " << testScores5[i] << "\n";

    std::cout << "\n";



    // === Using auto as lambda parameter type specifiers ===
    int num1{10};
    float num2{5.5f};

    auto autoLambda = [](auto num) { std::cout << num << std::endl; };
    autoLambda(num1);
    autoLambda(num2);

    std::cout << "\n";


    std::vector<int> myTestScores {93, 88, 75, 68, 65};
    std::vector<float> myTestScores1 {88.5f, 85.5f, 75.5f, 68.5f, 65.5f};

    auto myBonus = [](auto& scores, int bonusPoints) {
        for (auto& score : scores) {
            score += bonusPoints;
            std::cout << score << " ";
        }
        std::cout << "\n";
    };
    myBonus(myTestScores, 5);
    myBonus(myTestScores1, 5);

    std::cout << "\n";


    auto ll = foo();
    ll(10);


    std::cout << "\n";


    // === Predicate Lambda ===
    std::vector<int> myNums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printIf(myNums, [](auto x) { return x % 2 == 0; });
    printIf(myNums, [](auto x) { return x % 2 != 0; });

    return 0;
}


// === Using lambda expressions as function parameters ===
// #include <functional> for std::function

void foo(std::function<void(int)> lambda) {  // C++14
    lambda(10);
}

void foo(void (*lambda) (int)) {  // C++14
    lambda(10);
}

void foo(auto lambda) {  // C++20
    lambda(10);
}


// === Returning lambda expressions from functions ===
std::function<void(int)> foo() {
    return [](int x) { std::cout << x << std::endl; };
}

void (*foo1()) (int) {
    return [](int x) { std::cout << x << std::endl; };
}

auto foo2() {
    return [](int x) { std::cout << x << std::endl; };
}


// === Predicate Lambda ===
void printIf(std::vector<int> nums, bool (*predicate)(int)) {
    for (int i : nums)
        if (predicate(i))
            std::cout << i << " ";
}


