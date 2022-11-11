//
// Created by Liam Ross on 07/07/2022.
//

#include <iostream>
#include <algorithm>
#include <list>
#include <forward_list>
#include <iterator> // For std::advance
#include <vector>
#include <string>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
private:
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

// Template function for displaying a list of any type
template<typename T>
void display(const std::string&& name, const std::list<T>& list) {
    auto it = std::find(list.begin(), list.end(), list.front());

    std::cout << name << ": [ ";
    while(it != std::end(list)) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "]\n";
}

int main() {
    // /**===================================**/
    // ===== std::list & std::forward_list =====
    // /**===================================**/

    // - Sequence Containers
    // - Non-contiguous in memory
    // - No direct access to elements
    // - Very efficient for inserting and deleting elements once an element is found


    // /**================**/
    // ===== std::list =====
    // /**===============**/

    // - Dynamic size
    //   - List of elements
    //   - list is bidirectional (doubly-linked)

    // - Direct element access is NOT provided
    // - Rapid insertion and deletion of elements anywhere in the container (constant time)
    // - All iterators available and invalidate when corresponding element is deleted


    // /**=========================================**/
    // === std::list - Initialization & Assignment ===
    // /**=========================================**/

    std::list<int> list {1, 2, 3};
    std::list<int> list1 (10, 100); // Ten elements all set to 100

    std::list<std::string> stooges {
        std::string{"Larry"},
        "Moe",
        std::string{"Curly"}
    };

    list = {2, 4, 6, 8, 10}; // Assignment


    // /**============================**/
    // === std::list - Common Methods ===
    // /**============================**/

    // No direct access to elements so the:
    // subscript operator ([]) & the .at() method are not available
    std::cout << list.size() << std::endl;
    std::cout << list.max_size() << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;

    stooges.push_back("Liam"); // Adds "Liam" to the back of the list
    stooges.pop_back(); // Removes "Liam" from the back of the list

    stooges.push_front("Liam"); // Adds "Liam" to the front of the list
    stooges.pop_front(); // Removes "Liam" from the front of the list

    stooges.emplace_back("Liam"); // Adds "Liam" to the back of the list - More efficient
    stooges.emplace_front("Liam"); // Adds "Liam" to the front of the list - More efficient


    std::cout << "\n";


    // /**========================================**/
    // === std::list - Methods that use iterators ===
    // /**========================================**/
    std::list<int> list2 {1, 2, 3, 4, 5};
    auto it = std::find(list2.begin(), list2.end(), 3); // iterator referencing 3 from the list

    list2.insert(it, 10);  // 1, 2, 10, 3, 4, 5
    list2.erase(it);         // erases the 3 -> 1, 2, 10, 4, 5 (Iterator "it" becomes invalid now)
    list2.resize(2);        // 1, 2
    list2.resize(5);       // 1, 2, 0, 0, 0

    // === Traversing a list ===
    list2 = {1, 2, 3, 4, 5};
    auto it1 = std::find(list2.begin(), list2.end(), 3);

    std::cout << *it1 << std::endl; // 3
    it1++;
    std::cout << *it1 << std::endl; // 4
    it1--;
    std::cout << *it1 << std::endl; // 3

    std::cout << "\n";



    // /**=======================**/
    // ===== std::forward_list =====
    // /**=======================**/

    // - Dynamic size
    //   - Lists of elements
    //   - list uni-directional (singly-linked)
    //   - Less overhead than a std::list

    // - Direct element access is NOT provided
    // - Rapid insertion and deletion of elements anywhere in the container (constant time)
    // - Reverse iterators not available. Iterators invalidate when corresponding element is deleted


    // /**====================================**/
    // === std::forward_list - Common Methods ===
    // /**====================================**/
    std::forward_list<int> forwardList {1, 2, 3, 4, 5};
    std::forward_list<std::string> stooges1 {
        std::string{"Larry"},
        "Moe",
        std::string{"Curly"}
    };

    std::cout << forwardList.max_size() << std::endl;
    std::cout << forwardList.front() << std::endl;
//    std::cout << forwardList.size << std::endl; // NOT AVAILABLE
//    std::cout << forwardList.back() << std::endl; // NOT AVAILABLE

    stooges1.push_front("Liam"); // Adds "Liam" to the front of the list
    stooges1.pop_front(); // Removes "Liam" from, the front of the list

    stooges1.emplace_front("Liam"); // Adds "Liam" to the front of the list - More efficient


    // /**================================================**/
    // === std::forward_list - Methods that use iterators ===
    // /**================================================**/
    std::forward_list<int> forwardList1 {1, 2, 3, 4, 5};
    auto it3 = std::find(forwardList1.begin(), forwardList1.end(), 3);

    forwardList1.insert_after(it3, 10); // 1, 2, 3, 10, 4, 5
    forwardList1.emplace_after(it3, 100); // 1, 2, 3, 100, 10, 4, 5

    forwardList1.erase_after(it3); // erases the 100, 1, 2, 3, 10, 4, 5

    forwardList1.resize(2); // 1, 2
    forwardList1.resize(5); // 1, 2, 0, 0, 0



    // /**========================**/
    // ==== Examples - std::list ====
    // /**========================**/
    std::cout << "\n=== Examples ===\n";

    std::list<int> l1 (10, 100);
    display("l1", l1);

    std::list<std::string> l2;
    l2.emplace_back("Back");
    l2.emplace_front("Front");
    display("l2", l2);

    std::cout << "\n";


    std::list<int> l3 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display("l3", l3);
    std::cout << "Size: " << l3.size() << std::endl;
    std::cout << "Front: " << l3.front() << std::endl;
    std::cout << "Back: " << l3.back() << std::endl;

    l3.clear();
    display("l3", l3);
    std::cout << "Size: " << l3.size() << std::endl;

    std::cout << "\n";


    std::list<int> l4 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display("l4", l4);

    l4.resize(5);
    display("l4", l4);

    l4.resize(10); // Will fill the list with zeros -> 1 2 3 4 5 0 0 0 0 0
    display("l4", l4);

    std::list<Person> persons;
    persons.resize(10); // Uses Default Person Constructor
    display("persons", persons);

    std::cout << "\n";


    // === Inserting Elements ===
    std::list<int> l5 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display("l5", l5);

    auto iter = std::find(std::begin(l5), std::end(l5), 5);
    if (iter != std::end(l5))
        l5.insert(iter, 100); // Inserts the 100 before the iterator -> Before the 5
    display("l5", l5);

    std::list<int> l6 {1000, 2000, 3000};
    l5.insert(iter, l6.begin(), l6.end());
    display("l6", l6);
    display("l5", l5);

    std::advance(iter, -4); // Was pointing at the 5 but now points to the 100
    std::cout << *iter << std::endl;

    l5.erase(iter); // Removes the 100 - The iterator becomes invalid
    display("l5", l5);

    std::cout << "\n";



    std::list<Person> stooges2 {
            {"Larry", 18},
            {"Moe", 20},
            {"Curly", 19}
    };
    display("stooges2", stooges2);

    std::string name;
    int age;
    std::cout << "Enter the name of the next stooge:\n>";
    getline(std::cin, name);
    std::cout << "Enter their age:\n>";
    std::cin >> age;

    stooges2.emplace_back(name, age); // .emplace_back() creates the object for us
    display("stooges2", stooges2);

    // Inserting Frank before Moe - Overloaded equality operator (==) is used here
    auto iter1 = std::find(stooges2.begin(), stooges2.end(), Person{"Moe", 20});
    if (iter1 != std::end(stooges2))
        stooges2.emplace(iter1, "Frank", 18);
    display("stooges2", stooges2);

    std::cout << "\n";

    // Sorting
    std::list<Person> friends {
            {"Liam", 20},
            {"Brian", 21},
            {"James", 20},
            {"Richard", 19},
            {"Mark", 21}
    };
    display("friends", friends);

    friends.sort(); // Uses the overloaded less than operator (<) and compares the ages
    display("friends", friends);
    return 0;
}
