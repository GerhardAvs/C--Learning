/**
 * @file Functions.h
 * @brief Binary search functions: iterative and recursive implementations.
 * @details This header provides the menu function and both versions of the
 *          binary search algorithm for use with a sorted integer array.
 * @author Student
 * @date 2026
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

/**
 * @brief Displays the program menu and validates the selected option.
 * @details Shows the available binary search methods and forces the user
 *          to select a valid option (1, 2, or 3) using a do-while loop.
 * @return int The validated menu option selected by the user.
 */
int menu()
{
    int option;

    do
    {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "        MENU - BINARY SEARCH              " << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "1. Iterative Binary Search" << std::endl;
        std::cout << "2. Recursive Binary Search" << std::endl;
        std::cout << "3. Exit Program" << std::endl;
        std::cout << "\nSelect an option: ";

        std::cin >> option;
        std::cout << std::endl;

    } while (option < 1 || option > 3);

    return option;
}

/**
 * @brief Performs an iterative binary search on a sorted array.
 * @details Repeatedly divides the search interval in half using a while loop.
 *          The search continues until the target is found or the interval
 *          becomes invalid (low > high).
 *
 * @param arr Sorted integer array to search in.
 * @param x   Target value to search for.
 * @param low Starting index of the search interval.
 * @param high Ending index of the search interval.
 *
 * @return int Index of the target value if found.
 * @return -1  If the target value does not exist in the array.
 *
 * @note Time complexity: O(log n) | Space complexity: O(1)
 */
int iterative_binary_search(int arr[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x == arr[mid])
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

/**
 * @brief Performs a recursive binary search on a sorted array.
 * @details Recursively divides the search interval until the target is found
 *          or the base case is reached (low > high), indicating the element
 *          does not exist in the array.
 *
 * @param arr Sorted integer array to search in.
 * @param x   Target value to search for.
 * @param low Starting index of the current search interval.
 * @param high Ending index of the current search interval.
 *
 * @return int Index of the target value if found.
 * @return -1  If the target value does not exist in the array (base case).
 *
 * @note Time complexity: O(log n) | Space complexity: O(log n) due to call stack
 */
int recursive_binary_search(int arr[], int x, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (x == arr[mid])
    {
        return mid;
    }
    else if (x > arr[mid])
    {
        return recursive_binary_search(arr, x, mid + 1, high);
    }
    else
    {
        return recursive_binary_search(arr, x, low, mid - 1);
    }
}

#endif // FUNCTIONS_H