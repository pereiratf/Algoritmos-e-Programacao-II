#include <iostream>  

using namespace std; 

//parte a
template <typename T1, typename T2>  
T2 max(T1 x, T2 y) {      
    return (x > y)? x : y;  
}

//questão b
/*
int max(int x, int y){
    return (x > y)? x : y;
}
float max(float x, float y){
    return (x > y)? x : y;
}
float max(int x, float y){
    return (x > y)? x : y;
}

float max(float x, int y){
    return (x > y)? x : y;
}
*/
int main() {  

    cout << max(3, 7) << endl;      

    cout << max(3.0, 7.0) << endl; 

    cout << max(3, 7.0) << endl;      

    return 0;  

}  