#include <iostream>

using namespace std;
/**
Construa um algoritmo que solicite 5 valores inteiros ao usuário e os armazene em um vetor.
Após, deverá ser invertido os valores do vetor utilizando um segundo vetor.
*/

#define T 5
int main()
{   ///criando vetor chamado a com posições definidas
    int a[T], b[T], indice; ///temp serve para guardar o valor de A[]

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<"a["<<indice<<"] = "; ///escreve o pedido na tela
        cin>>a[indice]; ///armazena na posição indice o valor digitado
        indice = indice + 1; ///igual a escrever indice++;
    }


    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        b[indice]=a[T-1-indice]; ///t-1 significa a última posição e o -indice significa que é para ir voltando 1 posição a partir da última por vez
        cout<<"\n"<<a[indice]<<"\t"<<b[indice];
        indice = indice + 1; ///igual a escrever indice++;
    }

    return 0;
}
