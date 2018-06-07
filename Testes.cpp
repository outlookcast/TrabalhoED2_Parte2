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
        entradaInsercao<<aux[i].getQuestionID()<<" "<<aux[i].getUserID()<<" "<<aux[i].getDate()<<" "<<aux[i].getScore()<<" "<<aux[i].getTitle();
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
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
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
    geraSaidaUsuariosMaisAtivos(dados,N); ///Gera o arquivo entradaUsuariosMaisAtivos.txt para buscar os rand() % N usuários mais ativos
    cout<<"Iniciando testes de busca de N Usuarios mais ativos"<<endl;
    clock_t Ticks[2];
    int numElementos = rand()%N;
    vector<int> usuariosMaisAtivos = retornaUsuariosMaisAtivos(numElementos);
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
        arvore->buscaUserID(usuariosMaisAtivos[i]);
    }
    Ticks[1] = clock();
    cout<<"Iniciando busca de N Usuarios aleatorios"<<endl;
    double Tempo1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    int numAleat = rand() % N;
    geraEntradaParaBuscaAleatoria(dados,N,numAleat);
    vector<int> usuariosAleatorios = retornaUsuariosAleatorios(numAleat);
    Ticks[0] = clock();
    for(int i=0;i<numAleat;i++)
    {
        cout<<"dentro do for ";
        if(i == (int)numAleat/10)
            cout<<"10%"<<endl;
        if(i == (int)numAleat/4)
            cout<<"25%"<<endl;
        if(i == (int)numAleat/2)
            cout<<"50%"<<endl;
        ///Realiza a busca dos N UserID's
        arvore->buscaUserID(usuariosAleatorios[i]);
    }
    Ticks[1] = clock();
    double Tempo2 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaBusca;
    saidaBusca.open("saidaBusca.txt");
    saidaBusca<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaBusca<<"Tempo de Busca para "<<numElementos<<" Usuarios mais ativos: "<<Tempo1<<" ms"<<endl;
    saidaBusca<<"Tempo de Busca para "<<numAleat<<" Usuarios aleatorios: "<<Tempo2<<" ms"<<endl;
    saidaBusca.close();
    geraEntradaRemocao(dados,N);
    geraSaidaRemocao(dados,arvore,N);
}

void geraEntradaRemocao(Data * dados, int N)
{
    ofstream saidaT;
    saidaT.open("entradaRemocao.txt");
    int num = rand() % N;
    for(int i=0;i<num;i++)
    {
        saidaT<<dados[i].getQuestionID()<<" "<<dados[i].getUserID()<<" "<<dados[i].getDate()<<" "<<dados[i].getScore()<<" "<<dados[i].getTitle();
    }
    saidaT.close();
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
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaRemocao;
    saidaRemocao.open("saidaRemocao.txt");
    saidaRemocao<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaRemocao<<"Tempo de Remoção para "<<numElementos<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaRemocao.close();
    delete [] dados;
    delete arvore;
}


void geraSaidaUsuariosMaisAtivos(Data * data, int N)
{
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
    delete [] anser;
    delete hash;

}

vector<int> retornaUsuariosMaisAtivos(int N)
{
    ifstream ip("entradaUsuariosMaisAtivos.txt");
    if(!ip.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo." << endl;
    }
    else
    {
        vector<int> usuarios;
        cout<<"Lendo o arquivo entradaUsuariosMaisAtivos.txt..."<<endl;
        int i = 0;
        while(i < N)
        {
            string UserID,freq;
            getline(ip,UserID,' ');
            getline(ip,freq);
            int U_ID = atoi(UserID.c_str());
            usuarios.push_back(U_ID);
            i++;
        }
        return usuarios;
    }
}

void geraEntradaParaBuscaAleatoria(Data * dados,int N,int tam)
{
    int cont = 0;
    ofstream entradaParaBuscaAleatoria;
    entradaParaBuscaAleatoria.open("entradaBuscaAleatoria.txt");
    for(int i=0;i<tam;i++)
        entradaParaBuscaAleatoria<<dados[i].getUserID()<<endl;
    entradaParaBuscaAleatoria.close();
}

vector<int> retornaUsuariosAleatorios(int N)
{
    ifstream ip("entradaBuscaAleatoria.txt");
    if(!ip.is_open())
    {
        cout<<"Não foi possível abrir o arquivo."<<endl;
    }
    else
    {
        vector<int> usuarios;
        cout<<"Lendo o arquivo entradaUsuariosMaisAtivos.txt..."<<endl;
        int i = 0;
        while(i < N)
        {
            string UserID;
            getline(ip,UserID);
            int U_ID = atoi(UserID.c_str());
            usuarios.push_back(U_ID);
            i++;
        }
        return usuarios;
    }
}
