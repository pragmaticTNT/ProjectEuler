#include "Solution.h"

Solution::Solution(){
    populate();
}

void Solution::populate(){
    ifstream questionList;
    int index;
    std::string line, title, description;

    qList.open(qFileName);
    while (getline(questionList, line)){
       index = std::stoi(line);
       getline(questionList, title);
       getline(questionList, description);

       Question q = new Question(index, title, description);
       questions.push_back(q);

       getline(questionList, line);
    }
    questionList.close();
}

void Solution::displayStatus(){
    int count = 0;
    for (int i = 0; i < questions.size()/maxCellPerLine; i++){
        // going to make sure the other stuff works first
    } 
}

void Solution::solve(int index){
    if (index < questions.size() && index >= 0)
        questions[index].display();
}
