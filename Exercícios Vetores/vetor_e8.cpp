#include <iostream>
using namespace std;

/**
Fa�a um programa que carregue um vetor com 10 elementos inteiros e
verifique a exist�ncia de elementos m�ltiplos de 5,
mostrando as posi��es em que esses elementos aparecem.
*/
#define T 10
int main()
{
    int vetor[T], indice; ///criando um vetor com T posi��es

    indice=0;
    while(indice<T){ ///la�o para preencher todo vetor
        cout<<"vetor["<<indice<<"] = ";
        cin>>vetor[indice]; ///coloca o valor digitado na posi��o do vetor
        indice=indice+1; ///equivalente a indice++;
    }

    indice=0;
    while(indice<T){
        if (vetor[indice]%5==0){ ///se o conte�do da posi��o do vetor for m�ltiplo de 5
            cout<<"\nvetor["<<indice<<"] = "<<vetor[indice];
        }
        indice=indice+1; ///equivalente a indice++;
    }


    return 0;
}
