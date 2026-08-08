/**
 * @file main.cpp
 * @brief Main program for Binary Search demonstration.
 * @details This program allows the user to perform iterative or recursive
 *          binary searches on a pre-sorted integer array containing values
 *          from 1 to 25. The array is displayed at startup and the user
 *          can search repeatedly using the menu.
 * @author Student
 * @date 2026
 */

#include <iostream>
#include <cstdlib>
#include "Functions.h"

using namespace std;

/**
 * @brief Entry point of the program.
 * @details Initializes a sorted integer array with values 1 to 25,
 *          displays its contents, and enters a loop where the user
 *          can perform binary searches using either the iterative
 *          or recursive method until they choose to exit.
 *
 * @return int Returns 0 on normal termination.
 */
int main()
{
    /** @brief Sorted array containing integers from 1 to 25. */
    int arr[25] = {
         1,  2,  3,  4,  5,
         6,  7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25
    };

    int n    = sizeof(arr) / sizeof(arr[0]);
    int low  = 0;
    int high = n - 1;

    int result;
    int x;

    /** @brief Display the array contents at startup. */
    cout << "Sorted array: [ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;

    /** @brief Main program loop: repeat until user selects Exit. */
    while (true)
    {
        switch (menu())
        {
            case 1:
                cout << "Enter the value to search: ";
                cin >> x;

                result = iterative_binary_search(arr, x, low, high);

                if (result != -1)
                    cout << "Value found at index: arr[" << result << "]" << endl;
                else
                    cout << "The value does not exist in the array." << endl;
                break;

            case 2:
                cout << "Enter the value to search: ";
                cin >> x;

                result = recursive_binary_search(arr, x, low, high);

                if (result != -1)
                    cout << "Value found at index: arr[" << result << "]" << endl;
                else
                    cout << "The value does not exist in the array." << endl;
                break;

            case 3:
                cout << "Exiting program..." << endl;
                exit(0);
                break;
        }
    }

    return 0;
}