/**
 * @file 0408_1.cpp
 *
 * @brief Input an integers, it would print all the even numbers within
 *        one to this number.
 *
 * @example
 *      1. [Input]
 *             10
 *         [Output]
 *             2 4 6 8 10
 *      2. [Input]
 *             15
 *         [Output]
 *              2  4  6  8  10
 *             12 14
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 08, 2020
 *      - Orignial: Apr. 08, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <iomanip>

int main() {
    // Declare the varialbe
    int num, num_2 = int();
    int digits = 0;

    // User input the needed number
    std::cout << "Please enter an integer number." << std::endl;
    std::cin >> num;
    num_2 = num;

    // Logic & Output
    /** Count the digits */
    while(num_2 != 0) {
        num_2 /= 10;
        digits++;
    }

    for (int i = 1 ; i * 2 <= num ; i++) {
        std::cout << std::setw(digits + 1) << i * 2;

        if (i % 5 == 0)
            std::cout << std::endl;
        else
            std::cout << " ";
    }

    return 0;
}
