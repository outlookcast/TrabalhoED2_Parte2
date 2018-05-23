#include "NoAVL.h"
#include <iostream>

using namespace std;

class AVL
{

private:
    NoAVL *raiz;

    bool auxBusca(NoAVL * p, int c);
    NoAVL* libera(NoAVL *p);
    NoAVL* auxInsere(NoAVL *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprimePorNivel(NoAVL* p, int nivel);
    NoAVL* menorSubArvDireita(NoAVL *p);
    NoAVL* removeFolha(NoAVL *p);
    NoAVL* remove1Filho(NoAVL *p);
    NoAVL* auxRemove(NoAVL *p, int C);
    NoAVL* rotacaoEsquerda(NoAVL *x);
    NoAVL* rotacaoDireita(NoAVL *x);
    NoAVL* balanciamentoInsert(NoAVL *x);

public:

    AVL();
    ~AVL();
    void rotacaoD(int x);
    void rotacaoE(int x);
    int getRaiz();
    bool vazia();
    bool busca(int x);
    void remove(int C);
    void insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprime();

// outras operacoes

};
