#include <iostream>
using namespace std;

float serie (int n){
    float S=0;
    for (int i=1;i<=n;i++){
        ///PEGADINHA mesmo que S seja um float
        ///na hora que ocorre a divisão se só
        ///tiver inteiros o número arredonda
        S=S+(1.0+i*i)/i; ///1.0 serve para evitar a pegadinha
    }
    return S;
}

int main()
{
    int n;
    cout<<"Informe N: ";
    cin>>n;
    cout<<"\nSerie: "<<serie(n);
    return 0;
}
