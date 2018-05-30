#include <iostream>
#include "HashInt.h"

using namespace std;

HashInt::HashInt(int tam,int tipoDeColisao)
{
    this->tam = tam;
    this->array = new int [tam];
    for(int i=0; i<tam; i++)
    {
        this->array[i] = -1;
    }
    this->qnt = 0;

    this->numColisoes = 0;

    this->tipoDeColisao = tipoDeColisao;

}

HashInt::~HashInt()
{
    delete [] array;
}

int HashInt::funcaoHash(int val)
{
    return val % this->tam;
}

int HashInt::funcaoHash2(int val,int i)
{
    return (i - (val % i));
}

int HashInt::buscaTrataColisao(int val,int posicao)
{
    int i;
    for(i=posicao; i<this->tam; i++)
    {
        if(this->array[i] == val)
        {
            return i;
        }
    }
    if(i==tam) //Chegou no final e nao encontrou posição livre, portanto volta ao início
    {
        int j;
        for(j=0; j<posicao; j++)
        {
            if(this->array[j] == val)
            {
                return j;
            }
        }
        if(j==posicao)
        {
            cout<<"Valor não encontrado!"<<endl;
            exit(1);
        }
    }
}

void HashInt::trataColisaoSondagemLinear(int val,int posicao)
{
    int i;
    for(i=posicao; i<this->tam; i++)
    {
        if(this->array[i] == -1)
        {
            this->array[i] = val;
            this->qnt++;
            break;
        }
        else
        {
            this->numColisoes++;
        }
    }
    if(i==tam) //Chegou no final e nao encontrou posição livre, portanto volta ao início
    {
        int j;
        for(j=0; j<posicao; j++)
        {
            if(this->array[j] == -1)
            {
                this->array[j] = val;
                this->qnt++;
                break;
            }
            else
            {
                this->numColisoes++;
            }
        }
        if(j==posicao)
        {
            cout<<"Array lotado!!"<<endl;
        }
    }
}


void HashInt::inserir(int val)
{
    int posicao = this->funcaoHash(val);

    if(this->array[posicao] == -1)
    {
        this->array[posicao] = val;
        this->qnt++;
    }
    else
    {
        if( this->qnt < this->tam)
        {
            if(this->tipoDeColisao == 1)
            {
                this->trataColisaoSondagemLinear(val,posicao);
            }
            else if(this->tipoDeColisao == 2)
            {
                this->trataColisaoSondagemQuadratica(val,posicao);
            }
            else if(this->tipoDeColisao == 3)
            {
                this->trataColisaoSondagemDuploHash(val,posicao);
            }
        }

    }

}

void HashInt::remover(int val)
{
    int posicao = this->funcaoHash(val);
    if(this->array[posicao] == val)
    {
        this->array[posicao] = -1; // removendo
    }
    else
    {
        int novaPosicao = buscaTrataColisao(val,posicao);
        this->array[novaPosicao] = -1; //removendo
    }
}

void HashInt::imprimir()
{
    for(int i=0; i<this->tam; i++)
        cout<<this->array[i]<<" ";
    cout<<endl;
}


void HashInt::trataColisaoSondagemQuadratica(int val, int posicao)
{
    int index;
    int i = 0;
    while(true)
    {
        index = (val + i*i) % tam;
        if (this->array[index] == -1)
        {
            this->array[index] = val;
            break;
        }
        else
            this->numColisoes++;
        i++;
    }
}

void HashInt::trataColisaoSondagemDuploHash(int val, int posicao)
{

    int i = 1;
    while(true)
    {
        this->numColisoes++;
        int f1 = this->funcaoHash(val);
        int f2 = this->funcaoHash2(val,i);
        //Calcula o novo hash
        int pos = (f1 + f2) % this->tam;
        if(this->array[pos] == -1)
        {
            this->array[pos] = val;
            this->qnt++;
            break;
        }
        i++;
    }
}

int HashInt::getNumColisoes()
{
    return this->numColisoes;
}

int HashInt::getQnt()
{
    return this->qnt;
}

bool HashInt::busca(int val)
{
    int posicao = this->funcaoHash(val);
    if(this->array[posicao] == val)
    {
        return true;
    }
    else
    {
        return this->buscaTrataColisao2(val,posicao);
    }
}

bool HashInt::buscaTrataColisao2(int val,int posicao)
{
    int i;
    for(i=posicao; i<this->tam; i++)
    {
        if(this->array[i] == val)
        {
            return true;
        }
    }
    if(i==tam) //Chegou no final e nao encontrou posição livre, portanto volta ao início
    {
        int j;
        for(j=0; j<posicao; j++)
        {
            if(this->array[j] == val)
            {
                return true;
            }
        }
        if(j==posicao)
        {
            return false;
        }
    }
}
