#include <iostream>
#include <windows.h>

using namespace std;

#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15

void cor_texto (int fonte, int fundo=0) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (fonte | fundo<<4));
}


int main () {
    cor_texto(6,11);
    cout<<"Oi";
    cor_texto(0,14);
    cout<<"Mundo!";
    cor_texto(7,0);
    //system("pause");
}