#include <iostream>

using namespace std;
/**
Construa um algoritmo que solicite 5 valores ao usu�rio, armazene estes em um vetor de 5 posi��es inteiras.
Ap�s, descubra quantos elementos s�o maiores do que o elemento da primeira posi��o.
*/

#define T 5
int main()
{   ///criando vetor chamado a com posi��es definidas
    int a[T], indice, mp=0;

    indice=0; ///inicio do vetor
    while (indice<T){ ///enquanto menor que tamanho do vetor
        cout<<"a["<<indice<<"] = "; ///escreve o pedido na tela
        cin>>a[indice]; ///armazena na posi��o indice o valor digitado

        indice = indice + 1; ///igual a escrever indice++;
    }

    indice=1; ///segunda posi��o do vetor, pois vai testar com a primeira
    while (indice<T){ ///enquanto menor que tamanho do vetor
        if (a[indice] > a[0]){
            mp++;
        }
        indice = indice + 1; ///igual a escrever indice++;
    }
    cout<<"Existem "<<mp<<" elementos maiores que o elemento "<<a[0]<<" do vetor.";
    return 0;
}
