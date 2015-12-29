#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Question.h"

#ifndef SOLUTION_H
#define SOLUTION_H
class Solution{
    public:
        Solution();
        ~Solution();
        void displayStatus();
        void showQuestion(int);
		int size();

    private:
        std::vector<Question*> questions;
        std::string qFileName;
        int cellPerLine;
        int charPerCell;	// use an odd number

        int getSolution(int);
        void populate();
		bool validIndex(int);
		void displayBoundary(int);
		void displayIndex(int);
		void displayLine(int&, int);
		void addSpaces(int);
		int digitsInInt(int);

        // ===> HELPER FUNCTIONS <===
        int sumMultLT(int, int);
        bool isPalindrome(std::string);

        // ===> SOLUION FUNCTIONS <===
        int multiplesOf3And5();
		int evenFibonacciNumbers();
		int largestPrimeFactor();
		int largestPalindromeProduct();
		int smallestMultiple();
		int sumSquareDifference();
};

#endif
