 #include <iostream>  

  

using namespace std;  

template <typename T>  
void fun(const T & x)  {  
    static int contador = 0;  
    cout << "x = " << x << " contador = " << contador << endl;  
    ++contador;     
    return;  
}  

int main() {  

fun<int> (1);     cout << endl;  //x = 1 contador = 0   
fun<int> (1);     cout << endl;  //x = 1 contador = 1  
fun<double>(1.1); cout << endl;  //x = 1.1 contador = 2 mistake contador = 0, pois houve sobrecarga
fun<int> (1);     cout << endl;  //x = 1 contador = 2  

    return 0;  

}  