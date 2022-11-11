//
// Created by Liam Ross on 13/07/2022.
//

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <deque>

template<typename T>
void display(const std::string&& name, std::queue<T> q) {
    std::cout << name << ": [ ";
    while (!q.empty()) {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

int main() {
    // /**================**/
    // ===== std::queue =====
    // /**================**/

    // - First In First Out data structure

    // - Implemented as an adapter over the STL container
    //   Can be implemented as a list or deque

    // - Elements are pushed from the back and popped from the front

    // - No iterators are supported

    // - #include <queue>
    // - push - insert an element at the back of the queue
    // - pop - remove an element from the front of the queue
    // - front - access the element at the front
    // - back - access the element at the back
    // - empty - is the queue empty?
    // - size - number of elements in the queue


    // /**=================================**/
    // ===== std::queue - Initialization =====
    // /**=================================**/
    std::queue<int> queue1;                     // deque (used as the underlying container by default)
    std::queue<int, std::list<int>> queue2;     // list
    std::queue<int, std::deque<int>> queue3;    // deque


    // /**=================================**/
    // ===== std::queue - Common Methods =====
    // /**=================================**/
    std::queue<int> q;
    q.push(10); // 10 is both the back and front element in the queue.
    q.push(20); // 20 pushed to the back, 10 is at the front.
    q.push(30); // 30 pushed to the back, 10 is at the front.

    std::cout << q.front() << std::endl; // 10
    std::cout << q.back() << std::endl;  // 30

    q.pop(); // Removes 10 from the front -> 20 is now at the front
    q.pop(); // Removes 20 from the front -> 30 is now at the front (and the back)

    std::cout << q.size() << std::endl; // 1

    std::cout << "\n";



    // /**===========================**/
    // ===== std::queue - Examples =====
    // /**===========================**/
    std::queue<int> q1;

    for (int i : {1, 2, 3, 4, 5})
        q1.push(i);
    display("q1", q1);

    std::cout << "Front: " << q1.front() << std::endl;
    std::cout << "Back: " << q1.back() << std::endl;

    q1.push(100);
    display("q1", q1);

    q1.pop();
    q1.pop();
    display("q1", q1);

    while (!q1.empty())
        q1.pop();
    display("q1", q1);

    std::cout << "Size: " << q1.size() << std::endl;

    q1.push(10);
    q1.push(100);
    q1.push(1000);
    display("q1", q1);

    std::cout << "Front: " << q1.front() << std::endl;
    std::cout << "Back: " << q1.back() << std::endl;

    q1.front() = 5;
    q1.back() = 5000;
    display("q1", q1);

    std::cout << "Front: " << q1.front() << std::endl;
    std::cout << "Back: " << q1.back() << std::endl;

    return 0;
}