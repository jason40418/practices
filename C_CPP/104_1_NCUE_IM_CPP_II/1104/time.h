#ifndef TIME_H // include guard
#define TIME_H

#include <iostream>
#include <limits>

namespace time
{
    class Time
    {
        public:
            void input()
            {
                std::cout << "Please enter the \"Hour\": ";
                hour = get_input(true);
                std::cout << "Please enter the \"Minute\": ";
                minute = get_input(false);
                std::cout << "Please enter the \"Second\": ";
                second = get_input(false);
            }

            int get_input(bool is_hour)
            {
                const size_t MAX_INT_LEN(10);
                char input[MAX_INT_LEN];
                int value = int();

                while(true)
                {
                    std::cin.getline(input, 11, '\n');

                    // Transfer the array of string to int
                    value = atoi(input);

                    if (std::cin.fail())
                    {
                        std::cout << "Please input the integer number only!" << std::endl;

                        // Reset the input error flag
                        std::cin.clear();
                        // Clean the input buffer
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (is_hour)
                    {
                        if(value >= 0 && value <= 23) {
                            break;
                        }
                        else {
                            std::cout << "The range of the number is 0-23!" << std::endl;
                        }
                    }
                    else
                    {
                        if(value >= 0 && value <= 59) {
                            break;
                        }
                        else {
                            std::cout << "The range of the number is 0-59!" << std::endl;
                        }
                    }

                    std::cout << "Re-enter the number: ";
                }

                return value;
            }

            int duration()
            {
                const int HOUR_SECOND = 60 * 60;
                const int MINUTE_SECOND = 60;
                int total;
                total = hour * HOUR_SECOND + minute * MINUTE_SECOND + second;
                return total;
            }

        private:
            int hour;
            int minute;
            int second;
    };
}

#endif
