#ifndef TIME_H // include guard
#define TIME_H

#include <iostream>
#include <limits>

namespace time
{
    class Time
    {
        public:
            explicit Time()
            {
                hour = 0;
                minute = 0;
                second = 0;
            }
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

            int get_hour()
            {
                return hour;
            }

            int get_minute()
            {
                return minute;
            }

            int get_second()
            {
                return second;
            }

            Time operator + (const Time &another_time) const;
	        Time operator - (const Time &another_time) const;

        private:
            int hour;
            int minute;
            int second;
    };

    time::Time time::Time::operator + (const Time &another_time) const
    {
        Time result;

        // Calculate the second
        result.second = this -> second + another_time.second;
        while(result.second >= 60)
        {
            result.minute++;
            result.second %= 60;
        }

        // Calculate the minute
        result.minute = result.minute + this -> minute + another_time.minute;
        while(result.minute >= 60)
        {
            result.hour++;
            result.minute %= 60;
        }

        // Calculate the hour
        result.hour = result.hour + this -> hour + another_time.hour;

        return result;
    }

    time::Time time::Time::operator - (const Time & another_time) const
    {
        Time result;

        // Calculate the second
        result.second = this -> second - another_time.second;
        while(result.second < 0)
        {
            result.minute--;
            result.second += 60;
        }

        // Calculate the minute
        result.minute = result.minute + this -> minute - another_time.minute;
        while(result.minute < 0)
        {
            result.hour--;
            result.minute += 60;
        }

        // Calculate the hour
        result.hour = result.hour + this -> hour - another_time.hour;

        return result;
    }
}

#endif
