#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

// compilazione: g++ lezione1-2-insertion_sort-details.c
//
// Obiettivi: - controllo dettagli esecuzione
//            - contare il numero di swap effettuati come misura di operazioni di base
//            - contare il numero di accessi mem + op alu effettuati come misura di operazioni di base

// Lanciare per controllare i dettagli
// > ./a.out 10 1

// Lanciare con
// > ./a.out 10
// > ./a.out 100

// cambio array in ingresso con totalmente ordinato crescente (caso migliore?)
// > ./a.out 10 1

// cambio array in ingresso con valori random (caso medio?)
// > ./a.out 10 1

int details = 0;

int ct_swap = 0; /// contatore swap
int ct_op = 0;   /// contatore operazioni di base (accesso memoria + aritmetica)

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    ct_swap++;
}

void insertion_sort(int *A, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        ct_op += 2; /// incremento + test

        for (j = i - 1; j >= 0; j--) {
            ct_op += 2; /// decremento + test
            ct_op += 3; /// 2 letture in memoria + test
            if (A[j] > A[j + 1]) {
                ct_op += 2; /// 2 letture in memoria
                swap(A[j], A[j + 1]);
            } else {
                break;
            }
        }

        /// stampa i passi dell'algoritmo
        if (details) {
            cout << "passo " << i << ":\n";
            for (j = 0; j < n; j++) {
                cout << A[j] << " ";
            }
            cout << "\n";
        }
    }
}

int main(int argc, char **argv) {
    int n, i;
    // int* A;

    /// controllo argomenti
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " dim-array [details=0/1]\n";
        return 1;
    }

    /// parsing argomento
    n = atoi(argv[1]);
    if (argc == 3)
        details = atoi(argv[2]);

    // init random
    srand((unsigned)time(NULL));

    /// allocazione array
    int *A = new int[n];

    /// inizializzazione array
    for (i = 0; i < n; i++) {
        // A[i] = n - i;
        // A[i]=i;
        A[i]= rand() % (1000);  ///
        // A[i]= rand() % (5);  /// range compatto
    }

    /// input
    if (details) {
        cout << "L'input e':\n";
        for (i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }

    /// sort
    insertion_sort(A, n);

    /// output
    if (details) {
        cout << "L'output e':\n";
        for (i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }

    cout << "Totale swap " << ct_swap << "\n";
    cout << "Totale op " << ct_op << "\n";

    delete[] A;
    return 0;
}
