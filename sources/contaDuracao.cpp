#include <chrono>
#include <vector>

#include "../headers/contaDuracao.h"
#include "../headers/metodosOrdenacao.h"

using namespace std;
using namespace std::chrono;

int getTime(vector<int>& arr, int metodo, long long& cont){

    auto start = high_resolution_clock::now();
    
    if(metodo == 0) 
        bubbleSort(arr, 0, cont);
    else if(metodo == 1)
        insertionSort(arr,0,cont);
    else if(metodo == 2)
        shellSort(arr,0,cont);
    else
        mergeSort(arr,0,(int)arr.size() - 1, cont);
    
    auto endd = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endd - start);
    return (int)duration.count();
}