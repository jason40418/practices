/**
 * @file 1007.cpp
 *
 * @brief
 *      1. Make a simple calculator.
 *      2. Only need to identify the ., +, -, *, / only.
 *      3. System would point out the wrong position.
 *          - Before the decimal need a digit.
 *          - Before the expression need a digit.
 *          - Expression could not at first or last place.
 *
 * @example
 *      [Input]
 *          12+16.+
 *
 *      [Output]
 *          ====== Result ======
 *          Arrrgh!*#!! There's an error
 *          12+16.+
 *                ^
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Nov. 07, 2020
 *      - Orignial: Oct. 07, 2015
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
void error(char *str);

int main(int argc, char *argv[])
{

    // Declare the varialbe
    char buffer[MAX_LEN] = {0};

    // User input
    std::cout << "Please enter formula only with + or - or * or /."
              << std::endl;

    // User Input: Formula 1
    std::cout << "Please enter formula: " << std::endl;
    std::cin.getline(buffer, sizeof buffer);
    // Check if not enter anything
    if(!buffer[0])
        return EXIT_SUCCESS;

    // Preprocess & Logic
    // Clean the space part
    eatspaces(buffer);

    // Output
    std::cout << "====== Result ======" << std::endl;
    std::cout << "\t= " << expr(buffer) << std::endl;

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
    while ((*(str + i) = *(str + j++)) != '\0') {
        if (*(str + i) != ' ') {
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
                error(str);
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
        error(str);
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

/**
 * To find the illegal formula position.
 *
 * @param str [pointer of char] A array of string. (User input formula.)
 *
 * @return None
 */
void error(char *str)
{
    char word, prior_word;
    int idx(0), temp(-1);

    // Iteration to print the whole string
    for(idx = 0 ; *(str + idx) != '\0' ; idx++)
    {
        std::cout << *(str + idx);
    }
    std::cout << std::endl;

    idx = 0;
    // Need to identify the space
    while(*(str + idx) != '\0')
    {
        // Get the pointer current character
        word = *(str + idx);

        // If the current character is mathematical operators
        if (word == '+' || word == '-' || word == '*' || word == '/')
        {
            temp = idx;
            temp--;

            // To get the prior character
            while (*(str + temp) == ' ' && temp > 0)
                temp--;

            prior_word = *(str + temp);

            // If prior word is 0-9 or decimal point
            if ((prior_word >= 48 && prior_word <= 57) || prior_word == '.')
            {
                temp = idx;
                temp++;

                // To get the next character
                while (*(str + temp) == ' ' && *(str + temp) != '\0')
                    temp++;

                // If next word is last word
                if (*(str + temp) == '\0')
                    std::cout << "^";
                else
                    std::cout << " ";
            }
            // If the prior word is illegal
            else if (word == '+' || word == '-' || word == '*' || word == '/')
                std::cout << "^";
            // Check the next word is digit
            else
            {
                temp = idx;
                temp++;

                // To get the next character
                while (*(str + temp) == ' ' && *(str + temp) != '\0')
                    temp++;

                // If next character is 0-9
                if (*(str + temp) >= 48 && *(str + temp) <= 57)
                    std::cout << " ";
                else
                    std::cout << "^";
            }
        }
        // If current character is decimal point
        else if (*(str + idx) == '.')
        {
            temp = idx;
            temp--;

            // To get the prior character
            while (*(str + temp) == ' ' && temp > 0)
                temp--;

            // Check if prior character is 0-9
            if (*(str + temp) >= 48 && *(str + temp) <= 57)
                std::cout << " ";
            else
                std::cout << "^";
        }
        // If current character is 0-9
        else if (*(str + idx) >= 48 && *(str + idx) <= 57)
            std::cout << " ";
        // If current character is space
        else if (*(str + idx) == ' ')
            std::cout << " ";
        // Other character identify as illegal character
        else
            std::cout << "^";

        idx++;
    }
    std::cout << std::endl;
}
