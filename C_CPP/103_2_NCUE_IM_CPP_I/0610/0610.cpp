/**
 * @file 0610.cpp
 *
 * @brief Using template to sort and output the given test cases.
 *
 * @test
 *      { 1, 24, 34, 22 }
 *      { 23, 245, 123, 1, 234, 2345 }
 *      { 23.0, 1.4, 2.456, 345.5, 12.0, 21.0 }
 *
 * @example
 *      [Output]
 *           1 22 24 34
 *           1 23 123 234 245 2345
 *           1.4 2.456 12 21 23 345.5
 *
 * @author Jason Lin
 *
 * @date
 *      - Revision: Aug. 29, 2020
 *      - Orignial: Jun. 10, 2015
 *
 * @version 2.0.0
 *
 */

#include <iostream>

template <typename T> T * sort(T data[], size_t len);
template <typename T> void output(T data[], size_t len);

int main() {
    // Testcases
    int small[] = { 1, 24, 34, 22 };
    long medium[] = { 23, 245, 123,1, 234, 2345 };
    double large[] = { 23.0, 1.4, 2.456, 345.5, 12.0, 21.0 };

    // Declare the varialbe
    size_t len_small(sizeof small/sizeof small[0]);
    size_t len_medium(sizeof medium/sizeof medium[0]);
    size_t len_large(sizeof large/sizeof large[0]);

    // Preprocess
    sort(small, len_small);
    sort(medium, len_medium);
    sort(large, len_large);

    // Output
    output(small, len_small);
    output(medium, len_medium);
    output(large, len_large);

    return 0;
}

// Logic: Bubble Sort Template
template <typename T>
T * sort(T data[], size_t len) {
    int i = 0, j = 0;
    T temp = T();

    while (i < len) {
        j = 0;
        while (j < len - 1) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
            j++;
        }
        i++;
    }

    return data;
};

// Logic: Output
template <typename T>
void output(T data[], size_t len) {
    for (int i = 0 ; i < len ; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
};
