#include <iostream>
#include <time.h>

#include "./utilities/utility.h"

using namespace std;

/*
 * Compilazione: g++ main.cpp -o main
 * Esecuzione: ./main 100 1 (100 è la dimensione dell'array, 1 è il valore della variabile "details")
 * Per visualizzare il tempo di esecuzione: time ./main 100 1
*/

int ct_op = 0;

/*
	Obiettivi: TODO

*/

void insertion_sort(int *A, int dim, bool details){
	for(int i = 0; i < dim; i++) {
		ct_op += 2; // incremento (i++) + test (i < dim)

		for(int j = i - 1; j >= 0; j--) {
			ct_op += 2; // decremento (j--) + test (j >= 0)

			ct_op += 3; // 2 letture in memoria (A[j] e A[j + 1]) + test
			if(A[j] > A[j + 1]){
				
				ct_op += 3;	// 2 letture in memoria (A[j] e A[j + 1]) + chiamata funzione swap
				swap(A[j], A[j + 1]);
			}	
		}
		// ct_op++; // test finale uscita dal for (j < 0)
	
		if(details) {
			cout << "Passo " << i <<": ";
			print_array(A, dim);
		}
	}
	// ct_op++; // test finale uscita dal for (i == dim)

	// Gauss: ct_swap = dim * (dim - 1) / 2 nel caso peggiore (?) TODO: verificare
	cout << "Totale swap: " << ct_swap << endl;
	cout << "Totale op: " << ct_op << endl;
}


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