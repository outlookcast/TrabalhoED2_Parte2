#include "arvoreSplay.h"
#include <iostream>
#include "FuncoesAuxiliares.h"

using namespace std;

int main()
{
    arvoreSplay arvore;
    Data * dados = vetorRandomData(42);
    for(int i=0;i<5;i++)
    {
        cout<<dados[i].getQuestionID()<<" "<<dados[i].getScore()<<endl;
        arvore.inserir(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    arvore.imprime();
    delete [] dados;
}
