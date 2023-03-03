#include <iostream>
using namespace std;

void castigo(int N)
{
    int i;
    i=0;
    while (i<N){
        cout<<"\nNão vou colar na prova!";
        i++;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int N;
    cout<<"Informe o tamanho do castigo: ";
    cin>>N;
    castigo(N);
    return 0;
}
