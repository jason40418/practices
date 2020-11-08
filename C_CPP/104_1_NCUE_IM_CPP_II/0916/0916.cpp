/**
 * @file 0916.cpp
 *
 * @brief
 *      1. Could input a text with space.
 *      2. Remove space with eatspaces().
 *      3. Output the largest and the smallest character.
 *      Hint: Related to ASCII.
 *
 * @example
 *      [Input]
 *          This is a book.
 *      [Output]
 *          Thisisabook.
 *          MAX = T ; MIN = a
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 29, 2020
 *      - Orignial: Sep. 16, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

void eatspaces(char *str);
char compare(char alphatbat[], int type);

// Logic: To remove the text space.
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

// Logic: To compare the largest or smallest character.
// 0: To find largest, 1: To find smallest.
char compare(char alphabat[], int type)
{
    // Start from first character.
    char result = alphabat[0];

    for (int i = 0 ; alphabat[i] != '\0' ; i++)
    {
        // To find largest
        if (type == 0 && alphabat[i] > result)
        {
            result = alphabat[i];
        }
        // To find smallest
        else if (type == 1 && alphabat[i] < result)
        {
            result = alphabat[i];
        }
    }

    return result;
}

// Logic: To find the extrema.
// 0: To find largest, 1: To find smallest.
char extrema(char upper, char lower, int type)
{
    char ext = char();

    // Check if upper or lower is empty
    if (upper == '\0')
    {
        ext = lower;
    }
    else if (lower == '\0')
    {
        ext = upper;
    }
    else
    {
        // Change upper to lower to compare
        if (upper + 32 > lower && type == 0)
            ext = upper;
        else if (type == 0)
            ext = lower;
        else if (upper + 32 <= lower && type == 1)
            ext = upper;
        else if (type == 1)
            ext = lower;
    }

    return ext;
}

int main(int argc, char *argv[])
{

    // Declare the varialbe
    char input[10000];
    char char_upper[10000], char_lower[10000];
    char max_upper, min_upper;
    char max_lower, min_lower;
    int j(0), k(0);

    // User input
    std::cout << "Please enter a text. (At most 10000 character.): ";
    std::cin.getline(input , 10001 ,'\n');

    // Preprocess
    int input_len = strlen(input);
    eatspaces(input);

    for(int i = 0 ; i < input_len ; i++)
    {
        // Upper alphabat
        if (input[i] >= 65 && input[i] <= 90)
        {
            char_upper[j] = input[i];
            j++;
        }

        // Lower alphabat
        else if (input[i] >= 97 && input[i] <= 122)
        {
            char_lower[k] = input[i];
            k++;
        }
        // Non-alphabat
        else
        {
            continue;
        }
    }

    // Logic
    max_upper = compare(char_upper, 0);
    min_upper = compare(char_upper, 1);
    max_lower = compare(char_lower, 0);
    min_lower = compare(char_lower, 1);

    // Output
    std::cout << "Your input: " << input << std::endl;
    std::cout << "MAX = " << extrema(max_upper, max_lower, 0) << " ; ";
    std::cout << "MIN = " << extrema(min_upper, min_lower, 1);

    return EXIT_SUCCESS;
}


