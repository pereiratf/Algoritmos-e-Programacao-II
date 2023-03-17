
#include <iostream>
using namespace std;



void imprime_matriz (int m[5][4]){
    for (int i=0;i<5;i++){
        for (int j=0;j<4;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void matriz_par_impar(int m[5][4]){
int parx=0, pary=0, imparx=1, impary=0;
    int r;
    while (parx!=6 || imparx!=5) {
        r=rand()%10+1;
        if(r%2==0 && parx!=6){
            m[parx][pary]=r;
            if(pary<3){
                pary++;
            } else {
                pary=0;
                parx=parx+2;
            }
        } //par

        if(r%2!=0 && imparx!=5){
            m[imparx][impary]=r;
            if(impary<3){
                impary++;
            } else {
                impary=0;
                imparx=imparx+2;
            }
        } //impar
    } //while
}

int main() {
    int m[5][4]={0};
    matriz_par_impar(m);
    imprime_matriz(m);
    
    return 0;
}
