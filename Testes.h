#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
#include <vector>
#include "AVL.h"
#include "Data.h"

void geraSaida(int N);
void geraSaidaBusca(Data * dados,AVL * arvore, int N);
void geraSaidaRemocao(Data * dados,AVL * arvore, int N);
void geraSaidaUsuariosMaisAtivos(Data * data, int N);
vector<int> retornaUsuariosMaisAtivos(int N);
void geraEntradaParaBuscaAleatoria(Data * dados,int N,int numAleat);
vector<int> retornaUsuariosAleatorios(int N);
void geraEntradaRemocao(Data * dados, int N);
#endif // TESTES_H_INCLUDED
