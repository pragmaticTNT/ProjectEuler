#include "Solution.h"
#include "helperFunctions.h"

Solution::Solution(){
    populate();
}

void Solution::populate(){
    int index;
    std::string line, title, description;

    std::ifstream qList(qFileName.c_str());
    while (getline(qList, line)){
       index = std::stoi(line.c_str());
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

int Solution::multiplesOf3And5(){
    int bound = 1000;
    return sumMultLT(3,bound) + sumMultLT(5,bound) - sumMultLT(15,bound);
}

