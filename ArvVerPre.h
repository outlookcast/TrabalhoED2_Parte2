#ifndef ARVVERPRE_H_INCLUDED
#define ARVVERPRE_H_INCLUDED
#include "NoCor.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

class ArvVerPre
{

private:
    NoCor *raiz;

    bool auxBusca(NoCor * p, int c);
    NoCor* libera(NoCor *p);
    NoCor* auxInsere(NoCor *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title, NoCor *&noX);
    void imprimePorNivel(NoCor* p, int nivel);
    NoCor* menorSubArvDireita(NoCor *p);
    NoCor* removeFolha(NoCor *p);
    NoCor* remove1Filho(NoCor *p);
    ///NoCor* auxRemove(NoCor* p, int C, NoCor *&x);
    NoCor* rotacaoEsquerda(NoCor *x);
    NoCor* rotacaoDireita(NoCor *x);
    void arrumaInsercao(NoCor *z);
    ///void arrumaRemocao(NoCor *x);
    long long unsigned calculaChave(int QuestionID, int OwnerUserID);



public:

    ArvVerPre();
    ~ArvVerPre();
    void rotacaoD(int x);
    void rotacaoE(int x);
    bool vazia();
    bool busca(int x);
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
