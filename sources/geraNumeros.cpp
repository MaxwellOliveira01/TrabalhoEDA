#include <iostream>
#include <vector>

#include <algorithm>
#include <chrono>
#include <random>

#include "../headers/geraNumeros.h"

using namespace std;

vector<int> gerador(int N, int ordem){
    if(ordem == 1) return ordemCrescente(N);
    else if(ordem == 2) return ordemDecrescente(N);
    return ordemAleatoria(N);
}

vector<int> ordemCrescente(int N){
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }
    return arr;
}

vector<int> ordemDecrescente(int N){
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        arr[N - i - 1] = i + 1;
    }
    return arr;
}

vector<int> ordemAleatoria(int N){
    
    /* A linha a seguir é baseada no seguinte blog:
    https://codeforces.com/blog/entry/61587 ,
    onde ele incentiva a não usar o rand padrão para coisas
    aleatórias.*/

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> arr = ordemCrescente(N);
    shuffle(arr.begin(), arr.end(), rng);
    return arr;

}