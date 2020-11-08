/**
 * @file 1202.cpp
 *
 * @brief
 *      1. Input a person first name and last name.
 *      2. Enter this person age.
 *      3. Ouput the longest name and its age.
 *
 * @example
 *      [Input]
 *      Please enter the first name, last name and age.
 *      It will output the longest name.
 *      Enter the first name or press enter to end: Andy
 *      Enter the last name or press enter to end: Liu
 *      Enter Andy's age: 25
 *      Enter the first name or press enter to end: Johny
 *      Enter the last name or press enter to end: Wang
 *      Enter Johny's age: 30
 *      Enter the first name or press enter to end: Jason
 *      Enter the last name or press enter to end: Lin
 *      Enter Jason's age: 24
 *      Enter the first name or press enter to end:
 *      Done!
 *
 *      [Output]
 *      The longest name you entered is:
 *      Johny Wang aged 30.
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Oct. 14, 2020
 *      - Orignial: Dec. 02, 2015
 *
 * @version 2.0.0
 *
 */
#include <iostream>
#include <string>

const size_t MAX_LEN = 100;

/**
 * Output the longest name and its age.
 *
 * @param names [string] An array to store the person names.
 * @param ages [string] An array to store the person ages.
 * @param count [size_t] The number of person store in the array.
 *
 * @return None
 */
void output(std::string names[], std::string ages[], size_t count)
{
    size_t longest(0), i(1);

    if(count == 0)
    {
        std::cout << "There is not any data." << std::endl;
    }
    else
    {
        // Find the longest string
        while(i < count && !names[i].empty())
  	    {
            if(names[i].length() > names[longest].length())
                longest = i;
            i++;
  	    }

        std::cout << std::endl << "The longest name you entered is: "
                  << std::endl
                  << names[longest] + " aged " + ages[longest] + '.'
                  << std::endl;
    }
}

int main(int argc, char *argv[])
{
    // Declare the varialbe
    size_t count = 0;
    std::string names[MAX_LEN];
    std::string ages[MAX_LEN];
    std::string first_name, last_name;

    // User input
    std::cout << "Please enter the first name, last name and age." << std::endl
              << "It will output the longest name." << std::endl;

    for(size_t i = 0 ; i < MAX_LEN ; i++)
    {
        std::cout << "Enter the first name or press enter to end: ";
        getline(std::cin, first_name, '\n');

        if(first_name.empty()) {
            std::cout << "Done!" << std::endl;
            break;
        }

        std::cout << "Enter the last name or press enter to end: ";
        getline(std::cin, last_name, '\n');

        names[i] = first_name + ' ' + last_name;

        std::cout << "Enter " + first_name + "'s age: ";
        getline(std::cin, ages[i], '\n');

        count = i + 1;
    }

    // Logic
    if(count == MAX_LEN)
    {
        std::cout << "No more space to store more names." << std::endl;
    }

    // Output
    output(names, ages, count);

    return EXIT_SUCCESS;
}
