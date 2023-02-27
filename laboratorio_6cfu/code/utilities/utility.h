using namespace std;
int ct_swap = 0;

/*
 * Effettua lo swap del contenuto di due variabili intere
*/
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
	ct_swap++;
}

/*
 * Stampa a video il contenuto di un array
*/
void print_array(int *A, int n){
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

/*
 * Popola array con interi in ordine decrescente: caso peggiore
*/
void populate_array(int *A, int n){
	for(int i = 0; i < n; i++)
		// A[i] = n - i; // caso peggiore
		// A[i] = i; // caso migliore
		A[i] = rand() % (1000); // caso medio
}