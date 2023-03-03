#include <iostream>

using namespace std;
int resto(int divisor, int dividendo)
{
    int resultado, multiplicando;
    multiplicando = divisor/dividendo;
    resultado = divisor-dividendo*multiplicando;

    return resultado;
}
int resto2(int divisor, int dividendo)
{
    int anterior;
    anterior=0;
    while (divisor>=0){
        anterior=divisor;
        divisor = divisor-dividendo;
    }

    return anterior;
}
int main()
{
    int num1, num2;
    cout<<"Informe o divisor: ";
    cin>>num1;
    cout<<"Informe o dividendo: ";
    cin>>num2;
    cout<<resto2(num1,num2);

    return 0;
}
