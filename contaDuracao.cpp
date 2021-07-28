#include <chrono>
#include <vector>

#include "contaDuracao.h"
#include "metodosOrdenacao.h"

using namespace std;
using namespace std::chrono;

int getTime(vector<int> arr, int metodo){

    auto start = high_resolution_clock::now();
    
    if(metodo == 1){
        mergeSort(arr,0);
    } else if(metodo == 2){
        shellSort(arr, 0);
    } else if(metodo == 3){
        insertionSort(arr, 0);
    } else {
        bubbleSort(arr, 0);
    }
    
    auto endd = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endd - start);
    return (int)duration.count();
    
}

int getTimeMerge(vector<int> arr){
    return getTime(arr,1);
}

int getTimeShell(vector<int> arr){
    return getTime(arr,2);
}

int getTimeInsertion(vector<int> arr){
    return getTime(arr,3);
}

int getTimeBubble(vector<int> arr){
    return getTime(arr,4);
}
