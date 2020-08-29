/**
 * @file 0527.cpp
 *
 * @brief Input a number, identify if it is perfect number (or factor).
 *        6 = 1 + 2 + 3 (perfect)
 *        12 = 1 + 2 + 3 + 4 + 6 (not perfect)
 *
 * @example
 *      1. [Input]
 *             6
 *         [Output]
 *             6 is perfect.
 *      2. [Input]
 *             12
 *         [Output]
 *             12 is not perfect.
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 29, 2020
 *      - Orignial: May. 27, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

bool isPerfect(int num);

int main() {
    // Declare the varialbe
    int input = int();

    std::cout << "Please enter an integer number: ";
    std::cin >> input;

    // Preprocess
    bool is_perfect = isPerfect(input);

    // Output
    if (is_perfect)
        std::cout << input << " is perfect." << std::endl;
    else
        std::cout << input << " is not perfect." << std::endl;

    return 0;
}

// Logic
bool isPerfect(int num) {
    int sum = 0;

    for (int i = 1 ; i <= num / 2 ; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return (sum == num) ? true : false;
}
