#include "Data.h"
#include "answer.h"
unsigned long llrand(); ///Função para gerar numeros aleatórios no windows
Data* readFile(); ///Função para ler o arquivo Questions.CSV
Data* vetorRandomData(int tam); ///Função para pegar 'tam' itens aleatórios do Questions.CSV
Answer* randomRead(int num);
Answer *randomReadAux(int num, Answer *answer);
Answer* readFile3();
