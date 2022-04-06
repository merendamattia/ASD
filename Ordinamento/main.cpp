#include <iostream>
using namespace std;
#define DIM 10

void scambia(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

ostream& operator<<(ostream& dest, int vet[]){
    for(int i = 0; i < DIM; i++)
        dest << vet[i] << " ";
    dest << endl;
    return dest;
}

void insertionSort(int vet[]){
    cout << "Insertion sort:\n";
    int cont = 0;
    int chiave, i;
    for(int j = 1; j < DIM; j++){
        chiave = vet[j];
        i = j - 1;
        while(i >= 0 && vet[i] > chiave){
            vet[i + 1] = vet[i];
            i--;
            cout << ++cont << ")\t\t" << vet;
        }
        vet[i + 1] = chiave;
        cout << ++cont << ")\t\t" << vet;
    }
}

void merge(int arr[], const int begin, const int mid, const int end) {
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[begin + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[mid + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i = 0, j = 0, k = begin;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int vet[], const int begin, const int end){
    if(begin < end){
        int mid = (begin + end) / 2;
        mergeSort(vet, begin, mid);
        mergeSort(vet, mid + 1, end);
        merge(vet, begin, mid, end);
    }
}

void bubbleSort(int vet[]){
    for(int i = 0; i < DIM; i++)
        for(int j = DIM - 1; j > i; j--)
            if(vet[j] < vet[j - 1])
                scambia(vet[j], vet[j - 1]);
}

int partition(int vet[], int begin, int end){
    int pivot = vet[end];
    int i = begin - 1;
    for(int j = begin; j < end; j++)
        if(vet[j] <= pivot){
            i++;
            scambia(vet[j], vet[i]);
        }
    scambia(vet[i + 1], vet[end]);
    return i + 1;
}

void quicksort(int vet[], int begin, int end){
    if(begin < end){
        int mid = partition(vet, begin, end);
        quicksort(vet, begin, mid - 1);
        quicksort(vet, mid + 1, end);
    }
}

int main() {

    //int vet[] = {2,3,8,1,9,4,6,5,7,0};          //caso medio
    int vet[] = {9,8,7,6,5,4,3,2,1,0};          //caso peggiore

    cout << "Array non ordinato: " << vet;

    //insertionSort(vet);
    //mergeSort(vet, 0, DIM);
    //bubbleSort(vet);
    quicksort(vet, 0, DIM - 1);

    cout << "Array ordinato: " << vet;

    return 0;
}
