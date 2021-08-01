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

vector<int> merge(vector<int>& a, ll& cont){
    //IMPLEMENTAR denovo
}

void mergeSort(vector<int>& v, long long& cont){
    //IMPLEMENTAR denovo
}

void bubbleSort(vector<int>& v, int decres, long long& cont){

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

void insertionSort(vector<int>&v, int decres, long long& cont){
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

void shellSort(vector<int>&v, int decres, long long& cont){

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

