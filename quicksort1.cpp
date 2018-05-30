#include <iostream>
#include "quickSort1.h"
#include "Data.h"

void quicksort(int *vetor, int inicio, int fim, int *comparacoes, int *numCopias)
{

    if(inicio == fim)
        return;

    int meio = (inicio + fim)/2;     // seleciona o pivo.
    swap(vetor[inicio], vetor[meio]);

    int pivo = vetor[inicio];

    int inferior = inicio + 1;
    int superior = fim;

    while(inferior <= superior)
    {

        while(vetor[inferior] < pivo)
        {
            inferior += 1;
            *comparacoes += 1;

        }
        *comparacoes += 1;

        while(vetor[superior] > pivo)
        {
            superior -= 1;
            *comparacoes += 1;
        }
        *comparacoes += 1;

        if(inferior < superior)
        {
            swap(vetor[inferior++], vetor[superior--]);
            *numCopias += 1;
        }
        else
            inferior += 1;
    }
    swap(vetor[inicio], vetor[superior]);
    *numCopias += 1;

    if(inicio <  superior - 1)
        quicksort(vetor, inicio, superior, comparacoes, numCopias);

    if(superior+1 < fim)
        quicksort(vetor, superior+1, fim, comparacoes, numCopias);


}

void quicksort(int *vetor, int n, int *comparacoes, int *numCopias)
{

    int maior = 0;

    // Acha o maior elemento
    for(int i = 1; i < n; ++i)
    {

        if(vetor[i] > vetor[maior])
        {
            maior = i;
            *comparacoes += 1;
        }
        *comparacoes += 1;
    }


    swap(vetor[maior], vetor[n-1]);//coloca o maior elemento no final do vetor.
    *numCopias +=1;
    quicksort(vetor, 0, n-2, comparacoes, numCopias);
}

void swap(int *valor1, int *valor2)
{

    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;

}

