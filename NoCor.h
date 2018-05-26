#ifndef NOCOR_H_INCLUDED
#define NOCOR_H_INCLUDED
#include <iostream>
using namespace std;
class NoCor
{

public:

    NoCor() {};
    ~NoCor() {};

    void setEsq(NoCor *p)
    {
        esq = p;
    }

    void setDir(NoCor *p)
    {
        dir = p;
    }

    void setInfo(int c)
    {
        info = c;
    }

    NoCor * getEsq()
    {
        return esq;
    }

    NoCor * getDir()
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
    void setCor(int a)
    {
      cor = a;
    }
    int getCor()
    {

      return cor;
    }
    NoCor* getPai()
    {
      return pai;
    }
    void setPai(NoCor *pai)
    {
      this->pai = pai;
    }

    int OwnerUserID;
    string CreationDate;
    int Score;
    string Title;

private:

    int info; ///Info = QuestionID
    NoCor * esq;
    NoCor * dir;
    NoCor *pai;
    int altura;
    int cor; //1 para vermelho, 2 para preto.


};

#endif // NO_H_INCLUDED
