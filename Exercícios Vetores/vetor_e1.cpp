#include <iostream>

using namespace std;
/**
Fa�a um algoritmo que leia um vetor de 30 posi��es e
informe quantos elementos s�o m�ltiplos de 2 e quantos
s�o m�ltiplos de 3.
*/

#define T 5
int main()
{   ///criando vetor chamado a com posi��es definidas
    int a[T], indice, m2=0, m3=0;

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<"a["<<indice<<"] = "; ///escreve o pedido na tela
        cin>>a[indice]; ///armazena na posi��o indice o valor digitado

        ///poderia testar o conte�do se � multiplo aqui

        indice = indice + 1; ///igual a escrever indice++;
    }

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        if (a[indice] % 2 == 0){
            m2++;
        }

        if (a[indice] % 3 == 0){
            m3++;
        }

        indice = indice + 1; ///igual a escrever indice++;
    }
    cout<<"M2: "<<m2<<"\nM3:"<<m3;
    return 0;
}
