#include <iostream>
using namespace std;
/**
Faça um algoritmo que preencha um vetor de 10 posições com números aleatórios
(entre 10 e 30) e informe quantos números são múltiplos de 5,
e em que posição se encontram.
*/
#include<stdlib.h> ///para gerar números aleatórios
#include<time.h> ///para atribuir uma nova semente aleatória
#define T 10
int main()
{
    int v[T],n5=0;
    srand(time(NULL));

    ///preenche aleatóriamente o vetor
    for(int indice=0;indice<T;indice++){
        v[indice]=rand()%21+10; ///gerando números entre 0 e 20 + 10
        cout<<v[indice]<<" ";
    }

    ///busca o valor multiplo de 5 e diz quantas vezes já apareceu
    for(int indice=0;indice<T;indice++){
        if(v[indice]%5==0){
            n5++;
            cout<<"\nMultiplo de 5 encontrado em v["<<indice<<"] pela "<<n5<<"x";
        }
    }


    return 0;
}
