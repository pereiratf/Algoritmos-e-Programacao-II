#include <iostream>

using namespace std;
/**
Escreva um algoritmo que leia dois vetores de 10 posi��es e fa�a a multiplica��o dos elementos de mesmo �ndice,
colocando o resultado em um terceiro vetor. Exiba o vetor resultante.
*/

#define T 5
int main()
{   ///criando vetor chamado a com posi��es definidas
    int a[T], b[T], c[T], indice;

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
        c[indice] = a[indice] * b[indice]; ///coloca em cada indice de c os valores da multiplica��o de A x B do mesmo indice
        cout<<"\n"<<a[indice]<<" x "<<b[indice]<<" = "<<c[indice]; ///pode-se imprimir aqui, pois j� sei o conte�do de C daquele �ndice (calculado na linha acima)
        indice = indice + 1; ///igual a escrever indice++;

    }

    return 0;
}
