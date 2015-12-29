#include "Solution.h"

Solution::Solution(){
    populate();
}

Solution::~Solution(){
    //dtor
}

void Solution::populate(){
    int index;
    std::string line, title, description;

    std::ifstream qList(qFileName.c_str());
    while (getline(qList, line)){
       index = std::strtol(line);
       getline(qList, title);
       getline(qList, description);

       Question* q = new Question(index, title, description);
       questions.push_back(q);

       getline(qList, line);
    }
    qList.close();
}

void Solution::displayStatus(){
    int count = 0;
    for (int i = 0; i < questions.size()/maxCellPerLine; i++){
        // going to make sure the other stuff works first
    }
}

void Solution::solve(int index){
    if (index < questions.size() && index >= 0){
        if(!questions[index - 1]->solved())
            setSolution(index);
        questions[index - 1]->display();
    }
}

void Solution::setSolution(int index){
    int solution;
    switch(index){
        case 1:
            solution = multiplesOf3And5();
            break;
        default:
            return;
    }
    questions[index-1]->setSolution(solution);
}

int Solution::sumMultLT(int base, int bound){
    int multiples = (bound-1) / base;
    return (base * multiples * (multiples+1)) / 2;
}

bool Solution::isPalindrome(string s){
    int range = s.size();
    for (int i = 0; i <= (range/2)-1; i++)
        if (s[i] != s[range-1-i])
            return false;
    return true;
}

int Solution::multiplesOf3And5(){
    int bound = 1000;
    return sumMultLT(3,bound) + sumMultLT(5,bound) - sumMultLT(15,bound);
}
