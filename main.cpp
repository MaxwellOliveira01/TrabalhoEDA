#include <algorithm>
#include <iostream>

#include "contaDuracao.h"
#include "geraNumeros.h"

using namespace std;

int main(){

    int N;
    cin >> N;
    
    vector<int> arr = ordemAleatoria(N);
    cout << "Merge: " << getTimeMerge(arr) << " ms\n";
    cout << "Shell: " << getTimeShell(arr) << " ms\n";
    cout << "Insertion: " << getTimeInsertion(arr) << " ms\n";
    cout << "Bubble: " << getTimeBubble(arr) << " ms\n";

    return 0;
}