#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Grau2 {
    float a, b, c;
    float delta;
    float x1, x2;
    
    void entrada(float aa, float bb, float cc) {
        a=aa;
        b=bb;
        c=cc;
    }

    void calcula () {
        delta = b*b -4*a*c;
        if (delta >= 0){
            x1 =  (-b +sqrt(delta))/(2*a);
            x2 =  (-b -sqrt(delta))/(2*a);
        }
    }

    void resultado () {
        
        ofstream arq;
        arq.open("grau2.txt", ios_base::app);
        if (delta >=0){
            if(b>=0 && c>=0){
                arq<<a<<"x² + "<<b<<"x + "<<c;
                arq<<"\nx' = "<<x1<<", x'' = "<<x2<<"\n\n";
            } else if (b>=0) {
                arq<<a<<"x² + "<<b<<"x "<<c;
                arq<<"\nx' = "<<x1<<", x'' = "<<x2<<"\n\n";
            } else {
                arq<<a<<"x² "<<b<<"x + "<<c;
                arq<<"\nx' = "<<x1<<", x'' = "<<x2<<"\n\n";
            }
        } else {
            arq<<a<<"x² "<<b<<"x + "<<c;
            arq<<"Não tem raizes reais!\n\n";
        }
        
        arq.close();
        
    }
};

main () {

    Grau2 g;
    g.entrada(1,-2,-3);
    g.calcula();
    g.resultado();


    return 0;


}