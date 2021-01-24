/**
    @file 10905-12-1.cpp

    @brief
    To print whole the American Standard Code for Information Interchange
    (ASCII) character.

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
        ...
        111 o
        112 p
        113 q
        ...

    @author Jason Lin

    @date
        - Revision: Jan. 23, 2021
        - Orignial: 2012

    @version 2.0.0
**/

#include <iostream>
#include <iomanip>

int
main (
    int argc,
    char *argv[]
    )
{
    const int AsciiCnt = 128;

    for (size_t i = 0; i < AsciiCnt; i++) {
        std::cout << std::setw (3) << i << std::setw (2) << char (i)
                  << std::endl;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
