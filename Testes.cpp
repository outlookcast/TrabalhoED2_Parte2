#include "Testes.h"
#include "FuncoesAuxiliares.h"
#include "AVL.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Data.h"
#include <stdlib.h>
#include "HashInt.h"
#include "answer.h"
#include "HashAnswer.h"
#include "HashBuscaAnswer.h"
#include "quickSort1.h"

void geraSaida(int N)
{
    cout<<"Iniciando testes de inserção de N elementos aleatorios"<<endl;
    clock_t Ticks[2];
    Data * aux = vetorRandomData(N);
    ofstream entradaInsercao;
    entradaInsercao.open("entradaInsercao.txt");
    for(int i=0;i<N;i++)
    {
        entradaInsercao<<aux[i].getQuestionID()<<" "<<aux[i].getUserID()<<" "<<aux[i].getDate()<<" "<<aux[i].getScore()<<" "<<aux[i].getTitle()<<endl;
    }
    entradaInsercao.close();
    AVL * arvore = new AVL();
    Ticks[0] = clock();
    for(int i=0;i<N;i++)
    {
        if(i == (int)N/10)
            cout<<"10%"<<endl;
        if(i == (int)N/4)
            cout<<"25%"<<endl;
        if(i == (int)N/2)
            cout<<"50%"<<endl;
        ///Insere os N elementos aleatórios de QuestionsID
        arvore->insere(aux[i].getQuestionID(),aux[i].getUserID(),aux[i].getDate(),aux[i].getScore(),aux[i].getTitle());
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaInsercao;
    saidaInsercao.open("saidaInsercao.txt");
    saidaInsercao<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaInsercao<<"Tempo de inserção: "<<Tempo<<" ms"<<endl;
    saidaInsercao<<"Número de Rotações: "<<arvore->numRotacoes<<endl;
    saidaInsercao.close();
    geraSaidaBusca(aux,arvore,N);
}

void geraSaidaBusca(Data * dados, AVL * arvore, int N)
{
    cout<<"Iniciando testes de busca de N elementos aleatorios"<<endl;
    clock_t Ticks[2];
    int numElementos = rand()%N;
    Ticks[0] = clock();
    for(int i=0;i<numElementos;i++)
    {
        if(i == (int)numElementos/10)
            cout<<"10%"<<endl;
        if(i == (int)numElementos/4)
            cout<<"25%"<<endl;
        if(i == (int)numElementos/2)
            cout<<"50%"<<endl;
        ///Realiza a busca dos N UserID's
        arvore->buscaUserID(dados[i].getUserID());
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaBusca;
    saidaBusca.open("saidaBusca.txt");
    saidaBusca<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaBusca<<"Tempo de Busca para "<<numElementos<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaBusca.close();
    geraSaidaRemocao(dados,arvore,N);
}

void geraSaidaRemocao(Data * dados,AVL * arvore, int N)
{
    cout<<"Iniciando testes de remoção de N elementos aleatorios"<<endl;
    clock_t Ticks[2];
    Ticks[0] = clock();
    int numElementos = rand() % N;
    for(int i=0;i<numElementos;i++)
    {
        if(i == (int)numElementos/10)
            cout<<"10%"<<endl;
        if(i == (int)numElementos/4)
            cout<<"25%"<<endl;
        if(i == (int)numElementos/2)
            cout<<"50%"<<endl;
        ///Realiza a remoção
        arvore->remove(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    Ticks[0] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaRemocao;
    saidaRemocao.open("saidaRemocao.txt");
    saidaRemocao<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaRemocao<<"Tempo de Remoção para "<<numElementos<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaRemocao.close();
    geraSaidaUsuariosMaisAtivos(dados,N);
    ///delete [] dados;
    delete arvore;
}


void geraSaidaUsuariosMaisAtivos(Data * data, int N)
{
    cout<<"FREQUÊNCIA DE USUARIOS"<<endl;
    ofstream saidaT;
    saidaT.open("entradaUsuariosMaisAtivos.txt");
    int tam = N;
    HashBuscaAnswer * hash = new HashBuscaAnswer(1387272);
    HashAnswer * hashLeitura = new HashAnswer(tam*9);
    Answer * anser = readFile3();
    for(int i=0; i<987272; i++)
        hash->insere(anser[i]);

    for(int i=0; i<tam; i++)
    {
        int questId = data[i].getQuestionID();
        list<int> listaQuestion = hash->busca(questId);
        for (list<int>::iterator i = listaQuestion.begin(); i != listaQuestion.end(); ++i)
        {
            Answer ans;
            ans.setQuestionID(questId);
            ans.setUserID(*i);
            hashLeitura->inserir(ans);
        }
    }

    vector<FrequenciaTag> vetor = hashLeitura->frequenciaDeTodosUsuarios();

    FrequenciaTag * array = new FrequenciaTag[vetor.size()];
    FrequenciaTag * array2 = new FrequenciaTag[vetor.size()];
    int k = vetor.size() -1;
    for(int i=0;i<vetor.size();i++)
    {
        array[i].frequencia = vetor[i].frequencia;
        array[i].tag = vetor[i].tag;
    }
    quicksort(array,vetor.size());
    for(int i=0;i<vetor.size();i++)
    {
        array2[i].frequencia = array[k].frequencia;
        array2[i].tag = array[k].tag;
        k--;
    }

    for(int i=0;i<vetor.size();i++)
        saidaT<<array2[i].tag<<" "<<array2[i].frequencia<<endl;


    delete [] array;
    delete [] array2;
    delete hashLeitura;
    delete [] data;
    delete [] anser;
    delete hash;

}
