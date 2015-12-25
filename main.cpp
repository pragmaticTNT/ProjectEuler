#include <iostream>
#include <string>

using namespace std;

/***
 *  HELPER FUNCTIONS
 *
***/
void displayQuestion(int index, string title, string question){
    cout << "Problem 1: Multiples of 3 and 5\n";
    cout << "Find the sum of all the multiples of 3 or 5 below 1000.\n";
    cout << "Solution: " << multiplesOf3And5(upperBound) << endl;
    cout << endl;
}

int sumMultiplesLT(int base, int bound){
    int multiples = (bound-1) / base;
    return (base * multiples * (multiples+1)) / 2;
}

int isPalindrome(String str){
    return 0;
}

int multiplesOf3And5(int bound){
    int sumMult3    = sumMultiplesLT(3, bound);   
    int sumMult5    = sumMultiplesLT(5, bound);
    int sumMult15   = sumMultiplesLT(15, bound);
    return sumMult3 + sumMult5 - sumMult15;
}

int evenFibonacciNumbers(int upperBound){
    int prev    = 1;
    int curr    = 2;
    int total   = 0;
    while(curr < upperBound){
        if( curr % 2 == 0)
            total += curr;
        int temp = prev;
        prev = curr;
        curr = temp + prev;
    }
    return total;
}

int largestPalindromeProduct(){

}

int main(){
    int upperBound = 1000;
    cout << "Problem 1: Multiples of 3 and 5\n";
    cout << "Find the sum of all the multiples of 3 or 5 below 1000.\n";
    cout << "Solution: " << multiplesOf3And5(upperBound) << endl;
    cout << endl;
    
    upperBound = 4000000;
    cout << "Problem 2: Even Fibonacci Numbers\n";
    cout << "Consider the fibonacci seqence with initial constraints\n"
            "1, 2, 3, 5, 8, ... Sum all even-valued terms"
            " less than four million.\n";
    cout << "Solution: " << evenFibonacciNumbers(upperBound) << endl;
    cout << endl;

    cout << "Problem 3: Largest Prime Factor\n";
    cout << endl; 
    cout << "Problem 4: Largest Palindrome Product\n";
    cout << "Find the largest palindrome made from the product of"
            " two 3-digit numbers.\n";
    cout << "Solution: " << largestPalindromeProduct() << endl;
    cout << endl;
    
    cout << "Problem 5: Smallest Multiple\n";
    cout << endl;

    cout << "Problem 6: 
    cout << endl;
    

    return 0;
}
