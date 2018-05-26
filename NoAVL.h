#ifndef NOAVL_H_INCLUDED
#define NOAVL_H_INCLUDED

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


class NoAVL
{

public:

    NoAVL() {};
    ~NoAVL() {};

    void setEsq(NoAVL *p)
    {
        esq = p;
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


    void setDir(NoAVL *p)
    {
        dir = p;
    }

    /*
    void setInfo(int c)
    {
        info = c;
    }
    */

    NoAVL * getEsq()
    {
        return esq;
    }

    NoAVL * getDir()
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

    int getBalanciamento()
    {
        return fatorBanciamento;
    }

    void setBalanciamento(int x)
    {
        fatorBanciamento = x;
    }

    int QuestionID;
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

#endif // NO_H_INCLUDED
