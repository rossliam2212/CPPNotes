//
// Created by Liam Ross on 13/07/2022.
//

#include <iostream>
#include <string>
#include <algorithm>

#include <set>
#include <map>
#include <unordered_map>


void display(const std::string&& name, const std::map<std::string, std::set<int>>& m) {
    std::cout << name << ": [ ";
    for (const auto& i : m) {
        std::cout << i.first << ": [ ";
        for (const auto& j : i.second)
            std::cout << j << " ";
        std::cout << "] ";
    }
    std::cout << "]\n";
}

template<typename T1, typename T2>
void display(const std::string&& name, const std::map<T1, T2> m) {
    std::cout << name << ": [ ";
    for (const auto& i : m)
        std::cout << i.first << ":" << i.second << " ";
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

    // Maps
    // - std::map (Most often used)
    // - std::unordered_map
    // - std::multimap
    // - std::unordered_multimap


    // /**==============**/
    // ===== std::map =====
    // /**==============**/

    // - #include <map>
    // - Similar to a dictionary
    // - Elements stored as Key, Value pairs (std::pair)
    // - Ordered by key
    // - No duplicate elements (keys are unique)
    // - Direct element access using the key
    // - All iterators available and invalidate when corresponding element is deleted


    // /**============================================**/
    // ===== std::map - Initialization & Assignment =====
    // /**============================================**/
    std::map<std::string, int> map1 {
            {"Larry", 18},
            {"Moe", 20}
    };

    std::map<std::string, std::string> names {
            {"Liam", "Ross"},
            {"Brian", "Farrell"},
            {"James", "Murphy"}
    };


    // /**===============================**/
    // ===== std::map - Common Methods =====
    // /**===============================**/
    std::cout << names.size() << std::endl; // 3
    std::cout << names.max_size() << std::endl; // A very large number

    // - No concept of front and back

    std::pair<std::string, std::string> p1 {"Richard", "Laffan"};
    names.insert(p1);

    names.insert(std::make_pair("Mark", "Melia"));

    // Inserting & Updating
    names["Nialler"] = "Shannon"; // Inserting Key, Value pair "Nialler", "Shannon" if it doesn't already exist

    names["Nialler"] = "McGarry"; // Updating Key "Nialler" with Value "McGarry"

    names.at("Brian") = "Farrell Yip Yip"; // Updating

    names.erase("Nialler"); // Erase Key, Value pair whose key is "Nialler"

    if (names.find("Liam") != names.end())
        std::cout << "Found Liam!" << std::endl;

    auto it = names.find("Mark"); // Returns iterator to the map element if it is found
    if (it != std::end(names))
        names.erase(it); // Erase "Mark"

    auto count = names.find("James"); // Returns 0 or 1 depending on if the element is in the map or not

    names.clear(); // Removes all elements
    names.empty(); // True or False depending on if the map is empty of not

    std::cout << "\n";



    // /**===================**/
    // ===== std::multimap =====
    // /**===================**/

    // - #include <map>
    // - Ordered by key
    // - Allows duplicate elements
    // - All iterators are available



    // /**========================**/
    // ===== std::unordered_map =====
    // /**========================**/

    // - #include <unordered_map>
    // - Elements are unordered
    // - No duplicate elements allowed
    // - No reverse iterators are allowed



    // /**=============================**/
    // ===== std::unordered_multimap =====
    // /**=============================**/

    // - #include <unordered_map>
    // - Elements are unordered
    // - Allows duplicate elements
    // - No reverse iterators are allowed



    // /**=======================**/
    // ===== std::map Examples =====
    // /**=======================**/

    // std::string, int key value pairs
    // Key -> std::string
    // Value -> int
    std::map<std::string, int> m1 {
            {"Larry", 3},
            {"Moe", 1},
            {"Curly", 2}
    };
    display("m1", m1);

    m1.insert(std::pair<std::string, int>("Anna", 10));
    display("m1", m1);

    m1.insert(std::make_pair("Joe", 5));
    display("m1", m1);

    m1["Frank"] = 18;
    display("m1", m1);

    m1["Frank"] += 10; // Changing the value associated with the Key "Frank"
    display("m1", m1);

    m1.erase("Frank");
    display("m1", m1);

    std::cout << "Count for Joe: " << m1.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m1.count("Frank") << std::endl;

    auto iter = m1.find("Larry");
    if (iter != std::end(m1))
        std::cout << "Found: " << iter->first << " : " << iter->second << std::endl;

    m1.clear();
    display("m1", m1);

    std::cout << "\n";



    // Key -> std::string
    // Value -> std::set<int>
    std::map<std::string, std::set<int>> grades {
            {"Larry", {100, 90}},
            {"Moe", {94}},
            {"Curly", {80, 90, 100}}
    };
    display("grades", grades);

    grades["Larry"].insert(95); // Insert 95 into "Larry"'s set of grades
    display("grades", grades);

    auto iter1 = grades.find("Moe");
    if (iter1 != grades.end())
        iter1->second.insert(1000);
    display("grades", grades);


    return 0;
}