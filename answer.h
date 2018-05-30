#ifndef ANSWER_H
#define ANSWER_H
#include <iostream>
#include <list>
using namespace std;

class Answer
{
    public:
        Answer();
        ~Answer();

        //sets
        void setAnswerID(int answerID);
        void setUserID(int userID);
        void setDate(string date);
        void setQuestionID(int questionID);
        void setScore(int score);

        //gets
        int getAnswerID();
        int getUserID();
        string getDate();
        int getQuestionID();
        int getScore();
        list<Answer> getLista();

        void inserirNaLista(Answer answer);
        void imprime();

    private:
        int answerID;
        int userID;
        string date;
        int questionID;
        int score;
        list<Answer> lista;
};

#endif // ANSWER_H
