/**
 * @file 0325.cpp
 *
 * @brief Input three integers to find the maximum and the minimum.
 *
 * @example
 *      1. [Input]
 *             10 25 11
 *         [Output]
 *             The maximum number is: 25.
 *             The minimum number is: 10.
 *      2. [Input]
 *             35 20 15
 *         [Output]
 *             The maximum number is: 35.
 *             The minimum number is: 15.
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 08, 2020
 *      - Orignial: Mar. 25, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

int main() {
    // Declare the varialbe
    int num_1, num_2, num_3 = int();
    int max, min = int();

    // User input the needed number
    std::cout << "Please enter three interger numbers." << std::endl;
    std::cout << "Seperate with space." << std::endl;
    std::cin >> num_1 >> num_2 >> num_3;

    // Logic
    max = num_1;
    if (num_2 > max)
        max = num_2;
    if (num_3 > max)
        max = num_3;

    min = num_1;
    if (num_2 < min)
        min = num_2;
    if (num_3 < min)
        min = num_3;

    // Output
    std::cout << "The maximum number is: " << max << std::endl;
    std::cout << "The minimum number is: " << min << std::endl;

    return 0;
}
