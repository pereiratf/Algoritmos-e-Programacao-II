#include <iostream>
using namespace std;

/**
Fa�a um algoritmo que leia dois vetores (A e B) de dez posi��es de n�meros inteiros.
O algoritmo deve, ent�o, subtrair o primeiro elemento de A do �ltimo elemento de B,
e acumular o valor, subtrair o segundo elemento de A do pen�ltimo elemento de B,
acumulando o resultado, e assim por diante. Mostre o resultado do somat�rio acumulado.
*/

int main()
{
    int A[10], B[10], indice, soma=0;

    indice=0;
    while(indice<10){
        cout<<"A["<<indice<<"] = ";
        cin>>A[indice];
        indice++;
    }

    indice=0;
    while(indice<10){
        cout<<"B["<<indice<<"] = ";
        cin>>B[indice];
        indice++;
    }

    indice=0;
    while(indice<10){
        soma=soma+(A[indice]-B[9-indice]);
        cout<<"\n"<<soma<<" + "<<A[indice]<<" - "<<B[indice];
        indice++;
    }

    return 0;
}
