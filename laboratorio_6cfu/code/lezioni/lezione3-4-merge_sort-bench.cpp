#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

/*
Compilazione: g++ lezione2-4-merge_sort-bench.c

Opzioni:
   max-dim: specifica la massima dimensione n del problema
   -d=<int>: Specifica quanti test lanciare, ciascuno con dimensione diversa [default: 1]
             la dimensione di ciascun array n e' calcolata: n = k * max-dim / d, k=1..d
   -t=<int>: Specifica quante volte viene lanciato l'algoritmo per una specifica dimensione [default: 1]
             Utile nel caso in cui l'input viene inizializzato in modo random per calcolare i valori medi
   -verbose: Abilita stampe durante l'esecuzione dell'algoritmo
*/

// esecuzioni
// osservare i vari passaggi
// ./a.out 10 -verbose

// osservare la progressione n log (n)
// ./a.out 100 -d=10

// come cambiano i confronti al variare della dimensione dell'array: divisione ricorsiva a volte chiede piu' confronti (rispetto al caso con albero completo)
// ./a.out 128 -d=128 -t=1

// il numero dei confronti non cambia con diversi input (min=avg=max)
// ./a.out 100 -d=10 -t=100

int ct_swap = 0;
int ct_cmp = 0;

int max_dim = 0;
int ntests = 1;
int ndiv = 1;
int details = 0;

int n = 0; /// dimensione dell'array

void print_array(int *A, int dim) {
    for (int j = 0; j < dim; j++) {
        cout << A[j] << " ";
    }
    cout << "\n";
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    /// aggiorno contatore globale di swap
    ct_swap++;
}

void merge(int *A, int p, int q, int r, int *L, int *R) {

    /// copia valori delle due meta p..q e q+1..r
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < q - p + 1; i++)
        L[i] = A[p + i];
    L[i] = 1000000; /// un numero grande

    for (i = 0; i < r - q; i++)
        R[i] = A[q + 1 + i];
    R[i] = 1000000; /// un numero grande

    //// dettagli
    if (details) {
        cout << "Array L (" << p << " .. " << q << "): ";
        print_array(L, q - p + 1);
        cout << "Array R (" << q + 1 << " .. " << r << "): ";
        print_array(R, r - q);
    }

    i = 0; /// usato per gestire array L
    j = 0; /// usato per gestire array R

    for (k = p; k <= r; k++) {
        ct_cmp++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int *A, int p, int r, int *L, int *R) {
    /// gli array L e R sono utilizzati come appoggio per copiare i valori: evita le allocazioni nella fase di merge
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, L, R);
        merge_sort(A, q + 1, r, L, R);
        merge(A, p, q, r, L, R);
        if (details)
            print_array(A, n);
    }
}

int parse_cmd(int argc, char **argv) {
    /// controllo argomenti
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " max-dim [Options]\n";
        cout << "   max-dim: specifica la massima dimensione n del problema\n";
        cout << "Options:\n";
        cout << "  -d=<int>: Specifica quali dimensioni n del problema vengono lanciate in sequenza [default: 1] \n";
        cout << "            n = k * max-dim / d, k=1 .. d\n";
        cout << "  -t=<int>: Specifica quanti volte viene lanciato l'algoritmo per una specifica dimensione n [default: 1]\n";
        cout << "            Utile nel caso in cui l'input viene inizializzato in modo random\n";
        cout << "  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n";
        return 1;
    }

    /// parsing argomento
    max_dim = atoi(argv[1]);

    for (int i = 2; i < argc; i++) {
        if (argv[i][1] == 'd')
            ndiv = atoi(argv[i] + 3);
        if (argv[i][1] == 't')
            ntests = atoi(argv[i] + 3);
        if (argv[i][1] == 'v')
            details = 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    int i, test;
    int *A;
    int *L; /// usato come buffer di appoggio
    int *R; /// usato come buffer di appoggio

    if (parse_cmd(argc, argv))
        return 1;

    /// allocazione array
    A = new int[max_dim];
    L = new int[max_dim + 1];
    R = new int[max_dim + 1];

    // init random
    srand((unsigned)time(NULL));

    if (ndiv > 1)
        cout << "Dim_array,N_test,min_swap,avg_swap,max_swap,worst_case_swap,min_cmp,avg_cmp,max_cmp,worst_case_cmp\n";

    // printf("Parametri: max-dim %d, d %d, t %d, verbose %d\n",max_dim,ndiv,ntests,details);

    //// inizio ciclo per calcolare 100 dimensioni di array crescenti
    for (n = max_dim / ndiv; n <= max_dim; n += max_dim / ndiv) {
        int swap_min = -1;
        int swap_max = -1;
        long swap_avg = 0;

        int cmp_min = -1;
        int cmp_max = -1;
        long cmp_avg = 0;

        //// lancio ntests volte per coprire diversi casi di input random
        for (test = 0; test < ntests; test++) {

            /// inizializzazione array: numeri random con range dimensione array
            for (i = 0; i < n; i++) {

                // A[i]= n-i;
                A[i] = i;
                A[i]= rand() % (3*n);
            }

            if (details) {
                cout << "creato array di dimensione " << n << "\n";
                print_array(A, n);
            }

            ct_swap = 0;
            ct_cmp = 0;

            /// algoritmo di sorting
            merge_sort(A, 0, n - 1, L, R);

            /// statistiche
            swap_avg += ct_swap;
            if (swap_min < 0 || swap_min > ct_swap)
                swap_min = ct_swap;
            if (swap_max < 0 || swap_max < ct_swap)
                swap_max = ct_swap;
            cmp_avg += ct_cmp;
            if (cmp_min < 0 || cmp_min > ct_cmp)
                cmp_min = ct_cmp;
            if (cmp_max < 0 || cmp_max < ct_cmp)
                cmp_max = ct_cmp;
        }

        if (ndiv > 1)
            cout << n << "," << ntests << "," << swap_min << "," << (0.0 + swap_avg) / ntests << "," << swap_max << "," << 0.0 << "," << cmp_min << "," << (0.0 + cmp_avg) / ntests << "," << cmp_max << "," << n * log(n) / log(2) << "\n";
    }

    delete[] A;
    delete[] L;
    delete[] R;
    return 0;
}
