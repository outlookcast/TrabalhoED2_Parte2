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
/*
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
*/

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


void ArvVerPre::insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{
    NoCor *noX = NULL;
    int a = 0;
    long long unsigned x = calculaChave(QuestionID,OwnerUserID);
    raiz = this->auxInsere(raiz, QuestionID,OwnerUserID,CreationDate,Score,Title, *&noX);

    raiz->setPai(NULL);

    if (raiz->calculaChave() != x)
        arrumaInsercao(noX);

    raiz->setCor(2);
}

NoCor *ArvVerPre::auxInsere(NoCor *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title, NoCor *&noX)
{
    long long unsigned x = calculaChave(QuestionID,OwnerUserID);
    if (p == NULL) //Insere um nó
    {
        p = new NoCor;

        p->QuestionID = QuestionID;
        p->OwnerUserID = OwnerUserID;
        p->CreationDate = CreationDate;
        p->Title = Title;
        p->Score = Score;

        p->setDir(NULL);
        p->setEsq(NULL);
        p->setCor(1);
        noX = p;
    }
    else
    {

        if (x > p->calculaChave()) //O local de inserção do x está a direita
        {

            p->setDir(auxInsere(p->getDir(),QuestionID,OwnerUserID,CreationDate,Score,Title, noX));
            p->getDir()->setPai(p);
        }
        else
        {

            if (x <= p->calculaChave()) //O local de inserção do x está a esquerda
            {

                p->setEsq(auxInsere(p->getEsq(),QuestionID,OwnerUserID,CreationDate,Score,Title, noX));
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
        cout << p->QuestionID << " " << p->getCor() << endl;
        imprimePorNivel(p->getEsq(), nivel + 1);
        imprimePorNivel(p->getDir(), nivel + 1);
    }
}

///OK
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

///OK
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
                {
                    //avo é a raiz
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
                {
                    //avo é a raiz
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

long long unsigned ArvVerPre::calculaChave(int QuestionID, int OwnerUserID)
{
    ///calcula chave
    string U_ID = convertePraString(OwnerUserID);
    string Q_ID = convertePraString(QuestionID);
    U_ID = completaString(U_ID);
    Q_ID = completaString(Q_ID);
    long long unsigned num = convertePraInt(U_ID,Q_ID);
    return num;
}

bool ArvVerPre::buscaQuestinIDUserID(int QuestionID, int UserID)
{
    return this->auxBuscaQuestinIDUserID(this->raiz,QuestionID,UserID);
}

bool ArvVerPre::auxBuscaQuestinIDUserID(NoCor * p, int QuestionID, int UserID)
{

    if(p != NULL)
    {
        if(calculaChave(QuestionID,UserID) == p->calculaChave())
            return true;
        else
        {
            if(calculaChave(QuestionID,UserID) > p->calculaChave())
            {
                cout<<calculaChave(QuestionID,UserID)<<" e maior que "<<p->calculaChave()<<endl<<endl;
                return auxBuscaQuestinIDUserID(p->getDir(),QuestionID,UserID);
            }
            else
            {
                cout<<calculaChave(QuestionID,UserID)<<" e menor que "<<p->calculaChave()<<endl<<endl;
                return auxBuscaQuestinIDUserID(p->getEsq(),QuestionID,UserID);
            }
        }
    }
    else
    {
        return false;
    }
}

bool ArvVerPre::buscaUserID(int UserID)
{
    this->auxBuscaUserID(this->raiz,UserID);
}

bool ArvVerPre::auxBuscaUserID(NoCor * no,int UserID)
{
    if(no != NULL)
    {
        if(UserID == no->OwnerUserID)
            return true;
        else
        {
            if(calculaChave(0,UserID) > no->calculaChave())
            {
                cout<<calculaChave(0,UserID)<<"e maior que "<<no->calculaChave()<<endl<<endl;
                return auxBuscaUserID(no->getDir(),UserID);
            }
            else
            {
                cout<<calculaChave(0,UserID)<<" e menor que "<<no->calculaChave()<<endl<<endl;
                return auxBuscaUserID(no->getEsq(),UserID);
            }
        }
    }
    else
    {
        return false;
    }
}
