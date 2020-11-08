/**
 * @file 1125.cpp
 *
 * @brief
 *      1. Input two time to compare the longest it is.
 *      2. (Optional) Could build a header file to store Time class.
 *          - get_input: Let user input the data.
 *          - input: Store the user input hour/minute/second.
 *          - get_hour: Return the time hour part.
 *          - get_minute: Return the time minute part.
 *          - get_second: Return the time second part.
 *          - operator +: Custom the operator work. (const)
 *          - operator -: Custom the operator work. (const)
 *          - Make the variable as private and explicit them.
 *
 * @example
 *      [Input]
 *      1. 14 15 10, 12 10 5
 *      2. 12 10 5, 14 15 10
 *
 *      [Output]
 *      1. time 1 + time 2 = 26 : 25 : 15
 *         time 1 - time 2 = 2 : 5 : 5
 *      2. time 1 + time 2 = 26 : 25 : 15
 *         time 1 - time 2 = -3 : 54 : 55
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Nov. 05, 2020
 *      - Orignial: Oct. 25, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include "time.h"

int main(int argc, char *argv[])
{
    // Declear variable
    time::Time time_1 , time_2, add, minus;

    // User Input
    std::cout << "Please enter time 1 & time 2." << std::endl;
    std::cout << "System will count (time 1 + time 2) and (time 1 - time 2)."
              << std::endl;

	std::cout << "Please input time 1: " << std::endl;
	time_1.input();
	std::cout << "Please input time 2: " << std::endl;
	time_2.input();

    // Logic
    add = time_1 + time_2;
    minus = time_1 - time_2;

    // Output
	std::cout << "---------RESULT---------" << std::endl;
	std::cout << "time 1 + time 2 = " << add.get_hour() << " : "
              << add.get_minute() << " : "
              << add.get_second() << std::endl;
    std::cout << "time 1 - time 2 = " << minus.get_hour() << " : "
              << minus.get_minute() << " : "
              << minus.get_second() << std::endl;

    return EXIT_SUCCESS;
}
