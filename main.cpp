#include "metodos.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x: arr)
        cin >> x;
    
    shellSort(arr,0);

    for(auto x: arr)
        cout << x << " ";
    cout << endl;

    return 0;
}