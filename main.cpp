#include <iostream>
#include "FuncoesAuxiliares.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "arvoreSplay.h"
#include "AVL.h"
#include "ArvVerPre.h"
#include <time.h>
#include "Testes.h"

using namespace std;


int main()
{
    //geraSaida(100000);

    ArvVerPre arvore;
    int tam = 500000;
    Data * dados = vetorRandomData(tam);
    for(int i=0;i<tam-1;i++)
    {
        arvore.insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    //arvore.imprime();
    /*
    for(int i=0;i<tam;i++)
    {
        if(i == (int)tam/10)
            cout<<"10%"<<endl;
        else if(i == (int)tam/4)
            cout<<"25%"<<endl;
        else if(i == (int)tam/2)
            cout<<"50%"<<endl;
        arvore.insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<"Fim da insercao"<<endl;
    for(int i=0;i<tam;i++)
    {
        arvore.buscaUserID(dados[i].getUserID());

        if(i == (int)tam/10)
            cout<<"10%"<<endl;
        else if(i == (int)tam/4)
            cout<<"25%"<<endl;
        else if(i == (int)tam/2)
            cout<<"50%"<<endl;
    }
    tf = clock();
    double tempo_gasto = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
    cout<<"Tempo gasto: "<<tempo_gasto<<endl;
    cout<<endl;
    //arvore.imprime();
    cout<<endl<<endl;
    cout<<"Inicio da busca"<<endl;





*/
    delete [] dados;

    return 0;
}
