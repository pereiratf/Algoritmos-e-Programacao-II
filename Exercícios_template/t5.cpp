 


#include <iostream>

using namespace std;
template <typename tipo>
void imprime_vetor(tipo v[5], int t){
    for(int i=0; i<t; i++){
        cout<<v[i]<<" ";
    }
}


int main(){
    //int v[5]={1,2,3,4,5};
    char v[5]={'a','b','c','d', 'e'};
    //float v[5]={0.1, 0.2, 0.3, 0.4, 0.5};
    imprime_vetor(v, 5);

}