// ProjectEuler.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
	int index;
    Solution sln = Solution();
	do{
		sln.displayStatus();
		cout << " Available Questions [1~" 
			<< sln.size()
			<< "]. Enter an index or 0 to exit: ";
		cin >> index;
		sln.showQuestion(index);
	}while(index);
    return 0;
}