#include <iostream>

using namespace std;

class NoAVL
{
public:
    NoAVL() {};
    ~NoAVL() {};
    void setEsq(NoAVL *p)
    {
        esq = p;
    }

    void setDir(NoAVL *p)
    {
        dir = p;
    }

    void setInfo(int c)
    {
        info = c;
    }

    NoAVL * getEsq()
    {
        return esq;
    }

    NoAVL * getDir()
    {
        return dir;
    }

    int getInfo()
    {
        return info;
    }
    int getAltura()
    {

        return altura;
    }
    void setAltura(int x)
    {

        altura = x;
    }

    int getBalanciamento()
    {

        return fatorBanciamento;
    }

    void setBalanciamento(int x)
    {

        fatorBanciamento = x;
    }

    NoAVL(int info, int OwnerUserID, string CreationDate, int Score, string Title)
    {
        this->info = info;
        this->OwnerUserID = OwnerUserID;
        this->CreationDate = CreationDate;
        this->Score = Score;
        this->Title = Title;
    }

    ///Dados de Question.csv
    ///info = QuestionID
    int info;
    int OwnerUserID;
    string CreationDate;
    int Score;
    string Title;

private:
    NoAVL * esq;
    NoAVL * dir;
    int altura;
    int fatorBanciamento;
};
