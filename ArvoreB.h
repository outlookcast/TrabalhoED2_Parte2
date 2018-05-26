#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <iostream>
using namespace std;

#include "NoB.h"
#include "merge.h"
class ArvoreB
{

private:

    NoB *raiz;
    int ordem;
    void deletaArvore(NoB *no);
    void ordenaVetorChaves(int *vetorChaves, NoB **vetorPonteiros, int tam, bool folha);
    void imprimePorNivel(NoB *x, int nivel);

public:

    ArvoreB(int ordem);
    ~ArvoreB();
    void adicionarElemento(int x);
    void removerElemento(int x);
    NoB* busca(int k);
    void imprime();




};
#endif
