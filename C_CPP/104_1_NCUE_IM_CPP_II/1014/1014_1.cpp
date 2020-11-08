/**
 * @file 1014_1.cpp
 *
 * @brief
 *      1. Input the time hour/minute/second.
 *      2. Transfer it into total second.
 *
 * @example
 *      [Input]
 *      Please enter the time "Hour": 12
 *      Please enter the time "Minute": 25
 *      Please enter the time "Second": 14
 *
 *      [Output]
 *      44714 seconds
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

int input(bool is_hour)
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
        else if (is_hour)
        {
            if(value >= 0 && value <= 23) {
                break;
            }
            else {
                std::cout << "The range of the number is 0-23!" << std::endl;
            }
        }
        else
        {
            if(value >= 0 && value <= 59) {
                break;
            }
            else {
                std::cout << "The range of the number is 0-59!" << std::endl;
            }
        }

        std::cout << "Re-enter the number: ";
    }

    return value;
}

int main(int argc, char *argv[])
{
    // Declear variable
    Time time;
    int value(0), summary(0);

    // User input
    std::cout << "Please enter the time \"Hour\": ";
    value = input(true);
    time.hour = value;
    std::cout << "Please enter the time \"Minute\": ";
    value = input(false);
    time.minute = value;
    std::cout << "Please enter the time \"Second\": ";
    value = input(false);
    time.second = value;

    // Logic
    summary += time.hour * HOUR_SECOND;
    summary += time.minute * MINUTE_SECOND;
    summary += time.second;

    // Output
    std::cout << summary << " seconds" << std::endl;

    return EXIT_SUCCESS;
}
