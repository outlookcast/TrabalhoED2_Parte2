#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>

using namespace std;

class Data
{
public:
    int questionID;
    int userID;
    string date;
    int score;
    string title;

    Data(int questionID,int userID,string date, int score, string title);
    Data();

    //sets
    void setQuestionID(int questionID);
    void setUserID(int userID);
    void setDate(string date);
    void setScore(int score);
    void setTitle(string title);

    //gets
    int getQuestionID();
    int getUserID();
    string getDate();
    int getScore();
    string getTitle();

};
#endif // DATA_H_INCLUDED
