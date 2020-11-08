/**
 * @file 1104.cpp
 *
 * @brief
 *      1. Input two time calculate the sum and difference.
 *      2. (Optional) Could build a header file to store Time class.
 *          - get_input: Let user input the data.
 *          - input: Store the user input hour/minute/second.
 *          - duration: Calculate the total second.
 *          - Make the variable as private.
 *
 * @example
 *      [Input]
 *      Please enter time 1 & time 2.
 *      System will count total of time (time 1 + time 2) seconds.
 *      Please input time 1:
 *      Please enter the "Hour": 14
 *      Please enter the "Minute": 15
 *      Please enter the "Second": 17
 *      Please input time 2:
 *      Please enter the "Hour": 15
 *      Please enter the "Minute": 57
 *      Please enter the "Second": 12
 *
 *      [Output]
 *      Total seconds : 108749
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
#include "time.h"

int main(int argc, char *argv[])
{
    // Declear variable
    time::Time time_1 , time_2;

    std::cout << "Please enter time 1 & time 2." << std::endl;
    std::cout << "System will count total of time (time 1 + time 2) seconds."
              << std::endl;

	std::cout << "Please input time 1: " << std::endl;
	time_1.input();
	std::cout << "Please input time 2: " << std::endl;
	time_2.input();

    // Output
	std::cout << "Total seconds : "
              << time_1.duration() + time_2.duration()
              << std::endl;

    return EXIT_SUCCESS;
}
