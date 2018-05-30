#ifndef HASHBUSCAANSWER_H_INCLUDED
#define HASHBUSCAANSWER_H_INCLUDED
#include <iostream>
#include "answer.h"
#include <list>

using namespace std;

class HashBuscaAnswer
{
    private:
        Answer * array;
        int tam;

    public:
        HashBuscaAnswer(int tam);
        ~HashBuscaAnswer();
        int funcaoHash(int questionID);
        int funcaoHash(Answer answer);
        list<int> busca(int questionID);
        void insere(Answer answer);
};

#endif // HASHBUSCAANSWER_H_INCLUDED
