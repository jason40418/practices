/**
 * @file 1230.cpp
 *
 * @brief
 *      1. Input a series of integer number (unknown length).
 *      2. If the number has been stored, ignore this number.
 *      3. Need to identify the data type.
 *      4. input 0 as finish input.
 *      HINT: You could use Vector to store the number.
 *
 * @example
 *      [Input]
 *          12+15+36
 *          12/4+3
 *      [Output]
 *          Add: 69
 *          Subtract: 57
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Sep. 02, 2020
 *      - Orignial: Dec. 30, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>

bool input(int *number);

int main(int argc, char *argv[]) {

    // Declare the varialbe
    int number = int();
    bool found = false;
    bool error_type = false;
    std::vector <int> list;

    while(true) {
        found = false;

        std::cout << "Please enter No. " << list.size() + 1 << " number: ";
        error_type = input(&number);


        if (error_type) {
            std::cout << "--> You need to input the integer number."
                      << std::endl;
            continue;
        }
        // Need to check effective input first.
        else if (number == 0) {
            break;
        }
        else {
            // Logic: Find if the number duplicate.
            for (int i = 0 ; i < list.size() ; i++) {
                if (list[i] == number) {
                    found = true;
                }
            }

            if (found) {
                std::cout << "The number " << number
                          << " you input is duplicated!"
                          << " It would not be stored."
                          << std::endl;
                continue;
            }
            else {
                list.push_back(number);
            }
        }
    }

    // Output
    std::cout << "--> The following numbers are you input: " << std::endl;
    for(int i = 0 ; i < list.size() ; i++) {
        std::cout << "No. " << i+1 << " number is " << list[i] << std::endl;
    }

    return EXIT_SUCCESS;
}

// Logic: User input the number and check if error type.
bool input(int *number) {
    // User input
    double input_double = double();
    std::string user_input = "";
    std::cin >> user_input;

    // Preprocess
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    else {
        try {
            input_double = std::stod(user_input);
        }
        catch (std::invalid_argument const &e) {
            std::cout << "Bad input: Invail argument." << std::endl;
            return true;
        }
        catch (std::out_of_range const &e) {
            std::cout << "Overflow: Out of the range" << std::endl;
            return true;
        }

        // Prevent input is not integer would automate fetch the integer part.
        if (double(int(input_double)) == input_double) {
            return false;
        }
        else {
            *number = int(input_double);
            return true;
        }
    }
}
