#include "FuncoesAuxiliares.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdlib.h>

using namespace std;

unsigned long llrand() ///Em alguns compiladores a função rand() é limitada em 32767, então usamos essa função para retornar um valor randomizado maior.
{
    unsigned long r = 0;
    for (int i = 0; i < 5; ++i)
    {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    return r & 0xFFFFFFFFFFFFFFFFULL;
}

Data* readFile()
{
    int tam = 607357;
    Data *data = new Data[tam];
    ifstream ip("Questions.csv");

    if(!ip.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo." << endl;
        return data;
    }
    else
    {
        cout<<"Lendo o arquivo questions.csv..."<<endl;
        string ID;
        string OwnerUserId;
        string CreationDate;
        string Score;
        string Title;
        string restOfLine;
        string trash;
        int c=0;
        int cont = 1;
        getline(ip,trash);
        int i;
        int posicao = 0;

        while(ip.good())
        {
            if(cont == 1)
            {
                getline(ip,ID,',');
                cont++;
            }
            else if(cont == 2)
            {
                getline(ip,OwnerUserId,',');
                cont++;
            }
            else if(cont == 3)
            {
                getline(ip,CreationDate,',');
                cont++;
            }
            else if(cont == 4)
            {
                getline(ip,Score,',');
                cont++;
            }
            else if(cont == 5)
            {
                getline(ip,restOfLine,'\n');
                string titleAux = "";
                for(i=0; i<(int)restOfLine.size(); i++)
                {
                    if(restOfLine[i]!='"' && i==0)
                    {
                        for(int j=0; j<(int)restOfLine.size(); j++)
                        {
                            if(restOfLine[j] != ',')
                            {
                                titleAux += restOfLine[j];
                            }
                            else
                            {
                                i = j+1;
                                titleAux += '\n';
                                break;
                            }
                        }
                        break;
                    }
                    else
                    {

                        if(restOfLine[i] != '"')
                        {
                            titleAux += restOfLine[i];
                        }
                        else if(restOfLine[i] == '"')
                        {
                            if (restOfLine[i] == '"' && restOfLine[i+1] == '"' && restOfLine[i+2] == '"')
                            {
                                i+=2;
                                titleAux += '"';
                                titleAux += '\n';
                                break;
                            }
                            else if(restOfLine[i+1] == ',' && restOfLine[i-1] != '"')
                            {
                                i+=2;
                                titleAux += '\n';
                                break;
                            }
                            else if(restOfLine[i+1] == '"')
                            {
                                titleAux += '"';
                                i++;
                            }
                        }
                    }
                }
                Title = titleAux;
                cont++;
            }
            else if (cont == 6)
            {
                trash = restOfLine;
                int j = i;
                //cout<<ID<<" "<<OwnerUserId<<" "<<CreationDate<<" "<<Score<<" "<<Title<<endl;
                data[posicao].questionID = atoi(ID.c_str());
                data[posicao].userID = atoi(OwnerUserId.c_str());
                data[posicao].date = CreationDate;
                data[posicao].score = atoi(Score.c_str());
                data[posicao].title = Title;

                while(true)
                {
                    if (trash[j]=='"' && trash[j+1]=='\0')
                        break;
                    else if (trash[j]=='"' && trash[j+1] == '"')
                    {
                        j++;
                    }
                    else if (trash[j]=='\0')
                    {
                        getline(ip,trash);
                        j = -1;
                    }
                    j++;
                }
                cont = 1;
                c += 1;
                posicao += 1;
            }
        }
        ip.close();
        cout<<"Fim da leitura"<<endl;
        return data;
    }
}

Data* vetorRandomData(int tam)
{
    Data *aux = readFile();
    srand(time(NULL));
    Data *randomArray = new Data[tam];
    int j;
    int *vet = new int [607357];
    for(int i=0;i<607357;i++)
    	vet[i]=0;
    for (int i=0; i<tam; i++)
    {
        j = (llrand() % 607356);
        while(vet[j]==-1)
        {
        	j = (llrand() % 607356);
      //  	if(j%10000==0)
       //         cout<<j<<endl;
        }
        vet[j] = -1;
        randomArray[i].questionID = aux[j].questionID;
        randomArray[i].userID = aux[j].userID;
        randomArray[i].date = aux[j].date;
        randomArray[i].score = aux[j].score;
        randomArray[i].title = aux[j].title;
    }
    delete [] vet;
    return randomArray;
}

int* vetorRandomInt(int tam, Data *aux)
{
    int *randomArray = new int[tam];
    int j;
    for (int i=0; i<tam; i++)
    {
        j = rand() % 607357;
        randomArray[i] = aux[j].questionID;

    }
    return randomArray;
}
