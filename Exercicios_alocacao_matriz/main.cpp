#include <iostream>
#include <stdlib.h> //rand()
#include <time.h> //time()
using namespace std;

void preenche(int **m, int li, int co){
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

void gera_matriz1(int** m, int li, int co){
    int pa=0, im=1;
    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            if(i%2==0){
                m[i][j]=pa;
                pa=pa+2;
            } else {
                m[i][j]=im;
                im=im+2;
            }

        }
    }
}

void gera_matriz2(int** m, int li, int co){
    int c=0;
    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            m[i][j]=c%2;
            c++;

        }
    }
}

void gera_matriz3(int** m, int li, int co){
    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            if (j<=i){
                m[i][j]=0;
            } else{
                m[i][j]=1;
            }

        }
    }
}

int** soma_matriz(int** m1, int** m2, int li, int co){
    int**m3;
    m3=new int*[li];
    for (int i=0;i<li;i++){
        m3[i]=new int[co]; //aloca as colunas da matriz
    }

    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            m3[i][j]=m1[i][j]+m2[i][j];
        }
    }

    return m3;
}

bool primo (int n){
    if (n<=1){
        return false;
    }
    for(int i=2;i<n/2+1;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void dobro_primo_secundaria(int** m, int li, int co){
    for (int i=0;i<li;i++){
        for (int j=0;j<co;j++){
            if ((j+i>li-1) && primo(m[i][j])){
                m[i][j]=2*m[i][j];
            }

        }
    }
}

void questao1 (){
    srand(time(0));
    int li=rand()%10+1;
    int co=rand()%10+1;
    int**m;
    m=new int*[li];
    for (int i=0;i<li;i++){
        m[i]=new int[co]; //aloca as colunas da matriz
    }

    preenche(m, li, co);
    imprime(m, li, co);

    ///DELETE
    for (int i=0;i<li;i++){
        delete m[i]; ///deleta as colunas da matriz
    }
    delete m;
}

void questao2(){
    int escolha, li, co;
    cout<<"Digite 1 para\n0 2 4\n1 3 5\n6 8 10\n\n";
    cout<<"Digite 2 para\n0 1 0\n1 0 1\n0 1 0\n\n";
    cout<<"Digite 3 para\n0 1 1\n0 0 1\n0 0 0\n\n";
    cin>>escolha;
    cout<<"Digite o tamanho da matriz: ";
    cin>>li;
    co=li;

    //Criando a matriz dinâmica
    int **m=new int*[li];
    for (int i=0;i<li;i++){
        m[i]=new int[co]; //aloca as colunas da matriz
    }


    //imprime(m, li, co);
    switch (escolha) {
    case 1:
        gera_matriz1(m, li, co);
        break;
    case 2:
        gera_matriz2(m, li, co);
        break;
    default:
        gera_matriz3(m, li, co);

    }
    imprime(m, li, co);

        ///DELETE
    for (int i=0;i<li;i++){
        delete m[i]; ///deleta as colunas da matriz
    }
    delete m;
}

void questao3(){
    srand(time(0));
    int li=rand()%10+1;
    int co=rand()%10+1;

    //Cria a matriz 1
    int**m1;
    m1=new int*[li];
    for (int i=0;i<li;i++){
        m1[i]=new int[co]; //aloca as colunas da matriz
    }

    //Cria a matriz 2
    int**m2;
    m2=new int*[li];
    for (int i=0;i<li;i++){
        m2[i]=new int[co]; //aloca as colunas da matriz
    }

    //Cria a matriz 3
    int**m3;



    preenche(m1, li, co);
    preenche(m2, li, co);
    m3 = soma_matriz(m1,m2,li,co);
    imprime(m1, li, co);
    cout<<"\n\n";
    imprime(m2, li, co);
    cout<<"\n\n";
    imprime(m3, li, co);

    ///DELETE
    for (int i=0;i<li;i++){
        delete m1[i]; ///deleta as colunas da matriz
        delete m2[i]; ///deleta as colunas da matriz
        delete m3[i]; ///deleta as colunas da matriz
    }
    delete m1;
    delete m2;
    delete m3;
}

void questao4 (){
    srand(time(0));
    int li=rand()%10+1;
    int co=li;
    int**m;
    m=new int*[li];
    for (int i=0;i<li;i++){
        m[i]=new int[co]; //aloca as colunas da matriz
    }

    preenche(m, li, co);
    imprime(m, li, co);

    dobro_primo_secundaria(m, li, co);
    cout<<"\n\n";
    imprime(m, li, co);

    ///DELETE
    for (int i=0;i<li;i++){
        delete m[i]; ///deleta as colunas da matriz
    }
    delete m;
}


int main()
{
    //questao1();
    //questao2();
    //questao3();
    questao4();

    return 0;
}
