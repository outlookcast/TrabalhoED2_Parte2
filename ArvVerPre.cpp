// pagina 92
#include "ArvVerPre.h"

ArvVerPre::ArvVerPre()
{

    raiz = NULL;
}
ArvVerPre::~ArvVerPre()
{

    raiz = libera(raiz);
}

NoCor *ArvVerPre::libera(NoCor *p)
{

    if (p != NULL)
    {

        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }

    return NULL;
}

int ArvVerPre::getRaiz()
{

    if (raiz != NULL)
        return raiz->getInfo();

    else
    {
        cout << "Erro, arvore vazia\n";
        exit(1);
    }
}

bool ArvVerPre::vazia()
{

    if (raiz == NULL)
    {

        return true;
    }
    else
    {

        return false;
    }
}

bool ArvVerPre::busca(int x)
{

    return auxBusca(raiz, x);
}

bool ArvVerPre::auxBusca(NoCor *p, int c)
{

    if (p != NULL)
    {

        if (p->getInfo() == c)
            return true;

        else
        {

            if (c > p->getInfo())
                return auxBusca(p->getDir(), c);

            else
                return auxBusca(p->getEsq(), c);
        }
    }
    else
    {

        return false;
    }
}

void ArvVerPre::remove(int C)
{
    NoCor *x = NULL;
    raiz = auxRemove(raiz, C, *&x);
    if(x->getCor() == 2)
      arrumaRemocao(x);
}

void ArvVerPre::arrumaRemocao(NoCor *x)
{

    while(x != raiz && x->getCor() == 2)
    {
        if(x->getPai()->getEsq() == x)
        {
            NoCor *w = x->getPai()->getDir(); //w é o irmão de x

            if(w != NULL && w->getCor() == 1)
            {

            }

        }
        else
        {


        }
    }

}

NoCor* ArvVerPre::auxRemove(NoCor* p, int C, NoCor *&x)
{
    if(p == NULL)
        return NULL;
    else if(C < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), C, x));
    else if(C > p->getInfo())
        p->setDir(auxRemove(p->getDir(), C, x));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
        {
           NoCor *paiP = p->getPai();
           p = removeFolha(p);
           NoCor *newNo = new NoCor;
           newNo->setInfo(-1);
           newNo->setCor(2);
           newNo->setPai(paiP);
           x = newNo;

        }
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
        {
          NoCor *paiP = p->getPai();
          p = remove1Filho(p);
          p->setPai(paiP);
          x = p;
        }
        else
        {
            NoCor *aux = menorSubArvDireita(p->getDir());
            int auxC = aux->getInfo();
            p->setInfo(auxC);
            aux->setInfo(C);
            p->setDir(auxRemove(p->getDir(), C, x));
            x = p;
        }
    }
    return p;
}

NoCor* ArvVerPre::removeFolha(NoCor *p)
{
    delete p;
    return NULL;
}

NoCor* ArvVerPre::remove1Filho(NoCor *p)
{
    NoCor *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}


NoCor* ArvVerPre::menorSubArvDireita(NoCor *p)
{

    for(; p->getEsq() != NULL; p=p->getEsq());

    return p;
}


void ArvVerPre::insere(int x,int OwnerUserID, string CreationDate, int Score, string Title)
{
    NoCor *noX = NULL;
    int a = 0;
    raiz = this->auxInsere(raiz, x,OwnerUserID,CreationDate,Score,Title, *&noX);

    raiz->setPai(NULL);

    if (raiz->getInfo() != x)
        arrumaInsercao(noX);

    raiz->setCor(2);
}

