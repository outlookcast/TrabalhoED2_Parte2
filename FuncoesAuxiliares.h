#include "Data.h"
#include "answer.h"
unsigned long llrand(); ///Fun��o para gerar numeros aleat�rios no windows
Data* readFile(); ///Fun��o para ler o arquivo Questions.CSV
Data* vetorRandomData(int tam); ///Fun��o para pegar 'tam' itens aleat�rios do Questions.CSV
Answer* randomRead(int num);
Answer *randomReadAux(int num, Answer *answer);
Answer* readFile3();
