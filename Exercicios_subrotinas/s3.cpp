#include <iostream>
using namespace std;

int mdc(int b,int a) {
    while (a!=b){
        if(a>b){
            a=a-b;
        } else {
            b=b-a;
        }
    }
    return a;
}
int main()
{
    int v1, v2, r;
    cout << "Informe o valor 1: ";
    cin>>v1;
    cout << "Informe o valor 2: ";
    cin>>v2;
    r=mdc(v1,v2);
    cout<<"MDC: "<<r;
    return 0;
}
