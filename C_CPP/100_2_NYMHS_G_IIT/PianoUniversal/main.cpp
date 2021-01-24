/**
    @file main.cpp

    @brief
    Use the Windows API to beep from Do to Si.
    (Project build from Dev-C++ 5.8.2 with GCC)

    @copyright
    Copyright (C) 2012 - 2021 Jason Lin <jason40418>.

    MIT License

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.

    @example
        N/A

    @author Jason Lin

    @date
        - Revision: Jan. 23, 2021
        - Orignial: 2012

    @version 2.0.0
**/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#define CAX 1048
#define DAX 1179
#define EAX 1310
#define FAX 1441
#define GAX 1572
#define AAX 1703
#define BAX 1834

int
main (
    int argc,
    char *argv[]
    )
{
    const int DURATION = 100;
    int input = 0;

    Beep (GAX, DURATION);
    Beep (FAX, DURATION);
    Beep (EAX, DURATION);
    Beep (DAX, DURATION);
    Beep (EAX, DURATION);
    Beep (CAX, DURATION);
    Beep (EAX, DURATION);
    Beep (DAX, DURATION);

    std::cout << "**********************************************" << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"Z\" or \"z\" to beep Do." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"X\" or \"x\" to beep Re." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"C\" or \"c\" to beep Mi." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"V\" or \"v\" to beep Fa." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"B\" or \"b\" to beep So." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"N\" or \"n\" to beep La." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"M\" or \"m\" to beep Si." << std::endl;
    std::cout << "*" << std::setw (8) << " Press \"space\" to exit." << std::endl;
    std::cout << "**********************************************" << std::endl;

    while ( (input = getch ()) != 0x20 ) {
        switch (input) {
            case 'Z':
            case 'z': {
                Beep (CAX, DURATION);
                std::cout << "Do ";
                break;
            }
            case 'X':
            case 'x': {
                Beep (DAX, DURATION);
                std::cout << "Re ";
                break;
            }
            case 'C':
            case 'c': {
                Beep (EAX, DURATION);
                std::cout << "Mi ";
                break;
            }
            case 'V':
            case 'v': {
                Beep (FAX, DURATION);
                std::cout << "Fa ";
                break;
            }
            case 'B':
            case 'b': {
                Beep (GAX, DURATION);
                std::cout << "So ";
                break;
            }
            case 'N':
            case 'n': {
                Beep (AAX, DURATION);
                std::cout << "La ";
                break;
            }
            case 'M':
            case 'm': {
                Beep (BAX, DURATION);
                std::cout << "Si ";
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}

