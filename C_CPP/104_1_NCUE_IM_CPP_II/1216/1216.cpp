/**
 * @file 1216.cpp
 *
 * @brief
 *      1. Input a series of word.
 *      2. Calculate the word frequence.
 *      3. Sort by the count of alphabat then the alphabetical order.
 *
 * @example
 *      [Input]
 *          Lorem Ipsum is simply dummy text of the printing and
 *          typesetting industry. Lorem Ipsum has been the industry's
 *          standard dummy text ever since the 1500s, when an unknown
 *          printer took a galley of type and scrambled it to make
 *          a type specimen book. It has survived not only five
 *          centuries, but also the leap into electronic typesetting,
 *          remaining essentially unchanged. It was popularised in the
 *          1960s with the release of Letraset sheets containing Lorem
 *          Ipsum passages, and more recently with desktop publishing
 *          software like Aldus PageMaker including versions of
 *          Lorem Ipsum.
 *      [Output]
 *          a            2
 *          It           2
 *          an           1
 *          in           1
 *          is           1
 *          it           1
 *          of           4
 *          to           1
 *          and          3
 *          ...
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Oct. 14, 2020
 *      - Orignial: Dec. 16, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>
#include <iomanip>
#include <tuple>
#include <string>

#define MAX_INPUT_LEN (100);

const size_t MAX_LEN = MAX_INPUT_LEN;
const std::string SEPARATORS = " \".,:;!?()\n";

/**
 * To split the text to word.
 *
 * @param  text [string] A series of words. (User input text.)
 * @param  words [string] An array of string to store.
 *
 * @return [tuple<size_t, size_t>] To return the number of word and max width.
 */
std::tuple<size_t, size_t> slice(std::string text, std::string *words)
{
    // Offset: To store the current query location
    std::string word;
    size_t start(0), end(0), offset(0);
    size_t n_word(0);
    size_t max_width(0);

    while (true)
    {
        // Find the split word start location
        start = text.find_first_not_of(SEPARATORS, offset);
        if (std::string::npos == start)
        {
            break;
        }
        offset = start + 1;

        // Find the split word end location
        end = text.find_first_of(SEPARATORS, offset);
        if (std::string::npos == end)
        {
            offset = end;
            end = text.length();
        }
        else
        {
            offset = end + 1;
        }

        // Store the word into array
        word = text.substr(start, end - start);
        words[n_word] = word;

        // Calculate the longest word length
        if (max_width < word.length())
            max_width = word.length();

        // Check if not find the word
        if (std::string::npos == offset)
            break;

        // Check if the word is up to limit
        if (++n_word == MAX_LEN)
        {
            std::cout << std::endl
                      << "Maximum number of words reached." << std::endl
                      << "Processing what we have." << std::endl;
            break;
        }
    }

    return std::make_tuple(n_word, max_width);
}

/**
 * Use the swap sort to sort the word order with alphabetical.
 *
 * @param strings [string] An array of string to store.
 * @param count [size_t] The number of the words in array.
 *
 * @return None
 */
void sort(std::string *strings, size_t count)
{
    bool swapped(false);

    while (true)
    {
        for (size_t i = 0; i < count - 1; i++)
        {
            // Check if the length of string larger than next one
            if (strings[i].size() > strings[i + 1].size())
            {
                swapped = true;
                strings[i].swap(strings[i + 1]);
            }
            // If the two string size is same
            else if (strings[i].size() == strings[i + 1].size())
            {
                // Compare the two string capital word
                if (strings[i] > strings[i + 1])
                {
                    swapped = true;
                    strings[i].swap(strings[i + 1]);
                }
            }
        }
        if (!swapped)
            break;
        swapped = false;
    }
}

/**
 * To format the output result.
 *
 * @param n_word [size_t] Number of the word.
 * @param max_width [size_t] The most long length word in array.
 * @param words [string] An array of string to store.
 *
 * @return None
 */
void output(size_t n_word, size_t max_width, std::string *words)
{
    size_t count(0);

    for(size_t i = 0 ; i < n_word ; i++) {
        // Check if a new word to count
        if (count == 0) count = 1;

        // Check if the word is the same as the prior or the last word
        if(i < n_word-1 && words[i] == words[i+1])
        {
            ++count;
            continue;
        }

        // Output the result
        std::cout << std::setiosflags(std::ios::left)
                  << std::setw(max_width + 2) << words[i];
        std::cout << std::resetiosflags(std::ios::right)
                  << std::setw(5) << count << std::endl;
        count = 0;
    }
}

int main(int argc, char *argv[])
{
    // Declare the varialbe
    std::string text;
    std::string words[MAX_LEN];
    size_t n_word(0), max_width(0);
    std::tuple<int, int> result;

    // User input
    std::cout << "Enter a series lines of text." << std::endl
              << "Finish the input with an asterisk (*):" << std::endl;
    getline(std::cin, text, '*');

    // Logic
    result = slice(text, words);
    n_word = std::get<0>(result);
    max_width = std::get<1>(result);
    sort(words, n_word);

    // Output
    output(n_word, max_width, words);

    return EXIT_SUCCESS;
}
