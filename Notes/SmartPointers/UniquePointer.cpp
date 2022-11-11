//
// Created by Liam Ross on 12/10/2022.
//

#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;

public:
    Test() : data{} {
        std::cout << "Test constructor(" << data << ")\n";
    }
    explicit Test(int data) : data{data} {
        std::cout << "Test constructor(" << data << ")\n";
    }
    ~Test() {
        std::cout << "Test destructor\n";
    }
    int getData() const {
        return data;
    }
};

int main() {

    // ***=====================***
    // ===== std::unique_ptr =====
    // ***=====================***

    // - Simple smart pointer - very efficient

    // std::unique_ptr<T>
    // - Points to an object of type T on the heap
    // - It is unique - there can only be one std::unique_ptr<T> pointing to the object on the heap
    // - Owns what it points to
    // - Cannot be assigned or copied
    // - CAN be moved
    // - When the pointer is destroyed, what is points to is automatically destroyed


    // Creating, Initializing and Using
    {

        std::unique_ptr<int> p1 {new int{100}};

        std::cout << *p1 << std::endl; // 100
        *p1 = 200;
        std::cout << *p1 << std::endl; // 200

    } // automatically deleted

    std::cout << "\n";



    // /**================**/
    // === Useful Methods ===
    // /**================**/

    {
        std::unique_ptr<int> p1 {new int{100}};

        std::cout << p1.get() << std::endl; // Memory address

        p1.reset(); // p1 is now nullptr

        if (p1)
            std::cout << *p1 << std::endl; // Won't execute as ptr is nullptr

    } // automatically deleted



    // /**==================**/
    // === Vectors and Move ===
    // /**==================**/

    {
        std::vector<std::unique_ptr<int>> vec;
        std::unique_ptr<int> ptr {new int{100}};

//        vec.push_back(ptr); // Error - copy not allowed

        vec.push_back(std::move(ptr)); // the vector now owns the pointer

    } // automatically deleted



    // /**==========================**/
    // === std::make_unique - C++14 ===
    // /**==========================**/

    // - More efficient - no calls to new or delete
    {
        std::unique_ptr<int> p1 = std::make_unique<int>(100);
        auto p2 = std::make_unique<double>(50.55);

//        std::unique_ptr<Account> p3 = std::make_unique<Account>("Liam", 1000);

    } // automatically deleted

    std::cout << "\n";


    // /**======================**/
    // === Using the Test class ===
    // /**======================**/

    std::unique_ptr<Test> t1 {new Test{100}};

    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

    std::unique_ptr<Test> t3;
//    t3 = t1;
    t3 = std::move(t1);

    if (!t1)
        std::cout << "t1 is nullptr\n";

    return 0;
}

