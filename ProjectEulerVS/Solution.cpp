#include "Solution.h"

Solution::Solution(){
    qFileName = "questionList.txt";
	cellPerLine = 15;
	charPerCell  = 3;
	populate();
}
Solution::~Solution(){
    //dtor
}

// ===> PRIVATE METHODS <===
int Solution::getSolution(int index){
    switch(index){
        case 1:
            return multiplesOf3And5();
		case 2:
			return evenFibonacciNumbers();
		case 3:
			return largestPrimeFactor();
		case 4:
			return largestPalindromeProduct();
		case 5:
			return smallestMultiple();
		case 6:
			return sumSquareDifference();
		default:
            return 0;
    }
}
void Solution::populate(){
    int index, solution;
    std::string line, title, description;
    std::ifstream qList(qFileName.c_str());
	
	if(qList){
		while (getline(qList, line)){
			index = std::stoi(line);
			getline(qList, title);
			getline(qList, description);

			Question* q = new Question(index, title, description);
			q->setSolution(getSolution(index));
			questions.push_back(q);

			getline(qList, line);
		}
		qList.close();	
	} else {
		std::cout << "Unable to open file.\n";
	}
}
bool Solution::validIndex(int index){
	return index > 0 && index <= questions.size();
}
void Solution::displayBoundary(int cells){
	std::cout << " ";
	for (int j = 0; j < cells; j++){
		std::cout << " ---";
	}
	std::cout << " \n";
}
void Solution::displayIndex(int index){
	int padding = (charPerCell - 1)/2;
	if(questions[index]->solved()){
		addSpaces(padding);
		std::cout << "X";
		addSpaces(padding);
	} else {
		int spaces = charPerCell - digitsInInt(index+1);
		if (spaces > 1){
			addSpaces(spaces - 1);
			std::cout << index+1 << " ";	
		} else {
			addSpaces(spaces);
			std::cout << index+1;
		}
	}
}
void Solution::displayLine(int& start, int length){
	displayBoundary(length);
	std::cout << " |";
	for (int j = 0; j < length; j++){
		displayIndex(start++);
		std::cout << "|";
	}
	std::cout << std::endl;
	displayBoundary(length);
}
void Solution::addSpaces(int howMany){
	for (int i = 0; i < howMany; i++)
		std::cout << " ";
}
int Solution::digitsInInt(int index){
	int digits = 0;
	while(index){
		digits++;
		index /= 10;
	}
	return digits;
}

// ===> PUBLIC METHODS <===
void Solution::showQuestion(int index){
    if (validIndex(index)){
        questions[index - 1]->display();
    }
}
void Solution::displayStatus(){
	int count = 0;
    int lines = questions.size()/cellPerLine;
	int remaining = questions.size() % cellPerLine;
	
	if(!remaining) lines++;
    for (int i = 0; i < lines; i++){
		displayLine(count, cellPerLine);
    }
	if (remaining){
		displayLine(count, remaining);
	} 
}
int Solution::size(){
	return questions.size();
}

// ===> HELPER FUNCTIONS <===
int Solution::sumMultLT(int base, int bound){
    int multiples = (bound-1) / base;
    return (base * multiples * (multiples+1)) / 2;
}
bool Solution::isPalindrome(std::string s){
    int range = s.size();
    for (int i = 0; i <= (range/2)-1; i++)
        if (s[i] != s[range-1-i])
            return false;
    return true;
}

// ===> SOLUION FUNCTIONS <===
int Solution::multiplesOf3And5(){
    int bound = 1000;
    return sumMultLT(3,bound) + sumMultLT(5,bound) - sumMultLT(15,bound);
}
int Solution::evenFibonacciNumbers(){
    int upperBound = 4000000;
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
int Solution::largestPrimeFactor(){
	return 0;
}
int Solution::largestPalindromeProduct(){
	int bound = 1000;
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
int Solution::smallestMultiple(){
    // it suffices to find LCM in our range of numbers
    return 2*2*2*2*3*3*5*7*11*13*17*19;
}
int Solution::sumSquareDifference(){
	int bound = 100;
    int sumSqr  = bound*(2*bound+1)*(bound+1) / 6;
    int sum     = bound * (bound+1) / 2;
    return (sum*sum) - sumSqr;
}
