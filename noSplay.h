#ifndef NOSPLAY_H_INCLUDED
#define NOSPLAY_H_INCLUDED
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

class noSplay
{
public:
    noSplay *esq;
    noSplay *dir;
    noSplay *parent;

    int QuestionID;
    int OwnerUserID;
    string CreationDate;
    int Score;
    string Title;

    long long unsigned chave;

    noSplay(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
    {
        this->QuestionID = QuestionID;
        this->OwnerUserID = OwnerUserID;
        this->CreationDate = CreationDate;
        this->Score = Score;
        this->Title = Title;

        esq = NULL;
        dir = NULL;
        parent = NULL;

        chave = calculaChave();
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
};


#endif // NOSPLAY_H_INCLUDED
