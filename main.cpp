#include <iostream>
using namespace std;

#include "headers/moduloDeAprendizagem.h"
#include "headers/moduloDeTestes.h"

int main(){
    int secao;
    string continuar;
    cout << "Bem vindo ao projeto da disciplina de Estrutura de Dados!\n";
    cout << "Temos duas seções disponíveis";
    do {
        cout << "digite:\n1 - Seção Educativa\n2 - Seção de Testes\n";
        cin >> secao;
        cout << "\n";
        if(secao == 1){
            continuar = moduloDeAprendizagem();
        } else {
            continuar = moduloDeTestes();
        }

        cout << "\n\nDeseja encerrar o programa? Digite Sim/sim/s para afirmar\n";
        cin >> continuar;

    } while( continuar != "Sim" && continuar != "sim" && continuar != "s" );


}