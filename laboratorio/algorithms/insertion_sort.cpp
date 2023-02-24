#include "../utilities/utility.h"

void insertion_sort(int *A, int dim){
	for(int i = 0; i < dim; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
}

