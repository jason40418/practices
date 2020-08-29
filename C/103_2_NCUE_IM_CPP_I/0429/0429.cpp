/**
 * @file 0429.cpp
 *
 * @brief Input a integer that less than 100000 it would convert
 *        the number into word.
 *        (You need to check the input if larger than 100000.)
 *
 * @example
 *      1. [Input]
 *             500
 *         [Output]
 *             Five Zero Zero
 *      2. [Input]
 *             7521
 *         [Output]
 *             Seven Five Two One
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 27, 2020
 *      - Orignial: Apr. 29, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <string>
#include <limits>
//#include <typeinfo>


int main() {
    // Declare the varialbe
    const char* DIGIT_MAPPER[10] = {
        "Zero", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine"
    };
    char input[10];
    int value = int();

    // Preprocess
    // User input the needed number.
    std::cout << "Please enter the number less than 100000.\
    Then it would convert to word." << std::endl;

    // Check if number larger than 100000
    do {
        std::cout << "Your number: ";
        // Get only the first 10 digit to prevent integer overflow
        std::cin.getline(input, 11, '\n');
        // Check the variable type: A10_c
        // std::cout << input << typeid(input).name() << std::endl;

        // Transfer the array of string to int
        value = atoi(input);

        // Check the variable type: i
        // std::cout << value << typeid(value).name() << std::endl;

        if (value >= 100000 || std::cin.fail()) {
            std::cout << "Your input "
                      << input
                      << " is larger than 100000."
                      << " Please re-enter the number."
                      << std::endl;

            // Reset the input error flag
            std::cin.clear();
            // Clean the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // VS/VC only
            //std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
        }
        else {
            break;
        }
    } while(true);

    // Logic & Output
    // Check if the number exist
    // Could check if the location is not 0. (input[i] != 0)
    for (int i = 0 ; input[i] ; i++) {
        // Input is character represent the ASCII,
        // so need to minus '0' character to get the mapping number.
        std::cout << DIGIT_MAPPER[input[i] - '0'] << " ";
    }

    std::cout << std::endl;

    return 0;
}
