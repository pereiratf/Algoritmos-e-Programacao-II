#include <iostream>

using namespace std;
/**
Construa um algoritmo que solicite 5 valores inteiros ao usuário e os armazene em um vetor.
Após, deverá ser invertido os valores do vetor sem utilizar um segundo vetor.
*/

#define T 5
int main()
{   ///criando vetor chamado a com posições definidas
    int a[T], temp, indice; ///temp serve para guardar o valor de A[]

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<"a["<<indice<<"] = "; ///escreve o pedido na tela
        cin>>a[indice]; ///armazena na posição indice o valor digitado
        indice = indice + 1; ///igual a escrever indice++;
    }


    indice=0; ///inicio do vetor
    while (indice<T/2){ ///enquanto menor que tamanho do vetor
        temp=a[indice];
        a[indice]=a[T-1-indice]; ///última depois penúltima e assim por diante
        a[T-1-indice]=temp;
        indice = indice + 1; ///igual a escrever indice++;
    }

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<a[indice]<<" ";
        indice = indice + 1; ///igual a escrever indice++;
    }

    return 0;
}
