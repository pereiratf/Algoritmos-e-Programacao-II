#include <iostream>

using namespace std;

int verifica_positivo(int x)
{
    if (x>=0){
        return 1;
    } else {
        return 0;
    }
}
int main()
{
    int valor, resultado;
    cout << "Informe valor:"; ///printf
    cin >> valor;               ///scanf
    resultado = verifica_positivo(valor);
    cout<<resultado;
    return 0;
}
