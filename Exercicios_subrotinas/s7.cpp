#include <iostream>
using namespace std;
///homens, calcular o peso ideal usando a fórmula PI = 72,7 * altura – 58,
///e para as mulheres PI = 62,1 * altura – 44,7.
float pi (float altura, char sexo){
    if(sexo=='f'){
        return 62.1*altura-44.7;
    } else {
        return 72.7*altura-58;
    }
}
int main()
{
    char sexo;
    float altura;
    cout << "Informe seu sexo: ";
    cin >> sexo;
    cout << "informe sua altura em metros: ";
    cin >> altura;
    cout<<"Seu peso ideal: " << pi(altura,sexo);
    return 0;
}
