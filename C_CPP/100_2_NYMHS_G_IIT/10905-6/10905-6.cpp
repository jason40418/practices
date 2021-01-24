/**
    @file 10905-6.cpp

    @brief
    Practice for standard output ("std::cout" "std::endl") and use
    the escape character (include "\t" "\n" "\r").
    std::cout - to do the ouput to standad output
    std::endl - break new line
    "\t": tab
    "\n": linefeed
    "\r": carriage return

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
        - Revision: Jan. 17, 2021
        - Orignial: 2012

    @version 2.0.0
**/

#include <iostream>

int
main (
    int argc,
    char *argv[]
    )
{
    std::cout << "Class\\109\t"
              << "No: 05\t"
              << "\tName: Jason Lin\n"
              << std::endl;
    std::cout << std::endl
              << "Address: No.8, Deshou Street,Taoyuani Dist.,"
              << "Taoyuan City 330, Taiwan(R.O.C.)\n";
    std::cout << "Gradtute from: Taoyuan Municipal"
              << "Ching-Hsi Junior High School\n";
    std::cout << "Marital Status: Single\n";

    std::cout << "Self-introduction: None\n";
    std::cout << "Specialty: "
              << "Have, Microsfot Office Series and web design\n"
              << "Have, PowerPoint design\n"
              << "Have, Video editing\n"
              << "Have, Web editing\n";

    std::cout << std::endl << "Joke: \n";
    std::cout << "Police arrested two kids yesterday,\n"
              << "one was drinking battery acid,\n"
              << "the other was eating fireworks.\n"
              << "They charged one - and let the other one off.\n\n\n";

    return EXIT_SUCCESS;
}
