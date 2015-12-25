#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/***
 *  HELPER FUNCTIONS
 *
***/
void displayQuestion(int index, string title, string question){
    cout << endl;
    cout << "Problem " << index << ": " << title << endl;
    cout << question << endl;
    cout << "Solution: ";  
}

void displayIncomplete(){
    cout << "THIS QUESTION IS INCOMPLETE" << endl;
}

int sumMultiplesLT(int base, int bound){
    int multiples = (bound-1) / base;
    return (base * multiples * (multiples+1)) / 2;
}

bool isPalindrome(string s){
    int range = s.size();
    for (int i = 0; i <= (range/2)-1; i++)
        if (s[i] != s[range-1-i])
            return false;
    return true;
}

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

    title       = "Sum Square Difference"; 
    question    = "Find the difference between the sum of the squares of the first 100 natural numbers and the square of the sum.";
    upperBound  = 100;
    displayQuestion(index++, title, question);
    cout << sumSquareDifference(upperBound) << endl;
    
    title       = ""; 
    question    = "";
    upperBound  = 0;
    // displayQuestion(index++, title, question);
    // cout << function() << endl;
    return 0;
}
