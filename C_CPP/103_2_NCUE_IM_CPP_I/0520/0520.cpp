/**
 * @file 0520.cpp
 *
 * @brief Input a number, it would output the reverse result.
 *        The number needs to less than 10000.
 *        Define a new function called reverse().
 *
 * @example
 *      1. [Input]
 *             1725
 *         [Output]
 *             5271
 *      2. [Input]
 *             -4312
 *         [Output]
 *             -2134
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 29, 2020
 *      - Orignial: May. 20, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <algorithm>
#include <new>

char * reverse(char *input, int value, size_t len);

int main() {
    // Declare the varialbe
    const size_t MAX_INT_LEN(10);
    char input[MAX_INT_LEN];
    int value = int();

    // Preprocess
    // User input the needed number.
    std::cout << "Please enter the number less than 100000.\
    Then it would convert to word." << std::endl;

    // Check if number larger than 100000
    do {
        std::cout << "Your number: ";
        std::cin.getline(input, 11, '\n');

        // Transfer the array of string to int
        value = atoi(input);

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
        }
        else {
            break;
        }
    } while(true);



    // Output
    std::cout << "Original: " << input << std::endl;
    std::cout << "Reverse: " << reverse(input, value, MAX_INT_LEN) << std::endl;

    return 0;
}

// Logic
char * reverse(char *input, int value, size_t len) {
    // Apply for a dynamic memory
    char *temp = new char[len];

    // Get the length of the character array
    int length = strlen(input);
    // Copy an array
    std::copy(input, input + len, temp);

    // Reverse
    if (value >= 0) {
        for (int i = 0 ; i < length ; i++) {
            input[i] = temp[length - i - 1];
        }
    }
    else {
        for (int i = 1 ; i < length ; i++) {
            input[i] = temp[length - i];
        }
    }

    // Release memory
    delete [] temp;


    return input;
}
