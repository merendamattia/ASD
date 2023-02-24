#include <iostream>
#include "./utilities/utility.h"
#include "./algorithms/insertion_sort.cpp"

using namespace std;

/*
 * Compilazione: g++ main.cpp -o main
 * Esecuzione: ./main 100 (100 è la dimensione dell'array)
 * Per visualizzare il tempo di esecuzione: time ./main 100
*/

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

	print_array(A, dim);

	return 0;
}