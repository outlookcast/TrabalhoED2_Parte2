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
    NoCor* auxInsere(NoCor *p, int x,int OwnerUserID, string CreationDate, int Score, string Title, NoCor *&noX);
    void imprimePorNivel(NoCor* p, int nivel);
    NoCor* menorSubArvDireita(NoCor *p);
    NoCor* removeFolha(NoCor *p);
    NoCor* remove1Filho(NoCor *p);
    NoCor* auxRemove(NoCor* p, int C, NoCor *&x);
    NoCor* rotacaoEsquerda(NoCor *x);
    NoCor* rotacaoDireita(NoCor *x);
    void arrumaInsercao(NoCor *z);
    void arrumaRemocao(NoCor *x);



  public:

    ArvVerPre();
    ~ArvVerPre();
    void rotacaoD(int x);
    void rotacaoE(int x);
    int getRaiz();
    bool vazia();
    bool busca(int x);
    void remove(int C);
    void insere(int x,int OwnerUserID, string CreationDate, int Score, string Title);
    void imprime();


// outras operacoes

};

#endif // ARVBINBUSCA_H_INCLUDED
