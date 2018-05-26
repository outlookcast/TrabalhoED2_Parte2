#include "ArvoreB.h"

ArvoreB::ArvoreB(int ordem)
{

    this->ordem = ordem;
    raiz = new NoB(ordem);

}

void ArvoreB::deletaArvore(NoB *no)
{
    if(no->getFolha() == true)  //Caso base, se o no é uma folha
        delete no;
    else
    {
        NoB **vetorPonteiro = no->getVetorPonteios();  //Para pegar as referencias dos sucessores do no

        int tam = no->getNumChaves() + 1;  //Número de chaves
        for(int i = 0; i < tam; ++i)
        {
            deletaArvore(vetorPonteiro[i]);   //Chama recurcivamente deletaArvore para cada filho de no
        }

        delete no;  //Depois de todos os filhos deletados, o no de fato é deletado
    }

}

ArvoreB::~ArvoreB()
{
    deletaArvore(raiz);
}

void ArvoreB::ordenaVetorChaves(int *vetorChaves, NoB **vetorPonteiros, int tam, bool folha)
{
    int numTrocas = 0;
    int numComparacoes = 0;
    merge(vetorChaves, tam, &numTrocas, &numComparacoes);

    if(folha == false)
    {
        merge(vetorPonteiros, 0, tam, &numTrocas, &numComparacoes);
    }

}

void ArvoreB::adicionarElemento(int x)
{

    //encontrar um no folha

    NoB *no = raiz;
    while(no->getFolha() == false)
    {

        int *chaves = no->getVetorChaves();
        NoB **ponteiros = no->getVetorPonteios();

        int i;
        for(i = 0; i < (no->getNumChaves()) && x > chaves[i]; ++i);  //seleciona o i

        no = ponteiros[i];

    }


    NoB *a = NULL;
    while(true)
    {

        int *vetorChaves = no->getVetorChaves();
        int posicaoLivre = no->getNumChaves();
        NoB **vetorPonteiros = no->getVetorPonteios();

        vetorChaves[posicaoLivre] = x;      //Insere a chave
        no->setNumChaves(posicaoLivre + 1); //Atualiza o número de chaves

        //cout<<"Conteudo de no:\n";

        if(a != NULL)
        {
            vetorPonteiros[posicaoLivre+1] = a;
            a = NULL;
            ordenaVetorChaves(vetorChaves, vetorPonteiros, posicaoLivre + 1, false);
        }
        else
            ordenaVetorChaves(vetorChaves, vetorPonteiros, posicaoLivre + 1, no->getFolha());

        if(no->getNumChaves() <= ordem ) //Verifica se o nó tem capacide de receber mais uma chave
        {
            //O nó tem capacide de receber mais uma chave
            return;
        }
        else
        {
            /*
               O nó não tem capacidade de receber mais uma chave, por isso ele vai ser dividido
            */
            int posicaoMeio = (posicaoLivre + 1)/2;    //A posição da Chave que vai ser promovida
            NoB *newNo = new NoB(ordem);                 //Cria um novo no
            int *vetorChavesNewNo = newNo->getVetorChaves();
            NoB **vetorPonteirosNewNo = newNo->getVetorPonteios();

            //Guarda o valor da chave, e o ponteiro do newNo
            x = vetorChaves[posicaoMeio];
            a = newNo;

            int i;
            //cout<<"Conteudo copiado para newNo:\n";
            for(i = posicaoMeio + 1; i <= posicaoLivre; ++i)
            {
                //Copia as chaves e os ponteiros para newNo
                //cout<<vetorChaves[i]<<" ";
                vetorChavesNewNo[i - (posicaoMeio+1)] = vetorChaves[i];
                vetorPonteirosNewNo[i - (posicaoMeio + 1)] = vetorPonteiros[i];

            }
            vetorPonteirosNewNo[i-(posicaoMeio + 1)] = vetorPonteiros[i];
            //cout<<"\n";
            //Corrige os valores de chaves dos nós
            newNo->setNumChaves(no->getNumChaves() - (posicaoMeio + 1));
            no->setNumChaves(posicaoMeio);
            newNo->setPai(no->getPai());   //O pai do novo Nó é o pai de no
            newNo->setFolha(true);

            if(no == raiz)
            {

                /*
                   Se o no é a raiz, deve cria um novo nó, colocar o x nesse nó e colocar o no e o newNo como filhos dele e arumar
                   as referencias do pai do no e de newNo.
                */
                NoB *novaRaiz = new NoB(ordem);
                no->setPai(novaRaiz);
                newNo->setPai(novaRaiz);

                int *vetorChavesNovaRaiz = novaRaiz->getVetorChaves();
                vetorChavesNovaRaiz[0] = x;

                NoB **vetorPonteiroNovaRaiz = novaRaiz->getVetorPonteios();
                vetorPonteiroNovaRaiz[0] = no;
                vetorPonteiroNovaRaiz[1] = newNo;

                novaRaiz->setFolha(false);
                novaRaiz->setNumChaves(1);
                raiz = novaRaiz;

                ordenaVetorChaves(raiz->getVetorChaves(), raiz->getVetorPonteios(), raiz->getNumChaves(), raiz->getFolha());
                return;
            }
            else
            {
                no = no->getPai();
            }


        }
    }
}

void ArvoreB::removerElemento(int x)
{

}

NoB* ArvoreB::busca(int k)
{


}

void ArvoreB::imprimePorNivel(NoB *x, int nivel)
{

    int *vetorC = x->getVetorChaves();
    cout<<"Nivel "<<nivel<<": ";

    for(int i = 0; i < x->getNumChaves(); ++i)
        cout<<vetorC[i]<<" ";
    cout<<"\n";
    if(x->getFolha() == true)
    {
        return;
    }
    else
    {

        NoB **vetorNos = x->getVetorPonteios();

        for(int i = 0; i < x->getNumChaves() + 1; ++i)
            imprimePorNivel(vetorNos[i], nivel + 1);

    }

}
void ArvoreB::imprime()
{
    imprimePorNivel(raiz, 0);
}
