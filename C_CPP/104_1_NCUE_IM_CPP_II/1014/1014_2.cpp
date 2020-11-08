/**
 * @file 1014_2.cpp
 *
 * @brief
 *      1. Input the total seconds.
 *      2. Transfer it into hour : minute : second format.
 *
 * @example
 *      [Input]
 *      Please input the second (integer): 12576
 *
 *      [Output]
 *      The time is : 3 : 29 : 36
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Oct. 16, 2020
 *      - Orignial: Dec. 02, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <limits>

struct Time
{
   int hour;
   int minute;
   int second;
};

const int HOUR_SECOND = 60 * 60;
const int MINUTE_SECOND = 60;

int input()
{
    const size_t MAX_INT_LEN(10);
    char input[MAX_INT_LEN];
    int value = int();

    while(true)
    {
        std::cin.getline(input, 11, '\n');

        // Transfer the array of string to int
        value = atoi(input);

        if (std::cin.fail())
        {
            std::cout << "Please input the integer number only!" << std::endl;

            // Reset the input error flag
            std::cin.clear();
            // Clean the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }

        std::cout << "Re-enter the number: ";
    }

    return value;
}

int main(int argc, char *argv[])
{
    // Declear the variable
    int input_sec;
    Time time;

    // User input
    std::cout << "Please input the second (integer): ";
    input_sec = input();

    // Logic
    time.hour = input_sec / HOUR_SECOND;
    input_sec %= HOUR_SECOND;
    time.minute = input_sec / MINUTE_SECOND;
    input_sec %= MINUTE_SECOND;
    time.second = input_sec;

    // Output
    std::cout << "The time is : "
              << time.hour << " : "
              << time.minute << " : "
              << time.second
              << std::endl;

    return EXIT_SUCCESS;
}
