/**
 * @file 0506.cpp
 *
 * @brief Input three integers to find minimun and maximun.
 *        Output the number and the memory address.
 *
 * @example
 *      [Input]
 *             78 12 15
 *      [Output]
 *             1st number: 78  Address = 0000002A95CFFCF4
 *             2nd number: 12  Address = 0000002A95CFFCF8
 *             3rd number: 15  Address = 0000002A95CFFCF0
 *             Max. number: 78  Address = 0000002A95CFFCF4
 *             Min. number: 12  Address = 0000002A95CFFCF8
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 27, 2020
 *      - Orignial: May. 06, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

int main() {
    // Declare the varialbe
    int num_1, num_2, num_3 = int();
    int *max, *min;

    // Preprocess
    std::cout << "Please enter three interger number."
              << " Sperate the different number with space."
              << std::endl;
    std::cin >> num_1 >> num_2 >> num_3;

    // Logic
    // Point to the input memory location
    int *x1,*x2,*x3;
    x1 = &num_1;
    x2 = &num_2;
    x3 = &num_3;

    max = x1;
    if (*x2 > *max)
        max = x2;
    if (*x3 > *max)
        max = x3;

    min = x1;
    if (*x2 < *min)
        min = x2;
    if (*x3 < *min)
        min = x3;

    // Output
    std::cout << "1st number: " << std::dec << num_1
              << "  Address = " << std::hex << &num_1 << std::endl;
    std::cout << "2nd number: " << std::dec << num_2
              << "  Address = " << std::hex << &num_2 << std::endl;
    std::cout << "3rd number: " << std::dec << num_3
              << "  Address = " << std::hex << &num_3 << std::endl;
    std::cout << "Max. number: " << std::dec << *max
              << "  Address = " << std::hex << max << std::endl;
    std::cout << "Min. number: " << std::dec << *min
              << "  Address = " << std::hex << min << std::endl;

    return 0;
}
