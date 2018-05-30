#include "answer.h"
#include <vector>


using namespace std;

Answer::Answer()
{
    this->answerID = -1;
    this->userID = -1;
    this->date = "-1";
    this->questionID = -1;
    this->score = -1;
}

Answer::~Answer(){}

//sets
void Answer::setAnswerID(int answerID)
{
    this->answerID = answerID;
}
void Answer::setUserID(int userID)
{
    this->userID = userID;
}
void Answer::setDate(string date)
{
    this->date = date;
}
void Answer::setQuestionID(int questionID)
{
    this->questionID = questionID;
}
void Answer::setScore(int score)
{
    this->score = score;
}
//gets
int Answer::getAnswerID()
{
    return answerID;
}
int Answer::getUserID()
{
    return userID;
}
string Answer::getDate()
{
    return date;
}
int Answer::getQuestionID()
{
    return questionID;
}
int Answer::getScore()
{
    return score;
}

list<Answer> Answer::getLista()
{
    return this->lista;
}

void Answer::inserirNaLista(Answer answer)
{
    this->lista.push_back(answer);
}

/*
void Answer::imprime()
{
    cout<<" -> ";
    if(this->lista.size() == 0)
    {
        cout<<"Lista vazia!";
    }
    else
    {
        for(int i=0;i<this->lista.size();i++)
        {
            cout<<this->lista[i].getUserID()<<" ";
        }
    }
}
*/


