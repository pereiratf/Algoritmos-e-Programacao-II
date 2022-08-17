#include <iostream>
#include <time.h> //para saber o dia atual
using namespace std;
#define T 40

struct Horario {
    int hora, minuto, segundo;
};

struct Data {
    int dia, mes, ano;
};

struct Cadastro {
    string nome;
    Data nascimento;
};

struct Apartamento {
    string nome;
    int apartamento, moradores;
    float area, valor;
};

struct Carro {
    char marca[15];
    int ano;
    char cor[10];
    float preco;
};

struct Gado {
    int codigo;
    float leite, alimento;
    Data nascimento;
    bool abate;
};

Horario DefineHorario(){
    Horario h;
    do {
        cout<<"Informe a hora: ";
        cin>>h.hora;
    } while (h.hora<0 || h.hora>23);
    
    do {
        cout<<"Informe o minuto: ";
        cin>>h.minuto;
    } while (h.minuto<0 || h.minuto>59);
    do {
        cout<<"Informe o segundo: ";
        cin>>h.segundo;
    } while (h.segundo<0 || h.segundo>59);
    return h;
}
Horario SomaHorario (Horario h1, Horario h2){
    Horario h;
    h.segundo = (h1.segundo + h2.segundo)%60; //soma segundos sem passar o segundo máximo
    h.minuto = (h1.minuto + h2.minuto + (h1.segundo + h2.segundo)/60)%60; //com o segundo que passou e sem passar o máximo
    h.hora = (h1.hora + h2.hora + (h1.minuto + h2.minuto + (h1.segundo + h2.segundo)/60)/60)%24;
    return h;
}

bool DataValida (Data d){
    switch(d.mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (d.dia>=1 && d.dia<=31){
                return true;
            }
            return false;
        break;
        case 4: case 6: case 9: case 11:
            if (d.dia>=1 && d.dia<=30){
                return true;
            }
            return false;
        break;
        case 2:
            if ((d.ano%4==0 && d.ano%100!=0) || d.ano%400==0){
                if (d.dia>=1 && d.dia<=29){
                    return true;
                }
                return false;
            } else {
                if (d.dia>=1 && d.dia<=28){
                    return true;
                }
                return false;
            }
        break;
        default:
        return false;
    }
}

void CriaData(Data &d){
    d.mes = 1 + (rand() % 12);
    d.ano = 1980 + (rand() % 43);
    d.dia = 1 + (rand() % 30);
}

int Idade (Data d){
    //pegando a hora atual da biblioteca time.h
    struct tm *DA; //data atual
    time_t s;
    time(&s);
    DA=localtime(&s);
    
    //carregando a data da biblioteca na nossa struct local para facilitar
    Data data_atual;
    data_atual.dia = DA->tm_mday;
    data_atual.mes = DA->tm_mon+1;
    data_atual.ano = DA->tm_year+1900;

    //calculando idade
    if(d.mes>data_atual.mes || (d.mes==data_atual.mes && d.dia>=data_atual.dia)){
        return (data_atual.ano - d.ano);
    }
    return (data_atual.ano - d.ano - 1);
    
}

void CadastrarApartamento(Apartamento &ap){
    cout<<"Nome do responsável pelo apartamento: ";
    cin>>ap.nome;
    cout<<"Número do apartamento: ";
    cin>>ap.apartamento;
    cout<<"Área do apartamento: ";
    cin>>ap.area;
    cout<<"Número de moradores: ";
    cin>>ap.moradores;
}

void CadastrarCarro(Carro &carro){
    cout<<"Marca: ";
    cin>>carro.marca;
    cout<<"Ano: ";
    cin>>carro.ano;
    cout<<"Cor: ";
    cin>>carro.cor;
    cout<<"Preço: ";
    cin>>carro.preco;
}

