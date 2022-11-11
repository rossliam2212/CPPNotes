//
// Created by Liam Ross on 05/07/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    std::vector<int>::iterator it = nums.begin();
    std::vector <int>::reverse_iterator it = vec.rbegin();
//    std::vector <int>::reverse_iterator iter(vec.end());

    while (it != vec.rend()){
        std::cout << *it << " ";
        ++it;
    }
    return 0;
}

