#include <iostream>
using namespace std;
/**
Construa um algoritmo que preencha um vetor com 5 valores inteiros.
Após verifique se o número 7 se encontra no vetor.
Em caso positivo, exiba qual a posição em que ele foi encontrado.
Se ele for encontrado mais de uma vez também quantas vezes ele foi encontrado.
*/
#include<stdlib.h> ///para gerar números aleatórios
#include<time.h> ///para atribuir uma nova semente aleatória
#define T 5
int main()
{
    int v[T],n7=0,indice;
    srand(time(NULL));

    ///preenche aleatóriamente o vetor
    indice=0;
    while(indice<T){
        v[indice]=rand()%8;
        cout<<v[indice]<<" ";
        indice++;
    }

    ///busca o valor 7 e diz quantas vezes já apareceu
    indice=0;
    while(indice<T){
        if(v[indice]%7==0){
            n7++;
            cout<<"\n7 encontrado em v["<<indice<<"] pela "<<n7<<"x";
        }
        indice++;
    }


    return 0;
}
