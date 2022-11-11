//
// Created by Liam Ross on 06/07/2022.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <numeric>
#include <numbers>

void displayArr(const std::string&& name, const std::array<int, 5>& arr);

int main() {
    // /**================**/
    // ===== std::array =====
    // /**================**/

    // Initialization & Assignment
    std::array<int, 5> arr {1, 2, 3, 4, 5};

    std::array<std::string, 4> theBois {
        "Liam",
        std::string{"James"},
        "Brian",
        "Richard"
    };

    std::for_each(theBois.begin(), theBois.end(),
                  [](const std::string& s) { std::cout << s << ", "; });

    // Common Methods
    std::cout << "\ntheBois.size: " << theBois.size() << std::endl;
    std::cout << "theBois.at(0): " << theBois.at(2) << std::endl;
    std::cout << "theBois[1]: " << theBois[1] << std::endl;
    std::cout << "*theBois.begin(): " << *theBois.begin() << std::endl;
    std::cout << "theBois.front(): " << theBois.front() << std::endl;
    std::cout << "theBois.back(): " << theBois.back() << std::endl;
    std::cout << std::boolalpha << "theBois.empty(): " << theBois.empty() << std::endl;
    std::cout << "theBois.max_size(): " << theBois.max_size() << std::endl;

    std::string* data = theBois.data(); // get the raw array address
    std::cout << *data << std::endl;
    std::cout << data << std::endl;

//    std::array<int, 5> arr {1, 2, 3, 4, 5};
//    std::array<int, 5> arr1 {100, 200, 300, 400, 500};
//    arr.swap(arr1); // Swaps the 2 arrays


    std::cout << "\n";


    // /**=====================**/
    // === Swapping & Filling ===
    // /**=====================**/

    // .fill() & .swap()
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 {10, 20, 30, 40, 50};

    displayArr("arr1", arr1);
    displayArr("arr2", arr2);

    std::cout << "\n";

    arr1.fill(100); // Changes all the elements in the array to 100
    arr2.fill(500); // Changes all the elements in the array to 500
    displayArr("arr1", arr1);
    displayArr("arr2", arr2);

    std::cout << "\n";

    arr1.swap(arr2); // Swaps the elements in arr1 and arr2
    displayArr("arr1", arr1);
    displayArr("arr2", arr2);

    std::cout << "\n";


    // /**====================================**/
    // === Accessing the underlying raw array ===
    // /**====================================**/

    // The std::array is really a wrapper around a raw array
    // .data()
    std::array<int, 5> arr3 {20, 40, 60, 80, 100};
    int* ptr = arr3.data();
    std::cout << ptr << std::endl;

    *ptr = 1000;
    displayArr("arr3", arr3);

    std::cout << "\n";


    // /**==================**/
    // === Sorting an array ===
    // /**==================**/

    // std::sort()
    std::array<int, 5> arr4 {2, 1, 4, 5, 3};
    displayArr("arr4", arr4);

    std::sort(std::begin(arr4), std::end(arr4)); // Same as: std::sort(arr4.begin(), arr4.end());
    displayArr("arr4", arr4);


    std::cout << "\n";


    // /**===================**/
    // === Minimum & Maximum ===
    // /**===================**/

    // std::min_element & std::max_element
    std::array<int, 5> arr5 {2, 1, 4, 5, 3};
    std::array<int, 5>::iterator min_num = std::min_element(arr5.begin(), arr5.end());
    auto max_num = std::max_element(arr5.begin(), arr5.end());

    displayArr("arr5", arr5);
    std::cout << "min element: " << *min_num << std::endl;
    std::cout << "max element: " << *max_num << std::endl;

    std::cout << "\n";


    // /**===============**/
    // === Adjacent Find ===
    // /**===============**/

    // std::adjacent_find()
    std::array<int, 5> arr6 {2, 1, 4, 4, 3};
    displayArr("arr6", arr6);

//    std::array<int, 5>::iterator adjacent = std::adjacent_find(arr6.begin(), arr6.end());
    auto adjacent = std::adjacent_find(arr6.begin(), arr6.end());

    if (adjacent != arr6.end())
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else
        std::cout << "No adjacent elements found" << std::endl;


    std::cout << "\n";


    // /**============**/
    // === Accumulate ===
    // /**============**/

    // std::accumulate() - in <numeric> header
    std::array<int, 5> arr7 {2, 4, 6, 8, 10};
    auto sum = std::accumulate(arr7.begin(), arr7.end(), 0);

    displayArr("arr7", arr7);
    std::cout << "Sum of elements in arr7: " << sum << std::endl;

    std::cout << "\n";


    // /**=======**/
    // === Count ===
    // /**=======**/

    // std::count()
    std::array<int, 5> arr8 {1, 2, 3, 3, 3};
    auto count = std::count(arr8.begin(), arr8.end(), 3);

    displayArr("arr8", arr8);
    std::cout << "Found 3 -> " << count << " times" << std::endl;

    std::cout << "\n";


    // /**==========**/
    // === Count If ===
    // /**==========**/

    // std::count_if()
    std::array<int, 5> arr9 {1, 9, 15, 35, 88};
    auto count1 = std::count_if(arr9.begin(), arr9.end(),
                                [](int x) { return x > 10 && x < 50; });

    displayArr("arr9", arr9);
    std::cout << count1 << " elements are between 10 and 50 in arr9" << std::endl;


    std::cout << "\n";

    return 0;
}

/**
 * \n
 * Function for displaying an std::array.
 * @param name The name of the array.
 * @param arr The array to display.
 */
void displayArr(const std::string&& name, const std::array<int, 5>& arr) {
    std::cout << name << ": [ ";
    for(const auto& i : arr)
        std::cout << i << " ";
    std::cout << "]\n";
}

