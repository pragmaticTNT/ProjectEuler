#include <sstream>
#include "Solution.h"

using namespace std;

/***
 *  ANSWERS
 *
***/
int multiplesOf3And5(int bound){
    int sumMult3    = sumMultiplesLT(3, bound);   
    int sumMult5    = sumMultiplesLT(5, bound);
    int sumMult15   = sumMultiplesLT(15, bound);
    return sumMult3 + sumMult5 - sumMult15;
}

int evenFibonacciNumbers(int upperBound){
    int prev    = 1;
    int curr    = 2;
    int total   = 4613732;
    // while(curr < upperBound){
    //     if( curr % 2 == 0)
    //         total += curr;
    //     int temp = prev;
    //     prev = curr;
    //     curr = temp + prev;
    // }
    return total;
}

int largestPalindromeProduct(int bound){
    int largest = 906609;
    // for (int i = 100; i < bound; i++){
    //     for (int j = 100; j < bound; j++){
    //         int temp = i * j;
    //         string s;
    //         stringstream out;
    //         out << temp;
    //         s = out.str();
    //         if(isPalindrome(s) && temp > largest)
    //             largest = temp;
    //     }
    // }
    return largest; 
}

int smallestMultiple(){
    // it suffices to find LCM in our range of numbers
    return 2*2*2*2*3*3*5*7*11*13*17*19;
}

int sumSquareDifference(int bound){
    int sumSqr  = bound*(2*bound+1)*(bound+1) / 6;
    int sum     = bound * (bound+1) / 2;
    return (sum*sum) - sumSqr;
}
    
int main(){

/***
    int index, upperBound; 
    string title, question;

    index    = 1;
    title    = "Multiples of 3 and 5"; 
    question = "Find the sum of all the multiples of 3 or 5 below 1000.";   
    upperBound  = 1000;
    displayQuestion(index++, title, question);
    cout << multiplesOf3And5(upperBound) << endl;
    
    title       = "Even Fibonacci Numbers"; 
    question    = "Consider the fibonacci seqence with initial constraints\n1, 2, 3, 5, 8, ... Sum all even-valued terms less than four million.";
    upperBound  = 4000000;
    displayQuestion(index++, title, question);
    cout << evenFibonacciNumbers(upperBound) << endl;

    title       = "Largest Prime Factor";
    question    = ""; 
    displayQuestion(index++, title, question);
    displayIncomplete();

    title       = "Largest Palindrome Product";
    question    = "Find the largest palindrome made from the product of two 3-digit numbers."; 
    upperBound = 1000;
    displayQuestion(index++, title, question);
    cout << largestPalindromeProduct(upperBound) << endl;
    
    title       = "Smallest Multiple";
    question    = "What is the smallest positive number evenly divisible by all the number from 1 to 20?";
    displayQuestion(index++, title, question);
    cout << smallestMultiple() << endl; 

    title       = "Sum Square Difference";              // Q1~6 
    question    = "Find the difference between the sum of the squares of the first 100 natural numbers and the square of the sum.";
    upperBound  = 100;
    displayQuestion(index++, title, question);
    cout << sumSquareDifference(upperBound) << endl;
    
    title       = "Largest Product in a Series.";       // Q8 
    question    = "Find the thirteen adjacent digits in th 1000-digit number that have the greatest product. What is the value of the product?";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;

    title       = "Special Pythagorean Triple";         // Q9 
    question    = "There exist exactly one Pythagorean triple for which a = b + c = 1000. Find the product abc.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
    
    title       = "Largest product in a grid";          // Q11 
    question    = "What is the greatest product of four adjacent numbers in the same diretion (up, down, left, right, or diagonally) in the 20x20 grid?";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;

    title       = "Highly Divisible Triangular Number"; 
    question    = "What is the value of the first triangular number with over 500 divisors?";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
    
    title       = "Large Sum"; 
    question    = "Work out the first ten digits of the sum of the floowing one-hundred 50-digit numbers.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
    
    title       = "Longest Collatz Sequence"; 
    question    = "Which starting number, under one million, produces the longest chain?";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
    
    title       = "Lattice Paths"; 
    question    = "How many paths, starting in the top left corner using only down and left moves ending the in bottom right corner, are there on a 20x20 grid.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Power Digit Sum"; 
    question    = "What is the sum of the digits of the number 2^1000?";
    // displayQuestion(index++, title, question);
    // cout << 1366 << endl;    // got this from python
    
    title       = "Number Letter Counts"; 
    question    = "If all the numbers form 1 to 1000 inclusive were written out in words, how many letters would be used? NOTE: Do not count spaces or hyphens. The use of \"and\" when writting out numbers is in compliance with British usage.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Maximum Path Sum I"; 
    question    = "Find the maximum total from top to bottm of the triangle given.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Counting Sundays"; 
    question    = "How many Sundays fell on the first of the month during the twentieth centry (1 Jan 1901 to 31 Dec 2000?";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Factorial Digit Sum"; 
    question    = "Find the sum of the digits in the number 100!";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Amicable Numbers"; 
    question    = "Evaluate the sum of all the amicable numbers under 10000.AMICABLE NUMBERS are a, b such that a != b and d(a) = b and d(b) = a where d(n) is the function which sums the proper divisors of n.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Name Scores"; 
    question    = "What is the total of all the name scores in the file?";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Non-abundant Sums"; 
    question    = "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers. An ABUNDANT NUMBER n is one which is less than the sum of its proper divisors.";
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
     
    title       = "Lexicographic Permutations"; 
    question    = "What is the millionth lexicographic permutations of the ditits 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9?";
    // displayQuestion(index++, title, question);
    // cout << 266251220 << endl;
     
    title       = "1000-Digit Fibonacci Number"; 
    question    = "What is the index of the first term in the Fibonacci sequence to contain 1000 digits?";
    // displayQuestion(index++, title, question);
    // cout << 4997 << endl;
***/     
    Solution sln = new Solution();
    sln.solve(4);

    return 0;
}
