#include "Data.h"

unsigned long llrand(); ///Função para gerar numeros aleatórios no windows
Data* readFile(); ///Função para ler o arquivo Questions.CSV
Data* vetorRandomData(int tam, Data *aux); ///Função para pegar 'tam' itens aleatórios do Questions.CSV
