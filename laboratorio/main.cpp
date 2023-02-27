#include <iostream>
#include <time.h>

#include "./utilities/utility.h"
#include "./algorithms/insertion.cpp"

using namespace std;

/*
 * Compilazione: g++ main.cpp -o main
 * Esecuzione: ./main 100 1 (100 è la dimensione dell'array, 1 è il valore della variabile "details")
 * Per visualizzare il tempo di esecuzione: time ./main 100 1
*/

int main(int argc, char **argv){

	srand(time(NULL)); // Inizializzo la generazione di numeri casuali
	
	// controllo argomenti
	if (argc != 3) {
		printf("ERRORE %s\n",argv[0]);
		return -1;
	}

	int dim = atoi(argv[1]); // parsing argomento

	bool details = atoi(argv[2]);

	int *A = new int[dim];

	populate_array(A, dim);

	//print_array(A, dim);

	insertion_sort(A, dim, details);

	//print_array(A, dim);

	delete[] A;
	return 0;
}