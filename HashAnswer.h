#ifndef HASHANSWER_H_INCLUDED
#define HASHANSWER_H_INCLUDED
#include "answer.h"
#include "HashInt.h"
#include <vector>
#include "FrequenciaTag.h"

using namespace std;

class HashAnswer
{
private:
    Answer * array;
    int tam;
    int qnt;
    int numColisoes;
    int funcaoHash(Answer answer);
    void trataColisao(Answer answer,int posicao);
    bool buscaTrataColisao2(int val,int posicao);

public:
    HashAnswer(int tam);
    ~HashAnswer();
    int getQnt();
    int getNumColisoes();
    void inserir(Answer answer);
    void imprimir();
    int frenquenciaUsuario(Answer user);
    vector<FrequenciaTag> frequenciaDeTodosUsuarios();
};


#endif // HASHANSWER_H_INCLUDED
