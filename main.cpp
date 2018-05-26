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

using namespace std;


int main()
{

    arvoreSplay arvore;
    Data * dados = vetorRandomData(42);
    for(int i=0;i<10;i++)
    {
        cout<<dados[i].getQuestionID()<<" "<<dados[i].getUserID()<<" "<<dados[i].getDate()<<" "<<dados[i].getScore()<<" "<<dados[i].getTitle()<<endl;
        arvore.inserir(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<endl;
    arvore.imprime();

    delete [] dados;


    return 0;
}
