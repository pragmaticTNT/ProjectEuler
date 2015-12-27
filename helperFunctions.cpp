#include "helperFunctions.h"

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

