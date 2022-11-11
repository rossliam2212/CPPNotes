//
// Created by Liam Ross on 13/07/2022.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <deque>


// The stack is passed by value, so we don't affect
// the passed in stack.
template<typename T>
void display(const std::string&& name, std::stack<T> s) {
    std::cout << name << ": [ ";
    while (!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // /**================**/
    // ===== std::stack =====
    // /**================**/

    // - Last In First Out (LIFO) data structure
    // (Like a stack of plates, we add plates to the top of the stack and remove from the top)

    // - Implemented as an adapter over the STL container
    //   Can be implemented as a vector, list or deque

    // - All operations occur on one end of the stack (top)

    // - No iterators are supported

    // - #include <stack>
    // - push - insert an element at the top of the stack
    // - pop - remove an element from the top of the stack
    // - top - access the top element of the stack
    // - empty - is the stack empty?
    // - size - number of elements in the stack



    // /**=================================**/
    // ===== std::stack - Initialization =====
    // /**=================================**/
    std::stack<int> stack1;                     // deque (used as the underlying container by default )
    std::stack<int, std::vector<int>> stack2;   // vector
    std::stack<int, std::list<int>> stack3;     // list
    std::stack<int, std::deque<int>> stack4;    // deque


    // /**=================================**/
    // ===== std::stack - Common Methods =====
    // /**=================================**/
    std::stack<int> s;
    s.push(10); // 10 added to the top of the stack
    s.push(20); // 20 added to the top of the stack, above the 10
    s.push(30); // 30 added to the top of the stack, above the 20

    std::cout << s.top() << std::endl; // 30

    s.pop(); // 30 is removed, 20 is now at the top

    s.pop(); // 20 is removed, 10 is now at the top

    std::cout << s.size() << std::endl; // 1

    std::cout << "\n";



    // /**===========================**/
    // ===== std::stack - Examples =====
    // /**===========================**/
    std::stack<int> s1;
    std::stack<int, std::vector<int>> s2;
    std::stack<int, std::list<int>> s3;
    std::stack<int, std::deque<int>> s4;

    std::vector<int> vec;

    for (int i : {1, 2, 3, 4, 5})
        s1.push(i);
    display("s1", s1);

    s1.push(100);
    display("s1", s1);

    s1.pop();
    s1.pop();
    display("s1", s1);

    while (!s1.empty())
        s1.pop();
    display("s1", s1);

    std::cout << "s1 size: " << s1.size() << std::endl;

    s1.push(10);
    display("s1", s1);

    s1.top() = 100;
    display("s1", s1);

    return 0;
}