void quicksort(Data *vetor, int inicio, int fim, int *comparacoes, int *numCopias)
{
    if(inicio == fim)
        return;
	int questionID;
    int userID;
    string date ;
    int score;
    string title;
    int meio = (inicio + fim)/2;     // seleciona o pivo.

    //swap(vetor[inicio], vetor[meio]);

	questionID = vetor[inicio].questionID;
    userID = vetor[inicio].userID;
    date = vetor[inicio].date;
    score = vetor[inicio].score;
    title = vetor[inicio].title;

    vetor[inicio].questionID = vetor[meio].questionID;
    vetor[inicio].userID = vetor[meio].userID;
    vetor[inicio].date = vetor[meio].date;
    vetor[inicio].score = vetor[meio].score;
    vetor[inicio].title = vetor[meio].title;

	vetor[meio].questionID = questionID;
    vetor[meio].userID = userID;
    vetor[meio].date = date;
    vetor[meio].score = score;
    vetor[meio].title = title;

    *numCopias += 1;
    int pivo = vetor[inicio].questionID;

    int inferior = inicio + 1;
    int superior = fim;

    while(inferior <= superior)
    {

        while(vetor[inferior].questionID < pivo)
        {
            inferior += 1;
            *comparacoes += 1;

        }
        *comparacoes += 1;

        while(vetor[superior].questionID > pivo)
        {
            superior -= 1;
            *comparacoes += 1;
        }
        *comparacoes += 1;

        if(inferior < superior)
        {
          //  swap(vetor[inferior++], vetor[superior--]);

  			questionID = vetor[inferior].questionID;
    		userID = vetor[inferior].userID;
    		date = vetor[inferior].date;
   			score = vetor[inferior].score;
    		title = vetor[inferior].title;

    		vetor[inferior].questionID = vetor[superior].questionID;
    		vetor[inferior].userID = vetor[superior].userID;
    		vetor[inferior].date = vetor[superior].date;
    		vetor[inferior].score = vetor[superior].score;
    		vetor[inferior].title = vetor[superior].title;

			vetor[superior].questionID = questionID;
   		    vetor[superior].userID = userID;
    		vetor[superior].date = date;
    		vetor[superior].score = score;
    		vetor[superior].title = title;
			inferior++;
			superior--;
            *numCopias += 1;
        }
        else
            inferior += 1;
    }
   // swap(vetor[inicio], vetor[superior]);

  	questionID = vetor[inicio].questionID;
    userID = vetor[inicio].userID;
    date = vetor[inicio].date;
   	score = vetor[inicio].score;
    title = vetor[inicio].title;
    vetor[inicio].questionID = vetor[superior].questionID;
    vetor[inicio].userID = vetor[superior].userID;
    vetor[inicio].date = vetor[superior].date;
    vetor[inicio].score = vetor[superior].score;
    vetor[inicio].title = vetor[superior].title;

	vetor[superior].questionID = questionID;
   	vetor[superior].userID = userID;
    vetor[superior].date = date;
    vetor[superior].score = score;
    vetor[superior].title = title;
    *numCopias += 1;

    if(inicio <  superior - 1)
        quicksort(vetor, inicio, superior, comparacoes, numCopias);

    if(superior+1 < fim)
        quicksort(vetor, superior+1, fim, comparacoes, numCopias);
}
void quicksort(Data *vetor, int n,  int *comparacoes, int *numCopias)
{
    int maior = 0;

    // Acha o maior elemento
    for(int i = 1; i < n; ++i)
    {

        if(vetor[i].questionID > vetor[maior].questionID)
        {
            maior = i;
            *comparacoes += 1;
        }
        *comparacoes += 1;
    }


 //   swap(vetor[maior], vetor[n-1]);//coloca o maior elemento no final do vetor.

	int questionID = vetor[maior].questionID;
    int userID = vetor[maior].userID;
    string date = vetor[maior].date;
    int score = vetor[maior].score;
    string title = vetor[maior].title;

    vetor[maior].questionID = vetor[n-1].questionID;
    vetor[maior].userID = vetor[n-1].userID;
    vetor[maior].date = vetor[n-1].date;
    vetor[maior].score = vetor[n-1].score;
    vetor[maior].title = vetor[n-1].title;

	vetor[n-1].questionID = questionID;
    vetor[n-1].userID = userID;
    vetor[n-1].date = date;
    vetor[n-1].score = score;
    vetor[n-1].title = title;

    *numCopias += 1;
    quicksort(vetor, 0, n-2, comparacoes, numCopias);
}

void quicksort(FrequenciaTag *vetor, int inicio, int fim)
{
  if(inicio == fim)
      return;

  int meio = (inicio + fim)/2;     // seleciona o pivo.
  swap(&vetor[inicio], &vetor[meio]);

  int pivo = vetor[inicio].frequencia;

  int inferior = inicio + 1;
  int superior = fim;

  while(inferior <= superior)
  {

      while(vetor[inferior].frequencia < pivo)
      {
          inferior += 1;


      }

      while(vetor[superior].frequencia > pivo)
      {
          superior -= 1;

      }


      if(inferior < superior)
      {
          swap(&vetor[inferior++], &vetor[superior--]);

      }
      else
          inferior += 1;
  }
  swap(&vetor[inicio], &vetor[superior]);


  if(inicio <  superior - 1)
      quicksort(vetor, inicio, superior-1);

  if(superior+1 < fim)
      quicksort(vetor, superior+1, fim);



}

void quicksort(FrequenciaTag *vetor, int n)
{
  int maior = 0;

  // Acha o maior elemento
  for(int i = 1; i < n; ++i)
  {

      if(vetor[i].frequencia > vetor[maior].frequencia)
      {
          maior = i;

      }

  }


  swap(&vetor[maior], &vetor[n-1]);//coloca o maior elemento no final do vetor.

  quicksort(vetor, 0, n-2);

}

void swap(FrequenciaTag *valor1, FrequenciaTag *valor2)
{
  FrequenciaTag temp;
  temp.frequencia = valor1->frequencia;
  temp.tag = valor1->tag;

  valor1->frequencia = valor2->frequencia;
  valor1->tag = valor2->tag;

  valor2->frequencia = temp.frequencia;
  valor2->tag = temp.tag;

}
