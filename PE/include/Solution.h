#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Question.h"

#ifndef SOLUTION_H
#define SOLUTION_H

class Solution{
    public:
        Solution();
        ~Solution();
        void displayStatus();
        void solve(int);

    private:
        std::vector<Question*> questions;
        std::string qFileName = "questionList.txt";
        int maxCellPerLine = 15;
        int digitsPerCell  = 3;

        void populate();
        void setSolution(int);

        // Helper functions
        int sumMultLT(int, int);
        bool isPalindrome(std::string);

        // All the rest of the solution function
        int multiplesOf3And5();
};

#endif // SOLUTION_H
