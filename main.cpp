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

using namespace std;


int main()
{

    arvoreSplay arvore;
    Data * dados = vetorRandomData(4500);
    for(int i=0;i<300;i++)
    {
        arvore.inserir(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<endl;
    arvore.imprime();
    cout<<endl<<endl;
    cout<<"Inicio da busca"<<endl;
    cout<<"O UserID "<<dados[301].getUserID()<<" esta na arvore? "<<arvore.buscaUserID(dados[301].getUserID())<<endl;

    delete [] dados;


    return 0;
}
