#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Prints all elements of a vector.
 * 
 * @tparam T Data type stored in the vector
 * @param vec Vector to print
 */
template <typename T>
void printVector(const vector<T>& vec) {
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

#endif