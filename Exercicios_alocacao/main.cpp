#include <iostream>

using namespace std;

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

void preenche_vetor(int *v, int t) {
    for (int i=0; i<t; i++){
        cout<<"Informe v["<<i<<"]: ";
        cin>>v[i];
    }
}

void imprime_vetor(int *v, int t) {
    for (int i=0; i<t; i++){
        cout<<"v["<<i<<"]: "<<v[i]<<"\n";
    }
}


void alterna(int *v1, int *v2, int *v3, int t) {
    for (int i=0; i<t; i++){
        v3[2*i]=v1[i];
        v3[2*i+1]=v2[i];
    }

}


int soma_vetor (int* v, int t) {
    int soma=0;
    for (int i=0; i<t; i++){
        soma=soma+v[i];
    }

    return soma;
}

bool simetrico (int* v, int t) {
    for (int i=0; i<t/2; i++){
        if (v[i]!=v[t-1-i]){
            return false;
        }
    }
    return true;
}

void bolha (int* v, int t){
    int temp;
    for (int i=0;i<t;i++){
        for (int j=0;j<t-1;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

void bolha_inversa (int* v, int t){
    int temp;
    for (int i=0;i<t;i++){
        for (int j=0;j<t-1;j++){
            if(v[j]<v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

void questao1 (){
    int t;
    cout<<"Informe o tamanho dos vetores: ";
    cin>>t;

    int *v1, *v2, *v3;
    v1 = new int[t];
    v2 = new int[t];
    v3 = new int[t+t];

    preenche_vetor(v1, t);
    bolha(v1, t);
    preenche_vetor(v2, t);
    bolha(v2, t);
    alterna(v1,v2,v3,t);
    imprime_vetor(v3, 2*t);

    delete []v1;
    delete []v2;
    delete []v3;
}

void questao2(){
    int t=0, tp=0, tn=0, n, sp, sn;
    int *vp, *vn;
    cout<<"Informe o numero de valores: ";
    cin>>t;
    vp = new int[t];
    vn = new int[t];
    for (int i=0; i<t; i++){
        cout<<"informe um numero: ";
        cin>>n;
        if (primo(n)){
            vp[tp]=n;
            tp++;
        } else {
            vn[tn]=n;
            tn++;
        }
    }

    sp=soma_vetor(vp, tp);
    sn=soma_vetor(vn, tn);

    if(sp>sn){
        imprime_vetor(vp, tp);
    } else if (sn>sp){
        imprime_vetor(vn, tn);
    } else {
        imprime_vetor(vp, tp);
        imprime_vetor(vn, tn);
    }

    delete []vp;
    delete []vn;
}

void questao3(){
    int t;
    int *v;
    cout<<"Informe o tamanho do vetor: ";
    cin>>t;
    v = new int[t];
    preenche_vetor(v, t);
    if(simetrico(v,t)){
        cout<<"vetor simetrico!";
    } else {
        cout<<"vetor nao simetrico!";
    }

    delete []v;
}

void questao4(){
    int t, seletor;
    int *v;
    cout<<"Informe o tamanho do vetor: ";
    cin>>t;
    v = new int[t];
    preenche_vetor(v, t);

    cout<<"digite 1 para crescente e 0 para decrescente: ";
    cin>>seletor;

    if (seletor){
        bolha(v, t);
    } else {
        bolha_inversa(v, t);
    }
    imprime_vetor(v, t);

    delete []v;

}

int main()
{
    //questao1();
    //questao2();
    //questao3();
    questao4();
    return 0;
}
