#include "noSplay.h"

class arvoreSplay
{
private:
    noSplay *raiz;
    unsigned long tamanho;
    void rotacaoEsquerda(noSplay *x);
    void rotacaoDireita(noSplay *x);
    void splay(noSplay *x);
    void trocar(noSplay *x, noSplay *y);
    noSplay *subArvoreMinima(noSplay *x);
    noSplay *subArvoreMaxima(noSplay *x);

public:
    arvoreSplay();
    void inserir(int key,int OwnerUserID, string CreationDate, int Score, string Title);
    noSplay *busca(int key);
    void deletar(int key);
    void imprime();
    void imprimeAux(noSplay *x, int nivel);
    int getTamanho();
};
