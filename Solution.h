#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> stoi(s.c_str(),0,10);
#include "Question.h"

#ifndef __SOLUTION_H_INCLUDED__
#define __SOLUTION_H_INCLUDED__

class Solution{
    std::vector<Question*> questions;
    std::string qFileName = "questionList.txt";
    int maxCellPerLine = 15;
    int digitsPerCell  = 3;

    void populate();
    void setSolution(int);

    // All the rest of the solution function
    int multiplesOf3And5();

public:
    Solution();
    void displayStatus();
    void solve(int);
};

#endif

/***
 --- --- --- ---
| 1 | 2 | 3 | X |
 --- --- --- ---
 ***/

