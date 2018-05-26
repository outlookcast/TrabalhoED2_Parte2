#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "NoAVL.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

class AVL
{

private:
    NoAVL *raiz;

    bool auxBusca(NoAVL * p, long long unsigned c);
    NoAVL* libera(NoAVL *p);
    NoAVL* auxInsere(NoAVL *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprimePorNivel(NoAVL* p, int nivel);
    NoAVL* menorSubArvDireita(NoAVL *p);
    NoAVL* removeFolha(NoAVL *p);
    NoAVL* remove1Filho(NoAVL *p);
    ///NoAVL* auxRemove(NoAVL *p, int C);
    NoAVL* rotacaoEsquerda(NoAVL *x);
    NoAVL* rotacaoDireita(NoAVL *x);
    NoAVL* balanciamentoInsert(NoAVL *x);

    long long unsigned calculaChave(int QuestionID, int OwnerUserID);


public:

    AVL();
    ~AVL();
    void rotacaoD(long long unsigned x);
    void rotacaoE(long long unsigned x);
    ///int getRaiz();
    bool vazia();
    bool busca(int QuestionID);
    ///void remove(int C);
    void insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprime();


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


// outras operacoes

};

#endif // ARVBINBUSCA_H_INCLUDED
