#include <iostream>
#include "HashBuscaAnswer.h"
#include "answer.h"

using namespace std;

HashBuscaAnswer::HashBuscaAnswer(int tam)
{
    this->tam = tam;
    this->array = new Answer[this->tam];
}

HashBuscaAnswer::~HashBuscaAnswer()
{
    delete [] this->array;
}


int HashBuscaAnswer::funcaoHash(int questionID)
{
    return questionID % this->tam;
}

int HashBuscaAnswer::funcaoHash(Answer answer)
{
    return answer.getQuestionID() % this->tam;
}

list<int> HashBuscaAnswer::busca(int questionID)
{
    int posicao = funcaoHash(questionID);
    list<int> lista;
    if(this->array[posicao].getQuestionID() == questionID)
    {
        lista.push_back(this->array[posicao].getUserID());
    }
    list<Answer> listaAuxiliar = this->array[posicao].getLista();

    for (list<Answer>::iterator i = listaAuxiliar.begin(); i != listaAuxiliar.end(); ++i)
    {
        if(i->getQuestionID() == questionID )
        {
            lista.push_back(i->getUserID());
        }
    }
    return lista;
}

void HashBuscaAnswer::insere(Answer answer)
{
    int posicao = this->funcaoHash(answer.getQuestionID());
    if(this->array[posicao].getQuestionID() == -1)
    {
        this->array[posicao].setQuestionID(answer.getUserID());
        this->array[posicao].setAnswerID(answer.getAnswerID());
        this->array[posicao].setDate(answer.getDate());
        this->array[posicao].setScore(answer.getScore());
        this->array[posicao].setUserID(answer.getUserID());
    }
    else
    {
        this->array[posicao].inserirNaLista(answer);
    }
}

