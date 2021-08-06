#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../headers/moduloDeAprendizagem.h"
#include "../headers/contaDuracao.h"
#include "../headers/geraNumeros.h"

using namespace std;

int moduloDeAprendizagem(){
    int metodo, N, repet, tempo = 0;
    long long comp = 0;
    string line;
    ifstream arq;
    vector<string> names = {"BubbleSort", "InsertionSort", "ShellSort", "MergeSort"};

    {//recebendo input e dando boas vindas
        cout << "Bem vindo ao módulo de aprendizagem!\n";
        cout << "Escolha um método para ver informações sobre, digite\n";
        cout << "1 - BubbleSort\n2 - InsertionSort\n3 - ShellSort\n4 - MergeSort\n";
        cin >> metodo;
    }

    { //printando a descricao
        if(metodo == 1){
            arq.open("descricao/bubblesort.txt");
        } else if(metodo == 2){
            arq.open("descricao/insertionsort.txt");
        } else if(metodo == 3){
            arq.open("descricao/shellsort.txt");
        } else {
            arq.open("descricao/mergesort.txt");
        }

        while(getline(arq,line)){
            cout << line << "\n";
        }

        arq.close();
    }

    { //testando o método escolhido
        cout << "Deseja testar o método?\nDigite Sim/sim/s para afirmar.\n";
        cin >> line;
        
        if(line == "Sim" || line == "sim" || line == "s"){
            cout << "Digite a quantidade de valores que deseja.\n";
            cin >> N;
            cout << "Digite a quantidade de repetições que deseja usar para fazer a média\n";
            cin >> repet;
            
            N > 30000 || N <= 0 ? N = 10 : N = N;
            repet > 10 || repet <= 0 ? repet = 1 : repet = repet;

            for(int i = 0; i < repet; i++){
                vector<int> arr = ordemAleatoria(N);
                tempo += getTime(arr,metodo - 1, comp);
            }

            cout << "O método " << names[metodo - 1] << " usou em média " << (tempo + repet - 1) / repet << " ms "
            << "e " << (comp + repet - 1) / repet << " comparações para ordenar vetores de tamanho " << N << "\n";
        }
    }

    
    return 0;
}
