#include <iostream>

using namespace std;

//Fa�a um programa que preencha um vetor de 30 posi��es
//com os primeiros n�meros primos a partir de 333.
//Exiba o vetor resultante na tela.
int main()
{
    int vetor[30],teste, p=0, numero=333;


    while (p<30){
        teste=0;
        for (int i=2; i<numero;i++){
            if (numero%i==0){
                teste=1;
            }
        }

        if (teste==0){
            //se entrou aqui o n�mero � primo
            vetor[p]=numero;
            //printf("\n%d", numero);
            p++;
        }

        numero++;
    }

    for (int i=0;i<30;i++){
        cout<<"\nvetor["<<i<<"] = "<<vetor[i];
    }

    return 0;
}
