#include <chrono>
#include <vector>

#include "contaDuracao.h"
#include "metodosOrdenacao.h"

using namespace std;
using namespace std::chrono;

int getTime(vector<int>& arr, int metodo, long long& cont){

    auto start = high_resolution_clock::now();
    
    if(metodo == 4){
        mergeSort(arr, 0, (int)arr.size()-1, cont);
    } else if(metodo == 3){
        shellSort(arr, 0, cont);
    } else if(metodo == 2){
        insertionSort(arr, 0, cont);
    } else {
        bubbleSort(arr, 0, cont);
    }
    
    auto endd = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endd - start);
    return (int)duration.count();
}

int getTimeMerge(vector<int>& arr, long long& cont){
    return getTime(arr, 1, cont);
}

int getTimeShell(vector<int>& arr, long long& cont){
    return getTime(arr,2, cont);
}

int getTimeInsertion(vector<int>& arr, long long& cont){
    return getTime(arr,3, cont);
}

int getTimeBubble(vector<int>& arr, long long& cont){
    return getTime(arr,4, cont);
}
