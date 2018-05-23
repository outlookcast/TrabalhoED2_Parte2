#include <iostream>
#include <string>

using namespace std;

class noSplay
{
public:
    noSplay *esq;
    noSplay *dir;
    noSplay *parent;
    int chave;
    noSplay(int key)
    {
        esq = NULL;
        dir = NULL;
        parent = NULL;
        chave = key;
    }
};
