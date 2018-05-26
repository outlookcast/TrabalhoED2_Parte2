#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED
#include "stdlib.h"

class NoB
{

private:

    int *vetorChaves;
    NoB **vetorPonteiro;
    NoB *pai;
    int tamVetorC;  //tamanho do vetor de chaves
    int tamVetorP; //tamanho do vetor de ponteiros
    int numChaves;
    bool folha;

public:

    NoB* getPai()
    {
        return pai;
    }

    ~NoB()
    {
        delete []vetorChaves;
        delete []vetorPonteiro;
    }

    void setPai(NoB *p)
    {
        pai = p;
    }

    NoB(int ordem)
    {
        if(ordem < 1)
            exit(-1);

        vetorChaves = new int[ordem];
        tamVetorC = ordem;

        vetorPonteiro = new NoB*[ordem + 1];
        tamVetorP = ordem + 1;

        numChaves = 0;
        folha = true;
    }

    int* getVetorChaves()
    {
        return vetorChaves;
    }

    NoB ** getVetorPonteios()
    {
        return vetorPonteiro;
    }

    int getTamVetorChaves()
    {
        return tamVetorC;
    }

    int getTamVetorPont()
    {
        return tamVetorP;
    }

    int getNumChaves()
    {
        return numChaves;
    }

    void setNumChaves(int num)
    {
        numChaves = num;
    }

    bool getFolha()
    {
        return folha;
    }
    void setFolha(bool f)
    {
        folha = f;
    }


};
#endif
