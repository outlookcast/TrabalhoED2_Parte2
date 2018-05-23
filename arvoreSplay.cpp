#include "arvoreSplay.h"
#include <iostream>

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

void arvoreSplay::deletar(int key)
{
    noSplay *z = busca(key);
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

noSplay * arvoreSplay::busca(int key)
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


void arvoreSplay::inserir(int key,int OwnerUserID, string CreationDate, int Score, string Title)
{
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

    z = new noSplay(key,OwnerUserID,CreationDate,Score,Title);
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

arvoreSplay::arvoreSplay()
{
    raiz = NULL;
    tamanho = 0;
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
