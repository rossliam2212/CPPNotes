//
// Created by Liam Ross on 11/07/2022.
//

#include <iostream>
#include <string>
#include <algorithm>

#include <set>
#include <unordered_set>

class Person {
private:
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string& name, int age) : name{name}, age{age} {}
    Person(std::string&& name, int age) : name{name}, age{age} {}


    bool operator<(const Person& rhs) const {
        return age < rhs.age;
    }
    bool operator==(const Person& rhs) const {
        return name == rhs.name && age == rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << ":" << person.age;
    return os;
}

template<typename T>
void display(const std::string&& name, const std::set<T>& s) {
    std::cout << name << ": [ ";
    for (const auto& e : s)
        std::cout << e << " ";
    std::cout << "]\n";
}

int main() {
    // /**========================**/
    // ===== STL Set Containers =====
    // /**========================**/

    // Associative Containers
    // - Collection of stored objects that allow fast retrieval using a key
    // - STL provides Sets and Maps
    // - Usually implemented as a balanced binary tree or hashsets
    // - Most operations are very efficient

    // Sets
    // - std::set (Most often used)
    // - std::unordered_set
    // - std::multiset
    // - std::unordered_multiset



    // /**==============**/
    // ===== std::set =====
    // /**==============**/

    // #include <set>
    // - Similar to mathematical set
    // - Ordered by key
    // - No duplicate elements
    // - All iterators available and invalidate when corresponding element is deleted


    // /**============================================**/
    // ===== std::set - Initialization & Assignment =====
    // /**============================================**/
    std::set<int> set1 {1, 2, 3, 4, 5};

    std::set<std::string> stooges {
        std::string{"Larry"},
        "Moe",
        std::string{"Curly"}
    };

    set1 = {2, 4, 6, 8, 10};


    // /**===============================**/
    // ===== std::set - Common Methods =====
    // /**===============================**/

    // No duplicates elements are allowed in a set - The duplicates are ignored
    std::set<int> set2 {4, 1, 1, 3, 3, 2, 5}; // 1, 2, 3, 4, 5

    std::cout << set2.size() << std::endl; // 5
    std::cout << set2.max_size() << std::endl; // Very large number

    set2.insert(7); // 1, 2, 3, 4, 5, 7

    // - There is no concept of front and back in sets

    // - The elements in the set will be ordered
    for (const auto& i : set2)
        std::cout << i << " ";

    std::cout << "\n";

    std::set<std::string> names {"Liam", "Brian", "James"};
    // operator< is used for ordering
    // returns a std::pair<iterator, bool>
    // - first is an iterator to the inserted element or to the duplicate in the set
    // - second is a boolean indicating success or failure
    auto result = names.insert("Mark");


    std::set<int> set3 {1, 2, 3, 4, 5};
    set3.erase(3); // erase the 3 -> 1, 2, 4, 5

    auto it = set3.find(4);
    if (it != set3.end())
        set3.erase(it); // erase the 4 -> 1, 2, 5

    auto count = set3.count(1); // 0 or 1 depending on if the element is in the set or not
    set3.clear(); // removes all the elements in the set
    set3.empty(); // True or False depending on if the set is empty or not

    std::cout << "\n";


    // /**===================**/
    // ===== std::multiset =====
    // /**===================**/

    // - #include <set>
    // - Sorted by key
    // - Allows duplicate elements
    // - All iterators are available


    // /**========================**/
    // ===== std::unordered_set =====
    // /**========================**/

    // - #include <unordered_set>
    // - Elements are unordered
    // - No duplicate elements allowed
    // - Elements cannot be modified
    //   - Must be erased and new element inserted
    // - No reverse iterators are allowed


    // /**=============================**/
    // ===== std::unordered_multiset =====
    // /**=============================**/

    // - Elements are unordered
    // - Allows duplicate elements
    // - No reverse iterators allowed


    // /**=======================**/
    // ===== std::set Examples =====
    // /**=======================**/
    std::set<int> s1 {1, 4, 3, 5, 2};
    display("s1", s1);

    s1 = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5}; // The duplicates will be omitted
    display("s1", s1);

    s1.insert(0);
    s1.insert(10);
    display("s1", s1);

    if (s1.count(10))
        std::cout << "10 is in the set!" << std::endl;
    else
        std::cout << "10 is not in the set!" << std::endl;

    auto iter = s1.find(5);
    if (iter != s1.end())
        std::cout << "Found: " << *iter << std::endl;

    s1.clear();

    std::cout << '\n';



    std::set<Person> stooges1 {
            {"Larry", 18},
            {"Moe", 17},
            {"Curly", 19}
    };
    display("stooges1", stooges1);

    stooges1.emplace("Liam", 20);
    display("stooges1", stooges1);

    stooges1.emplace("Brian", 20); // Won't be added - 20 already exists in the set even though the names are different
    display("stooges1", stooges1);

    auto iter1 = stooges1.find(Person{"Liam", 20});
    if (iter1 != std::end(stooges1))
        stooges1.erase(iter1);
    display("stooges1", stooges1);

    iter1 = stooges1.find(Person{"XXXX", 19}); // Will remove Curly! -> using overloaded operator<
    if (iter1 != std::end(stooges1))
        stooges1.erase(iter1);
    display("stooges1", stooges1);

    std::cout << "\n";



    std::set<std::string> s2 {"A", "B", "C"};
    display("s2", s2);

    auto result1 = s2.insert("D"); // Returns a std::pair<iterator, bool>
    display("s2", s2);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result1.first) << std::endl;
    std::cout << "second: " << result1.second << std::endl; // If true, then the element was added successfully

    std::cout << "\n";

    result1 = s2.insert("A");
    display("s2", s2);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result1.first) << std::endl;
    std::cout << "second: " << result1.second << std::endl; // False because "A" is already in the set, Insertion was unsuccessful

    return 0;
}