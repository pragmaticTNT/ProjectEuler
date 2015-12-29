#include <string>
#include <iostream>

#ifndef __QUESTION_H_INCLUDED__
#define __QUESTION_H_INCLUDED__

class Question {
    std::string title, description;
    int index;
    bool isSolved;    
    int solution;

public:
    Question (int i, std::string t, std::string d) : 
        index(i),
        title(t),
        description(d),
        isSolved(false),
        solution(0) { }

    void setSolution(int sln){
        solution = sln; 
        isSolved = true;
    }

    bool solved(){
        return isSolved;
    }

    void display(){
        std::string lineBreak = "\n\t";
        int count = 0;
        int maxLineChar = 60;
        std::cout << "\nQ" << index << ": " << title << lineBreak;
        for (int i = 0; i < description.size(); i++){
            if (count < maxLineChar || description[i] != ' '){
                std::cout << description[i];
                count++;
            } else {
                std::cout << lineBreak;
                count = 0;
            }
        }
        if (isSolved)
            std::cout << "Solution: " << solution << std::endl;
        else
            std::cout << "THIS QUESTION IS INCOMPLETE.\n";
    }
};

#endif
