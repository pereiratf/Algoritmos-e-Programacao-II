
#include <iostream>
using namespace std;

float divide (int x, int y){
    return 1.0*x/y;
}

int main() {
    int m[5][5], soma=0, t=0;
    //preenche
    for(int li=0; li<5; li++){
        for(int co=0; co<5; co++){
            m[li][co]=rand()%10;
        }
    }

    //imprime
    for(int li=0; li<5; li++){
        cout<<"\n";
        for(int co=0; co<5; co++){
            cout<<m[li][co]<<" ";
        }
    }

    //execução
    for(int li=0; li<5; li++){
        for(int co=0+t; co<5-t; co++){
            soma=soma+m[li][co];
            
        }
        if(li<2){
                t++;
            } else {
                t--;
            }
    }

    //imprime
    for(int li=0; li<5; li++){
        cout<<"\n";
        for(int co=0; co<5; co++){
            cout<<m[li][co]<<" ";
        }
    }
    return 0;
}

