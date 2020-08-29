/**
 * @file 0603.cpp
 *
 * @brief Input two numbers to calculate the greatest common divisor
 *        (GCD). Sperate the number with space.
 *
 * @example
 *      1. [Input]
 *             12 24
 *         [Output]
 *             GCD: 12
 *      2. [Input]
 *             63 33
 *         [Output]
 *             GCD: 3
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 29, 2020
 *      - Orignial: Jun. 03, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

int gcd(int x, int y);

int main() {
    // Declare the varialbe
    int num_1, num_2 = int();

    std::cout << "Please enter an integer number: ";
    std::cin >> num_1 >> num_2;

    // Preprocess
    int gcdNum = gcd(num_1, num_2);

    // Output
    std::cout << "Your input: " << num_1 << " " << num_2 << std::endl;
    std::cout << "GCD: " << gcdNum << std::endl;

    return 0;
}

// Logic: Euclidean Algorithm (Division Algorithm)
int gcd(int x, int y) {
    int large_num = std::max(x, y);
    int small_num = std::min(x, y);

    if (small_num == 0) {
        return large_num;
    }
    else {
        return gcd(y, x % y);
    }
}
