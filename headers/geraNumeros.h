#include <vector>

using namespace std;

/*Todas as sequencias geradas pelos metodos a seguir
contém apenas numeros no intervalo [1,N].*/

/*usa a variavel ordem pra retornar algum dos outros métodos.*/
vector<int> gerador(int N, int ordem);

/*Retorna uma sequencia de numeros em ordem crescente*/
vector<int> ordemCrescente(int N);
/*Retorna uma sequencia de valores em ordem decrescente*/
vector<int> ordemDecrescente(int N);
/*Retorna uma sequencia de numeros em ordem aleatória*/
vector<int> ordemAleatoria(int N);