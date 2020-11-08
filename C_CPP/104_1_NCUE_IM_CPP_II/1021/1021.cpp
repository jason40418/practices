/**
 * @file 1021.cpp
 *
 * @brief
 *      1. Input two time calculate the sum and difference.
 *      2. (Optional) Could build a header file to store Time class.
 *
 * @example
 *      [Input]
 *      Please enter the time 1 "Hour": 12
 *      Please enter the time 1 "Minute": 14
 *      Please enter the time 1 "Second": 45
 *      Please enter the time 2 "Hour": 14
 *      Please enter the time 2 "Minute": 58
 *      Please enter the time 2 "Second": 12
 *
 *      [Output]
 *      Time 1: 12:14:45
 *      Time 2: 14:58:12
 *      Time 1 + Time 2: 27:12:57
 *      Time 1 + Time 2: -3:16:33
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
#include <algorithm>
#include <new>
#include "time.h"

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

time::Time add(time::Time time_1, time::Time time_2)
{
    int hour(0), minute(0), second(0), temp(0);
    time::Time result;

    second = time_1.second + time_2.second;
    if(second >= 60)
    {
      temp = second / 60;
      second %= 60;
    }

    minute = time_1.minute + time_2.minute + temp;
    if(minute >= 60)
    {
      temp = minute / 60;
      minute %= 60;
    }

    hour = time_1.hour + time_2.hour + temp;

    result.hour = hour;
    result.minute = minute;
    result.second = second;

    return result;
}

time::Time minus(time::Time time_1, time::Time time_2)
{
    int hour(0), minute(0), second(0);
    time::Time result;

    second = time_1.second - time_2.second;
    if(second < 0)
    {
      second += 60;
      minute --;
    }

    minute += time_1.minute - time_2.minute;
    if(minute < 0)
    {
      minute += 60;
      hour--;
    }

    hour += time_1.hour - time_2.hour;

    result.hour = hour;
    result.minute = minute;
    result.second = second;

    return result;
}


int main(int argc, char *argv[])
{
    time::Time time_1, time_2, add_time, minus_time;
    int value(0);

    /** ========================== TIME 1 ============================ */
    std::cout << "Please enter the time 1 \"Hour\": ";
    value = input(true);
    time_1.hour = value;
    std::cout << "Please enter the time 1 \"Minute\": ";
    value = input(false);
    time_1.minute = value;
    std::cout << "Please enter the time 1 \"Second\": ";
    value = input(false);
    time_1.second = value;

    /** ========================== TIME 2 ============================ */
    std::cout << "Please enter the time 2 \"Hour\": ";
    value = input(true);
    time_2.hour = value;
    std::cout << "Please enter the time 2 \"Minute\": ";
    value = input(false);
    time_2.minute = value;
    std::cout << "Please enter the time 2 \"Second\": ";
    value = input(false);
    time_2.second = value;

    /** ========================== Output ============================ */
    std::cout << "Time 1: "
              << time_1.hour << ":"
              << time_1.minute << ":"
              << time_1.second << std::endl;

    std::cout << "Time 2: "
              << time_2.hour << ":"
              << time_2.minute << ":"
              << time_2.second << std::endl;

    add_time = add(time_1, time_2);
    std::cout << "Time 1 + Time 2: "
              << add_time.hour << ":"
              << add_time.minute << ":"
              << add_time.second << std::endl;

    minus_time = minus(time_1, time_2);
    std::cout << "Time 1 - Time 2: "
              << minus_time.hour << ":"
              << minus_time.minute << ":"
              << minus_time.second << std::endl;


    return EXIT_SUCCESS;
}
