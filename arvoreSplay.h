#ifndef ARVORESPLAY_H_INCLUDED
#define ARVORESPLAY_H_INCLUDED
#include "noSplay.h"

class arvoreSplay
{
private:
    noSplay *raiz;

    unsigned long tamanho;

    void rotacaoEsquerda(noSplay *x);
    void rotacaoDireita(noSplay *x);
    void splay(noSplay *x);
    void trocar(noSplay *x, noSplay *y);
    noSplay *subArvoreMinima(noSplay *x);
    noSplay *subArvoreMaxima(noSplay *x);
    long long unsigned calculaChave(int QuestionID, int OwnerUserID);
    void auxDeletar(long long unsigned key);
    noSplay * auxBusca(long long unsigned key);
    void imprimeAux(noSplay *x, int nivel);
    noSplay * auxBuscaUserID(long long unsigned key,int UserID);
    string completaString(string s)
    {
        if(s.size() < 32)
        {
            for(int i=0; s.size()< 32; i++)
            {
                string aux = "0"+s;
                s = aux;
            }
        }
        return s;
    }

    long long unsigned convertePraInt(string s1, string s2)
    {
        string s = s1+s2;
        int ultimaPos = s.size()-1;
        long long unsigned num = 0;
        int contPot = 0;
        for(int i=ultimaPos; i>0; i--)
        {
            if(s[i] == '1')
            {
                long long unsigned calculo = pow(2,contPot);
                num += calculo;
            }
            contPot++;
        }
        return num;
    }

    string convertePraString(int num)
    {
        char aux[33];
        itoa(num,aux,2);
        return string(aux);
    }

public:

    arvoreSplay();
    void inserir(int QuestionID, int OwnerUserID, string CreationDate, int Score, string Title);
    void imprime();
    int getTamanho();
    void deletar(int QuestionID, int OwnerUserID);
    bool buscaQuestinIDUserID(int QuestionID,int UserID);
    bool buscaUserID(int UserID);
};


#endif // ARVORESPLAY_H_INCLUDED
