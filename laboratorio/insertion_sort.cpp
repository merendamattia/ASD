#include <iostream>
#include <string.h>
#include "./utilities/utility.h"

using namespace std;

/*
 * Compilazione: g++ insertionsort.cpp -o insertion_sort
 * Esecuzione: ./insertion_sort 100 (100 è la dimensione dell'array)
 * Per visualizzare il tempo di esecuzione: time ./insertion_sort 100
*/

void insertion_sort(int *A, int dim){
	for(int i = 0; i < dim; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
}

int main(int argc, char **argv){
	
	// controllo argomenti
	if (argc != 2) {
		printf("Inserire un solo elemento dopo il file eseguibile %s\n",argv[0]);
		return -1;
	}

	int dim = atoi(argv[1]); // parsing argomento

	int *A = new int[dim];

	populate_array(A, dim);

	//print_array(A, dim);

	insertion_sort(A, dim);

	//print_array(A, dim);

	return 0;
}