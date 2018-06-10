#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
#include <vector>
#include "AVL.h"
#include "Data.h"
#include "arvoreSplay.h"
#include "ArvVerPre.h"

void geraSaida(int N);
void geraSaidaBusca(Data * dados,AVL * arvore, int N);
void geraSaidaRemocao(Data * dados,AVL * arvore, int N);
void geraSaidaUsuariosMaisAtivos(Data * data, int N);
vector<int> retornaUsuariosMaisAtivos(int N);
void geraEntradaParaBuscaAleatoria(Data * dados,int N,int numAleat);
vector<int> retornaUsuariosAleatorios(int N);
void geraEntradaRemocao(Data * dados, int N);
vector<Data> leArquivoERetornaEntrada(int N);
void insercaoSplay(int N);
void buscaSplay(int N, arvoreSplay * splay);
vector<Data> pegaEntradaRemocao();
void remocaoSplay(int N, arvoreSplay * splay);
void insercaoVP(int N);
void buscaVP(int N, ArvVerPre * vp);
void remocaoVP(int N, ArvVerPre * vp);
void insercaoAVLModificada(int N);
void buscaAVLModificada(int N, AVL * avl);
void remocaoAVLModificada(int N, AVL * avl);
#endif // TESTES_H_INCLUDED
