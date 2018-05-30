#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "AVL.h"
#include "Data.h"

void geraSaida(int N);
void geraSaidaBusca(Data * dados,AVL * arvore, int N);
void geraSaidaRemocao(Data * dados,AVL * arvore, int N);
void geraSaidaUsuariosMaisAtivos(Data * data, int N);
#endif // TESTES_H_INCLUDED
