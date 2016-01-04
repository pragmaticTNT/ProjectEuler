#include <algorithm>
#include <array>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

#include "Question.h"

#ifndef SOLUTION_H
#define SOLUTION_H
class Solution{
    public:
        Solution();
        ~Solution();
		/**
		 * @summary Shows grid of solved and unsolved questions 
		 * @param	(None)
		 * @return	(None)
		*/
        void showStatus();
		/**
		 * @summary Shows question statement and solution (if solved) 
		 * @param	- question index (int): if index invalid nothing happens 
		 * @return	(None)
		*/
        void showQuestion(int);
		/**
		 * @return	Size of question list (int): question 1~size tracked
		*/
		int size();

    private:
        std::vector<Question*> questions;
        std::string qFileName;	// questions name and descriptions .txt file
        int cellPerLine;
        int charPerCell;		// use an odd number
		std::vector<int> primesList;
		long long int primesListLowerBound;

		// ---> Calculate and Save Solutions <---
        long long int getSolution(int);
        void populate();

		// ---> Showing Questions Grid <---
		bool isValidIndex(int);
		void displayBoundary(int);
		void displayIndex(int);
		void displayLine(int&, int);
		void addSpaces(int);
		int digitsInInt(int);
		

        // ===> HELPER FUNCTIONS <===
		/**
		 * @summary	Sums all the multiples of the base less than the 
					indicated bound. E.g.
						sumMultiplesLT(3, 12) => 3 + 6 + 9 = 18
					RunTime: O(1)
		 * @param	- Base (int): non-zero 
					- Bound (int): positive integers 
		 * @return	The aforementioned sum.
		*/
        int sumMultiplesLT(int, int);
		/**
		 * @summary Given a string - must be a string, in particular 
					ints must be cast - is a palindrome? E.g.
						isPalindrome("1234321") => true
					RunTime: O(length of string)
		 * @param	- str (string): string to check 
		 * @return	whether string is a palindrome (bool)
		*/        
		bool isPalindrome(std::string);
		/**
		 * @summary	Adds all primes between the upper and lower bound
					to an int vector (generally primesList, in which
					case primesListLowerBound keeps track of the next
					lower bound to use). 
		 * @param	- Lower bound (int): starts search, inclusive
					- Upper bound (int): ends search, inclusive
					- Primes (vector reference)
		 * @return	(None): all primes added to vector
		*/		
		void primesBT(int, int, std::vector<int>&);
		long long int nChooseR(int, int);
		int lengthCollatzSeq(int*, int, int);
		
		std::vector<std::string> splitLine(const std::string, char delim);
		void parseFile(std::string, std::vector<std::string>&);
		void parseFile(std::string, std::vector<std::vector<int> >&);


        // ===> SOLUION FUNCTIONS <===
        long long int multiplesOf3And5();
		long long int evenFibonacciNumbers();
		long long int largestPrimeFactor();
		long long int largestPalindromeProduct();
		long long int smallestMultiple();
		long long int sumSquareDifference();
		long long int tenThousandFirstPrime();
		long long int largestProductInSeries();
		long long int specialPythagoreanTriple();
		long long int summationOfPrimes();
		long long int largestProductInGrid();
		long long int highlyDivisibleTriangleNum();
		long long int largeSum();
		long long int longestCollatzSeq();
		long long int latticePaths();
		long long int powerDigitSum();
		long long int numberLetterCounts();
		long long int maxPathSum1();
		long long int countingSundays();
		long long int factorialDigitSum();
		long long int amicableNumbers();
		long long int nameScores();
		long long int nonabundantSums();
		long long int lexicographicPermutations();
		long long int oneThousandDigitFibNumber();
};

#endif
