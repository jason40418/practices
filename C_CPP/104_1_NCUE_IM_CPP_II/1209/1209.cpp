/**
 * @file 1209.cpp
 *
 * @brief
 *      1. Input a series of string.
 *      2. Sort the alphabet character with ASCII code order.
 *      3. Would ouput the illegal character.
 *
 * @example
 *      [Input]
 *      C language is a good programming language.
 *
 *      [Output]
 *        is not an alphabet character
 *        is not an alphabet character
 *        is not an alphabet character
 *        is not an alphabet character
 *        is not an alphabet character
 *        is not an alphabet character
 *      . is not an alphabet character
 *      Result: Caaaaaadeegggggggiillmmnnnoooprrsuunguage.
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Nov. 08, 2020
 *      - Orignial: Dec. 02, 2015
 *
 * @version 2.0.0
 *
 */
#include <iostream>
#include <string>

#define MAX_LEN 100

char *sort(char *strings, size_t count)
{
    char temp;
    bool swapped(false);

    while (true)
    {
        for (size_t i = 0; i < count - 1; i++)
        {
            if (strings[i] > strings[i + 1])
            {
                swapped = true;
                temp = strings[i];
                strings[i] = strings[i + 1];
                strings[i + 1] = temp;
            }
        }
        if (!swapped)
            break;
        swapped = false;
    }

    return strings;
}

char *combine(char *upper, char *lower, char *strings)
{
    size_t i(0), x(0), y(0);
    while (x < strlen(upper))
    {
        strings[i] = upper[x];
        i++;
        x++;
    }

    while (y < strlen(lower))
    {
        strings[i] = lower[y];
        i++;
        y++;
    }

    return strings;
}

int main(int argc, char *argv[])
{
    // Declear variable
    const size_t MAX_STR_LEN = MAX_LEN;

    char strings[MAX_STR_LEN] = {'\0'};     // Record user input
    char upper[MAX_STR_LEN] = {'\0'};       // Record upper alphabet
    char lower[MAX_STR_LEN] = {'\0'} ;      // Record lower alphabet
    size_t x(0), y(0);

    // User Input
    std::cout << "Please enter a series string (at most 100): " << std::endl;
    std::cin.getline(strings, MAX_STR_LEN, '\n');

    // Logic
    // Check if at least one character
    if (strlen(strings) == 0)
    {
        std::cout << "You do not enter any character!" << std::endl;
    }
    else
    {
        // Identify the character is upper or lower alphabet
        for (size_t i = 0 ; i < strlen(strings) ; i++)
        {
            // Upper alphabet character
            if (strings[i] >= 65 && strings[i] <= 90)
            {
                upper[x] = strings[i];
                x++;
            }
            // Lower alphabet character
            else if (strings[i] >= 97 && strings[i] <= 122)
            {
                lower[y] = strings[i];
                y++;
            }
            else
            {
                std::cout << strings[i] << " is not an alphabet character"
                          << std::endl;
            }
        }
    }
    // Sort the array of characters
    sort(upper , strlen(upper));
	sort(lower , strlen(lower));
    combine(upper , lower , strings);

    // Output
    std::cout << "Result: "
              << strings
              << std::endl;

    return EXIT_SUCCESS;
}
