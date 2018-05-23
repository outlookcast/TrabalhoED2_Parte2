#include "AVL.h"
#include "arvoreSplay.h"

using namespace std;

int main()
{
    /*
    AVL arv;
    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    int val;
    cin>>val;
    while(val >= 0)
    {
        arv.insere(val);
        arv.imprime();
        cout<<endl<<endl;
        cin>>val;
    }
    cin>>val;
    while(val >= 0)
    {
        arv.remove(val);
        cout<<endl<<endl;
        arv.imprime();
        cin>>val;
    }
    */
    arvoreSplay *arvore = new arvoreSplay();
    arvore->inserir(10);
    arvore->inserir(15);
    arvore->inserir(11);
    arvore->inserir(20);
    arvore->deletar(11);
    noSplay *noArvore = arvore->busca(15);
    cout<<"Tamanho: "<<arvore->getTamanho()<<endl;
    arvore->imprime();
    delete arvore;

    return 0;
}
