// ProjectEuler.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
	char indexRaw[10];
	int index;
    Solution sln = Solution();
	do{
		sln.showStatus();
		cout << " Available Questions [1~" 
			<< sln.size()
			<< "]. Enter an index or -1 to exit: ";
		cin >> indexRaw;
		index = atoi(indexRaw);
		sln.showQuestion(index);
	}while(index >= 0);
    return 0;
}