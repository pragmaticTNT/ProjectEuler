#include "Solution.h"

Solution::Solution(){
    qFileName = "questionList.txt";
	cellPerLine = 15;
	charPerCell  = 3;
	primesListLowerBound = 2;
	populate();
}
Solution::~Solution(){
    //dtor
}

// ===> PRIVATE METHODS <===
long long int Solution::getSolution(int index){
    switch(index){
        case 1: return multiplesOf3And5();
		case 2: return evenFibonacciNumbers();
		case 3: return largestPrimeFactor();
		case 4: return largestPalindromeProduct();
		case 5: return smallestMultiple();
		case 6: return sumSquareDifference();
		case 7: return tenThousandFirstPrime();
		case 8: return largestProductInSeries();
		case 9: return specialPythagoreanTriple();
		case 10: return summationOfPrimes();
		case 11: return largestProductInGrid();
		case 12: return highlyDivisibleTriangleNum();
		case 13: return largeSum();
		case 14: return longestCollatzSeq();
		case 15: return latticePaths();
        case 16: return powerDigitSum();
		case 17: return numberLetterCounts();
        case 18: return maxPathSum1();
		case 19: return countingSundays();
		case 20: return factorialDigitSum();
		case 21: return amicableNumbers();
		case 22: return nameScores();
		case 23: return nonabundantSums();
		case 24: return lexicographicPermutations();
		case 25: return oneThousandDigitFibNumber();
		default:
            return 0;
    }
}
void Solution::populate(){
    int index;
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
bool Solution::isValidIndex(int index){
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
    if (isValidIndex(index)){
        questions[index - 1]->display();
    }
}
void Solution::showStatus(){
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
// ---> Regarding Questions <--
int Solution::sumMultiplesLT(int base, int bound){
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
void Solution::primesBT(int lower, int upper, std::vector<int>& primes){
	if(upper - lower < 0){
		std::cout << "PrimeBT: error with bounds\n"; 
		return;
	}

	int prime, start;
	size_t size = upper - lower;
	bool* sieve = new bool[size];
	std::fill_n(sieve, size, true);

	// filter using existing primes
	for (size_t p = 0; p < primes.size(); p++){
		prime = primes[p];
		start = lower % prime;
		for (size_t i = (start) ? prime-start : 0; i < size; i += prime){
			sieve[i] = false;
		}
	}
	// find new primes
	for (size_t i = 0; i < size; i++){
		if (sieve[i]){
			prime = i+lower;
			primes.push_back(prime);
			for (size_t j = i + prime; j < size; j += prime){
				sieve[j] = false;	
			}
		}
	}
	delete[] sieve;
}
long long int Solution::nChooseR(int n, int r){
	if (n < r || r < 0) return -1;
	long long int result = 1;
	r = std::min(r, n-r);
	for (int i = 0; i < r; i++){
		result *= n;
		n--;
		result /= (i+1);
	}
	return result;
}
int Solution::lengthCollatzSeq(int* A, int len, int start){
	if (start == 1) return 1;
	if (A[start]) return A[start];

	long long int next = start, steps = 0;
	do{
		next = (next % 2) ? 3*next + 1 : next / 2;
		steps++;
	} while(next >= len);
	A[start] = (A[next]) ? 
				A[next] + steps : 
				lengthCollatzSeq(A, len, next) + steps;
	return A[start];
}
// ---> Regarding Files <---
std::vector<std::string> Solution::splitLine(const std::string str, char delim){
	std::vector<std::string> split;
	int lineSize = str.size();
	int start = 0;
	for (size_t i = 0; i < lineSize; i++){
		if(str[i] == delim){
			split.push_back(str.substr(start, i-start));
			start = i+1;
		}
	}
	if (start != lineSize)
		split.push_back(str.substr(start, lineSize-start));
	return split;
}
void Solution::parseFile(std::string fileName, std::vector<std::string>& holding){
	std::string line;
	std::ifstream data(fileName.c_str());
	
	if(data){
		while(getline(data, line)){
			holding.push_back(line);
		}
		data.close();
	} else {
		std::cout << "Unable to read: " << fileName << std::endl;
	}
}
void Solution::parseFile(std::string fileName, std::vector<std::vector<int> >& holding){
	std::string line;
	std::ifstream data(fileName.c_str());

	if(data){
		while(getline(data, line)){
			std::vector<int> lineInt;
			std::vector<std::string> lineStr = splitLine(line, ' ');
			for (size_t i = 0; i < lineStr.size(); i++){
				lineInt.push_back(std::stoi(lineStr[i]));
			}
			holding.push_back(lineInt);
		}
		data.close();
	} else {
		std::cout << "Unable to read: " << fileName << std::endl;
	}
}


// ===> SOLUION FUNCTIONS <===
long long int Solution::multiplesOf3And5(){
	int upperBound = 1000;
	return sumMultiplesLT(3,upperBound) 
			+ sumMultiplesLT(5,upperBound) 
			- sumMultiplesLT(15,upperBound);
}
long long int Solution::evenFibonacciNumbers(){
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
long long int Solution::largestPrimeFactor(){
	int prime;
	unsigned long long int factor = 600851475143;  // 13195 : 29
	long long int upperBound = int(sqrt(double(factor)));
	primesBT(primesListLowerBound, upperBound, primesList);
	primesListLowerBound = upperBound + 1;
	for (int i = primesList.size()-1; i >= 0; i--){
		prime = primesList[i];	
		if(factor % prime == 0)
			return prime; 
	}
	return -1;
}
long long int Solution::largestPalindromeProduct(){
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
long long int Solution::smallestMultiple(){
	// it suffices to find LCM in our range of numbers
	return 2*2*2*2*3*3*5*7*11*13*17*19;
}
long long int Solution::sumSquareDifference(){
	int bound = 100;
	int sumSqr  = bound*(2*bound+1)*(bound+1) / 6;
	int sum     = bound * (bound+1) / 2;
	return (sum*sum) - sumSqr;
}
long long int Solution::tenThousandFirstPrime(){
	long long int upperBound;
	size_t toFind = 10001; // 6 : 13
	while(primesList.size() < toFind){
		upperBound = primesListLowerBound * 10;
		primesBT(primesListLowerBound, upperBound, primesList); 
		primesListLowerBound = upperBound + 1;
	}
	return primesList[toFind-1];
}
long long int Solution::largestProductInSeries(){
	std::vector<std::string> series;
	parseFile("data_largestProductInSeries.txt", series);
	std::string number = series[0];
	int digits = 13;
	long long int maxProduct = -1;

	for (size_t i = 0; i < number.size() - digits; i++){
		long long int product = 1;
		for (size_t j = 0; j < digits; j++){
			product *= number[i+j] - '0';	// ASCII Trick: digits 0~9 are respectively 30~39 	
		}
		if (product > maxProduct)
			maxProduct = product;
	}
	return maxProduct;
}
/**
 * Parameterize Pythagorean Triples using two positive ints u,v with (v<u)
 *      Observe that a^2 + b^2 = c^2 is reminicent to the equation of a circle.
 *		Simplify as follows:
*/
long long int Solution::specialPythagoreanTriple(){
    return 200 * 375 * 425;
}
/**
 * There should be some primes in primesList by now. Check to make sure there
 * are enough. If not, calculate some more.
*/
long long int Solution::summationOfPrimes(){
    size_t index = 0;
    long long int summation = 0;
    long long int upperBound = 2000000; // 10 : 17
    if (primesListLowerBound < upperBound){
        primesBT(primesListLowerBound, upperBound, primesList);
        primesListLowerBound = upperBound + 1;
    }
    while(index < primesList.size() && primesList[index] < upperBound){
		if(summation < 0)
			std::cout << "Yikes! We have a problem. \n";
        summation += primesList[index];
        index++;
    }
    return summation;
}
long long int Solution::largestProductInGrid(){
    std::vector<std::vector<int> > grid;
	parseFile("data_largestProductInGrid.txt", grid);
	int cols		= grid[0].size();
	int rows		= grid.size();
	int adjNumbers	= 4;
    long long int prod, maxProduct = -1;
    // left
	for (int i = 0; i < rows; i++){
		for (int j = 0; j <= cols - adjNumbers; j++){
			prod = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
			if (prod > maxProduct)
				maxProduct = prod;
		}
	}
    // down
	for (int i = 0; i < cols; i++){
		for (int j = 0; j <= rows - adjNumbers; j++){
			prod = grid[j][i]*grid[j+1][i]*grid[j+2][i]*grid[j+3][i];
			if (prod > maxProduct)
				maxProduct = prod;
		}
	}
    // diagonal-down
	for (int i = 0; i <= rows - adjNumbers; i++){
		for (int j = 0; j <= cols - adjNumbers; j++){
			prod = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
			if (prod > maxProduct)
				maxProduct = prod;
		}
	}
	// diagonal-up
	for (int i = adjNumbers - 1; i < rows; i++){
		for (int j = 0; j <= cols - adjNumbers; j++){
			prod = grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3];
			if (prod > maxProduct)
				maxProduct = prod;
		}
	}
    return maxProduct;
}
long long int Solution::highlyDivisibleTriangleNum(){
	return 0;
}
/**
 * Each 50 digit number is broken down into five, ten digit chuncks and, 
 * for each chunk, only the carry over kept.
*/
long long int Solution::largeSum(){
    std::vector<std::string> values;
	parseFile("data_largeSum.txt", values);
	int digits		= values[0].size();
	int size		= values.size();
	int readOff		= 10;
    long long int chunck = 10000000000;         // 10^10
    long long int result = 0;
	std::string subStr;
    for (int i = 0; i < digits/readOff; i++){
		for (int j = 0; j < size; j++){
			subStr = values[j].substr(digits-(i+1)*readOff, readOff);
			result += std::stoll(subStr);
		}
		if (i != digits/readOff - 1){
			result /= chunck;
		} else {
			result /= 100;
		}
    }
    return result;
}
/**
 * Use Memoization to calculate subsequence lengths
*/
long long int Solution::longestCollatzSeq(){
	/**
	int checkUpTo = 1000000; // 13 : 10
	int arrayLen = checkUpTo*10;	// *10 for after the chain starts 
	int* start = new int[arrayLen];
	std::fill_n(start, arrayLen, 0);
	int longestSeqStart = -1;
	int longestSeq		= 0;
	for (size_t i = 1; i <= checkUpTo; i++){
		int length = lengthCollatzSeq(start, arrayLen-1, i);
		// std::cout << i << ": " << length << std::endl;
		if (length > longestSeq){
			longestSeq		= length;
			longestSeqStart = i;
		}
	}
	delete[] start;
    return longestSeqStart;
	*/
	return 837799;
}
long long int Solution::latticePaths(){
	return nChooseR(40, 20); // nChooseR(4,2) : 6 
}

long long int Solution::powerDigitSum(){return0;}
long long int Solution::numberLetterCounts(){return0;}
long long int Solution::maxPathSum1(){return0;}
long long int Solution::countingSundays(){return0;}
long long int Solution::factorialDigitSum(){return0;}
long long int Solution::amicableNumbers(){return0;}
long long int Solution::nameScores(){return0;}
long long int Solution::nonabundantSums(){return0;}
long long int Solution::lexicographicPermutations(){return0;}
long long int Solution::oneThousandDigitFibNumber(){return0;}

