#include <iostream>
using namespace std;

int amigos(int x, int y){
    int ax=0, ay=0;
    for (int i=1; i<x; i++){ ///i come�a em 1 porque n�o quero tentar dividir por 0
        if (x%i==0){
            ax=ax+i;
        }
    } ///fim do la�o for
    for (int i=1; i<y; i++){ ///i come�a em 1 porque n�o quero tentar dividir por 0
        if (y%i==0){
            ay=ay+i;
        }
    } ///fim do la�o for
    if(ax==y and ay==x){
        return 1;
    }
    return 0;
}


int main()
{
    setlocale(LC_ALL,"portuguese");
    int a,b;
    cout << "Informe A: ";
    cin >> a;
    cout << "Informe B: ";
    cin >> b;
    if(amigos(a,b)){
        cout<<a<<" � amigo de "<<b;
    } else {
        cout<<a<<" n�o � amigo de "<<b;
    }
    return 0;
}