void CadastrarGado(Gado &g){
    // inventei uns random para não precisar preencher na mão.
    static int code=0;
    g.codigo = code;
    code++;
    g.leite = 21 + rand()%80;
    g.alimento = 11 + rand()%40;
    do {
        CriaData(g.nascimento);
    } while (!DataValida);
}

void Abate (Gado &g){
    if (Idade(g.nascimento)>5 || g.leite<40 || (g.leite<70 && g.alimento>50)){
        g.abate = true;
    } else {
        g.abate = false;
    }
}


int main (){
    setlocale(LC_ALL, "portuguese");
    //questão 1
    Horario h1, h2, h3;

    //questão 2
    Data d1;

    //questão 3
    Cadastro ca[T];
    int idade_minima;
    

    //questão 4
    Apartamento ap[T];
    int menu, mais_moradores;
    float area_total;

    //questao 5
    Carro carro[T], busca_carro;
        //variável menu criada na questão anterior
    int preco;
    char marca[15];

    //questão 6
    Gado gado[T];
    float leite, alimento; 
    int gado_abate;

    int q;
    cout<<"\nInforme o numero da questão: ";
    cin>>q;
    switch (q){
        case 1:
            h1=DefineHorario();
            h2=DefineHorario();
            h3=SomaHorario(h1,h2);
            cout<<"\nHora Final = "<<h3.hora<<":"<<h3.minuto<<":"<<h3.segundo;
        break;

        case 2:             
            cout<<"Informe um dia: ";
            cin>>d1.dia;
            cout<<"Informe um mês: ";
            cin>>d1.mes;
            cout<<"Informe um ano: ";
            cin>>d1.ano;
            if(!DataValida){ //o símbolo ! na frente da função inverte o retorno lógico dela
                cout<<"Data inválida!";
            }
        break;
        
        case 3: 
            cout<<"Preenchendo cadastros...\n";
            for(int i=0;i<T;i++){
                cout<<"Informe o nome: ";
                cin>>ca[i].nome;
                do {
                    CriaData(ca[i].nascimento);
                } while (!DataValida);
            }

            cout<<"listando nomes e idades...";
            for(int i=0;i<T;i++){
                cout<<"\n"<<ca[i].nome<<"\t"<<Idade(ca[i].nascimento);
            }

            cout<<"\nQual a idade minima? ";
            cin>>idade_minima;
            cout<<"listando nomes e idades (após corte)...";
            for(int i=0;i<T;i++){
                if (Idade(ca[i].nascimento)>=idade_minima){
                    cout<<"\n"<<ca[i].nome<<"\t"<<Idade(ca[i].nascimento);
                }
                
            }

        break;

    case 4: 
            do {
                cout<<"\nEscolha \n\t1 - preencher cadastros\n\t2 - Calcular área total";
                cout<<"\n\t3 - Apartamentos com maior número de moradores\n\t4 - Sair\n";
                cin>>menu;
                switch (menu) {
                case 1:
                    for(int i=0;i<T;i++){
                        CadastrarApartamento(ap[i]);
                    }
                    break;
                case 2: 
                    area_total=0;
                    for(int i=0;i<T;i++){
                        area_total = area_total + ap[i].area;
                    }
                    cout<<"A área total é de "<<area_total<<" metros quadrados.";
                    break;
                
                case 3: 
                    //descobrir o maior numero de moradores
                    mais_moradores=0;
                    for(int i=0;i<T;i++) {
                        if(ap[i].moradores>mais_moradores){
                            mais_moradores=ap[i].moradores;
                        }
                    }
                    //imprimir os apartamentos com mais moradores
                    for(int i=0;i<T;i++) {
                        if(ap[i].moradores==mais_moradores){
                           cout<<"\nApartamento "<<ap[i].apartamento<<" possui "<<ap[i].moradores<<" moradores.";
                        }
                    }
                    
                    break;
                default:
                    menu=4;
                    cout<<"\nSaindo...\n";
                    break;
                } //switch menu da questão 4

            } while (menu!=4);
        break;

        case 5:
            cout<<"\nEscolha\n\t1 - preencher cadastro dos carros\n\t2 - Carros mais baratos que determinado valor";
            cout<<"\n\t3 - Exibe carros da marca escolhida\n\t4 - Buscar carro na base de dados\n\t5 - Sair";
            cin>>menu;
            do {
                switch (menu)
                {
                case 1:
                    for(int i=0;i<T;i++){
                        CadastrarCarro(carro[i]);
                    }
                    break;
                
                case 2:
                    cout<<"Informe o preço máximo: ";
                    cin>>preco;
                    for(int i=0;i<T;i++){
                        if(preco <= carro[i].preco){
                            cout<<i<<" carro: "<<carro[i].marca<<", ano "<<carro[i].ano<<", cor "<<carro[i].cor<<"\n";
                        }
                    }
                    break;
                case 3:
                    cout<<"Informe a marca do carro: ";
                    cin>>marca;
                    for(int i=0;i<T;i++){
                        if(marca == carro[i].marca){
                            cout<<i<<" ano "<<carro[i].ano<<", cor "<<carro[i].cor<<", preço "<<carro[i].preco<<" reais\n";
                        }
                    }
                    break;
                case 4:
                    cout<<"Informe os dados do carro que está procurando (marca ano cor): ";
                    cin>>busca_carro.marca >> busca_carro.ano >> busca_carro.cor;
                    for(int i=0;i<T;i++){
                        if(busca_carro.marca == carro[i].marca && busca_carro.ano == carro[i].ano && busca_carro.cor == carro[i].cor){
                            cout<<i<<" preço "<<carro[i].preco<<" reais\n";
                        }
                    }
                    break;
                default:
                    menu=5;
                    break;
                } //switch questao 5
            } while (menu!=5);
                

        break;

        case 6: 
            for(int i=0;i<T;i++){
                CadastrarGado(gado[i]);
            }
            cout<<"\nEscolha\n\t1 - Produção semanal de leite\n\t2 - Consumo de alimento por semana";
            cout<<"\n\t3 - Produção de leite (após abate)\n\t4 - Consumo de alimento(após abate)";
            cout<<"\n\t5 - Quantidade de gado para abate\n\t6 - Sair";
            cin>>menu;
            do {
                switch (menu)
                {
                case 1:
                    leite=0;
                    for(int i=0;i<T;i++){
                        leite = leite + gado[i].leite;
                    }
                    cout<<"A fazenda produz "<<leite<<" litros de leite por semana.";
                    break;
                
                case 2:
                    alimento=0;
                    for(int i=0;i<T;i++){
                        alimento = alimento + gado[i].alimento;
                    }
                    cout<<"A fazenda gasta "<<alimento<<" kilos de alimento por semana.";
                    break;
                case 3:
                    leite=0;
                    for(int i=0;i<T;i++){
                        if (!gado[i].abate){
                            leite = leite + gado[i].leite;
                        }                        
                    }
                    cout<<"A fazenda produzirá "<<leite<<" litros de leite por semana após o abate.";
                    break;
                case 4:
                    alimento=0;
                    for(int i=0;i<T;i++){
                        if (!gado[i].alimento){
                            alimento = alimento + gado[i].alimento;
                        }                          
                    }
                    cout<<"A fazenda gastará "<<alimento<<" kilos de alimento por semana após o abate.";
                    break;
                case 5:
                    gado_abate=0;
                    for(int i=0;i<T;i++){
                        if (gado[i].abate){
                            gado_abate++;
                        }                          
                    }
                    cout<<"A fazenda enviará "<<gado_abate<<" cabeças de gado para o abate.";
                    break;
                default:
                    menu=6;
                    break;
                } //switch questao 6
            } while (menu!=6);
        break;

        default:
        break;

    }//switch escolha questão questão


    return 0;
}