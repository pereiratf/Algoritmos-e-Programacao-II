#include <iostream>
using namespace std;

/**
Diz-se que uma sequência de n elementos é balanceada, com n par, se as seguintes somas são iguais:
• a soma do maior elemento com o menor;
• a soma do segundo maior elemento com o segundo menor;
• a soma do terceiro maior elemento com o terceiro menor.
ex: 2 12 3 6 16 15 é uma sequência balanceada, pois 16+2=15+3=12+6 Dados n (n par)
e uma sequência de n elementos, verificar se essa sequência é balanceada. Crie um vetor de 10 elementos e
informe se o mesmo é balanceado ou não.
*/
#define T 10
#include <stdlib.h> ///para o rand() e srand
#include <time.h> ///para o time(NULL)
int main()
{
    srand(time(NULL));
    int v[T];
    int balanceado=1, soma, aux;

    ///preenche aleatóriamente o vetor
    for(int indice=0;indice<T;indice++){
        v[indice]=rand()%10;
        cout<<v[indice]<<" ";
    }
    ///ordenação simples
    for(int i=0;i<T-1;i++){
        for(int j=0;j<T-1;j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }


    soma=v[0]+v[T-1];
    for(int i=1;i<T/2;i++){
        if ((v[i]+v[T-1-i])!=soma){
            balanceado=0;
        }
    }
    cout<<"\nBalanceamento = "<<balanceado;
    return 0;
}
