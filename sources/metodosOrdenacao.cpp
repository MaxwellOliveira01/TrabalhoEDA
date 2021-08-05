#include "../headers/metodosOrdenacao.h"

#include <iostream>
#include <vector>

using namespace std;

void mostraVetor(vector<int>& a, int quebra){
    for(auto x: a)
        cout << x << " ";
    cout << endl;
    if(quebra) cout << endl;
}

void merge(vector<int>& a, int ini, int meio, int fim, ll& cont){
    vector<int> esq(meio - ini + 1, 0);
    vector<int> dir(fim - meio, 0);

    for(int i = 0; i < (int)esq.size(); i++){
        esq[i] = a[ini + i];
    }

    for(int i = 0; i < (int)dir.size(); i++){
        dir[i] = a[meio + 1 + i]; //+1 pq o meio está no outro array
    }

    int p = 0, pesq = 0, pdir = 0;

    while(pesq < (int)esq.size() && pdir < (int)dir.size()){

        if(esq[pesq] < dir[pdir]){
            a[ini++] = esq[pesq++];
        } else {
            a[ini++] = dir[pdir++];
        }

        cont++;
    }

    /*os dois while's a seguir nao há a incrementação de "cont"
    pois não há comparação.*/

    while(pesq < (int)esq.size()){
        a[ini++] = esq[pesq++];
    }

    while(pdir < (int)dir.size()){
        a[ini++] = dir[pdir++];
    }


}

void mergeSort(vector<int>& v, int ini, int fim, long long& cont){
    if(ini >= fim) return; //caso base
    int m = ini + (fim - ini)/2;
    //ordena as duas partes
    mergeSort(v,ini,m,cont);
    mergeSort(v,m+1,fim,cont);
    //junta
    merge(v,ini,m,fim,cont);
}

void bubbleSort(vector<int>& v, long long& cont){

    for(int r = (int)v.size(); r >= 0; r--){
        int fim = 0;
        for(int l = 0; l < r - 1; l++){
            if(v[l] > v[l+1]){
                swap(v[l], v[l+1]);
                cont++;
                fim++;
            }
        }
        if(!fim){
            break;
        }
    } 

}

void insertionSort(vector<int>&v, long long& cont){
    int n = (int)v.size();
    for(int i = 1; i < n; i++){
        int j, aux = v[i];
        for(j = i - 1; j >= 0 && v[j] > aux; j--){
            v[j+1] = v[j];
            cont++;
        }
        v[j + 1] = aux;
    }
}

void shellSort(vector<int>&v, long long& cont){

    /*
    Implementação baseada no código do geeksforgeeks, segue o link
        https://www.geeksforgeeks.org/shellsort/
    */

    /*
    usando a tabela de gap's do link https://en.wikipedia.org/wiki/Shellsort#Gap_sequences
    usei a de 2^k-1 para manter a complexidade em O(N^(3/2))
    */
    for(ll k = 30; k > 0; k--){

        ll gap = (1<<k) - 1;

        //a seguir é a mesma ideia do insertion sort
        //só que ao invés de diminuir de 1 em 1 diminue o gap

        for(int i = gap - 1; i < (int)v.size(); i++){
            int aux = v[i], j;
            for(j = i; j >= gap && v[j-gap] > aux; j -= gap){
                v[j] = v[j - gap];
                cont++;
            }
            v[j] = aux;
        }
    }
    
}