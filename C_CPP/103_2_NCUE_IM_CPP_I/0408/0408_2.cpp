/**
 * @file 0408_2.cpp
 *
 * @brief Input an integers, it would print the layers of stars.
 *
 * @example
 *      1. [Input]
 *             5
 *         [Output]
 *             *
 *             **
 *             ***
 *             ****
 *             *****
 *      2. [Input]
 *             3
 *         [Output]
 *             *
 *             **
 *             ***
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 26, 2020
 *      - Orignial: Apr. 08, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

int main() {
    // Declare the varialbe
    int num = int();
    int digits = 0;

    // User input the needed number
    std::cout << "Please enter an integer number." << std::endl;
    std::cin >> num;

    // Logic & Output
    for (int i = 1 ; i <= num ; i++) {

        for (int j = 1 ; j <= i ; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    return 0;
}
