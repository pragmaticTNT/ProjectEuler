#include <string>
#include <iostream>

#ifndef QUESTION_H
#define QUESTION_H
class Question {
    public:
        Question (int i, std::string t, std::string d) :
            index(i),
            title(t),
            description(d),
            isSolved(false),
            solution(0) { }
        ~Question() {}
        void setSolution(long long int sln){
            if(sln){
				solution = sln;
				isSolved = true;		
			}
        }
        bool solved(){
            return isSolved;
        }
        void display(){
            std::string lineBreak = "\n\t";
            int count = 0;
            int maxLineChar = 60;
            std::cout << "\n Q" << index << ": " << title << lineBreak;
            for (size_t i = 0; i < description.size(); i++){
                if (count < maxLineChar || description[i] != ' '){
                    std::cout << description[i];
                    count++;
                } else {
                    std::cout << lineBreak;
                    count = 0;
                }
            }
			std::cout << std::endl;
            if (isSolved)
                std::cout << " SOLUTION: " << solution << std::endl;
            else
                std::cout << " THIS QUESTION IS INCOMPLETE.\n";
			std::cout << std::endl;
		}
    
	private:
        std::string title, description;
        int index;
        bool isSolved;
        long long int solution;
};

#endif
