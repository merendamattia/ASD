#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

// compilazione: g++ lezione6-12-bisection-dot.cpp
//
// Obiettivo:

// ricerca per bisezione su array ordinato
// 1) ./a.out 64 -verbose : osservare le operazioni effettuate (quando conviene sort + bisection vs ricerca O(n)

// 2) ./a.out 64 -t=1000 : osservare il numero di operazioni min/med/max

// 3) ./a.out 64 -graph; dot graph.dot -Tpdf -o graph.pdf : osservare il grafo

int ct_swap = 0;
int ct_cmp = 0;
int ct_op = 0; /// operazioni per la ricerca

int max_dim = 0;
int ntests = 1;
int ndiv = 1;
int details = 0;
int graph = 0;

int n = 0; /// dimensione dell'array

/// file di output per grafo
ofstream output_graph;

void print_array(int *A, int dim) {
    for (int j = 0; j < dim; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");
}

void print_array_graph(int *A, int n, string c, int a, int l, int m, int r) {
    /// prepara il disegno dell'array A ed il suo contenuto (n celle)
    /// a e' il codice del nodo e c la stringa
    /// l,m,r i tre indici della bisezione

    // return ;

    output_graph << c << a << " [label=<" << endl;

    /// tabella con contenuto array
    output_graph << "<TABLE BORDER=\"0\" CELLBORDER=\"0\" CELLSPACING=\"0\" > " << endl;
    /// indici
    output_graph << "<TR  >";
    for (int j = 0; j < n; j++) {
        output_graph << "<TD ";
        output_graph << ">" << j << "</TD>" << endl;
    }
    output_graph << "</TR>" << endl;
    output_graph << "<TR>";
    // contenuto
    for (int j = 0; j < n; j++) {
        output_graph << "<TD BORDER=\"1\"";
        if (j == m)
            output_graph << " bgcolor=\"#00a000\""; /// valore testato
        else if (j >= l && j <= r)
            output_graph << " bgcolor=\"#80ff80\""; /// range di competenza
        output_graph << ">" << A[j] << "</TD>" << endl;
    }
    output_graph << "</TR>" << endl;
    output_graph << "</TABLE> " << endl;

    output_graph << ">];" << endl;
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
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        ct_cmp++;
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
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

int bisection(int *A, int n, int t) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        ct_op++;
        int m = (l + r) / 2;
        if (details)
            printf("[%d .. %d .. %d]\n", l, m, r);

        print_array_graph(A, n, "node_", ct_op, l, m, r);
        output_graph << "node_" << ct_op - 1 << " -> ";
        output_graph << "node_" << ct_op << endl;
        if (ct_op == 1) {
            output_graph << "node_" << 0 << "[label=\"Search index of value " << t << "\"]\n";
        }

        if (A[m] < t)
            l = m + 1;
        else {
            if (A[m] > t)
                r = m - 1;
            else
                return m; /// trovato
        }
    }
    return -1; // non trovato
}

int parse_cmd(int argc, char **argv) {
    /// controllo argomenti
    if (argc < 2) {
        printf("Usage: %s max-dim [Options]\n", argv[0]);
        printf("   max-dim: specifica la massima dimensione n del problema\n");
        printf("Options:\n");
        printf("  -d=<int>: Specifica quali dimensioni n del problema vengono lanciate in sequenza [default: 1] \n");
        printf("            n = k * max-dim / d, k=1 .. d\n");
        printf("  -t=<int>: Specifica quanti volte viene lanciato l'algoritmo per una specifica dimensione n [default: 1]\n");
        printf("            Utile nel caso in cui l'input viene inizializzato in modo random\n");
        printf("  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n");
        printf("  -graph: creazione file di dot con il grafo dell'esecuzione (forza d=1 t=1)\n");
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

    if (parse_cmd(argc, argv))
        return 1;

    /// allocazione array
    A = new int[max_dim];

    // init random
    srand((unsigned)time(NULL));

    if (graph) {
        output_graph.open("graph.dot");
        /// preparo header
        output_graph << "digraph g" << endl;
        output_graph << "{ " << endl;
        output_graph << "node [shape=plaintext]" << endl;
    }

    if (!details)
        printf("Dim_array,N_test,min_cmp,avg_cmp,max_cmp,worst_case_cmp,min_op,avg_op,max_op\n");

    // printf("Parametri: max-dim %d, d %d, t %d, verbose %d\n",max_dim,ndiv,ntests,details);

    //// inizio ciclo per calcolare ndiv dimensioni di array crescenti
    for (n = max_dim / ndiv; n <= max_dim; n += max_dim / ndiv) {
        int swap_min = -1;
        int swap_max = -1;
        long swap_avg = 0;

        int cmp_min = -1;
        int cmp_max = -1;
        long cmp_avg = 0;

        int op_min = -1;
        int op_max = -1;
        long op_avg = 0;

        //// lancio ntests volte per coprire diversi casi di input random
        for (test = 0; test < ntests; test++) {

            /// inizializzazione array: numeri random con range dimensione array
            for (i = 0; i < n; i++) {
                // A[i]= n - i;
                A[i] = rand() % (n * 10);
            }

            if (details) {
                printf("creato array di dimensione %d\n", n);
                print_array(A, n);
            }

            ct_swap = 0;
            ct_cmp = 0;

            /// algoritmo di sorting
            quick_sort(A, 0, n - 1);

            if (details) {
                printf("Output:\n");
                print_array(A, n);
            }

            //// scelta random del valore T da cercare
            int t = A[rand() % n];
            if (details)
                printf("Search value %d\n", t);

            ct_op = 0;

            int idx = -1;

            idx = bisection(A, n, t);

            if (details) {
                printf("Idx found %d\n", idx);
                if (idx >= 0)
                    printf("A[%d]=%d\n", idx, A[idx]);
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
            op_avg += ct_op;
            if (op_min < 0 || op_min > ct_op)
                op_min = ct_op;
            if (op_max < 0 || op_max < ct_op)
                op_max = ct_op;
        }

        if (!details)
            printf("%d,%d,%d,%.2f,%d,%.2f,%d,%.2f,%d\n",
                   n, ntests,
                   cmp_min, (0.0 + cmp_avg) / ntests, cmp_max, 0.0 + n * n,
                   op_min, (0.0 + op_avg) / ntests, op_max);
    }

    if (graph) {
        /// preparo footer e chiudo file
        output_graph << "}" << endl;
        output_graph.close();
        cout << " File graph.dot scritto" << endl
             << "Creare il grafo con: dot graph.dot -Tpdf -o graph.pdf" << endl;
    }

    delete[] A;

    return 0;
}
