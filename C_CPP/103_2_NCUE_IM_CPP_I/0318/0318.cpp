/**
 * @file 0318.cpp
 *
 * @brief Enter a number to identify it is odd or even.
 *
 * @example
 *      1. [Input] 10; [Output] This number is even.
 *      2. [Input] 11; [Output] This number is odd.
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 04, 2020
 *      - Orignial: Mar. 18, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

int main() {
    // Declare the varialbe
    int num = int();

    // User input the needed number
    std::cout << "Please enter an interger number." << std::endl;
    std::cout << "Your number:";
    std::cin >> num;

    // Logic & Output
    if (num % 2 == 1)
        std::cout << "This number is odd." << std::endl;
    else
        std::cout << "This number is even." << std::endl;

    return 0;
}