NoCor *ArvVerPre::auxInsere(NoCor *p, int x,int OwnerUserID, string CreationDate, int Score, string Title, NoCor *&noX)
{

    if (p == NULL) //Insere um nó
    {
        p = new NoCor;
        p->setInfo(x);
        p->OwnerUserID = OwnerUserID;
        p->CreationDate = CreationDate;
        p->Score = Score;
        p->Title = Title;
        p->setDir(NULL);
        p->setEsq(NULL);
        p->setCor(1);
        noX = p;
    }
    else
    {

        if (x > p->getInfo()) //O local de inserção do x está a direita
        {

            p->setDir(auxInsere(p->getDir(), x,OwnerUserID,CreationDate,Score,Title, noX));
            p->getDir()->setPai(p);
        }
        else
        {

            if (x <= p->getInfo()) //O local de inserção do x está a esquerda
            {

                p->setEsq(auxInsere(p->getEsq(), x,OwnerUserID,CreationDate,Score,Title, noX));
                p->getEsq()->setPai(p);
            }
        }
    }

    return p;
}
void ArvVerPre::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvVerPre::imprimePorNivel(NoCor *p, int nivel)
{
    if (p != NULL)
    {
        cout << "(" << nivel << ")";
        for (int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << " " << p->getCor()<<" "<< p->Score<<endl;
        imprimePorNivel(p->getEsq(), nivel + 1);
        imprimePorNivel(p->getDir(), nivel + 1);
    }
}
NoCor *ArvVerPre::rotacaoEsquerda(NoCor *x)
{

    NoCor *novaRaiz = x->getDir();

    novaRaiz->setPai(x->getPai());
    x->setPai(novaRaiz);

    if (novaRaiz->getEsq() != NULL)
        novaRaiz->getEsq()->setPai(x);

    x->setDir(novaRaiz->getEsq());
    novaRaiz->setEsq(x);

    return novaRaiz;
}
NoCor *ArvVerPre::rotacaoDireita(NoCor *x)
{
    NoCor *novaRaiz = x->getEsq();

    novaRaiz->setPai(x->getPai());
    x->setPai(novaRaiz);
    if (novaRaiz->getDir() != NULL)
        novaRaiz->getDir()->setPai(x);

    x->setEsq(novaRaiz->getDir());
    novaRaiz->setDir(x);

    return novaRaiz;
}
void ArvVerPre::arrumaInsercao(NoCor *z)
{

    while (z->getPai()->getCor() == 1)
    {

        NoCor *avo = z->getPai()->getPai();

        NoCor *y = NULL;

        if (z->getPai() == avo->getEsq())
        {
            y = avo->getDir();

            if (y != NULL && y->getCor() == 1)
            {

                z->getPai()->setCor(2);
                y->setCor(2);
                avo->setCor(1);
                z = avo;
            }
            else
            {
                if (z == z->getPai()->getDir())
                {
                    z = z->getPai();
                    avo->setEsq(rotacaoEsquerda(avo->getEsq()));
                }

                z->getPai()->setCor(2);
                avo->setCor(1);
                NoCor *paiAvo = avo->getPai();
                if (paiAvo == NULL)
                { //avo é a raiz
                    raiz = rotacaoDireita(avo);
                }
                else
                {
                    if (paiAvo->getDir() == avo)
                        paiAvo->setDir(rotacaoDireita(avo));

                    else
                        paiAvo->setEsq(rotacaoDireita(avo));
                }
            }
        }
        else
        {
            y = avo->getEsq();

            if (y != NULL && y->getCor() == 1)
            {

                z->getPai()->setCor(2);
                y->setCor(2);
                avo->setCor(1);
                z = avo;
            }
            else
            {
                if (z == z->getPai()->getEsq())
                {
                    z = z->getPai();
                    avo->setDir(rotacaoDireita(avo->getDir()));
                }

                z->getPai()->setCor(2);
                avo->setCor(1);
                NoCor *paiAvo = avo->getPai();
                if (paiAvo == NULL)
                { //avo é a raiz
                    raiz = rotacaoEsquerda(avo);
                }
                else
                {
                    if (paiAvo->getEsq() == avo)
                        paiAvo->setDir(rotacaoEsquerda(avo));

                    else
                        paiAvo->setDir(rotacaoEsquerda(avo));
                }
            }
        }

        if (z == NULL)
            return;

        if (z->getPai() == NULL)
            return;
    }
}
