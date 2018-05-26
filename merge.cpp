#include <iostream>
#include <stdlib.h>
using namespace std;
#include "merge.h"

void merge(int *vetor, int tam, int *numTrocas, int *numComparacoes)
{

    merge(vetor, 0, tam-1, numTrocas, numComparacoes);
}

void intercala(int *vetor, int inicio, int meio, int fim, int *numTrocas, int *numComparacoes)
{
    int tamVetorAux = (fim - inicio) + 1;
    int *vetorAux = new int[tamVetorAux];  // vetor auxiliar.

    if(vetorAux == NULL)
    {
        cout<<"Erro ao alocar vetor.\n";
        exit(-1);
    }

    int indAux = 0;       // indice do vetor auxiliar.
    int indV1 = inicio;   // indice do vetor[inicio] a vetor[meio].
    int indV2 = meio + 1; // indice do vetor[meio+1] a vetor[fim].

    //Copia os elementos de forma ordenada de V1 ou V2 para vetorAux
    while(indV1 <= meio && indV2 <= fim) // verifica se os indices ainda estão dentro do limite do vetor.
    {
        if(vetor[indV1] < vetor[indV2])  // Verifica qual valor é menor.
        {
            vetorAux[indAux] = vetor[indV1];
            indAux += 1;
            indV1 += 1;

        }
        else
        {
            vetorAux[indAux] = vetor[indV2];
            indAux += 1;
            indV2 += 1;

        }

        *numComparacoes += 3;
        *numTrocas +=1;
    }

    *numComparacoes += 1;

    if(indV1 <= meio) //se existem posições v1 não escritas em vetorAux.
    {

        while(indV1 <= meio)
        {
            vetorAux[indAux] = vetor[indV1];
            indAux += 1;
            indV1 += 1;
            *numComparacoes += 1;
            *numTrocas +=1;
        }
        *numComparacoes += 1;
    }
    else
    {
        if(indV2 <= fim) //se existem posições v2 não escritas em vetorAux.
        {
            while(indV2 <= fim)
            {
                vetorAux[indAux] = vetor[indV2];
                indAux += 1;
                indV2 += 1;
                *numComparacoes += 1;
                *numTrocas +=1;
            }

            *numComparacoes += 1;
        }
        *numComparacoes += 1;
    }
    *numComparacoes += 1;
    // copia os elementos de vetorAux para vetor.
    int j = inicio;
    for(int i = 0; i < tamVetorAux; ++i)
    {
        vetor[j] = vetorAux[i];
        ++j;
        *numTrocas +=1;
    }

    delete []vetorAux;

}

void merge(int *vetor, int inicio, int fim, int *numTrocas, int *numComparacoes)
{
    if(fim > inicio)
    {
        int meio = (fim + inicio) / 2;
        merge(vetor, inicio, meio, numTrocas, numComparacoes);
        merge(vetor, meio + 1, fim, numTrocas, numComparacoes);
        intercala(vetor, inicio, meio, fim, numTrocas, numComparacoes);
    }

    *numComparacoes += 1;

}

void intercala(NoB **vetor, int inicio, int meio, int fim, int *numTrocas, int *numComparacoes)
{
    int tamVetorAux = (fim - inicio) + 1;
    NoB **vetorAux = new NoB*[tamVetorAux];  // vetor auxiliar.

    if(vetorAux == NULL)
    {
        cout<<"Erro ao alocar vetor.\n";
        exit(-1);
    }

    int indAux = 0;       // indice do vetor auxiliar.
    int indV1 = inicio;   // indice do vetor[inicio] a vetor[meio].
    int indV2 = meio + 1; // indice do vetor[meio+1] a vetor[fim].

    //Copia os elementos de forma ordenada de V1 ou V2 para vetorAux
    while(indV1 <= meio && indV2 <= fim) // verifica se os indices ainda estão dentro do limite do vetor.
    {

        int *vetorChavesIndV1 = vetor[indV1]->getVetorChaves();
        int elemIndV1 = vetorChavesIndV1[vetor[indV1]->getNumChaves() -1];

        int *vetorChavesIndV2 = vetor[indV2]->getVetorChaves();
        int elemIndV2 = vetorChavesIndV2[vetor[indV2]->getNumChaves() - 1];


        if(elemIndV1 < elemIndV2)  // Verifica qual valor é menor.
        {
            vetorAux[indAux] = vetor[indV1];
            indAux += 1;
            indV1 += 1;

        }
        else
        {
            vetorAux[indAux] = vetor[indV2];
            indAux += 1;
            indV2 += 1;

        }

        *numComparacoes += 3;
        *numTrocas +=1;
    }

    *numComparacoes += 1;

    if(indV1 <= meio) //se existem posições v1 não escritas em vetorAux.
    {

        while(indV1 <= meio)
        {
            vetorAux[indAux] = vetor[indV1];
            indAux += 1;
            indV1 += 1;
            *numComparacoes += 1;
            *numTrocas +=1;
        }
        *numComparacoes += 1;
    }
    else
    {
        if(indV2 <= fim) //se existem posições v2 não escritas em vetorAux.
        {
            while(indV2 <= fim)
            {
                vetorAux[indAux] = vetor[indV2];
                indAux += 1;
                indV2 += 1;
                *numComparacoes += 1;
                *numTrocas +=1;
            }

            *numComparacoes += 1;
        }
        *numComparacoes += 1;
    }
    *numComparacoes += 1;
    // copia os elementos de vetorAux para vetor.
    int j = inicio;
    for(int i = 0; i < tamVetorAux; ++i)
    {
        vetor[j] = vetorAux[i];
        ++j;
        *numTrocas +=1;
    }

    delete []vetorAux;
}

void merge(NoB **vetor, int inicio, int fim, int *numTrocas, int *numComparacoes)
{

    if(fim > inicio)
    {
        int meio = (fim + inicio) / 2;
        merge(vetor, inicio, meio, numTrocas, numComparacoes);
        merge(vetor, meio + 1, fim, numTrocas, numComparacoes);
        intercala(vetor, inicio, meio, fim, numTrocas, numComparacoes);
    }

    *numComparacoes += 1;
}
