#include <iostream>
#include "FuncoesAuxiliares.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

#include "AVL.h"

using namespace std;

string completaString(string s)
{
    if(s.size() < 32)
    {
        for(int i=0;s.size()< 32;i++)
        {
            string aux = "0"+s;
            s = aux;
        }
    }
    return s;
}

long long int convertePraInt(string s1, string s2)
{
    string s = s1+s2;
    cout<<s<<endl;
    int ultimaPos = s.size()-1;
    long long unsigned num = 0;
    int contPot = 0;
    for(int i=ultimaPos;i>0;i--)
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

int main()
{

    AVL arvore;
    Data * dados = vetorRandomData(42);
    for(int i=0;i<10;i++)
    {
        cout<<dados[i].getQuestionID()<<" "<<dados[i].getUserID()<<" "<<dados[i].getDate()<<" "<<dados[i].getScore()<<" "<<dados[i].getTitle()<<endl;
        arvore.insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<endl;
    arvore.imprime();

    delete [] dados;


    return 0;
}
