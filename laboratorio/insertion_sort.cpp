#include <iostream>
#include <string.h>
using namespace std;

void insertion_sort(int *A, int n){
	for(int i = 0; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void print_array(int *A, int n){
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
}

int main(){
	int n = 100;
	int *A = new int[n];

	for(int i = 0; i < n; i++)
		A[i] = n - i;

	print_array(A, n);

	insertion_sort(A, n);

	print_array(A, n);

	return 0;
}
