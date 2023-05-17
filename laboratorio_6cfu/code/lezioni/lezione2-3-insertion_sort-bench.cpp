#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

// compilazione: g++ lezione1-3-insertion_sort-bench.c
//
// Obiettivo: creazione di un benchmark su 100 array di dimensioni diverse, con contenuto random. Ogni test ripetuto 1000 volte
// viene misurato il caso migliore, peggiore e medio in termini di swap e confronti

// Lanciare con
// > ./a.out 500

// usare i risultati per plottare dei grafici ed osservare l'andamento rispetto a quello del caso peggiore atteso

int n_ripetizioni_tests = 10000;
int ct_swap = 0;
int ct_op = 0;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    /// aggiorno contatore globale di swap
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
    }
}

int main(int argc, char **argv) {
    int n, i, test;

    /// controllo argomenti
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " max-dim-array (minimo 100)\n";
        return 1;
    }

    /// parsing argomento
    int max_dim_array = atoi(argv[1]);
    if (max_dim_array < 100)
        max_dim_array = 100;

    /// allocazione array
    int *A = new int[max_dim_array];

    // init random
    srand((unsigned)time(NULL));

    cout << "Dim_array,n_ripetizioni_test,min_swap,avg_swap,max_swap,expected_worst_case_swap,min_op,avg_op,max_op\n";

    //// inizio il ciclo per calcolare 100 dimensioni di array crescenti
    for (n = max_dim_array / 100; n <= max_dim_array; n += max_dim_array / 100) {
        int swap_min = -1;
        int swap_max = -1;
        long swap_avg = -1;

        int op_min = -1;
        int op_max = -1;
        long op_avg = -1;

        //// lancio n_ripetizioni_tests volte per coprire diversi casi di input random
        for (test = 0; test < n_ripetizioni_tests; test++) {

            /// inizializzazione array: numeri random con range dimensione array
            for (i = 0; i < n; i++) {
                A[i] = rand() % n;
            }

            ct_swap = 0;
            ct_op = 0;

            /// algoritmo di sorting
            insertion_sort(A, n);

            /// statistiche
            swap_avg += ct_swap;
            if (swap_min < 0 || swap_min > ct_swap)
                swap_min = ct_swap;
            if (swap_max < 0 || swap_max < ct_swap)
                swap_max = ct_swap;
            op_avg += ct_op;
            if (op_min < 0 || op_min > ct_op)
                op_min = ct_op;
            if (op_max < 0 || op_max < ct_op)
                op_max = ct_op;
        }

        cout << n << ",";
        cout << n_ripetizioni_tests << ",";
        cout << swap_min << ",";
        cout << (int)round((0.0 + swap_avg) / n_ripetizioni_tests) << ",";
        cout << swap_max << ",";
        cout << n * (n - 1) / 2 << ",";
        cout << op_min << ",";
        cout << (int)round((0.0 + op_avg) / n_ripetizioni_tests) << ",";
        cout << op_max;
        cout << "\n";
    }

    delete[] A;
    return 0;
}
