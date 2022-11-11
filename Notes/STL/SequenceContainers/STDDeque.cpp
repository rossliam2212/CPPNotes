//
// Created by Liam Ross on 06/07/2022.
//

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>

template<typename T>
void display(const std::string&& name, const std::deque<T>& d) {
    std::cout << name << ": [ ";
    std::for_each(std::begin(d), std::end(d),[](T x) { std::cout << x << " "; });
    std::cout << "]\n";
}

int main() {

    // ***================***
    // ===== std::deque =====
    // ***================***

    // std::deque => double ended queue
    // - Dynamic size
    //   - Handled Automatically
    //   - Can expand and contract as needed
    //   - Elements are not stored in contiguous memory

    // - Rapid insertion and deletion at the front and back (constant time)
    // - Insertion or removal of elements (linear time)


    // ***=============================***
    // === Initialization & Assignment ===
    // ***=============================***
    std::deque<int> deque {1, 2, 3, 4, 5};
    std::deque<int> deque1 (10, 100); // Ten elements all set to 100

    std::deque<std::string> stooges {
        std::string{"Larry"},
        "Moe",
        std::string{"Curly"}
    };


    // ***================***
    // === Common Methods ===
    // ***================***
    std::cout << deque.size() << std::endl;
    std::cout << deque.max_size() << std::endl;
    std::cout << deque.at(0) << std::endl;
    std::cout << deque[1] << std::endl;
    std::cout << deque.front() << std::endl;
    std::cout << deque.back() << std::endl;

    stooges.push_back("Liam"); // Adds "Liam" to the back
    stooges.pop_back(); // Removes "Liam" from the back

    stooges.push_front("Liam"); // Adds "Liam" to the front
    stooges.pop_front(); // Removes "Liam from the front

    stooges.emplace_front("Liam"); // Adds "Liam" to the front - More Efficiently
    stooges.emplace_back("Liam"); // Adds "Liam" to the back - More Efficiently

    display("stooges", stooges);

    std::cout << "\n";


    // ***============***
    // === Assignment ===
    // ***============***
    std::deque<int> d1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display("d1", d1);

    d1 = {2, 4, 6, 8};
    display("d1", d1);

    std::cout << "\n";

    std::deque<int> d2 (10, 100);
    display("d2", d2);

    d2.at(0) = 500;
    d2[3] = 800;
    display("d2", d2);

    std::cout << "\n";


    // ***============***
    // === Push & Pop ===
    // ***============***
    std::deque<int> d3 {0, 0, 0};
    display("d3", d3);

    d3.push_back(10);
    d3.push_back(20);
    display("d3", d3);

    d3.push_front(100);
    d3.push_front(200);
    display("d3", d3);

    std::cout << "Front: " << d3.front() << std::endl;
    std::cout << "Back: " << d3.back() << std::endl;
    std::cout << "Size: " << d3.size() << std::endl;

    d3.pop_back();
    d3.pop_front();
    display("d3", d3);

    std::cout << "\n";



    // Inserting all the even numbers from a vector into the back of the deque
    // and all the odd numbers to the front of the deque
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d4;

    for(const auto& elem : vec) {
        if (elem % 2 == 0)
            d4.push_back(elem);
        else
            d4.push_front(elem);
    }
    display("d4", d4);

    std::cout << "\n";


    // ***===================================***
    // === Push Front vs. Push Back Ordering ===
    // ***===================================***
    std::vector<int> vec2 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d5;

    for (const auto& elem : vec2)
        d5.push_front(elem);
    display("d5", d5);

    d5.clear();

    for (const auto& elem : vec2)
        d5.push_back(elem);
    display("d5", d5);

    std::cout << "\n";


    // ***===========***
    // === std::copy ===
    // ***===========***

    // Same as example above but using:
    // std::copy with std::front_inserter & std::back_inserter
    std::vector<int> vec3 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d6;

    std::copy(vec3.begin(), vec3.end(), std::front_inserter(d6));
    display("d6", d6);

    d6.clear();

    std::copy(vec3.begin(), vec3.end(), std::back_inserter(d6));
    display("d6", d6);


    return 0;
}