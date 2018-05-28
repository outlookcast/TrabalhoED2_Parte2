// pagina 92
#include "AVL.h"

AVL::AVL()
{

    raiz = NULL;
}
AVL::~AVL()
{

    raiz = libera(raiz);

}

NoAVL* AVL::libera(NoAVL *p)
{

    if(p != NULL)
    {

        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }

    return NULL;

}

bool AVL::vazia()
{

    if(raiz == NULL)
    {

        return true;
    }
    else
    {

        return false;
    }
}

bool AVL::busca(int x)
{

    return auxBusca(raiz, x);

}

/*
void AVL::remove(int C)
{
    raiz = auxRemove(raiz, C);
    raiz = balanciamentoInsert(raiz);
}

NoAVL* AVL::auxRemove(NoAVL* p, int C)
{
    if(p == NULL)
        return NULL;
    else if(C < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), C));
    else if(C > p->getInfo())
        p->setDir(auxRemove(p->getDir(), C));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoAVL *aux = menorSubArvDireita(p->getDir());
            int auxC = aux->getInfo();
            p->setInfo(auxC);
            aux->setInfo(C);
            p->setDir(auxRemove(p->getDir(), C));
        }
    }
    return p;
}
*/

NoAVL* AVL::removeFolha(NoAVL *p)
{
    delete p;
    return NULL;
}

NoAVL* AVL::remove1Filho(NoAVL *p)
{
    NoAVL *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}


NoAVL* AVL::menorSubArvDireita(NoAVL *p)
{

    for(; p->getEsq() != NULL; p=p->getEsq());

    return p;
}

bool AVL::auxBusca(NoAVL * p, long long unsigned c)
{

    if(p != NULL)
    {

        if(p->calculaChave() == c)
            return true;

        else
        {

            if(c>p->calculaChave())
                return auxBusca(p->getDir(), c);

            else
                return auxBusca(p->getEsq(),c);

        }


    }
    else
    {

        return false;
    }

}

