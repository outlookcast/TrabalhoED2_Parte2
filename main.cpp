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

    AVL arvore;
    Data * dados = vetorRandomData(42);
    for(int i=0;i<15;i++)
    {
        cout<<dados[i].getQuestionID()<<" "<<dados[i].getUserID()<<" "<<dados[i].getDate()<<" "<<dados[i].getScore()<<" "<<dados[i].getTitle()<<endl;
        arvore.insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    cout<<endl;
    arvore.imprime();
    cout<<endl<<endl;
    cout<<"O UserID "<<dados[5].getUserID()<<" esta na arvore? "<<arvore.buscaQuestinIDUserID(dados[5].getQuestionID(),dados[5].getUserID())<<endl;

    delete [] dados;


    return 0;
}
