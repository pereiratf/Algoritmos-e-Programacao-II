#include <iostream>

using namespace std;
/**
Fazer um programa que leia dois vetores unidimensionais A e B, de tamanho 8, e realize a troca dos elementos destes
vetores; ou seja, ap�s a execu��o do programa o vetor B dever� conter os valores fornecidos para o vetor A,
e vice-versa.
*/

#define T 5
int main()
{   ///criando vetor chamado a com posi��es definidas
    int a[T], b[T], temp, indice; ///temp serve para guardar o valor de A[]

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<"a["<<indice<<"] = "; ///escreve o pedido na tela
        cin>>a[indice]; ///armazena na posi��o indice o valor digitado
        indice = indice + 1; ///igual a escrever indice++;
    }

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<"b["<<indice<<"] = "; ///escreve o pedido na tela
        cin>>b[indice]; ///armazena na posi��o indice o valor digitado
        indice = indice + 1; ///igual a escrever indice++;
    }


    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        temp=a[indice]; ///guarda o valor de a[] para n�o perder quando jogar b[] em cima dele
        a[indice]=b[indice];
        b[indice]=temp;
        cout<<"\n"<<a[indice]<<"\t"<<b[indice];
        indice = indice + 1; ///igual a escrever indice++;
    }

    return 0;
}
