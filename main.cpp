#include <iostream>

#include "contaDuracao.h"
#include "geraNumeros.h"

using namespace std;

int main(){

    int N;
    cin >> N;
    
    vector<int> arr = ordemAleatoria(N);
    vector< vector<int> > r(4, vector<int>(2, 0));

    r[0][0] = getTimeMerge(arr, r[0][1]);
    r[1][0] = getTimeShell(arr, r[1][1]);
    r[2][0] = getTimeInsertion(arr, r[2][1]);
    r[3][0] = getTimeBubble(arr, r[3][1]);

    cout << "Merge: " << r[0][0] << " ms, " << r[0][1] << " comparações\n";
    cout << "Shell: " << r[1][0] << " ms, " << r[1][1] << " comparações\n";
    cout << "Insertion: " << r[2][0] << " ms, " << r[2][1] << " comparações\n";
    cout << "Bubble: " << r[3][0] << " ms, " << r[3][1] << " comparações\n";

    return 0;
}