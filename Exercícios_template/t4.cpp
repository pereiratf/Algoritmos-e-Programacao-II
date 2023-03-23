 


#include <iostream>

using namespace std;

template <typename tipo>
void troca(tipo &a, tipo &b) {  
    tipo tmp = a;     
    a = b;  
    b = tmp;  
} 


int main(){
    float a, b;
    a=3.3, b=5.5;
    troca(a,b);
    cout<<a<<" "<<b;
}