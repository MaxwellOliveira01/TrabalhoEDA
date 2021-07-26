#include "metodosOrdenacao.h"
#include "geraNumeros.h"

using namespace std;

int main(){

    int N;
    cin >> N;
    
    for(int i = 0; i < 10; i++){
        vector<int> tmp = ordemAleatoria(N);
        mostraVetor(tmp,0);
    }
    
    return 0;
}