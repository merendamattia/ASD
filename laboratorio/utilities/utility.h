using namespace std;
/*
 * Effettua lo swap del contenuto di due variabili intere
*/
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

/*
 * Stampa a video il contenuto di un array
*/
void print_array(int *A, int n){
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
}

/*
 * Popola array con interi in ordine decrescente
*/
void populate_array(int *A, int n){
	for(int i = 0; i < n; i++)
		A[i] = n - i;
}