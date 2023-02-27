/*
 * Compilazione: g++ insertion.cpp -o insertion
 * Esecuzione: ./main 100 1 (100 è la dimensione dell'array, 1 è il valore della variabile "details")
 * Per visualizzare il tempo di esecuzione: time ./main 100 1
*/

#include <iostream>
#include <time.h>

using namespace std;
int ct_swap = 0;
int ct_op = 0;
bool details = false;


// Effettua lo swap del contenuto di due variabili intere
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
	ct_swap++;
}

// Stampa array
void print_array(int *A, int n){ 
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

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
			swap(A[j], A[j+1]);
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
}

int main(int argc, char **argv){
	if (argc < 2 || argc > 3) {
		 cout << "Usage: " << argv[0] << " dim-array [details=0/1]" << endl;
		return 1;
	}

	int n = atoi(argv[1]);
	if (n<=0) {
		cerr << "Invalid argument" << endl;
		return 1;
	}

	if (argc == 3)
        details = atoi(argv[2]);

	int* A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = n-i;
	
	// init random
    srand((unsigned)time(NULL));
	populate_array(A, n);
	insertion_sort_debug(A, n);
	print_array(A, n);

	cout << "Totale swap: " << ct_swap << endl;
	cout << "Totale op: " << ct_op << endl;

	delete [] A;
}