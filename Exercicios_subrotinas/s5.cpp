#include <iostream>
using namespace std;

int perfeito(int N){
    int acumulador=0;
    for (int i=1; i<N; i++){ ///i começa em 1 porque não quero tentar dividir por 0
        if (N%i==0){
            acumulador=acumulador+i;
        }
    } ///fim do laço for
    if (acumulador==N){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int N;
    cout << "Informe N: ";
    cin >> N;
    cout<<perfeito(N);
    return 0;
}
