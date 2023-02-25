#include <iostream>
using namespace std;
/**
Fa�a um algoritmo que preencha um vetor de 10 posi��es com n�meros aleat�rios
(entre 10 e 30) e informe quantos n�meros s�o m�ltiplos de 5,
e em que posi��o se encontram.
*/
#include<stdlib.h> ///para gerar n�meros aleat�rios
#include<time.h> ///para atribuir uma nova semente aleat�ria
#define T 10
int main()
{
    int v[T],n5=0;
    srand(time(NULL));

    ///preenche aleat�riamente o vetor
    for(int indice=0;indice<T;indice++){
        v[indice]=rand()%21+10; ///gerando n�meros entre 0 e 20 + 10
        cout<<v[indice]<<" ";
    }

    ///busca o valor multiplo de 5 e diz quantas vezes j� apareceu
    for(int indice=0;indice<T;indice++){
        if(v[indice]%5==0){
            n5++;
            cout<<"\nMultiplo de 5 encontrado em v["<<indice<<"] pela "<<n5<<"x";
        }
    }


    return 0;
}
