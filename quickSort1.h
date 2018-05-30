#include "Data.h"
#include "FrequenciaTag.h"

void swap(int *valor1, int *valor2);
void quicksort(int *vetor, int inicio, int fim, int *comparacoes, int *numCopias);
void quicksort(int *vetor, int n, int *comparacoes, int *numCopias);

void quicksort(Data *vetor, int inicio, int fim, int *comparacoes, int *numCopias);
void quicksort(Data *vetor, int n, int *comparacoes, int *numCopias);

void quicksort(FrequenciaTag *vetor, int inicio, int fim);
void quicksort(FrequenciaTag *vetor, int n);
void swap(FrequenciaTag *valor1, FrequenciaTag *valor2);
