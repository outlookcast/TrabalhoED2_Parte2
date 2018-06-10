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
#include "arvoreSplay.h"

void geraSaida(int N)
{
    cout<<"Iniciando testes de inserção de N elementos aleatorios - AVL TREE"<<endl;
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

    string inicioString("saidaInsercaoAVL");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;
    saidaInsercao.open(stringSalvarArquivo.c_str());
    saidaInsercao<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaInsercao<<"Tempo de inserção: "<<Tempo<<" ms"<<endl;
    saidaInsercao<<"Número de Rotações: "<<arvore->numRotacoes<<endl;
    saidaInsercao.close();
    geraSaidaBusca(aux,arvore,N);
}

void geraSaidaBusca(Data * dados, AVL * arvore, int N)
{
    geraSaidaUsuariosMaisAtivos(dados,N); ///Gera o arquivo entradaUsuariosMaisAtivos.txt para buscar os rand() % N usuários mais ativos
    cout<<"Iniciando testes de busca de N Usuarios mais ativos - AVL TREE"<<endl;
    clock_t Ticks[2];
    int numElementos = rand()%N;
    vector<int> usuariosMaisAtivos = retornaUsuariosMaisAtivos(numElementos);
    Ticks[0] = clock();
    for(int i=0;i<usuariosMaisAtivos.size();i++)
    {
        if(i == (int)usuariosMaisAtivos.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/2)
            cout<<"50%"<<endl;
        ///Realiza a busca dos N UserID's
        arvore->buscaUserID(usuariosMaisAtivos[i]);
    }
    Ticks[1] = clock();
    cout<<"Iniciando busca de N Usuarios aleatorios - AVL TREE"<<endl;
    double Tempo1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    int numAleat = rand() % N;
    geraEntradaParaBuscaAleatoria(dados,numAleat,numAleat);
    vector<int> usuariosAleatorios = retornaUsuariosAleatorios(numAleat);
    Ticks[0] = clock();
    for(int i=0;i<numAleat;i++)
    {
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
    string inicioString("saidaBuscaAVL");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;
    saidaBusca.open(stringSalvarArquivo.c_str());
    saidaBusca<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuariosMaisAtivos.size()<<" Usuarios mais ativos: "<<Tempo1<<" ms"<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuariosAleatorios.size()<<" Usuarios aleatorios: "<<Tempo2<<" ms"<<endl;
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
    cout<<"Iniciando testes de remocao de N elementos aleatorios - AVL TREE"<<endl;
    clock_t Ticks[2];
    Ticks[0] = clock();
    vector<Data> array = pegaEntradaRemocao();
    int numElementos = array.size();
    for(int i=0;i<numElementos;i++)
    {
        if(i == (int)numElementos/10)
            cout<<"10%"<<endl;
        if(i == (int)numElementos/4)
            cout<<"25%"<<endl;
        if(i == (int)numElementos/2)
            cout<<"50%"<<endl;
        ///Realiza a remoção
        arvore->remove(array[i].getQuestionID(),array[i].getUserID(),array[i].getDate(),array[i].getScore(),array[i].getTitle());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaRemocao;

    string inicioString("saidaRemocaoAVL");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;

    saidaRemocao.open(stringSalvarArquivo.c_str());
    saidaRemocao<<"Testes com a AVL - Número de Elementos = "<<N<<endl;
    saidaRemocao<<"Tempo de Remoção para "<<numElementos<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaRemocao.close();
    delete [] dados;
    delete arvore;
    insercaoSplay(N);
}


void geraSaidaUsuariosMaisAtivos(Data * data, int N)
{
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
    ofstream saidaT;
    saidaT.open("entradaUsuariosMaisAtivos.txt");
    int numAleat = rand() % vetor.size();
    for(int i=0;i<numAleat;i++)
        saidaT<<array2[i].tag<<" "<<array2[i].frequencia<<endl;

    saidaT.close();

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
        while(ip.good())
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
        cout<<"Lendo o arquivo entradaBuscaAleatoria.txt..."<<endl;
        int i = 0;
        while(ip.good())
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

void insercaoSplay(int N)
{
    cout<<"Iniciando testes de inserção de N elementos aleatorios - SPLAY TREE"<<endl;
    arvoreSplay * splay = new arvoreSplay();
    vector<Data> dados = leArquivoERetornaEntrada(N);
    clock_t Ticks[2];
    Ticks[0] = clock();
    ///Insercao aqui
    for(int i=0;i<N;i++)
    {
        splay->inserir(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    ofstream saidaInsercao;

    string inicioString("saidaInsercaoSplay");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaInsercao.open(stringSalvarArquivo.c_str());
    saidaInsercao<<"Testes com a Splay - Número de Elementos = "<<N<<endl;
    saidaInsercao<<"Tempo de inserção: "<<Tempo<<" ms"<<endl;
    saidaInsercao<<"Número de Rotações: "<<splay->numRotacoes<<endl;
    saidaInsercao.close();
    buscaSplay(N,splay);
}

void buscaSplay(int N, arvoreSplay * splay)
{
    cout<<"Iniciando testes de busca de N Usuarios mais ativos - SPLAY TREE"<<endl;
    vector<int> usuariosMaisAtivos = retornaUsuariosMaisAtivos(N);
    clock_t Ticks[4];
    Ticks[0] = clock();
    ///Busca dos mais ativos
    for(int i=0;i<usuariosMaisAtivos.size();i++)
    {
        if(i == (int)usuariosMaisAtivos.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/2)
            cout<<"50%"<<endl;
        splay->buscaUserID(usuariosMaisAtivos[i]);
    }
    Ticks[1] = clock();
    long double Tempo1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"Iniciando busca de N Usuarios aleatorios - SPLAY TREE"<<endl;
    vector<int> usuarios = retornaUsuariosAleatorios(N);
    Ticks[2] = clock();
    for(int i=0;i<usuarios.size();i++)
    {
        if(i == (int)usuarios.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuarios.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuarios.size()/2)
            cout<<"50%"<<endl;
        splay->buscaUserID(usuarios[i]);
    }

    Ticks[3] = clock();

    long double Tempo2 = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;

    ofstream saidaBusca;


    string inicioString("saidaBuscaSplay");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaBusca.open(stringSalvarArquivo.c_str());
    saidaBusca<<"Testes com a Splay - Número de Elementos = "<<N<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuariosMaisAtivos.size()<<" Usuarios mais ativos: "<<Tempo1<<" ms"<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuarios.size()<<" Usuarios aleatorios: "<<Tempo2<<" ms"<<endl;
    saidaBusca.close();
    remocaoSplay(N,splay);
}

void remocaoSplay(int N, arvoreSplay * splay)
{
    cout<<"Iniciando testes de remocao de N elementos aleatorios - SPLAY TREE"<<endl;
    vector<Data> array = pegaEntradaRemocao();
    clock_t Ticks[2];
    Ticks[0] = clock();
    for(int i=0;i<array.size();i++)
    {
        if(i == (int)array.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)array.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)array.size()/2)
            cout<<"50%"<<endl;
        ///Realiza a remoção
        splay->deletar(array[i].getQuestionID(),array[i].getUserID());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaRemocao;


    string inicioString("saidaRemocaoSplay");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaRemocao.open(stringSalvarArquivo.c_str());
    saidaRemocao<<"Testes com a Splay - Número de Elementos = "<<N<<endl;
    saidaRemocao<<"Tempo de Remoção para "<<array.size()<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaRemocao.close();
    delete splay;
    insercaoVP(N);

}

void insercaoVP(int N)
{
    cout<<"Iniciando testes de inserção de N elementos aleatorios - RED-BLACK TREE"<<endl;
    ArvVerPre * vp = new ArvVerPre();
    vector<Data> dados = leArquivoERetornaEntrada(N);
    clock_t Ticks[2];
    Ticks[0] = clock();
    ///Insercao aqui
    for(int i=0;i<N;i++)
    {
        vp->insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    ofstream saidaInsercao;


    string inicioString("saidaInsercaoVP");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaInsercao.open(stringSalvarArquivo.c_str());
    saidaInsercao<<"Testes com a VP - Número de Elementos = "<<N<<endl;
    saidaInsercao<<"Tempo de inserção: "<<Tempo<<" ms"<<endl;
    saidaInsercao<<"Número de Rotações: "<<vp->numRotacoes<<endl;
    saidaInsercao.close();
    buscaVP(N,vp);
}

void buscaVP(int N, ArvVerPre * vp)
{
    cout<<"Iniciando testes de busca de N Usuarios mais ativos - RED-BLACK TREE"<<endl;
    vector<int> usuariosMaisAtivos = retornaUsuariosMaisAtivos(N);
    clock_t Ticks[4];
    Ticks[0] = clock();
    ///Busca dos mais ativos
    for(int i=0;i<usuariosMaisAtivos.size();i++)
    {
        if(i == (int)usuariosMaisAtivos.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/2)
            cout<<"50%"<<endl;
        vp->buscaUserID(usuariosMaisAtivos[i]);
    }
    Ticks[1] = clock();
    long double Tempo1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"Iniciando busca de N Usuarios aleatorios - RED-BLACK TREE"<<endl;
    vector<int> usuarios = retornaUsuariosAleatorios(N);
    Ticks[2] = clock();
    for(int i=0;i<usuarios.size();i++)
    {
        if(i == (int)usuarios.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuarios.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuarios.size()/2)
            cout<<"50%"<<endl;
        vp->buscaUserID(usuarios[i]);
    }

    Ticks[3] = clock();

    long double Tempo2 = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;

    ofstream saidaBusca;


    string inicioString("saidaBuscaVP");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaBusca.open(stringSalvarArquivo.c_str());
    saidaBusca<<"Testes com a VP - Número de Elementos = "<<N<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuariosMaisAtivos.size()<<" Usuarios mais ativos: "<<Tempo1<<" ms"<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuarios.size()<<" Usuarios aleatorios: "<<Tempo2<<" ms"<<endl;
    saidaBusca.close();
    remocaoVP(N,vp);
}

void remocaoVP(int N, ArvVerPre * vp)
{
    cout<<"Iniciando testes de remocao de N elementos aleatorios - RED-BLACK TREE"<<endl;
    vector<Data> array = pegaEntradaRemocao();
    clock_t Ticks[2];
    Ticks[0] = clock();
    for(int i=0;i<array.size();i++)
    {
        if(i == (int)array.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)array.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)array.size()/2)
            cout<<"50%"<<endl;
        ///Realiza a remoção
        vp->removerValorCor(array[i].getQuestionID(),array[i].getUserID(),array[i].getDate(),array[i].getScore(),array[i].getTitle());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaRemocao;


    string inicioString("saidaRemocaoVP");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaRemocao.open(stringSalvarArquivo.c_str());
    saidaRemocao<<"Testes com a VP - Número de Elementos = "<<N<<endl;
    saidaRemocao<<"Tempo de Remoção para "<<array.size()<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaRemocao.close();
    delete vp;
    insercaoAVLModificada(N);
}

void insercaoAVLModificada(int N)
{
    cout<<"Iniciando testes de inserção de N elementos aleatorios - AVL Modificada TREE"<<endl;
    AVL * avl = new AVL(5);
    vector<Data> dados = leArquivoERetornaEntrada(N);
    clock_t Ticks[2];
    Ticks[0] = clock();
    ///Insercao aqui
    for(int i=0;i<N;i++)
    {
        avl->insere(dados[i].getQuestionID(),dados[i].getUserID(),dados[i].getDate(),dados[i].getScore(),dados[i].getTitle());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    ofstream saidaInsercao;


    string inicioString("saidaInsercaoAVLModificada");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaInsercao.open(stringSalvarArquivo.c_str());
    saidaInsercao<<"Testes com a AVL Modificada - Número de Elementos = "<<N<<endl;
    saidaInsercao<<"Tempo de inserção: "<<Tempo<<" ms"<<endl;
    saidaInsercao<<"Número de Rotações: "<<avl->numRotacoes<<endl;
    saidaInsercao.close();
    buscaAVLModificada(N,avl);
}

void buscaAVLModificada(int N, AVL * avl)
{
    cout<<"Iniciando testes de busca de N Usuarios mais ativos - AVL Modificada TREE"<<endl;
    vector<int> usuariosMaisAtivos = retornaUsuariosMaisAtivos(N);
    clock_t Ticks[4];
    Ticks[0] = clock();
    ///Busca dos mais ativos
    for(int i=0;i<usuariosMaisAtivos.size();i++)
    {
        if(i == (int)usuariosMaisAtivos.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuariosMaisAtivos.size()/2)
            cout<<"50%"<<endl;
        avl->buscaUserID(usuariosMaisAtivos[i]);
    }
    Ticks[1] = clock();
    long double Tempo1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"Iniciando busca de N Usuarios aleatorios - AVL Modificada TREE"<<endl;
    vector<int> usuarios = retornaUsuariosAleatorios(N);
    Ticks[2] = clock();
    for(int i=0;i<usuarios.size();i++)
    {
        if(i == (int)usuarios.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)usuarios.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)usuarios.size()/2)
            cout<<"50%"<<endl;
        avl->buscaUserID(usuarios[i]);
    }

    Ticks[3] = clock();

    long double Tempo2 = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;

    ofstream saidaBusca;


    string inicioString("saidaBuscaAVLModificada");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaBusca.open(stringSalvarArquivo.c_str());
    saidaBusca<<"Testes com a AVL Modificada - Número de Elementos = "<<N<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuariosMaisAtivos.size()<<" Usuarios mais ativos: "<<Tempo1<<" ms"<<endl;
    saidaBusca<<"Tempo de Busca para "<<usuarios.size()<<" Usuarios aleatorios: "<<Tempo2<<" ms"<<endl;
    saidaBusca.close();
    remocaoAVLModificada(N,avl);
}

void remocaoAVLModificada(int N, AVL * avl)
{
    cout<<"Iniciando testes de remocao de N elementos aleatorios - AVL Modificada TREE"<<endl;
    vector<Data> array = pegaEntradaRemocao();
    clock_t Ticks[2];
    Ticks[0] = clock();
    for(int i=0;i<array.size();i++)
    {
        if(i == (int)array.size()/10)
            cout<<"10%"<<endl;
        if(i == (int)array.size()/4)
            cout<<"25%"<<endl;
        if(i == (int)array.size()/2)
            cout<<"50%"<<endl;
        ///Realiza a remoção
        avl->remove(array[i].getQuestionID(),array[i].getUserID(),array[i].getDate(),array[i].getScore(),array[i].getTitle());
    }
    Ticks[1] = clock();
    long double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    ofstream saidaRemocao;


    string inicioString("saidaRemocaoAVLModificada");
    stringstream ss;
	ss << N;
    string meioString(ss.str());
    string finalString(".txt");
    string stringSalvarArquivo = inicioString+meioString+finalString;


    saidaRemocao.open(stringSalvarArquivo.c_str());
    saidaRemocao<<"Testes com a AVL Modificada - Número de Elementos = "<<N<<endl;
    saidaRemocao<<"Tempo de Remoção para "<<array.size()<<" elementos aleatórios: "<<Tempo<<" ms"<<endl;
    saidaRemocao.close();
    delete avl;
}


vector<Data> pegaEntradaRemocao()
{
    ifstream ip;
    ip.open("entradaRemocao.txt");
    if(!ip.is_open())
    {
        cout<<"Não foi possível abrir o arquivo."<<endl;
    }
    else
    {
        vector<Data> array;
        int i = 0;
        while(ip.good())
        {
            string QuestionID; ///int
            string OwnerUserID; ///int
            string CreationDate;
            string Score; ///int
            string Title;

            getline(ip,QuestionID,' ');
            getline(ip,OwnerUserID,' ');
            getline(ip,CreationDate,' ');
            getline(ip,Score,' ');
            getline(ip,Title);

            Data a;

            a.setQuestionID(atoi(QuestionID.c_str()));
            a.setUserID(atoi(OwnerUserID.c_str()));
            a.setDate(CreationDate);
            a.setScore(atoi(Score.c_str()));
            a.setTitle(Title);

            array.push_back(a);

            i++;
        }

        ip.close();
        return array;

    }
}

vector<Data> leArquivoERetornaEntrada(int N)
{
    ifstream ip("entradaInsercao.txt");
    if(!ip.is_open())
    {
        cout<<"Não foi possível abrir o arquivo."<<endl;
    }
    else
    {
        vector<Data> array;
        int i = 0;

        while(i < N)
        {
            string QuestionID; ///int
            string OwnerUserID; ///int
            string CreationDate;
            string Score; ///int
            string Title;

            getline(ip,QuestionID,' ');
            getline(ip,OwnerUserID,' ');
            getline(ip,CreationDate,' ');
            getline(ip,Score,' ');
            getline(ip,Title);

            Data a;

            a.setQuestionID(atoi(QuestionID.c_str()));
            a.setUserID(atoi(OwnerUserID.c_str()));
            a.setDate(CreationDate);
            a.setScore(atoi(Score.c_str()));
            a.setTitle(Title);

            array.push_back(a);

            i++;
        }

        ip.close();
        return array;

    }
}
