#include "arvoreSplay.h"
#include <iostream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void arvoreSplay::rotacaoEsquerda(noSplay *x)
{
    noSplay *y = x->dir;
    if(y)
    {
        x->dir = y->esq;
        if(y->esq)
            y->esq->parent = x;
        y->parent = x->parent;
    }

    if(!x->parent)
        raiz = y;
    else if(x == x->parent->esq)
        x->parent->esq = y;
    else
        x->parent->dir = y;
    if(y)
        y->esq = x;
    x->parent = y;
}

void arvoreSplay::rotacaoDireita(noSplay *x)
{
    noSplay *y = x->esq;
    if(y)
    {
        x->esq = y->dir;
        if(y->dir)
            y->dir->parent = x;
        y->parent = x->parent;
    }
    if(!x->parent)
        raiz = y;
    else if(x == x->parent->esq)
        x->parent->esq = y;
    else
        x->parent->dir = y;
    if(y)
        y->dir = x;
    x->parent = y;
}

void arvoreSplay::splay(noSplay *x)
{
    while(x->parent)
    {
        if(!x->parent->parent)
        {
            if(x->parent->esq == x)
                rotacaoDireita(x->parent);
            else
                rotacaoEsquerda(x->parent);
        }
        else if(x->parent->esq == x && x->parent->parent->esq == x->parent)
        {
            rotacaoDireita(x->parent->parent);
            rotacaoDireita(x->parent);
        }
        else if(x->parent->dir == x && x->parent->parent->dir == x->parent)
        {
            rotacaoEsquerda(x->parent->parent);
            rotacaoEsquerda(x->parent);
        }
        else if(x->parent->esq == x && x->parent->parent->dir == x->parent)
        {
            rotacaoDireita(x->parent);
            rotacaoEsquerda(x->parent);
        }
        else
        {
            rotacaoEsquerda(x->parent);
            rotacaoDireita(x->parent);
        }
    }
}

void arvoreSplay::trocar(noSplay *x, noSplay *y)
{
    if(!x->parent)
        raiz = y;
    else if(x == x->parent->esq)
        x->parent->esq = y;
    else
        x->parent->dir = y;
    if(y)
        y->parent = x->parent;
}

noSplay * arvoreSplay::subArvoreMinima(noSplay *x)
{
    while(x->esq)
        x = x->esq;
    return x;
}

noSplay * arvoreSplay::subArvoreMaxima(noSplay *x)
{
    while(x->dir)
        x = x->dir;
    return x;
}

arvoreSplay::arvoreSplay()
{
    raiz = NULL;
    tamanho = 0;
}

void arvoreSplay::inserir(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{
    long long unsigned key = calculaChave(QuestionID,OwnerUserID);
    noSplay *z = raiz;
    noSplay *p = NULL;
    while(z)
    {
        p = z;
        if(z->chave > key)
            z = z->dir;
        else
            z = z-> esq;
    }

    z = new noSplay(QuestionID,OwnerUserID,CreationDate,Score,Title);
    z->parent = p;

    if(!p)
        raiz = z;
    else if(p->chave > z->chave)
        p->dir = z;
    else
        p->esq = z;

    splay(z);
    tamanho++;
}

noSplay * arvoreSplay::auxBusca(long long unsigned key)
{
    noSplay *z = raiz;
    while(z)
    {
        if (z->chave > key)
            z = z->dir;
        else if(z->chave < key)
            z = z->esq;
        else
            return z;
    }
    return NULL;
}


void arvoreSplay::auxDeletar(long long unsigned key)
{
    noSplay *z = auxBusca(key);
    if(!z)
        return;

    splay(z);

    if(!z->esq)
        trocar(z, z->dir);
    else if(!z->dir)
        trocar(z, z->esq);
    else
    {
        noSplay *y = subArvoreMinima(z->dir);
        if(y->parent != z)
        {
            trocar(y, y->dir);
            y->dir = z->dir;
            y->dir->parent = y;
        }
        trocar(z, y);
        y->esq = z->esq;
        y->esq->parent = y;
    }
    delete z;
    tamanho --;
}

void arvoreSplay::imprime()
{
    this->imprimeAux(this->raiz,0);
}

void arvoreSplay::imprimeAux(noSplay *x, int nivel)
{
    if(x != NULL)
    {
        cout<<"Nivel: "<<nivel<<" Valor: "<<x->chave<<endl;
        this->imprimeAux(x->esq,nivel+1);
        this->imprimeAux(x->dir,nivel+1);
    }
}

int arvoreSplay::getTamanho()
{
    return tamanho;
}

long long unsigned arvoreSplay::calculaChave(int QuestionID, int OwnerUserID)
{
    ///calcula chave
    string U_ID = convertePraString(OwnerUserID);
    string Q_ID = convertePraString(QuestionID);
    U_ID = completaString(U_ID);
    Q_ID = completaString(Q_ID);
    long long unsigned num = convertePraInt(U_ID,Q_ID);
    return num;
}

bool arvoreSplay::buscaQuestinIDUserID(int QuestionID,int UserID)
{
    long long unsigned chaveAux = calculaChave(QuestionID,UserID);
    noSplay * no = auxBusca(chaveAux);
    if(no != NULL)
    {
        splay(no);
        return true;
    }
    else
        return false;
}

bool arvoreSplay::buscaUserID(int UserID)
{
    long long unsigned chaveAux = calculaChave(0,UserID);
    noSplay * no = auxBuscaUserID(chaveAux,UserID);
    if(no != NULL)
    {
        splay(no);
        return true;
    }
    else
        return false;
}

noSplay * arvoreSplay::auxBuscaUserID(long long unsigned key, int UserID)
{
    noSplay *z = raiz;
    while(z)
    {
        if(z->OwnerUserID == UserID)
            return z;
        else
        {
            if (z->chave > key)
                z = z->dir;
            else if(z->chave < key)
                z = z->esq;
        }
    }
    return NULL;
}

void arvoreSplay::deletar(int QuestionID, int OwnerUserID)
{
    long long unsigned key = calculaChave(QuestionID,OwnerUserID);
    this->auxDeletar(key);
}
