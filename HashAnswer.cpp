#include "HashAnswer.h"
#include <iostream>
#include <list>
#include "answer.h"
#include "HashInt.h"
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

HashAnswer::HashAnswer(int tam)
{
    this->tam = tam;
    this->array = new Answer[this->tam];
    this->qnt = 0;
    this->numColisoes = 0;
}

HashAnswer::~HashAnswer()
{
    delete [] this->array;
}

int HashAnswer::getQnt()
{
    return this->qnt;
}

int HashAnswer::getNumColisoes()
{
    return this->numColisoes;
}

void HashAnswer::inserir(Answer answer)
{
    int posicao = this->funcaoHash(answer);
    if(this->array[posicao].getUserID() == -1 && this->array[posicao].getQuestionID() == -1)
    {
        this->array[posicao].setUserID(answer.getUserID());
        this->array[posicao].setAnswerID(answer.getAnswerID());
        this->array[posicao].setDate(answer.getDate());
        this->array[posicao].setQuestionID(answer.getQuestionID());
        this->array[posicao].setScore(answer.getScore());
    }
    else
    {
        this->numColisoes++;
        this->trataColisao(answer,posicao);
    }
    this->qnt++;
}

int HashAnswer::funcaoHash(Answer answer)
{
    return answer.getUserID() % this->tam;
}


void HashAnswer::trataColisao(Answer answer,int posicao)
{
    this->array[posicao].inserirNaLista(answer);
}

vector<FrequenciaTag> HashAnswer::frequenciaDeTodosUsuarios()
{
    HashInt * hash = new HashInt(this->qnt,1);
    int numUsuariosNaoRepetidos = 0;
    vector<FrequenciaTag> vetor;
    for(int i=0; i<this->tam; i++)
    {
        if(this->array[i].getUserID() != -1 && this->array[i].getQuestionID() != -1)
        {
            if(hash->busca(this->array[i].getUserID()) == false)
            {
                hash->inserir(this->array[i].getUserID());
                FrequenciaTag a;
                stringstream ss;
                ss << this->array[i].getUserID();
                string str = ss.str();
                a.tag = str;
                a.frequencia = this->frenquenciaUsuario(this->array[i]);
                vetor.push_back(a);
                numUsuariosNaoRepetidos++;
            }
        }
    }
    delete hash;
    return vetor;
}

int HashAnswer::frenquenciaUsuario(Answer user)
{
    int posicao = this->funcaoHash(user);
    int userID = user.getUserID();
    int frequencia = 1;
    list<Answer> lst = this->array[posicao].getLista();
    for (list<Answer>::iterator i = lst.begin(); i != lst.end(); ++i)
    {
        if(i->getUserID() == userID )
        {
            frequencia++;
        }
    }
    return frequencia;
}

void HashAnswer::imprimir()
{
    int contador = 0;
    int colisao = 0;
    for(int i=0; i<this->tam; i++)
    {
        if(this->array[i].getUserID() != -1 && this->array[i].getQuestionID() != -1)
        {
            contador++;
            colisao += array[i].getLista().size();
            if(array[i].getLista().size() > 0)
            {
                cout<<"User ID"<<array[i].getLista().front().getUserID();
                cout<<"Date: "<<array[i].getLista().front().getDate();
            }
        }
    }
    cout<<"Numero de itens: "<<contador<<endl;
    cout<<"Numero de colisoes: "<<colisao<<endl;

}
