#include "ArvVerPre.h"
#include <iostream>
#include "FuncoesAuxiliares.h"

using namespace std;

int main()
{
    ArvVerPre arvore;
    Data * dados = vetorRandomData(42);
    for(int i=0;i<5;i++)
    {
        cout<<dados[i].getQuestionID()<<" "<<dados[i].getScore()<<endl;
        arvore.insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<endl;
    arvore.imprime();

    delete [] dados;
}
