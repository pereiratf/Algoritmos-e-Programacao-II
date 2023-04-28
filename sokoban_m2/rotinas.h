#ifndef ROTINAS_H_INCLUDED
#define ROTINAS_H_INCLUDED

#include <iostream>
#include <windows.h> //cursor
#include <conio.h> //getch
#include <fstream> //arquivo
#include <stdlib.h> //random

void menu(int m[10][10], int &x, int &y, bool &jogando);

/*
0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/


using namespace std;
    void posicaoxy( int column, int line )
    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }

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

    ///se algum dos símbolos não aparecer (ficar com ?, tente substituir a fonte para Fontes de Varredura em propriedades do console -> fonte
    void imprimir(int m[10][10], int x, int y){
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if(i==x and j==y){
                    colorir(10); ///colorir faz com que a escrita a seguir seja com a cor número 10
                    cout<<char(2); ///impressão do personagem.
                    colorir(7); ///retorna a cor original após o fim da escrita
                } else {
                    switch(m[i][j]){
                        case 0:
                            cout<<" "; ///impressão do espaço vazio
                            break;

                        case 1:
                            colorir(14);
                            //cout<<char(178); ///impressão da parede
                            cout<<char(219); ///impressão da parede
                            colorir(7);
                            break;

                        case 2:
                            colorir(12);
                            cout<<char(219); ///impressão da caixa
                            colorir(7);
                            break;
                        case 3:
                            colorir(9);
                            cout<<char(4); ///impressão do destino da caixa
                            colorir(7);
                            break;
                        case 4:
                            colorir(11);
                            cout<<char(219); ///impressão da caixa no destino
                            colorir(7);
                            break;
                    }
                }
            }
            cout<<"\n";
        }
    } //fim imprime()

    void movimentar (int m[10][10], int &x, int &y) {
        char tecla;
        if (_kbhit()){
            tecla=getch();
            switch(tecla){
                case 72:
                    ///move -> livre
                    if(m[x-1][y]==0 or m[x-1][y]==3){
                        x--;
                    }
                    ///caixa livre -> livre
                    else if(m[x-1][y]==2 and m[x-2][y]==0){
                        x--;
                        m[x][y]=0;  ///após o movimento
                        m[x-1][y]=2;  ///a frente do movimento

                    }
                    ///caixa fim -> livre
                    else if(m[x-1][y]==4 and m[x-2][y]==0){
                        x--;
                        m[x][y]=3;  ///após o movimento
                        m[x-1][y]=2;  ///a frente do movimento

                    }
                    ///caixa livre -> fim
                    else if(m[x-1][y]==2 and m[x-2][y]==3){
                        x--;
                        m[x][y]=0;  ///após o movimento
                        m[x-1][y]=4;  ///a frente do movimento

                    }
                    ///caixa fim -> fim
                    else if(m[x-1][y]==4 and m[x-2][y]==3){
                        x--;
                        m[x][y]=3;  ///após o movimento
                        m[x-1][y]=4;  ///a frente do movimento

                    }

                break;
                case 80: x++; break;
                case 75: y--; break;
                case 77: y++; break;
            }
        }
    } //movimento


    //Selecionar o mapa deveria chamar uma função que carrega um mapa escolhido
    //de um arquivo para matriz m
    void selecionar_mapa(int m[10][10], int &x, int &y){
        int selecionar;
        int n_itens=1;
        
        cout<<"\nSELECIONE: \n1 - mapa1\n2 - mapa aleatório\n";
        cin>>selecionar;
        if(selecionar==2){
           selecionar = rand()/n_itens + 1; //gera um selecionar válido aleatório
        } 
        switch(selecionar){
            case 1:
                x=2;    y=2;
                int mapa1[10][10]={ 1,1,1,1,1,1,0,0,0,0,
                                    1,0,0,0,0,1,0,0,0,0,
                                    1,0,0,2,0,1,1,1,1,1,
                                    1,0,0,0,0,0,0,0,0,1,
                                    1,0,0,0,0,2,2,0,0,1,
                                    1,0,0,0,0,2,0,1,3,1,
                                    1,1,1,0,1,0,0,1,3,1,
                                    1,0,0,0,0,0,0,1,3,1,
                                    1,0,0,0,0,0,0,1,3,1,
                                    1,1,1,1,1,1,1,1,1,1  };
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        m[i][j]=mapa1[i][j];
                    }
                }
            break;
        } //fim switch

        system("cls");
    } //fim selecionar

    //verifica vitória
    bool vitoria (int m[10][10]){
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (m[i][j]==3){
                    return false;
                }
            }
        }
        return true;
    }

    void sokoban(int m[10][10], int &x, int &y, bool &jogando){
        
        while(!vitoria(m)){
            imprimir(m, x, y);
            movimentar(m, x, y);
            posicaoxy(0,0); ///posiciona a escrita no console no eixo x,y. A posição 0,0 é a do canto superior esquerdo.
        }
        jogando=false;
        system("cls");
        cout<<"\nVocê venceu!\nAperte qualquer tecla para retornar ao menu.\n";
        
            char tecla=getch();
            system("cls");
            menu(m, x, y, jogando);       


        
    }

    void sobre(int m[10][10], int &x, int &y, bool &jogando){
        cout<<"\n\nJogo beta para auxílio na m2 de algoritmos2 desenvolvido por Felski.\nAperte qualquer tecla para retornar ao menu.\n";
        char tecla=getch();
        system("cls");
        menu(m, x, y, jogando);
    }

    void menu(int m[10][10], int &x, int &y, bool &jogando){

        int selecionar;
        system("cls");
        cout<<"\nSELECIONE: \n1 - novo jogo\n2 - continuar\n3 - sobre\n4 - sair\n";
        cin>>selecionar;
        switch(selecionar){
            case 1:
                jogando = true; 
                system("cls");
                selecionar_mapa(m, x, y); 
                sokoban(m, x, y, jogando);
                break;
            case 2: 
                if(jogando){
                    system("cls");
                    sokoban(m, x, y, jogando);
                } else {
                    system("cls");
                    jogando = true;
                    selecionar_mapa(m, x, y); 
                    sokoban(m, x, y, jogando);
                }
                 
                break;
            case 3: 
                system("cls");
                sobre(m, x, y, jogando); 
                break;
            case 4: 
                exit(0);
                break;
        } //fim switch

        system("cls");
    } //fim selecionar

#endif // ROTINAS_H_INCLUDED