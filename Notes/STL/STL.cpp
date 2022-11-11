//
// Created by Liam Ross on 05/07/2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>


struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    bool operator==(const Vector2& rhs) const { return x == rhs.x && y == rhs.y; }

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector2) {
        os << "x: " << vector2.x << ", y: " << vector2.y;
        return os;
    }
};

struct Square_Functor {
    void operator()(int x) {
        std::cout << x * x << " ";
    }
};

void square(int x) {
    std::cout << x * x << " ";
}


int main() {

    // **NOTE**
    // When using the STL with custom classes, it is so important to have a default constructor,
    // overloaded == operator and overloaded < operator

    // /**===============**/
    // ===== std::find =====
    // /**===============**/

    int numToCheckFor{5};
    std::vector<int> myNumbers {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto check = std::find(myNumbers.begin(), myNumbers.end(), numToCheckFor);

    if (check != myNumbers.end())
        std::cout << numToCheckFor << " was found!!" << std::endl;
    else
        std::cout << numToCheckFor << " was not found!!" << std::endl;


    // *NOTE*
    // std::find can also be used with custom classes but an overloaded equality operator
    // is needed so std::find can compare.

    std::vector<Vector2> vectors {
        Vector2{2, 2},
        Vector2{10, 5},
        Vector2{1, 9}
    };
    Vector2 vecToFind{10, 5};

    // Could also be written like this:
    auto check1 = std::find(std::begin(vectors), std::end(vectors), vecToFind);
//    auto check1 = std::find(vectors.begin(), vectors.end(), vecToFind);

    if (check1 != std::end(vectors))
        std::cout << *check1 << " was found!!\n" << std::endl;
    else
        std::cout << vecToFind << " was not found!\n" << std::endl;



    // /**===================**/
    // ===== std::for_each =====
    // /**===================**/

    // std::for_each applies a function to each element in the iterator sequence.
    // Functions must be provided to the algorithm as either a:
    // - Functor (function object)
    // - Function pointer
    // - Lambda expression (C++ 11)

    // Using a Functor:
    Square_Functor squareFunctor;
    std::vector<int> vec {1, 2, 3, 4};
    std::for_each(vec.begin(), vec.end(), squareFunctor);

    std::cout << '\n';

    // Using a Function Pointer:
    std::vector<int> vec1 {1, 2, 3, 4};
    std::for_each(vec1.begin(), vec1.end(), square);

    std::cout << '\n';

    // Using a Lambda:
    std::vector<int> vec2 {1, 2, 3, 4};
    std::for_each(vec2.begin(), vec2.end(),
                  [](int x) { std::cout << x * x << " ";});

    std::cout << "\n";


    // /**================**/
    // ===== std::count =====
    // /**================**/

    // std::cout counts the number of elements in a container.
    std::vector<int> numbers {0, 0, 0, 1, 2, 4, 4, 5, 1, 0, 7, 9, 9, 4, 3, 3};
    int numToFind = 0;
    std::size_t num = std::count(numbers.begin(), numbers.end(), numToFind);
    std::cout << "\n" << numToFind << " was found " << num << " times!" << std::endl;


    // /**===================**/
    // ===== std::count_if =====
    // /**===================**/

    // std::count_if counts the number of occurrences in a container based on a predicate
    // using a lambda expression.
    std::vector<int> vec3 {1, 2, 3, 4, 5, 1, 2, 1, 100};

    // Count only if the element is even
    auto even = std::count_if(std::begin(vec3), std::end(vec3),
                              [](int x){ return x % 2 == 0; });
    std::cout << "\n" << even << " even numbers found." << std::endl;

    // Count only if the element is odd
    auto odd = std::count_if(std::begin(vec3), std::end(vec3),
                              [](int x){ return x % 2 != 0; });
    std::cout << odd << " odd numbers found." << std::endl;

    auto greaterThanFive = std::count_if(vec3.begin(), vec3.end(),
                                         [](int x){ return x > 5; });
    std::cout << greaterThanFive << " numbers greater than 5." << std::endl;


    std::cout << '\n';

    // /**==================**/
    // ===== std::replace =====
    // /**==================**/
    // std::replace, replaces occurrences of elements in a container.
    std::vector<int> vec4 {1, 2, 3, 4, 5, 1, 2, 1};
    for (const auto& i : vec4)
        std::cout << i << " ";

    std::cout << '\n';

    // Replaces all 1's with 100
    std::replace(vec4.begin(), vec4.end(), 1, 100);

    for (const auto& i : vec4)
        std::cout << i << " ";

    std::cout << "\n\n";


    // /**=================**/
    // ===== std::all_of =====
    // /**=================**/

    // std::all_of checks if all elements in a container match a certain predicate.
    std::vector<int> vec5 {1, 3, 5, 7, 9, 1, 3, 13, 19, 5};

    // Checking if all elements in the vector are greater than 10
    if (std::all_of(vec5.begin(), vec5.end(), [](int x) { return x > 10; }))
        std::cout << "All elements are > 10." << std::endl;
    else
        std::cout << "Not all elements are > 10." << std::endl;

    // Checking if all elements in the vector are less than 20
    if (std::all_of(vec5.begin(), vec5.end(), [](int x) { return x < 20; }))
        std::cout << "All elements are < 20." << std::endl;
    else
        std::cout << "Not all elements are < 20." << std::endl;


    // /**====================**/
    // ===== std::transform =====
    // /**====================**/

    // std::transform , transforms elements in a container - strings in this example.
    std::string str {"Hello There"};
    std::cout << "\nBefore transform: " << str << std::endl;

    std::transform(str.begin(), str.end(), str.begin(), ::toupper); // Can pass custom function in here too.

    std::cout << "After transform: " << str << std::endl;

    return 0;
}

