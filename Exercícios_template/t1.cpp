#include <iostream>

using namespace std;

template <typename tipo>
tipo soma (tipo v1, tipo v2){
    return v1+v2;
}

int main(){
    cout<<soma(!true,false);
}