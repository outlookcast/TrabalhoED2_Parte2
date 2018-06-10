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

    ///bool auxBusca(NoCor * p, int c);
    NoCor* libera(NoCor *p);
    NoCor* auxInsere(NoCor *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title, NoCor *&noX);
    void imprimePorNivel(NoCor* p, int nivel);
    NoCor* menorSubArvDireita(NoCor *p);
    NoCor* rotacaoEsquerda(NoCor *x);
    NoCor* rotacaoDireita(NoCor *x);
    void arrumaInsercao(NoCor *z);
    NoCor *sucessor(NoCor *y);
    void removeFix(NoCor *p);
    NoCor *minNoCor(NoCor *p);
    NoCor *maxNoCor(NoCor *p);
    int retornaCor(NoCor *p);
    void setColor(NoCor *p, int cor);
    void rotacionarEsquerdaRemocao(NoCor *ptr);
    void rotacionarDireitaRemocao(NoCor *ptr);
    long long unsigned calculaChave(int QuestionID, int OwnerUserID);
    bool auxBuscaUserID(NoCor * no,int UserID);

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

  public:
    bool buscaUserID(int UserID);
    ArvVerPre();
    ~ArvVerPre();
    void rotacaoD(int x);
    void rotacaoE(int x);
    bool vazia();
    ///bool busca(int x);
    void insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprime();
    void removerValorCor (int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    NoCor *removeNoCor(NoCor *r, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    long long unsigned numRotacoes;
// outras operacoes

};

#endif // ARVBINBUSCA_H_INCLUDED
