#include <iostream>
#include "FuncoesAuxiliares.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "arvoreSplay.h"
#include "AVL.h"
#include "ArvVerPre.h"
#include <time.h>
#include "Testes.h"
#include <fstream>
using namespace std;


int main()
{
    ifstream ip("entrada.txt");
    string numString;
    if(!ip.is_open())
    {
        cout<<"Não foi possível abrir o arquivo entrada.txt"<<endl;
    }
    else
    {
        while(ip.good())
        {
            getline(ip,numString);
            int num = atoi(numString.c_str());
            cout<<"INICIANDO TESTES PARA N = "+numString<<endl<<endl;
            geraSaida(num);
        }
        ip.close();
    }


    return 0;
}