void AVL::insere(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{

    raiz = auxInsere(raiz, QuestionID,OwnerUserID,CreationDate,Score,Title);


}

NoAVL* AVL::auxInsere(NoAVL *p, int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title)
{

    long long unsigned x = calculaChave(QuestionID,OwnerUserID);

    if(p == NULL)     //Insere um nó
    {
        p = new NoAVL;

        p->QuestionID = QuestionID;
        p->OwnerUserID = OwnerUserID;
        p->CreationDate = CreationDate;
        p->Score = Score;
        p->Title = Title;

        p->setDir(NULL);
        p->setEsq(NULL);
        p->setAltura(0);
        p->setBalanciamento(0);

    }
    else
    {

        if(x > p->calculaChave())    //O local de inserção do x está a direita
        {

            p->setDir(auxInsere(p->getDir(),QuestionID,OwnerUserID,CreationDate,Score,Title));


        }
        else
        {

            if(x < p->calculaChave())//O local de inserção do x está a esquerda
            {

                p->setEsq(auxInsere(p->getEsq(),QuestionID,OwnerUserID,CreationDate,Score,Title));
            }
        }

        int alturaD = 0;
        if(p->getDir() != NULL)
            alturaD = p->getDir()->getAltura() + 1;    //Calcula a altura da subArvore a direita

        int alturaE = 0;
        if(p->getEsq() != NULL)
            alturaE = p->getEsq()->getAltura() + 1;   //calcula a altura da subArvore a esquerda

        if(alturaD > alturaE)
            p->setAltura(alturaD);    //A maior altura é da subArvore a direita

        else
            p->setAltura(alturaE);   //A maior altura é da subArvore a esquerda

        p->setBalanciamento(alturaD - alturaE);   //calcula o balanciamento

        if(p->getBalanciamento() == -2) //Verifica se a árvore está desbanceada para a esquerda
        {
            if(p->getEsq() != NULL)
                if(p->getEsq()->getBalanciamento() == 1) //Verifica se o filho a esquerda está desbalanceado a direita
                    p->setEsq(rotacaoEsquerda(p->getEsq()));

            return rotacaoDireita(p);

        }
        else if(p->getBalanciamento() == 2)//Verifica se a árvore está desbanceada para a direita
        {
            if(p->getDir() != NULL)
                if(p->getDir()->getBalanciamento() == -1)  //Verifica se o filho a direita está desbalanceado a esquerda
                    p->setDir(rotacaoDireita(p->getDir()));

            return rotacaoEsquerda(p);

        }

    }

    return p;


}


void AVL::imprime()
{
    imprimePorNivel(raiz, 0);
}

void AVL::imprimePorNivel(NoAVL* p, int nivel)
{
    if (p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << calculaChave(p->QuestionID,p->OwnerUserID)<<endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }

}


NoAVL* AVL::rotacaoEsquerda(NoAVL *x)
{

    NoAVL *novaRaiz = x->getDir();
    x->setDir(novaRaiz->getEsq());
    novaRaiz->setEsq(x);

    int alturaDir = 0;
    int alturaEsq = 0;

    if(x->getDir() != NULL)
        int alturaDir = x->getDir()->getAltura() + 1;
    if(x->getEsq() != NULL)
        int alturaEsq = x->getEsq()->getAltura() + 1;

    if(alturaDir > alturaEsq)
        x->setAltura(alturaDir);

    else
        x->setAltura(alturaEsq);

    x->setBalanciamento(alturaDir - alturaEsq);

    if(novaRaiz->getDir() != NULL )
        alturaDir = novaRaiz->getDir()->getAltura() + 1;
    if(novaRaiz->getEsq() != NULL)
        alturaEsq = novaRaiz->getEsq()->getAltura() + 1;

    if(alturaDir > alturaEsq)
        novaRaiz->setAltura(alturaDir);

    else
        novaRaiz->setAltura(alturaEsq);

    novaRaiz->setBalanciamento(alturaDir - alturaEsq);

    return novaRaiz;

}
NoAVL* AVL::rotacaoDireita(NoAVL *x)
{
    NoAVL *novaRaiz = x->getEsq();
    x->setEsq(novaRaiz->getDir());
    novaRaiz->setDir(x);

    int alturaDir = 0;
    int alturaEsq = 0;

    if(x->getDir() != NULL)
        int alturaDir = x->getDir()->getAltura() + 1;
    if(x->getEsq() != NULL)
        int alturaEsq = x->getEsq()->getAltura() + 1;

    if(alturaDir > alturaEsq)
        x->setAltura(alturaDir);

    else
        x->setAltura(alturaEsq);

    x->setBalanciamento(alturaDir - alturaEsq);

    if(novaRaiz->getDir() != NULL )
        alturaDir = novaRaiz->getDir()->getAltura() + 1;
    if(novaRaiz->getEsq() != NULL)
        alturaEsq = novaRaiz->getEsq()->getAltura() + 1;

    if(alturaDir > alturaEsq)
        novaRaiz->setAltura(alturaDir);

    else
        novaRaiz->setAltura(alturaEsq);

    novaRaiz->setBalanciamento(alturaDir - alturaEsq);

    return novaRaiz;

}

void AVL::rotacaoD(long long unsigned x)
{
    NoAVL *anterior = NULL;
    NoAVL *aux = raiz;

    while(aux->calculaChave() != x)
    {
        anterior = aux;
        if(x > aux->calculaChave())
            aux = aux->getDir();

        else
            aux = aux->getEsq();

    }

    if(anterior->getDir() == aux)
        anterior->setDir(rotacaoDireita(aux));

    else
        anterior->setEsq(rotacaoDireita(aux));



}
void AVL::rotacaoE(long long unsigned x)
{
    NoAVL *anterior = NULL;
    NoAVL *aux = raiz;

    while(aux->calculaChave() != x)
    {
        anterior = aux;
        if(x > aux->calculaChave())
            aux = aux->getDir();

        else
            aux = aux->getEsq();

    }

    if(anterior == NULL)
    {
        raiz = rotacaoEsquerda(aux);
        return;

    }

    if(anterior->getDir() == aux)
        anterior->setDir(rotacaoEsquerda(aux));

    else
        anterior->setEsq(rotacaoEsquerda(aux));

}

NoAVL* AVL::balanciamentoInsert(NoAVL *x)
{

    if(x == NULL)
        return NULL;

    int alturaD = 0;
    int alturaE = 0;

    if(x->getDir() != NULL)
    {
        x->setDir(balanciamentoInsert(x->getDir()));
        alturaD += 1 + x->getDir()->getAltura();
    }

    if(x->getEsq() != NULL)
    {
        x->setEsq(balanciamentoInsert(x->getEsq()));
        alturaE += 1 + x->getEsq()->getAltura();

    }

    if(alturaD > alturaE)
    {
        x->setAltura(alturaD);
    }
    else
        x->setAltura(alturaE);

    x->setBalanciamento(alturaD - alturaE);

    if(x->getBalanciamento() == -2)
    {
        if(x->getEsq() != NULL)
            if(x->getEsq()->getBalanciamento() == 1)
                x->setEsq(rotacaoEsquerda(x->getEsq()));

        return rotacaoDireita(x);

    }
    else if(x->getBalanciamento() == 2)
    {
        if(x->getDir() != NULL)
            if(x->getDir()->getBalanciamento() == -1)
                x->setDir(rotacaoDireita(x->getDir()));

        return rotacaoEsquerda(x);

    }



    return x;

}

long long unsigned AVL::calculaChave(int QuestionID, int OwnerUserID)
{
    ///calcula chave
    string U_ID = convertePraString(OwnerUserID);
    string Q_ID = convertePraString(QuestionID);
    U_ID = completaString(U_ID);
    Q_ID = completaString(Q_ID);
    long long unsigned num = convertePraInt(U_ID,Q_ID);
    return num;
}

bool AVL::buscaQuestinIDUserID(int QuestionID, int UserID)
{
    return this->auxBuscaQuestinIDUserID(this->raiz,QuestionID,UserID);
}

bool AVL::auxBuscaQuestinIDUserID(NoAVL * p, int QuestionID, int UserID)
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
                return auxBuscaQuestinIDUserID(p->getDir(), QuestionID,UserID);
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

bool AVL::buscaUserID(int UserID)
{
    this->auxBuscaUserID(this->raiz,UserID);
}

bool AVL::auxBuscaUserID(NoAVL * no,int UserID)
{
    if(no != NULL)
    {
        if(UserID == no->OwnerUserID)
            return true;
        else
        {
            if(UserID > no->OwnerUserID)
            {
                return auxBuscaUserID(no->getDir(),UserID);
            }
            else
            {
                return auxBuscaUserID(no->getEsq(),UserID);
            }
        }
    }
    else
    {
        return false;
    }
}
