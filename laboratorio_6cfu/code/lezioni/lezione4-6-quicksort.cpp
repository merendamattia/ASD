#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

// compilazione: g++ lezione4-6-quicksort.c
//
// Obiettivo:

// prove con array ordinato crescente, decrescente --> numero di confronti?
// ./a.out 1024 -d=16

// prove con array random --> numero di confronti?
// ./a.out 1024 -d=16 -t=100

int ct_swap = 0;
int ct_cmp = 0;
int ct_read = 0;

int max_dim = 0;
int ntests = 1;
int ndiv = 1;
int details = 0;
int graph = 0;

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

int partition(int *A, int p, int r) {

    /// copia valori delle due meta p..q e q+1..r
    ct_read++;
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        ct_cmp++;
        ct_read++;
        if (A[j] <= x) {
            i++;
            ct_read++;
            ct_read++;
            swap(A[i], A[j]);
        }
    }
    ct_read++;
    ct_read++;
    swap(A[i + 1], A[r]);

    return i + 1;
}

void quick_sort(int *A, int p, int r) {
    /// gli array L e R sono utilizzati come appoggio per copiare i valori: evita le allocazioni nella fase di merge
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int parse_cmd(int argc, char **argv) {
    /// controllo argomenti
    if (argc < 2) {
        cout << "Usage: " << argv[0] << "%s max-dim [Options]\n";
        cout << "   max-dim: specifica la massima dimensione n del problema\n";
        cout << "Options:\n";
        cout << "  -d=<int>: Specifica quali dimensioni n del problema vengono lanciate in sequenza [default: 1] \n";
        cout << "            n = k * max-dim / d, k=1 .. d\n";
        cout << "  -t=<int>: Specifica quanti volte viene lanciato l'algoritmo per una specifica dimensione n [default: 1]\n";
        cout << "            Utile nel caso in cui l'input viene inizializzato in modo random\n";
        cout << "  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n";
        cout << "  -graph: creazione file di dot con il grafo dell'esecuzione (forza d=1 t=1)\n";
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
        if (argv[i][1] == 'g') {
            graph = 1;
            ndiv = 1;
            ntests = 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    int i, test;
    int *A;
    int *B; /// buffer per visualizzazione algoritmo

    if (parse_cmd(argc, argv))
        return 1;

    /// allocazione array
    A = new int[max_dim];

    // init random
    srand((unsigned)time(NULL));

    if (ndiv > 1)
        cout << "Dim_array,N_test,min_swap,avg_swap,max_swap,min_cmp,avg_cmp,max_cmp,min_read,avg_read,max_read,n*n,n*log(n)\n";

    // printf("Parametri: max-dim %d, d %d, t %d, verbose %d\n",max_dim,ndiv,ntests,details);

    //// inizio ciclo per calcolare ndiv dimensioni di array crescenti
    for (n = max_dim / ndiv; n <= max_dim; n += max_dim / ndiv) {
        int swap_min = -1;
        int swap_max = -1;
        long swap_avg = 0;

        int cmp_min = -1;
        int cmp_max = -1;
        long cmp_avg = 0;

        int read_min = -1;
        int read_max = -1;
        long read_avg = 0;

        //// lancio ntests volte per coprire diversi casi di input random
        for (test = 0; test < ntests; test++) {

            /// inizializzazione array: numeri random con range dimensione array
            for (i = 0; i < n; i++) {
                // A[i] = i;
                // A[i] = n - i;
                A[i] = rand() % (n * 50);
            }

            if (details) {
                cout << "creato array di dimensione " << n << "\n";
                print_array(A, n);
            }

            ct_swap = 0;
            ct_cmp = 0;
            ct_read = 0;

            /// algoritmo di sorting
            quick_sort(A, 0, n - 1);

            if (details) {
                cout << "Output:\n";
                print_array(A, n);
            }

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
            read_avg += ct_read;
            if (read_min < 0 || read_min > ct_read)
                read_min = ct_read;
            if (read_max < 0 || read_max < ct_read)
                read_max = ct_read;
        }

        if (ndiv > 1)
            cout << n << "," << ntests << "," << swap_min << "," << (0.0 + swap_avg) / ntests << "," << swap_max << "," << cmp_min << "," << (0.0 + cmp_avg) / ntests << "," << cmp_max << "," << read_min << "," << (0.0 + read_avg) / ntests << "," << read_max << "," << 0.0 + n * n << "," << 0.0 + n * log(n) / log(2) << "\n";
    }

    delete[] A;

    return 0;
}
