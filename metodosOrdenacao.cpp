#include "metodosOrdenacao.h"

#include <iostream>
#include <vector>

using namespace std;

void mostraVetor(vector<int>& a, int quebra){
    for(auto x: a)
        cout << x << " ";
    cout << endl;
    if(quebra) cout << endl;
}

vector<int> merge(vector<int>& a, vector<int>& b, int decres, int& cont){
    vector<int> aux((int)a.size() + (int)b.size());
    int pa = 0, pb = 0, p = 0;

    while(pa < (int)a.size() && pb < (int)b.size()){
        
        if(decres == 0){
            
            if(a[pa] < b[pb]){
                aux[p] = a[pa++];
            } else {
                aux[p] = b[pb++];
            }

        } else {

            if(a[pa] > b[pb]){
                aux[p] = a[pa++];
            } else {
                aux[p] = b[pb++];
            }

        }

        cont++;
        p++;

    }

    //adiciona os que restaram

    while(pa < (int)a.size()){
        aux[p++] = a[pa++];
        cont++;
    }
    
    while(pb < (int)b.size()){
        aux[p++] = b[pb++];
        cont++;
    }

    return aux;
}

void mergeSort(vector<int>& v, int decres, int& cont){

    if((int)v.size() <= 1) //caso base, já está ordenado
         return;

    int l = 0, r = (int)v.size();
    int m = l + (r-l) / 2; //evita overflow
    
    vector<int> esq(v.begin(), v.begin() + m); //pega [0,m-1]
    vector<int> dir(v.begin() + m, v.end()); //pega [m,r]
    mergeSort(esq, decres, cont); //ordena esquerda
    mergeSort(dir, decres, cont); //ordena direita
    v = merge(esq, dir, decres, cont); //pega o merge dos dois
}

void bubbleSort(vector<int>& v, int decres, int& cont){

    for(int r = (int)v.size(); r >= 0; r--){
        int fim = 0;
        for(int l = 0; l < r - 1; l++){
            if(decres){
                if(v[l] < v[l+1]){
                    swap(v[l], v[l+1]);
                    cont++;
                    fim++;
                }
            } else {
                if(v[l] > v[l+1]){
                    swap(v[l], v[l+1]);
                    cont++;
                    fim++;
                }
            }
        }
        if(!fim){
            break;
        }
    } 

}

void insertionSort(vector<int>&v, int decres, int& cont){
    int n = (int)v.size();
    for(int i = 1; i < n; i++){
        int j, aux = v[i];
        if(decres){
            for(j = i - 1; j >= 0 && v[j] < aux; j--){
                v[j+1] = v[j];
                cont++;
            }
        } else {
            for(j = i - 1; j >= 0 && v[j] > aux; j--){
                v[j+1] = v[j];
                cont++;
            }
        }
        v[j + 1] = aux;
    }
}

void shellSort(vector<int>&v, int decres, int& cont){

    /*Implementação baseada no código do geeksforgeeks, segue o link
        https://www.geeksforgeeks.org/shellsort/
    */

    for(int k = 30; k > 0; k--){
        //o gap é 2^k-1 pra manter a O(n^(3/2))

        if(1 << k - 1 > (int)v.size())
            continue;
        
        //a seguir é a mesma ideia do insertion sort
        //só que ao invés de diminuir de 1 em 1 diminue o gap

        for(int i = (1 << k) - 1; i < (int)v.size(); i++){
            int aux = v[i], j, gap = ((1 << k) - 1);
            if(decres){
   
                for(j = i; j >= gap && v[j-gap] < aux; j -= gap){
                    v[j] = v[j - gap];
                    cont++;
                }

            } else {
                
                for(j = i; j >= gap && v[j-gap] > aux; j -= gap){
                    v[j] = v[j - gap];
                    cont++;
                }

            }
            v[j] = aux;
        }
    }

}

