/**
 * @file 0415.cpp
 *
 * @brief Input at most integers to calculate the average.
 *        -1 to close the input and would not be calculated.
 *        Notice: The intergers input could not duplicate.
 * @example
 *      1. [Input]
 *             -1
 *         [Output]
 *             Average: 0.00
 *      2. [Input]
 *             20 15 30 14 -1
 *         [Output]
 *             Average: 19.75
 *      3. [Input]
 *             10 20 30 40 50 60 70 80 90 100
 *         [Output]
 *             Average: 55.00
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 26, 2020
 *      - Orignial: Apr. 15, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

int main() {
    // Declare the varialbe
    long integers[10];
    int input, summary = int();
    int count = 0;
    bool duplicate = false;
    double average = double();

    // User input the needed number.
    std::cout << "Please enter at most 10 integer numbers. \
    (Could not duplicate.)" << std::endl;

    // Logic.
    while(count < 10) {
        std::cout << "Please enter the "
                  << count + 1 << " number: ";
        std::cin >> input;

        if (input == -1) {
            break;
        }
        else {
            // Check if duplicate in array.
            duplicate = false;
            for(int i = 1 ; i <= count ; i++){
                if (integers[i] == input) {
                    duplicate = true;
                    break;
                }
            }

            // If duplicated.
            if (duplicate) {
                std::cout << "The number "
                          << input
                          << " is duplicated. "
                          << "Please re-enter the value!"
                          << std::endl;
            }
            else {
                integers[count] = input;
                summary += input;
                count++;
            }

        }
    }

    // Output
    std::cout << std::string(50, '*') << std::endl;
    std::cout << "You total input "
              << count
              << " numbers."
              << std::endl;
    std::cout << "Average: "
              << std::fixed
              << std::setprecision(2)
              << std::showpoint
              << float(summary) / float(count)
              << std::endl;

    return 0;
}
