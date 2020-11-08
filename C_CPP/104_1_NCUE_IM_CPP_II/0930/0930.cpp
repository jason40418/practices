/**
 * @file 0930.cpp
 *
 * @brief
 *      1. Make a simple calculator.
 *      2. Only need to identify the ., +, -, *, / only.
 *      3. User could input two formula.
 *      4. Output would calculate the add and substract result.
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
 *      - Revision: Nov. 07, 2020
 *      - Orignial: Sep. 30, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <limits>
#include <cstdlib>                      // For the exit() function
#include <cctype>                       // For the isdigit() function

#define MAX_LEN 80

void eatspaces(char *str);              // Function to remove the blank space
double expr(char *str);                 // Function evaluating an expression
double term(char *str, int &index);     // Function analyzing a term
double number(char *str, int &index);   // Function to recognize a number

int main(int argc, char *argv[])
{

    // Declare the varialbe
    char buffer_1[MAX_LEN] = {0};
    char buffer_2[MAX_LEN] = {0};
    double result_1(0.0), result_2(0.0);

    // User input
    std::cout << "Please enter two formula only with + or - or * or /."
              << "It will calculate the add and subtract."
              << std::endl;

    // User Input: Formula 1
    std::cout << "Please enter 1st formula: " << std::endl;
    std::cin.getline(buffer_1, sizeof buffer_1, '\n');
    // Check if not enter anything
    if(!buffer_1[0])
        return EXIT_SUCCESS;

    // Reset the input error flag
    std::cin.clear();
    // Clean the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // User Input: Formula 2
    std::cout << "Please enter 2nd formula: " << std::endl;
    std::cin.getline(buffer_2, sizeof buffer_2, '\n');
    if(!buffer_2[0])
        return EXIT_SUCCESS;

    // Preprocess
    // Clean the space part
    eatspaces(buffer_1);
    eatspaces(buffer_2);

    // Logic
    result_1 = expr(buffer_1) + expr(buffer_2);
    result_2 = expr(buffer_1) - expr(buffer_2);

    // Output
    std::cout << "Buffer_1 + Buffer_2: " << result_1 << std::endl;
    std::cout << "Buffer_1 - Buffer_2: " << result_2 << std::endl;

    return EXIT_SUCCESS;
}

/**
 * Remove the input text space.
 *
 * @param str [pointer of char] A array of characters.
 *
 * @return None
 */
void eatspaces(char *str)
{
    int i(0), j(0);

    // pointer + offset
    while ((*(str + i) = *(str + j++)) != '\0')
    {
        if (*(str + i) != ' ')
        {
            // if it not space, need to add one
            i++;
        }
    }
}

/**
 * Read a series of term, separate with expression and decimal.
 *
 * @param str [pointer of char] A array of string. (User input formula.)
 *
 * @return value [double] Calculate the formula result.
 */
double expr(char *str)
{
    double value(0.0);
    int index(0);

    value = term(str, index);

    // Iteration the whole string
    for(;;)
    {
        // Choose action based on current character
        switch(*(str + index++))
        {
            // Touch the end of the string
            case '\0':
                return value;
            case '+':
                value += term(str, index);
                break;
            case '-':
                value -= term(str, index);
                break;
            default:
                std::cout << std::endl
                          << "Arrrgh!*#!! There's an error"
                          << std::endl;
                exit(EXIT_FAILURE);
        }
    }
}

/**
 * To calculate the multiply or divide part.
 *
 * @param str [pointer of char] A array of string. (User input formula.)
 * @param index [pointer of int] Record current read index location.
 *
 * @return value [double] The current cumulate value in this part.
 */
double term(char *str, int &index)
{
    double value(0.0);

    // Get the first number in term
    value = number(str, index);

    // To find the operator if it is multiply or divide
    while(true)
    {
        if(*(str + index) == '*')
            value *= number(str, ++index);
        else if(*(str + index) == '/')
            value /= number(str, ++index);
        else
            break;
    }

    return value;
}

/**
 * Read the value from the string.
 *
 * @param str [pointer of char] A array of string. (User input formula.)
 * @param index [pointer of int] Record current read index location.
 *
 * @return value [double] The current number in this part.
 */
double number(char *str, int &index)
{
    double value(0.0), factor(1.0);

    // Check if here has one digit at least
    if(!isdigit(*(str + index)))
    {
        std::cout << std::endl
                  << "Arrrgh!*#!! There's an error"
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    // Calculate the number
    while(isdigit(*(str + index)))
        value = 10 * value + (*(str + index++) - '0');

    // If the input is not number, check if it is decimal
    if(*(str + index) != '.')
        return value;

    while(isdigit(*(str + (++index))))
    {
        factor *= 0.1;
        value = value + (*(str + index) - '0') * factor;
    }

    return value;
}
