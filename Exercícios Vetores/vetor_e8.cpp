#include <iostream>
using namespace std;

/**
Faça um programa que carregue um vetor com 10 elementos inteiros e
verifique a existência de elementos múltiplos de 5,
mostrando as posições em que esses elementos aparecem.
*/
#define T 10
int main()
{
    int vetor[T], indice; ///criando um vetor com T posições

    indice=0;
    while(indice<T){ ///laço para preencher todo vetor
        cout<<"vetor["<<indice<<"] = ";
        cin>>vetor[indice]; ///coloca o valor digitado na posição do vetor
        indice=indice+1; ///equivalente a indice++;
    }

    indice=0;
    while(indice<T){
        if (vetor[indice]%5==0){ ///se o conteúdo da posição do vetor for múltiplo de 5
            cout<<"\nvetor["<<indice<<"] = "<<vetor[indice];
        }
        indice=indice+1; ///equivalente a indice++;
    }


    return 0;
}
