/*
	Compilazione: 
		g++ insertion.cpp ordinamento.cpp -I../include
	Esecuzione: 
		./insertion 100 1 (100 è la dimensione dell'array, 1 è il valore della variabile "details")
	Per visualizzare il tempo di esecuzione: 
		time ./insertion 100 1
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/ordinamento.hh"

using namespace std;

Stat stat; // Per le statistiche
int& ct_swap = stat.ct_swap;
int& ct_cmp = stat.ct_cmp;
int& ct_read = stat.ct_read;
int& ct_op = stat.ct_op;
int& n = stat.n;
int& max_dim = stat.max_dim;
int& ntests = stat.ntests;
int& ndiv = stat.ndiv;
bool& details = stat.details;
bool& graph = stat.graph;
bool& comparison = stat.comparison;
string& output_path = stat.output_path;
ofstream& output_graph = stat.output_graph;

// Inizializza l'array di interi
void populate_array(int *A, int n){
	for (int i = 0; i < n; i++)
		A[i] = n - i; // caso peggiore
		// A[i] = i; // caso migliore
		// A[i] = rand() % (1000); // caso medio
}

// Implementazione standard
void insertion_sort(int* A, int dim) {
	int i, j;

	for (i=1; i<dim; i++)
		for (j=i-1; j>=0 && A[j]>A[j+1]; j--)
			swap(A[j], A[j+1], ct_swap);
}

// Implementazione con debug
void insertion_sort_debug(int *A, int dim) {
    for(int i = 0; i < dim; i++) {
		ct_op += 2; // incremento (i++) + test (i < dim)

		for(int j = i - 1; j >= 0; j--) {
			ct_op += 2; // decremento (j--) + test (j >= 0)

			ct_op += 3; // 2 letture in memoria (A[j] e A[j + 1]) + test
			
			if(A[j] > A[j + 1]){
				ct_op += 2;	// 2 letture in memoria (A[j] e A[j + 1]) + chiamata funzione swap
				swap(A[j], A[j + 1], ct_swap);
			}	
		}
		// ct_op++; // test finale uscita dal for (j < 0)
	
		if(details) {
			cout << "Passo " << i <<": ";
			print_array(A, dim);
		}
	}
	// ct_op++; // test finale uscita dal for (i == dim)
}

int main(int argc, char **argv){
	if (parse_cmd(argc, argv, stat))
        return 1;

	int* A = new int[max_dim]; // init array
		
    srand((unsigned)time(NULL)); // init random

	populate_array(A, max_dim);
	insertion_sort_debug(A, max_dim);
	//print_array(A, n);

	cout << "Totale swap: " << ct_swap << endl;
	cout << "Totale operazioni: " << ct_op << endl;

	delete [] A;
	return 0;
}