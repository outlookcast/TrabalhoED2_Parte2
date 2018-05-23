#include <iostream>
#include "Data.h"

using namespace std;
//---------- Construtor ---------- //
Data::Data(int questionID,int userID,string date, int score, string title)
{
    this->questionID = questionID;
    this->userID = userID;
    this->date = date;
    this->score = score;
    this->title = title;
}

Data::Data()
{
    this->questionID = -1;
}


//---------- Set's ---------- //
void Data::setQuestionID(int questionID)
{
    this->questionID = questionID;
}

void Data::setUserID(int userID)
{
    this->userID = userID;
}

void Data::setDate(string date)
{
    this->date = date;
}

void Data::setScore(int score)
{
    this->score = score;
}

void Data::setTitle(string title)
{
    this->title = title;
}


//---------- Get's---------- //
int Data::getQuestionID()
{
    return this->questionID;
}

int Data::getUserID()
{
    return this->userID;
}

string Data::getDate()
{
    return this->date;
}

int Data::getScore()
{
    return this->score;
}
string Data::getTitle()
{
    return this->title;
}
