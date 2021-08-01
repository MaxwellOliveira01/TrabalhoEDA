#include <iostream>
#include <unistd.h>

#include "contaDuracao.h"
#include "geraNumeros.h"

#define ff first
#define ss second

using ll = long long;
using namespace std;

int main(){

    cout << "Bem vindo ao módulo de testes!\nVamos iniciar com algumas perguntas\n";
    vector<string> names = {"MergeSort", "ShellSort","InsertionSort","BubbleSort"};
    string recebe;
    vector<int> skip(4, 1);

    cout << "Responda as perguntas a seguir com Sim/sim/s, caso a resposta seja afirmativa.\n\n";

    sleep(1);

    for(int i = 0; i < 4; i++){
        cout << "Deseja utilizar o método " << names[i] << "? ";
        cin >> recebe;
        skip[i] = ((recebe == "Sim") || (recebe == "sim") || (recebe == "s"));
    }
    cout << "\n";

    sleep(1);

    cout << "Quantos elementos deseja utilizar? Insira um numero no intervalo [0, 30000]\n";
    int N; cin >> N;
    N = max(0, N); N = min(30000, N);
    cout << "\n\nQuase tudo pronto!\nDeseja usar quantas repetições de " << N << " elemento(s) para fazer a média?\n";
    int qnt; cin >> qnt;
    
    cout << "\n\nPor fim, em que ordem deseja que os numeros gerados estejam em que ordem?\n1 - Crescente\n2 - Decrescente\n3 - Aleatoria\n\n";

    int ordem; cin >> ordem;

    vector< pair<int,ll> > results(4);

    for(int i = 0; i < qnt; i++){
        vector<int> arr;
        
        if(qnt == 1) arr = ordemCrescente(N);
        else if(qnt == 2) arr = ordemDecrescente(N);
        else arr = ordemAleatoria(N);

        for(int j = 0; j < 4; j++){
            if(!skip[j]) continue;
            results[j].ff += getTime(arr,j,results[j].ss);
        }
        
    }

    cout << "\n";

    cout << "A seguir os resultados obtidos ao ordenar " << qnt << " array(s) de tamanho " << N << "\n\n";

    for(int i = 0; i < 4; i++){
        if(!skip[i]) continue;
        cout << "Ao todo, o " << names[i] << " levou " << results[i].ff << " ms e fez " << results[i].ss << " comparações\n";
    }

    return 0;
}