#ifndef NOCOR_H_INCLUDED
#define NOCOR_H_INCLUDED

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

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

    NoCor * getEsq()
    {
        return esq;
    }

    NoCor * getDir()
    {
        return dir;
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

    string completaString(string s)
    {
        if(s.size() < 32)
        {
            for(int i=0; s.size()< 32; i++)
            {
                string aux = "0"+s;
                s = aux;
            }
        }
        return s;
    }

    long long unsigned convertePraInt(string s1, string s2)
    {
        string s = s1+s2;
        int ultimaPos = s.size()-1;
        long long unsigned num = 0;
        int contPot = 0;
        for(int i=ultimaPos; i>0; i--)
        {
            if(s[i] == '1')
            {
                long long unsigned calculo = pow(2,contPot);
                num += calculo;
            }
            contPot++;
        }
        return num;
    }

    string convertePraString(int num)
    {
        char aux[33];
        itoa(num,aux,2);
        return string(aux);
    }

    long long unsigned calculaChave()
    {
        ///calcula chave
        string U_ID = convertePraString(this->OwnerUserID);
        string Q_ID = convertePraString(this->QuestionID);
        U_ID = completaString(U_ID);
        Q_ID = completaString(Q_ID);
        long long unsigned num = convertePraInt(U_ID,Q_ID);
        return num;
    }

    int QuestionID;
    int OwnerUserID;
    string CreationDate;
    int Score;
    string Title;



private:

    NoCor * esq;
    NoCor * dir;
    NoCor *pai;
    int altura;
    int cor; //1 para vermelho, 2 para preto.


};

#endif // NO_H_INCLUDED
