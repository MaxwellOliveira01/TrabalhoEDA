#include <iostream>
using namespace std;

#include "headers/moduloDeAprendizagem.h"
#include "headers/moduloDeTestes.h"

int main(){
    cout << "Teste!" << endl;
    int t = 0; cin >> t;
    if(t == 1) moduloDeTestes();
    else ok();
}