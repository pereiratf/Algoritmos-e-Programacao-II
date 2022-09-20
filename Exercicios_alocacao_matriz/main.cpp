#include <iostream>
#include <stdlib.h> //rand()
#include <time.h> //time()
using namespace std;

void preenche(int **m, int t){
    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            m[i][j]=rand()%9;
        }
    }
}

void imprime(int **m, int li, int co){
    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void questao1 (){
    srand(time(0));
    int li=rand()%10+1;
    int co=rand()%10+1;
    int **m=new int*[li];
    for (int i=0;i<t;i++){
        m[li]=new int[co]; //aloca as colunas da matriz
    }

    preenche(m, li, co);
    imprime(m, li, co);

    ///DELETE
    for (int i=0;i<li;i++){
        delete m[li]; ///deleta as colunas da matriz
    }
    delete m;
}

void questao2(){

}

int main()
{
    //questao1();

    return 0;
}
