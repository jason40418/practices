/**
    @file 10905-8.cpp

    @brief
    Generate a transcript table at least have 13 students and include the
    following subjects/disciplines with certain condition range.
        Chinese   : 50 - 89
        English   : 60 - 99
        Math      : 30 - 90
        Chemistry : 70 - 95
        Geography : 75 - 95
    HINT: Use the rand() with % to fetch spefic range. rand() % (Max-Min) + Max
    Need to make student ID automate increase and calculate each student
    average grades and each subjects average. Meanwhile, also need to know the
    total average.

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
    No.      Name         SID     Chinese     English        Math   Chemistry   Geography     Average
    ====================================================================================================================
     1  Jason                5          69          61          84          89          89        78.4
     2  Jason                6          75          75          67          70          79        73.2
     3  Jason                7          53          78          83          85          92        78.2
     4  Jason                8          64          90          44          86          79        72.6
     5  Jason                9          53          69          83          89          91        77.0
     6  Jason               10          52          74          31          82          89        65.6
     7  Jason               11          84          65          59          81          89        75.6
     8  Jason               12          51          91          86          70          91        77.8
     9  Jason               13          73          61          57          81          77        69.8
    10  Jason               14          84          90          70          70          82        79.2
    11  Jason               15          85          71          70          71          75        74.4
    12  Jason               16          58          61          86          72          93        74.0
    13  Jason               17          72          63          49          93          89        73.2
    ====================================================================================================================
                                      67.2        73.0        66.8        79.9        85.8        74.2

    @author Jason Lin

    @date
        - Revision: Jan. 17, 2021
        - Orignial: 2012

    @version 2.0.0
**/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int
main (
    int argc,
    char *argv[]
    )
{
    char    *Name = "Jason";
    int     StudentCnt (13), No (5);
    int     Chi = 0, Eng = 0, Mat = 0, Che = 0, Geo = 0;
    int     SumChi = 0, SumEng = 0, SumMat = 0, SumChe = 0, SumGeo = 0, Sum = 0.0;
    double  Average = 0.0;

    // set random seed
    srand (time (NULL));

    // Output the header
    std::cout << std::setw (5) << "No." << std::setw (10) << "Name"
              << std::setw (12) << "SID" << std::setw (12) << "Chinese"
              << std::setw (12) << "English" << std::setw (12) << "Math"
              << std::setw(12) << "Chemistry" << std::setw (12) << "Geography"
              << std::setw (12) << "Average" << std::endl;

    for (int i = 0; i <= 120 ; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

    // Ouput each student score
    for (int i = 0 ; i < StudentCnt ; i++) {
        Chi = rand () % (89 - 50 + 1) + 50; // 50-89
        Eng = rand () % (99 - 60 + 1) + 60; // 60-99
        Mat = rand () % (90 - 30 + 1) + 30; // 30-90
        Che = rand () % (95 - 70 + 1) + 70; // 70-95
        Geo = rand () % (95 - 75 + 1) + 75; // 75-95

        Average = (Chi + Eng + Mat + Che + Geo)/5.0;
        Sum += Average;

        SumChi += Chi;
        SumEng += Eng;
        SumMat += Mat;
        SumChe += Che;
        SumGeo += Geo;

        std::cout << std::right << std::setw (3) << i + 1 << "  "
                  << std::left << std::setw (10) << Name
                  << std::right << std::setw (12) << No++
                  << std::right << std::setw (12) << Chi
                  << std::right << std::setw (12) << Eng
                  << std::right << std::setw (12) << Mat
                  << std::right << std::setw (12) << Che
                  << std::right << std::setw (12) << Geo
                  << std::right << std::setw (12) << std::fixed
                  << std::setprecision(1) << Average << std::endl;
    }

    for (int i = 0; i <= 120 ; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

    // Output the summary
    std::cout << std::setw (39) << std::fixed
              << std::setprecision (1) << SumChi/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumEng/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumMat/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumChe/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumGeo/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << Sum/(double)StudentCnt << std::setw (12) << std::fixed
              << std::endl;

    return EXIT_SUCCESS;
}
