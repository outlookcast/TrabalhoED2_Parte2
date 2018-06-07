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
*/


NoCor* ArvVerPre::menorSubArvDireita(NoCor *p)
{

    for(; p->getEsq() != NULL; p=p->getEsq());

    return p;
}


void ArvVerPre::insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{
    NoCor *noX = NULL;
    raiz = this->auxInsere(raiz,QuestionID,OwnerUserID,CreationDate,Score,Title,*&noX);

    raiz->setPai(NULL);

    if (raiz->calculaChave() != calculaChave(QuestionID,OwnerUserID))
        arrumaInsercao(noX);

    raiz->setCor(2);
}

NoCor *ArvVerPre::auxInsere(NoCor *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title, NoCor *&noX)
{
    if (p == NULL) //Insere um nó
    {
        p = new NoCor();

        p->QuestionID = QuestionID;
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

        if (calculaChave(QuestionID,OwnerUserID) > p->calculaChave()) //O local de inserção do x está a direita
        {

            p->setDir(auxInsere(p->getDir(),QuestionID,OwnerUserID,CreationDate,Score,Title,noX));
            p->getDir()->setPai(p);
        }
        else
        {

            if (calculaChave(QuestionID,OwnerUserID) <= p->calculaChave()) //O local de inserção do x está a esquerda
            {

                p->setEsq(auxInsere(p->getEsq(),QuestionID,OwnerUserID,CreationDate,Score,Title,noX));
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
        cout << p->calculaChave() << " " << p->getCor() << endl;
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
                        paiAvo->setEsq(rotacaoEsquerda(avo));

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
///REMOÇÃO
NoCor *ArvVerPre::minNoCor(NoCor *p)
{
    NoCor *x = p;
    while (x->getEsq() != NULL)
    {
        x = x->getEsq();
    }
    return x;
}


void ArvVerPre::rotacionarEsquerdaRemocao(NoCor *p)
{
    NoCor *c = p->getDir();
    p->setDir(c->getEsq());

    if (p->getDir() != NULL)
        p->getDir()->setPai(p);

    c->setPai(p->getPai());

    if (p->getPai() == NULL)
        raiz = c;
    else if (p == p->getPai()->getEsq())
        p->getPai()->setEsq(c);
    else
        p->getPai()->setDir(c);

    c->setEsq(p);
    p->setPai(c);
}

void ArvVerPre::rotacionarDireitaRemocao(NoCor *p)
{
    NoCor *c = p->getEsq();
    p->setEsq(c->getDir());

    if (p->getEsq() != NULL)
        p->getEsq()->setPai(p);

    c->setPai(p->getPai());

    if (p->getPai() == NULL)
        raiz = c;
    else if (p == p->getPai()->getEsq())
        p->getPai()->setEsq(c);
    else
        p->getPai()->setDir(c);

    c->setDir(p);
    p->setPai(c);
}
int ArvVerPre::retornaCor(NoCor *p)
{
    if(p==NULL)
        return 2;
    else
        return p->getCor();
}

void ArvVerPre::setColor(NoCor *p, int cor)
{
    p->setCor(cor);
}

void ArvVerPre::removeFix(NoCor *p)
{
    if (p == NULL)
        return;
    if (p == raiz)
    {
        raiz = NULL;
        return;
    }
    if (p->getCor() == 1 || retornaCor(p->getEsq()) == 1 || retornaCor(p->getDir()) == 1)
    {
        NoCor *child = p->getEsq() != NULL ? p->getEsq() : p->getDir();
        if (p == p->getPai()->getEsq())
        {
            p->getPai()->setEsq(child);
            if (child != NULL)
            {
                child->setPai(p->getPai());
                child->setCor(2);
            }
            delete (p);
        }
        else
        {
            p->getPai()->setDir(child);
            if (child != NULL)
            {
                child->setPai(p->getPai());
                child->setCor(2);
            }
            delete (p);
        }
    }
    else
    {
        NoCor *s = NULL;
        NoCor *pai = NULL;
        NoCor *ptr = p;
        ptr->setCor(3);
        while (ptr != raiz && retornaCor(ptr) == 3)
        {
            pai = ptr->getPai();
            if (ptr == pai->getEsq())
            {
                s = pai->getDir();
                if (retornaCor(s) == 1)
                {
                    s->setCor(2);
                    pai->setCor(1);
                    rotacionarEsquerdaRemocao(pai);
                }
                else
                {
                    if (retornaCor(s->getEsq()) == 2 && retornaCor(s->getDir()) == 2)
                    {
                        s->setCor(1);
                        if(retornaCor(pai) == 1)
                            pai->setCor(2);
                        else
                            pai->setCor(3);
                        ptr = pai;
                    }
                    else
                    {
                        if (retornaCor(s->getDir()) == 2 && retornaCor(s->getEsq()) == 2)
                        {
                            s->getEsq()->setCor(2);
                            s->setCor(1);
                            rotacaoDireita(s);
                            s = pai->getDir();
                        }
                        s->setCor(pai->getCor());
                        pai->setCor(2);
                        s->getDir()->setCor(2);
                        rotacionarEsquerdaRemocao(pai);
                        break;
                    }
                }
            }
            else
            {
                s = pai->getEsq();
                if (retornaCor(s) == 1)
                {
                    s->setCor(2);
                    pai->setCor(1);
                    rotacionarDireitaRemocao(pai);
                }
                else
                {
                    if (retornaCor(s->getEsq()) == 2 && retornaCor(s->getDir()) == 2)
                    {
                        s->setCor(1);
                        if (retornaCor(pai) == 1)
                            pai->setCor(2);
                        else
                            pai->setCor(3);
                        ptr = pai;
                    }
                    else
                    {
                        if (retornaCor(s->getEsq()) == 2&& retornaCor(s->getDir()) == 2)
                        {
                            s->getDir()->setCor(2);
                            s->setCor(1);
                            rotacionarEsquerdaRemocao(s);
                            s = pai->getEsq();
                        }
                        s->setCor(retornaCor(pai));
                        pai->setCor(2);
                        s->getEsq()->setCor(2);
                        rotacionarDireitaRemocao(pai);
                        break;
                    }
                }
            }
        }
        if (p == p->getPai()->getEsq())
            p->getPai()->setEsq(NULL);
        else
            p->getPai()->setEsq(NULL);
        delete(p);
        raiz->setCor(2);
    }
}

NoCor* ArvVerPre::removeNoCor(NoCor *r,int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{
    long long unsigned key = calculaChave(QuestionID,OwnerUserID);

    if (r == NULL)
        return r;

    if (key < r->calculaChave())
        return removeNoCor(r->getEsq(),QuestionID,OwnerUserID,CreationDate,Score,Title);

    if (key > r->calculaChave())
        return removeNoCor(r->getDir(),QuestionID,OwnerUserID,CreationDate,Score,Title);

    if (r->getEsq() == NULL || r->getDir() == NULL)
        return r;

    NoCor *t = minNoCor(r->getDir());

    r->QuestionID = t->QuestionID;
    r->OwnerUserID = t->OwnerUserID;
    r->CreationDate = t->CreationDate;
    r->Score = t->Score;
    r->Title = t->Title;

    return removeNoCor(r->getDir(),QuestionID,OwnerUserID,CreationDate,Score,Title);
}

void ArvVerPre::removerValorCor (int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{
    NoCor *p = removeNoCor(raiz,QuestionID,OwnerUserID,CreationDate,Score,Title);
    removeFix(p);
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

















































