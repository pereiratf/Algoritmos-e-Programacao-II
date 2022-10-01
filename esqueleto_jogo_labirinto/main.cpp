/*ESQUELETO PARA UM JOGO DE LABIRINTO UTILIZANDO RECURSOS APRENDIDOS EM AULA
OBS: O programa tem melhorias óbvias considerando os conteúdos vistos em aula
- Por exemplo, o arquivo não é atualizado no final da execução

Enunciado da atividade feita em aula:
Faça um programa que lê um arquivo com indicações de espaço livre(0), barreira(1), personagem(2)
O jogo deve ter uma função que permite o movimento do personagem pelas posições livres sem deixar rastro

*/
#include <iostream>
#include <fstream>
#include <conio.h> //getch()
#include <windows.h> ///remover

using namespace std;

struct PLAYER {
    int x,y;

    void coord (int li, int co){
        x=li;
        y=co;
    }
};

struct ARQUIVO {
    char* nome;
    int x, y;
    int** m;


    void tam(int li, int co){
        x=li;
        y=co;
    }


    void carrega (){
        m = new int*[x];
        for (int i=0; i<x; i++){
            m[i]=new int[y];
        }

        ifstream mapa;
        mapa.open(nome);
        char c;

        ///coloca na matriz o mapa
        for(int i=0; i<x;i++){
            for(int j=0; j<y;j++){
                    mapa>>c;
                    m[i][j]=c-48;
            }
        }
    }

};
void mostrarCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void colorir (int cor) {

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, cor);
}
void posicaoxy( int column, int line )
    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }

void mostra_mapa (ARQUIVO a) {
    posicaoxy(0,0);
    for (int i=0; i<a.x; i++){
        for (int j=0; j<a.y; j++){
            switch(a.m[i][j]){
            case 0: cout<<" "; break;
            case 1: cout<<char(219); break;
            case 2: cout<<char(1); break;
            }
        }
        cout<<"\n";
    }
}

void mover (PLAYER &p, ARQUIVO &mapa){
    char tecla=getch();
    switch (tecla){
    case 'w':
        if(mapa.m[p.x-1][p.y]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x-1][p.y]=2;
            p.x=p.x-1;
        }
        break;
    case 's':
         if(mapa.m[p.x+1][p.y]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x+1][p.y]=2;
            p.x=p.x+1;
        }
        break;
    case 'a':
        if(mapa.m[p.x][p.y-1]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x][p.y-1]=2;
            p.y=p.y-1;
        }
        break;
    case 'd':
        if(mapa.m[p.x][p.y+1]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x][p.y+1]=2;
            p.y=p.y+1;
        }
        break;

    }
}

int main()
{
    mostrarCursor(false);
    PLAYER p;
    p.coord(3,4);

    ARQUIVO mapa;
    mapa.nome="labirinto.txt";
    mapa.tam(10,10);
    mapa.carrega();

    while (true){
        mostra_mapa(mapa);
        mover(p, mapa);
    }


    return 0;
}
