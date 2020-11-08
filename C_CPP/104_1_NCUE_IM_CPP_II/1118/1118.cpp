/**
 * @file 1118.cpp
 *
 * @brief
 *      1. Input two time to compare the longest it is.
 *      2. (Optional) Could build a header file to store Time class.
 *          - get_input: Let user input the data.
 *          - input: Store the user input hour/minute/second.
 *          - duration: Calculate the total second. (const)
 *          - operator >: Custom the operator work. (const)
 *          - operator <: Custom the operator work. (const)
 *          - Make the variable as private.
 *
 * @example
 *      [Input]
 * 		1. 12 15 30, 14 16 25
 * 		2. 14 16 25, 12 15 30
 * 		3. 12 15 30, 12 15 30
 *
 *      [Output]
 * 		1. Time 2 is larger.
 * 		2. Time 1 is larger.
 * 		3. Time 1 is as large as Time 2.
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Nov. 04, 2020
 *      - Orignial: Oct. 18, 2015
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

    // User Input
    std::cout << "Please enter time 1 & time 2." << std::endl;
    std::cout << "System will count total of time (time 1 + time 2) seconds."
              << std::endl;

	std::cout << "Please input time 1: " << std::endl;
	time_1.input();
	std::cout << "Please input time 2: " << std::endl;
	time_2.input();

    // Output
	if(time_1 > time_2)
		std::cout << "Time 1 is larger." << std::endl;
	else if(time_1 < time_2)
		std::cout << "Time 2 is larger." << std::endl;
	else
		std::cout << "Time 1 is as large as Time 2." << std::endl;

    return EXIT_SUCCESS;
}
