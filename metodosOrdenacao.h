#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

/*Ordena o array na ordem crescente ou decrescente usando o mergeSort*/
vector<int> merge(vector<int>& a, vector<int>& b, int decres, ll& cont);
void mergeSort(vector<int>& v, int decres, ll& cont);

/*Ordena o array na ordem crescente ou decrescente usando o bubbleSort*/
void bubbleSort(vector<int>& v, int decres, ll& cont);

/*Ordena o array na ordem crescente ou decrescente usando o insertionSort*/
void insertionSort(vector<int>&v, int decres, ll& cont);

/*Ordena o array na ordem crescente ou decrescente usando o shellSort*/
void shellSort(vector<int>&v, int decres, ll& cont);

/*Metodo auxiliar, apenas printa o vetor na tela*/
void mostraVetor(vector<int>& a, int quebra);