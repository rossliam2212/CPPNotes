//
// Created by Liam Ross on 21/07/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional> // for std::function

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string name;
    int age;

public:
    Person(std::string& name, int age) : name{name}, age{age} { }
    Person(std::string&& name, int age) : name{name}, age{age} { }
    Person(const Person& p) = default; // Copy constructor
    ~Person() = default;

    std::string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }

    void setName(std::string& name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "[Person: " << person.name << " : " << person.age << "]";
    return os;
}

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void filterVector(const std::vector<int>& vec, const std::function<bool(int)>& func);
auto makeLambda();

int main() {
    // Stateless Lambda Expressions
    // [] - Empty capture lists
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}


void test1() {
    std::cout << "\n========== Test 1 ==========" << std::endl;

    []() { std::cout << "Hi" << std::endl; }();
    [](int x) { std::cout << x << std::endl; }(10);
    [](int x, int y) { std::cout << x + y << std::endl; }(10, 20);
}


// Using values and references as lambda parameters
void test2() {
    std::cout << "\n========== Test 2 ==========" << std::endl;

    auto l1 = []() { std::cout << "Hi" << std::endl; };
    l1();

    int num1{100};
    int num2{200};

    auto l2 = [](int x, int y) { std::cout << x+y << std::endl; };
    l2(100, 300);
    l2(num1, num2);

    auto l3 = [](int& x, int y) {
        std::cout << "x: " << x << ", y: " << y << std::endl;
        x = 1000;
        y = 2000;
    };

    l3(num1, num2);
    std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;
}


// Using value and reference objects as lambda parameters
void test3() {
    std::cout << "\n========== Test 3 ==========" << std::endl;

    Person stooge{"Larry", 18};
    std::cout << stooge << std::endl;

    // Passed by Value -> Copy Constructor called
    auto l4 = [](Person p) {
        std::cout << p << std::endl;
    };
    l4(stooge);

    auto l5 = [](const Person& p) {
        std::cout << p << std::endl;
    };
    l5(stooge);

    auto l6 = [](Person& p) {
        std::string name{"Liam"};
        p.setName(name);
        p.setAge(20);
        std::cout << p << std::endl;
    };
    l6(stooge);

    std::cout << stooge << std::endl;
}

// Used for test4
// using std::function as a parameter in C++ 14 or greater
// or
// auto as parameter type in C++20
//void filterVector(const std::vector<int>& vec, auto func);
void filterVector(const std::vector<int>& vec, const std::function<bool(int)>& func) {
    std::cout << "[ ";
    for (int i : vec) {
        if (func(i))
            std::cout << i << " ";
    }
    std::cout << "]\n";
}

// Passing a lambda to a function
void test4() {
    std::cout << "\n========== Test 4 ==========" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    filterVector(nums, [](int x) { return x > 50; });
    filterVector(nums, [](int x) { return x <= 30; });
    filterVector(nums, [](int x) { return x >= 30 && x <= 60; });
}

// Used for test5
auto makeLambda() {
    return []() { std::cout << "This lambda was made using the makeLambda function!\n"; };
}

// Returning a lambda from a function
void test5() {
    std::cout << "\n========== Test 5 ==========" << std::endl;

    auto l5 = makeLambda();
    l5();
}

// Using auto in the lambda parameter list
void test6() {
    std::cout << "\n========== Test 6 ==========" << std::endl;

    auto l6 = [](auto x, auto y) {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    };

    l6(10, 20);
    l6(100.4, 200);
    l6(12.5, 15.54);

    l6(Person{"Liam", 20}, Person{"Erin", 20});
}

// Simple lambda examples with std::sort and std::for_each
void test7() {
    std::cout << "\n========== Test 7 ==========" << std::endl;

    std::vector<Person> stooges{
            {"Larry", 18},
            {"Moe",   30},
            {"Curly", 25}
    };

    std::sort(std::begin(stooges), std::end(stooges), [](const Person &p1, const Person &p2) {
        return p1.getName() < p2.getName();
    });
    std::for_each(stooges.begin(), stooges.end(), [](const Person& p) {
        std::cout << p << "\n";
    });


    std::cout << "\n";


    std::sort(std::begin(stooges), std::end(stooges), [](const Person &p1, const Person &p2) {
        return p1.getAge() < p2.getAge();
    });
    std::for_each(stooges.begin(), stooges.end(), [](const Person& p) {
        std::cout << p << "\n";
    });
}

