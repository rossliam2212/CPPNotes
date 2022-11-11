//
// Created by Liam Ross on 04/08/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string& name, int age) : name{name}, age{age} { }
    Person(std::string&& name, int age) : name{name}, age{age} { }
    Person(const Person& person) = default;
    ~Person() = default;

    std::string getName() { return this->name; }
    void setName(std::string name) { this->name = name; }

    int getAge() { return this->age; }
    void setAge(int age) { this->age = age; }

    auto changePerson1() { return [this](std::string& newName, int newAge) { name = newName; age = newAge; };}
    auto changePerson2() { return [=](std::string& newName, int newAge) { name = newName; age = newAge; };}
    auto changePerson3() { return [&](std::string& newName, int newAge) { name = newName; age = newAge; };}
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
void test8();
void test9();
void test10();

int globalX{1000};

int main() {

    // /**=================================**/
    // ===== Stateful Lambda Expressions =====
    // /**=================================**/

    // Syntax:
    // [captured_variables] () -> return_type specifiers { };

    // Non-empty capture list => defines what info/variables should be captured


    int x{100};
    [x]() { std::cout << "x: " << x << std::endl; }(); // 100

    std::cout << "\n";


    // Using mutable to modify variables captured by value
    // mutable:
    // tells the compiler to generate the lambda's operator function as a non-const member function
    int y{200};
    [y]() mutable {
        y += 100;
        std::cout << "y: " << y << std::endl; // 300
    }();

    std::cout << "y: " << y << std::endl; // 200


    std::cout << "\n";


    // Capture by reference
    int z{50};
    [&z]() { z += 50; }();
    std::cout << "z: " << z << std::endl; // 100

    std::cout << "\n";


    // --- Capturing by value and reference ---
    // [x, y]   - Capture both x and y by value
    // [x, &y]  - Capture x by value and y by reference
    // [&x, y]  - Capture x by reference and y by value
    // [&x, &y] - Capture both x and y by reference


    // --- Default Captures ---
    // [=]      - Default capture by value
    // [&]      - Default capture by reference
    // [this]   - Default capture this object by reference


    // --- Default and Explicit Captures ---
    // [=, &x]   - Default capture by value but capture x by reference
    // [&, y]    - Default capture by reference by capture y by value
    // [this, z] - Default capture this by capture z by value


    // --- Examples ---
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
 }

 // Capture by value
 // The global variable globalX cannot be captured because it is not
 // within the reaching scope of the lambda. However, it can still be
 // accessed from within the lambda using normal name lookup rules.
 void test1() {
    std::cout << "\n========== Test 1 ==========" << std::endl;

    int localX{100};

    auto l = [localX]() {
        std::cout << localX << std::endl;
        std::cout << globalX << std::endl;
    };

    l();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains
// to the captured variable within the lambda body and not the actual
// variable.
void test2() {
    std::cout << "\n========== Test 2 ==========" << std::endl;

    int x{100};

    auto l = [x]() mutable {
        x += 100;
        std::cout << "x: " << x << std::endl;
    };

    l();
    std::cout << "x: " << x << std::endl;

    l();
    std::cout << "x: " << x << std::endl;
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual variable.
void test3() {
    std::cout << "\n========== Test 3 ==========" << std::endl;

    int x{100};

    auto l = [&x]() mutable {
        x += 100;
        std::cout << "x: " << x << std::endl;
    };

    l();
    std::cout << "x: " << x << std::endl;
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value.
// The variable z is not captured by the lambda.
void test4() {
    std::cout << "\n========== Test 4 ==========" << std::endl;

    int x{100};
    int y{200};
    int z{300}; // Note that z is not captured in the lambda since it is not used.
                // This should produce an "unused variable" warning when compiling.

    auto l = [=]() mutable {
        x += 100;
        y += 100;
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    };

    l();

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

}

// Default capture by reference
// This time, because all three variables - x,y,z are used within the lambda
// body, all three of them will be captured by reference.
void test5() {
    std::cout << "\n========== Test 5 ==========" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&]() {
        x += 100;
        y += 100;
        z += 100;

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    l();

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;
}

// Default capture by value, capture y by reference
void test6() {
    std::cout << "\n========== Test 6 ==========" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [=, &y]() mutable{
        x += 100;
        y += 100;
        z += 100;

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    l();

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << z << std::endl;
    std::cout << "z: " << z << std::endl;
}

// Default capture by reference, capture x and z by value.
// Equivalent to test6
void test7() {
    std::cout << "\n========== Test 7 ==========" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&, x, z]() mutable {
        x += 100;
        y += 100;
        z += 100;

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };
    l();

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;
}

void test8() {
    std::cout << "\n========== Test 8 ==========" << std::endl;
}
void test9() {
    std::cout << "\n========== Test 9 ==========" << std::endl;
}
void test10() {
    std::cout << "\n========== Test 10 ==========" << std::endl;
}
