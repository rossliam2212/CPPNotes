//
// Created by Liam Ross on 15/07/2022.
//

#include <iostream>
#include <string>
#include <queue>

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
//        return this->age < rhs.age;
        return this->name < rhs.name;
    }
    bool operator==(const Person& rhs) const {
        return this->name == rhs.name && this->age == rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << ":" << person.age;
    return os;
}

template<typename T>
void display(const std::string&& name, std::priority_queue<T> pq) {
    std::cout << name << ": [ ";
    while (!pq.empty()) {
        T elem = pq.top();
        pq.pop();
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

int main() {

    // /**=========================**/
    // ===== std::priority_queue =====
    // /**=========================**/

    // - Allows insertions and removal of elements in order from the front of the container
    // - Elements are stored internally as a vector by default
    // - Elements are inserted in priority order  (The largest value will always be at the front)
    // - No iterators are supported

    // - #include <queue>
    // - push - inserted an element into sorted order
    // - pop - removes the top element (greatest)
    // - top - access the top element (greatest)
    // - empty - is the queue empty?
    // - size - number of elements in the queue


    // /**==========================================**/
    // ===== std::priority_queue - Initialization =====
    // /**==========================================**/
    std::priority_queue<int> pq; // vector is underlying container

    pq.push(10);
    pq.push(20);
    pq.push(3);
    pq.push(4);

    std::cout << pq.top() << std::endl; // 20 (largest)
    pq.pop(); // remove 20
    pq.top(); // 10 (largest)

    std::cout << "\n";


    // /**====================================**/
    // ===== std::priority_queue - Examples =====
    // /**====================================**/
    std::priority_queue<int> pq1;

    for (const int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
        pq1.push(i);

    std::cout << "Size: " << pq1.size() << std::endl;
    std::cout << "Top: " << pq1.top() << std::endl; // The top of the priority queue will always be the largest int
    display("pq1", pq1);

    pq1.pop();
    display("pq1", pq1);

    std::cout << "\n";


    std::priority_queue<Person> pq2;
    pq2.push(Person{"A", 10});
    pq2.push(Person{"B", 1});
    pq2.push(Person{"C", 14});
    pq2.push(Person{"D", 18});
    pq2.push(Person{"E", 7});
    pq2.push(Person{"F", 27});

    display("pq2", pq2);

    return 0;
}

