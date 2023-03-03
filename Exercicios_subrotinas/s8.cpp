#include <iostream>
using namespace std;

int primo (int N){
    for (int i=2;i<N;i++){
        if(N%i==0){
            ///se entrou aqui não é primo
            return 0;
        }
    }
    ///se chegar aqui é primo
    return 1;
}
void primo100 (){
    int N=100;
    for(int cont=1;cont<=10;cont++){
        if(primo(N)==1){
            cout<<"\n"<<cont<<": "<<N;
        } else {
            cont--;
        }
        N++;
    }
}

int main()
{
    primo100();
    return 0;
}
