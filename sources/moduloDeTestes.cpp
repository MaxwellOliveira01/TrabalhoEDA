#include <iostream>

#include "../headers/contaDuracao.h"
#include "../headers/geraNumeros.h"
#include "../headers/metodosOrdenacao.h"

#include "../headers/moduloDeTestes.h"

#define ff first
#define ss second

using ll = long long;
using namespace std;

ll ceil(ll a, ll b){
    return (a+b-1) / b;
}

int moduloDeTestes(){
    vector<string> names = {"BubbleSort","InsertionSort","ShellSort","MergeSort"};
    vector< pair<int,ll> > results(4, {0,0}); // tempo, quantidade de comparações
    vector< vector<int> > arr(4); //guarda os numeros a serem ordenados pelos métodos
    vector<int> useIt(4, 1); // terá 1 na posição i se o usuário quer usar o método i
    string recebe; //recebe input
    int N, qnt, ordem; //variaveis para salvar os valores digitados

    cout << "Bem vindo ao módulo de testes!\nVamos iniciar com algumas perguntas\n";
    cout << "Responda as perguntas a seguir com Sim/sim/s, caso a resposta seja afirmativa.\n\n";
    
    {    //recebendo os métodos desejados
        for(int i = 0; i < 4; i++){
            cout << "Deseja utilizar o método " << names[i] << "? ";
            cin >> recebe;
            useIt[i] = ((recebe == "Sim") || (recebe == "sim") || (recebe == "s"));
        }
        cout << "\n";
    }
    
    {   //recebendo a quantidade de elementos
        cout << "Quantos elementos deseja utilizar? Insira um numero no intervalo [0, 30000]\n";
        cin >> N;
        N > 30000 || N <= 0 ? N = 10 : N = N;
    }

    {   //recebendo a quantidade de repetições
        cout << "\nQuase tudo pronto!\nDeseja usar quantas repetições de " << N << " elemento(s) para fazer a média?\n";
        cin >> qnt;
        qnt > 10 || qnt <= 0 ? qnt = 1 : qnt = qnt;
    }

    {   //recebendo a ordem dos valores
        cout << "\nPor fim, em que ordem deseja que os numeros gerados estejam em que ordem?\n1 - Crescente\n2 - Decrescente\n3 - Aleatoria\n";
        cin >> ordem;
        ordem = max(1, ordem);
        ordem = min(3, ordem);
    }

    {    //gera N numeros, ordena por cada método e salva os resultados.
        for(int i = 0; i < qnt; i++){
            arr[0] = gerador(N, ordem);
            arr[1] = arr[0]; arr[2] = arr[0]; arr[3] = arr[0];
            for(int j = 0; j < 4; j++){
                if(!useIt[j]) continue;
                results[j].ff += getTime(arr[j],j,results[j].ss);
            }
        }
    }

    {   //coloca os dados na tela
        cout << "\nA seguir os resultados obtidos ao ordenar " << qnt << " array(s) de tamanho " << N << "\n";
        for(int i = 0; i < 4; i++){
            if(!useIt[i]) continue;
            cout << "Ao todo o " << names[i] << " usou " << ceil(results[i].ff,qnt) << " ms, fazendo " << ceil(results[i].ss,qnt) << " comparações\n";
        }
    }

    return 0;
}