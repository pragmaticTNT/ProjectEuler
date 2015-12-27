#include <string>
#include <iostream>

class Question {
    string title, description;
    int index;
    bool isSolved;    
    int (*solution)();
    void printDescription(){
        int count = 0
        char * token = strtok(description, " ");
         
    }

public:
    Question (int i, string t, string d, bool s = false) : 
        index(i),
        title(t),
        description(d),
        isSolved(s) { }

    bool setSolution(int(*solution)()){
        this.solution = &solution; 
    }

    void display(){
        string lineBreak = "\n\t";
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

    }

    int solve(){
        return solution(); 
    } 

}
