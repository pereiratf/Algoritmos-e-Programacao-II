#include <iostream>
using namespace std;

/**
Leia 30 valores e jogue os pares em um vetor e os ímpares em outro.
Após a leitura calcule o somatório dos dois vetores e exiba o de maior valor.
*/
#define T 30
int main()
{
    int par[T], impar[T]; ///desperdício de posições, no futuro vamos evitar isso
    int valor, indice, i_par=0, i_impar=0, a_par=0, a_impar=0; ///contadores e acumuladores para par e impar

    indice=0;
    while(indice<T){
        cout<<"Informe um valor: ";
        cin>>valor;
        if (valor%2==0){
            par[i_par]=valor;
            i_par++;
        } else {
            impar[i_impar]=valor;
            i_impar++;
        }
        indice=indice+1; ///equivalente a indice++;
    }

    indice=0;
    while(indice<i_par){
        a_par=a_par+par[indice];
        indice=indice+1; ///equivalente a indice++;
    }

    indice=0;
    while(indice<i_impar){
        a_impar=a_impar+impar[indice];
        indice=indice+1; ///equivalente a indice++;
    }
    if(a_par>a_impar){
        cout<<"\nPar venceu com total de "<<a_par;
    } else {
        cout<<"\nimpar venceu com total de "<<a_impar;
    }

    return 0;
}
