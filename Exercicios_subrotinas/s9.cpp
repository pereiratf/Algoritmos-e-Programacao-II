#include <iostream>
using namespace std;

int fatorial (int N){
    int f=1;
    for(int i=1;i<=N;i++){
        f=f*i;
    }
    return f;
}
float conjunto (int N, int K){
    return fatorial(N)/(fatorial(K)*fatorial(N-K));
}

int main()
{
    int n,k;
    cout<<"Informe N: ";
    cin>>n;
    cout<<"Informe K: ";
    cin>>k;
    cout<<conjunto(n,k);

    return 0;
}
