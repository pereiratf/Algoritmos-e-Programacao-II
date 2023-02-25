#include <iostream>
using namespace std;
/**
Faça um algoritmo que preencha um vetor de 10 posições com valores gerados
(utilize o rand), e garanta que não haja números repetidos.
A seguir, ordene o vetor e mostre-o na tela.
*/
#include<stdlib.h> ///para gerar números aleatórios
#include<time.h> ///para atribuir uma nova semente aleatória
#define T 10

int main()
{
    int v[T], aux; ///auxiliar para ordenar
    srand(time(NULL));
    for(int i=0;i<T;i++){
        v[i]=rand()%10;
        for(int j=0;j<i;j++){
            if(v[j]==v[i]){
                i--;
            }
        }
    }
    ///imprime o vetor fora de ordem
    for(int i=0;i<T;i++){
        cout<<v[i]<<" ";
    }

    ///ordenação simples
    for(int i=0;i<T-1;i++){
        for(int j=0;j<T-1;j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }

    ///imprime o vetor na ordem
    cout<<"\n";
    for(int i=0;i<T;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
