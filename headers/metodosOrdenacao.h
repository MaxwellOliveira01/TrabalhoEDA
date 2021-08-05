#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

/*Ordena o array na ordem crescente ou decrescente usando o mergeSort*/
void merge(vector<int>& a, int ini, int meio, int fim, ll& cont);
void mergeSort(vector<int>& v, int ini, int fim, ll& cont);

/*Ordena o array na ordem crescente usando o bubbleSort*/
void bubbleSort(vector<int>& v, ll& cont);

/*Ordena o array na ordem crescente usando o insertionSort*/
void insertionSort(vector<int>&v, ll& cont);

/*Ordena o array na ordem crescente usando o shellSort*/
void shellSort(vector<int>&v,ll& cont);

/*Metodo auxiliar, apenas printa o vetor na tela*/
void mostraVetor(vector<int>& a, int quebra);