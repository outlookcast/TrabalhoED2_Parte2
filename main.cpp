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

    ArvVerPre arvore;
    Data * dados = vetorRandomData(40);
    for(int i=0;i<15;i++)
    {
        arvore.insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<endl;
    arvore.imprime();
    cout<<endl<<endl;
    cout<<"Inicio da busca"<<endl;
    cout<<"O UserID "<<dados[5].getUserID()<<" esta na arvore? "<<arvore.buscaUserID(dados[5].getUserID())<<endl;

    delete [] dados;


    return 0;
}
