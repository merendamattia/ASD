#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

// compilazione: g++ -xc++ lezione5-2-counting_sort-dot.c
//
// Obiettivo:
// 1) analisi esecuzione ordine crescente
// ./a.out 10 -graph

// 2) analisi esecuzione ordine decrescente
// ./a.out 10 -graph

// 3) analisi esecuzione tutti numeri uguali
// ./a.out 10 -graph

// 4) analisi esecuzione random
// ./a.out 10 -graph

/// intero massimo usato
#define MAX_COUNT 1000000

int ct_swap = 0;
int ct_cmp = 0;

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

void print_array_graph(int *A, int a, int n, string c, int mark) {
    /// prepara il disegno dell'array A ed il suo contenuto (n celle)
    /// a e' il codice del nodo e c la stringa
    /// se mark>=0, colora lo sfondo della cella di indice mark

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
        if (j == mark)
            output_graph << " bgcolor=\"#ff8080\""; /// valore evidenziato
        else if (A[j] < 0)
            output_graph << " bgcolor=\"#808080\""; /// valore non inizializzato
        output_graph << ">" << A[j] << "</TD>" << endl;
    }
    output_graph << "</TR>" << endl;
    output_graph << "</TABLE> " << endl;

    output_graph << ">];" << endl;
}

void counting_sort(int *A, int *B, int *C, int n, int k) {
    /// A: array in input 0..n-1
    /// B: array in output 0..n-1
    /// C: array per conteggi 0..k
    /// n: elementi da ordinare
    /// k: valore massimo contenuto in A

    for (int i = 0; i <= k; i++) /// reset array conteggi
        C[i] = 0;

    for (int j = 0; j < n; j++) { /// conteggio istogramma
        C[A[j]]++;
        if (graph) {
            if (j + 1 < n) {
                output_graph << "nodeA_conteggio_" << j << " -> ";
                output_graph << "nodeA_conteggio_" << j + 1 << endl;
                output_graph << "nodeC_conteggio_" << j << " -> ";
                output_graph << "nodeC_conteggio_" << j + 1 << endl;
            } else { /// preparo per fase successiva
                output_graph << "nodeC_conteggio_" << j << " -> ";
                output_graph << "nodeC_accumulo_" << 1 << endl;
            }

            output_graph << "{rank = same; ";
            output_graph << "nodeC_conteggio_" << j << "; ";
            output_graph << "nodeA_conteggio_" << j << "; ";
            output_graph << "}" << endl;
            print_array_graph(A, j, n, "nodeA_conteggio_", j);
            print_array_graph(C, j, k + 1, "nodeC_conteggio_", A[j]);
        }
    }

    if (details) {
        printf("array conteggi\n");
        print_array(C, k + 1);
    }

    for (int i = 1; i <= k; i++) { /// C[i] contiene il numero di elementi <= i
        C[i] += C[i - 1];

        if (i < k) {
            output_graph << "nodeC_accumulo_" << i << " -> ";
            output_graph << "nodeC_accumulo_" << i + 1 << endl;
        } else { /// preparo per fase successiva
            output_graph << "nodeC_accumulo_" << i << " -> ";
            output_graph << "nodeA_sort_" << n - 1 << endl;
            output_graph << "nodeC_accumulo_" << i << " -> ";
            output_graph << "nodeC_sort_" << n - 1 << endl;
            output_graph << "nodeC_accumulo_" << i << " -> ";
            output_graph << "nodeB_sort_" << n - 1 << endl;
        }
        print_array_graph(C, i, k + 1, "nodeC_accumulo_", i);
    }

    if (details) {
        printf("array con conteggi accumulati\n");
        print_array(C, k + 1);
    }

    for (int j = n - 1; j >= 0; j--) { /// per ogni elemento originale in A ->
                                       /// mi chiedo nel conteggio C quanti sono gli elementi minori o uguali:
                                       /// questo corrisponde alla posizione dell'elemento in B
        int v = A[j];
        B[C[v] - 1] = v;

        if (j > 0) {
            output_graph << "nodeA_sort_" << j << " -> ";
            output_graph << "nodeA_sort_" << j - 1 << endl;
            output_graph << "nodeC_sort_" << j << " -> ";
            output_graph << "nodeC_sort_" << j - 1 << endl;
            output_graph << "nodeB_sort_" << j << " -> ";
            output_graph << "nodeB_sort_" << j - 1 << endl;
        }

        output_graph << "{rank = same; ";
        output_graph << "nodeA_sort_" << j << "; ";
        output_graph << "nodeC_sort_" << j << "; ";
        output_graph << "nodeB_sort_" << j << "; ";
        output_graph << "}" << endl;
        print_array_graph(A, j, n, "nodeA_sort_", j);
        print_array_graph(C, j, k + 1, "nodeC_sort_", A[j]);
        print_array_graph(B, j, n, "nodeB_sort_", C[A[j]] - 1);

        C[A[j]] = C[A[j]] - 1;
    }

    if (details) {
        printf("array con conteggi accumulati dopo il decremento\n");
        print_array(C, k + 1);
    }
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
    int *B;
    int *C;
    int k; /// valore massimo nell'array di input

    if (parse_cmd(argc, argv))
        return 1;

    /// allocazione array
    A = new int[max_dim];
    B = new int[max_dim];
    C = new int[MAX_COUNT]; /// alloco l'array per i conteggi

    // init random
    srand((unsigned)time(NULL));

    if (graph) {
        output_graph.open("graph.dot");
        /// preparo header
        output_graph << "digraph g" << endl;
        output_graph << "{ " << endl;
        output_graph << "node [shape=plaintext]" << endl;
    }

    if (ndiv > 1)
        printf("Dim_array,N_test,min_op,avg_op,max_op,avg_case_op\n");

    // printf("Parametri: max-dim %d, d %d, t %d, verbose %d\n",max_dim,ndiv,ntests,details);

    //// inizio ciclo per calcolare ndiv dimensioni di array crescenti
    for (n = max_dim / ndiv; n <= max_dim; n += max_dim / ndiv) {
        int op_min = -1;
        int op_max = -1;
        long op_avg = 0;

        //// lancio ntests volte per coprire diversi casi di input random
        for (test = 0; test < ntests; test++) {

            /// inizializzazione array: numeri random con range dimensione array
            k = 0;

            for (i = 0; i < n; i++) {
                // A[i]= 4;
                // A[i] = n - i - 1;
                A[i]= rand() % (n/3);

                B[i] = -1; // inizializzazione

                if (k < A[i])
                    k = A[i]; /// memorizzo il massimo in k
            }

            /// controllo se il massimo valore e' troppo grande
            if (k >= MAX_COUNT) {
                printf("interno in array troppo grande\n");
                return -1;
            }

            if (details) {
                printf("creato array di dimensione %d\n", n);
                print_array(A, n);
            }

            /// algoritmo di sorting
            counting_sort(A, B, C, n, k);

            if (details) {
                printf("array ordinato\n");
                print_array(B, n);
            }
        }

        if (ndiv > 1)
            printf("%d,%d,%d,%.1f,%d,%.1f\n",
                   n, ntests,
                   op_min, (0.0 + op_avg) / ntests, op_max, .0 + n + k);

    } /// termine del loop che lavora con array di dimensione n

    if (graph) {
        /// preparo footer e chiudo file
        output_graph << "}" << endl;
        output_graph.close();
        cout << " File graph.dot scritto" << endl
             << "Creare il grafo con: dot graph.dot -Tpdf -o graph.pdf" << endl;
    }

    delete[] A;
    delete[] B;
    delete[] C; /// dealloco l'array di supporto per i conteggi (dipende da k = massimo nell'array in uso)

    return 0;
}
