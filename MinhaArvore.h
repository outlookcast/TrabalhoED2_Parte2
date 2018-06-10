#ifndef MINHAARVORE_H_INCLUDED
#define MINHAARVORE_H_INCLUDED
#include "NoAVL.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

class MinhaArvore
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
    NoAVL* auxRemove(NoAVL *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    NoAVL* rotacaoEsquerda(NoAVL *x);
    NoAVL* rotacaoDireita(NoAVL *x);
    NoAVL* balanciamentoInsert(NoAVL *x);
    bool auxBuscaQuestinIDUserID(NoAVL * no, int QuestionID, int UserID);
    bool auxBuscaUserID(NoAVL * no,int UserID);
    long long unsigned calculaChave(int QuestionID, int OwnerUserID);
    int fatorDeBalanceamento;
    void splay(NoAVL * p);

public:

    MinhaArvore();
    MinhaArvore(int fatorDeBalanceamento);
    ~MinhaArvore();
    void rotacaoD(long long unsigned x);
    void rotacaoE(long long unsigned x);
    ///int getRaiz();
    bool vazia();
    bool busca(int QuestionID);
    void remove(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprime();
    bool buscaQuestinIDUserID(int QuestionID,int UserID);
    bool buscaUserID(int UserID);
    long long unsigned numRotacoes;


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

};

#endif // MINHAARVORE_H_INCLUDED
