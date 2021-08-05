#include <iostream>
#include <fstream>
#include <string>

#include "../headers/moduloDeAprendizagem.h"

using namespace std;

int moduloDeAprendizagem(){
    int metodo;
    string line;
    ifstream arq;

    cout << "Bem vindo ao módulo de aprendizagem!\n";
    cout << "Escolha um método para ver informações sobre, digite\n";
    cout << "1 - BubbleSort\n2 - InsertionSort\n3 - ShellSort\n4 - MergeSort\n";
    cin >> metodo;

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
    return 0;
}
