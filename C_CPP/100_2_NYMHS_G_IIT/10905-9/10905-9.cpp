/**
    @file 10905-9.cpp

    @brief
    Generate a transcript table at least have 13 students and use the 1D array
    to store the necessary information.
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
      No.                Name         SID     Chinese     English        Math   Chemistry   Geography     Average
    ====================================================================================================================
     0  Jason Lin                      5          66          74          56          89          88        74.4
     1  Ashton Thompson                1          66          81          63          48          86        76.4
     2  Oliver Turner                  2          65          70          45          44          64        61.6
     3  Ashton King                   16          86          70          87          82          88        83.8
     4  Josh Woods                     4          82          59          50          58          62        63.0
     5  Summer Dawson                  6          66          63          33          33          65        58.4
     6  Eva Watts                      7          60          79          61          82          74        69.6
     7  Sienna Newman                 37          69          58          76          56          76        71.0
     8  Abbie Wilson                   9          60          57          67          32          76        67.2
     9  Poppy Perry                   12          68          83          57          87          64        67.2
    10  Journee Farmer                40          56          49          42          44          72        58.2
    11  Saniya Harrell                41          88          85          70          50          80        80.6
    12  Jamari Hood                   13          80          71          44          43          64        64.6
    ====================================================================================================================
                                                70.2        69.2        57.8        57.5        73.8        68.5

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
    // Total number of students
    const int StudentCnt = 13;

    // Student's name
    char *Student[StudentCnt] = {
        "Jason Lin", "Ashton Thompson", "Oliver Turner", "Ashton King",
        "Josh Woods", "Summer Dawson", "Eva Watts", "Sienna Newman",
        "Abbie Wilson", "Poppy Perry", "Journee Farmer", "Saniya Harrell",
        "Jamari Hood"
    };

    // Student's seat ID
    char *SeatId[StudentCnt] = {
        "5", "1", "2", "16", "4", "6", "7",
        "37", "9", "12", "40", "41", "13"
    };

    // Score
    int ScoreChi[StudentCnt] = { 66, 66, 65, 86, 82, 66, 60, 69, 60, 68, 56, 88, 80 };
    int ScoreEng[StudentCnt] = { 74, 81, 70, 70, 59, 63, 79, 58, 57, 83, 49, 85, 71 };
    int ScoreMat[StudentCnt] = { 56, 63, 45, 87, 50, 33, 61, 76, 67, 57, 42, 70, 44 };
    int ScoreChe[StudentCnt] = { 89, 48, 44, 82, 58, 33, 82, 56, 32, 87, 44, 50, 43 };
    int ScoreGeo[StudentCnt] = { 88, 86, 64, 88, 62, 65, 74, 76, 76, 64, 72, 80, 64 };

    // Variable to deal with data process
    int SumChi = 0, SumEng = 0, SumMat = 0, SumChe = 0, SumGeo = 0, Sum = 0.0;
    double Average = 0.0;

    // Output the header
    std::cout << std::setw (5) << "No." << std::setw (20) << "Name"
              << std::setw (12) << "SID" << std::setw (12) << "Chinese"
              << std::setw (12) << "English" << std::setw (12) << "Math"
              << std::setw(12) << "Chemistry" << std::setw (12) << "Geography"
              << std::setw (12) << "Average" << std::endl;

    for (int i = 0; i <= 120 ; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

    // Ouput each student score
    for (int i = 0; i < StudentCnt; i++) {
        SumChi += ScoreChi[i];
        SumEng += ScoreEng[i];
        SumMat += ScoreMat[i];
        SumChe += ScoreChe[i];
        SumGeo += ScoreGeo[i];
        Average = (ScoreChi[i] + ScoreEng[i] + ScoreMat[i] + ScoreGeo[i] + ScoreGeo[i])/5.0;
        Sum += Average;

        std::cout << std::right << std::setw (3) << i << "  "
                  << std::left << std::setw (20) << Student[i]
                  << std::right << std::setw (12) << SeatId[i]
                  << std::right << std::setw (12) << ScoreChi[i]
                  << std::right << std::setw (12) << ScoreEng[i]
                  << std::right << std::setw (12) << ScoreMat[i]
                  << std::right << std::setw (12) << ScoreChe[i]
                  << std::right << std::setw (12) << ScoreGeo[i]
                  << std::right << std::setw (12) << std::fixed
                  << std::setprecision(1) << Average << std::endl;
    }

    for (int i = 0; i <= 120 ; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

    // Output the summary
    std::cout << std::setw (49) << std::fixed
              << std::setprecision (1) << SumChi/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumEng/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumMat/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumChe/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << SumGeo/(double)StudentCnt << std::setw (12) << std::fixed
              << std::setprecision (1) << Sum/(double)StudentCnt << std::setw (12) << std::fixed
              << std::endl;

    return EXIT_SUCCESS;
}
