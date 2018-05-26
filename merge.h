#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
#include "NoB.h"

void intercala(int *vetor, int inicio, int meio, int fim, int *numTrocas, int *numComparacoes);
void merge(int *vetor, int inicio, int fim, int *numTrocas, int *numComparacoes);
void merge(int *vetor, int tam, int *numTrocas, int *numComparacoes);
void intercala(NoB **vetor, int inicio, int meio, int fim, int *numTrocas, int *numComparacoes);
void merge(NoB **vetor, int inicio, int fim, int *numTrocas, int *numComparacoes);
#endif
