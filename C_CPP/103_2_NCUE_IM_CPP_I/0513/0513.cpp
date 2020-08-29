/**
 * @file 0513.cpp
 *
 * @brief Input a text, it would output the reverse result.
 *
 * @example
 *      [Input]
 *             Taiwan
 *      [Output]
 *             nawiaT
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 27, 2020
 *      - Orignial: May. 13, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

int main() {
    // Declare the varialbe
    const int MAX_LEN(10000);
    int text_len = 0;
    char text[MAX_LEN];

    // Preprocess
    std::cout << "Please enter the text, it would reverse." << std::endl;
    std::cout << "Your text: ";
    std::cin.getline(text, MAX_LEN + 1, '\n');

    // Logic
    // Caculate the vaild array length
    while(text[text_len]) {
        text_len++;
    }

    // Output
    for (int i = text_len - 1 ; i >= 0 ; i--) {
        std::cout << text[i];
    }

    return 0;
}
