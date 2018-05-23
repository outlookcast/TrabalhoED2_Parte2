#include <iostream>
#include <string>

using namespace std;

class noSplay
{
public:
    noSplay *esq;
    noSplay *dir;
    noSplay *parent;

    ///chave = QuestionID
    int chave;
    int OwnerUserID;
    string CreationDate;
    int Score;
    string Title;

    noSplay(int key,int OwnerUserID, string CreationDate, int Score, string Title)
    {
        esq = NULL;
        dir = NULL;
        parent = NULL;
        chave = key;
        this->OwnerUserID = OwnerUserID;
        this->CreationDate = CreationDate;
        this->Score = Score;
        this->Title = Title;
    }
};
