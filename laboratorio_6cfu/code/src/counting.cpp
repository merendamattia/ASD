/* 
    compilazione: 
        g++ counting.cpp ordinamento.cpp -I../include
    esecuzione:
        ./a.out 20 -g && dot graph.dot -Tpdf -o graph.pdf && open graph.pdf

    Obiettivo:
        1) analisi esecuzione ordine crescente
        ./a.out 10 -graph

        2) analisi esecuzione ordine decrescente
        ./a.out 10 -graph

        3) analisi esecuzione tutti numeri uguali
        ./a.out 10 -graph

        4) analisi esecuzione random
        ./a.out 10 -graph
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/ordinamento.hh"

#define MAX_COUNT 1000000

using namespace std;

Stat stat; // Per le statistiche
int& ct_swap = stat.ct_swap;
int& ct_cmp = stat.ct_cmp;
int& ct_read = stat.ct_read;
int& n = stat.n;
int& max_dim = stat.max_dim;
int& ntests = stat.ntests;
int& ndiv = stat.ndiv;
bool& details = stat.details;
bool& graph = stat.graph;
bool& comparison = stat.comparison;
string& output_path = stat.output_path;
ofstream& output_graph = stat.output_graph;

void print_array_graph(int *A, int a, int n, string c, int mark) {
    // prepara il disegno dell'array A ed il suo contenuto (n celle)
    // a e' il codice del nodo e c la stringa
    // se mark>=0, colora lo sfondo della cella di indice mark

    // return ;

    output_graph << c << a << " [label=<" << endl;

    // tabella con contenuto array
    output_graph << "<TABLE BORDER=\"0\" CELLBORDER=\"0\" CELLSPACING=\"0\" > " << endl;
    // indici
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
            output_graph << " bgcolor=\"#ff8080\""; // valore evidenziato
        else if (A[j] < 0)
            output_graph << " bgcolor=\"#808080\""; // valore non inizializzato
        output_graph << ">" << A[j] << "</TD>" << endl;
    }
    output_graph << "</TR>" << endl;
    output_graph << "</TABLE> " << endl;

    output_graph << ">];" << endl;
}

void counting_sort(int *A, int *B, int *C, int n, int k) {
    // A: array in input 0..n-1
    // B: array in output 0..n-1
    // C: array per conteggi 0..k
    // n: elementi da ordinare
    // k: valore massimo contenuto in A

    for (int i = 0; i <= k; i++) // reset array conteggi
        C[i] = 0;

    for (int j = 0; j < n; j++) { // conteggio istogramma
        C[A[j]]++;
        if (graph) {
            if (j + 1 < n) {
                output_graph << "nodeA_conteggio_" << j << " -> ";
                output_graph << "nodeA_conteggio_" << j + 1 << endl;
                output_graph << "nodeC_conteggio_" << j << " -> ";
                output_graph << "nodeC_conteggio_" << j + 1 << endl;
            } else { // preparo per fase successiva
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

    for (int i = 1; i <= k; i++) { // C[i] contiene il numero di elementi <= i
        C[i] += C[i - 1];

        if (i < k) {
            output_graph << "nodeC_accumulo_" << i << " -> ";
            output_graph << "nodeC_accumulo_" << i + 1 << endl;
        } else { // preparo per fase successiva
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

    for (int j = n - 1; j >= 0; j--) { 
        /* 
            per ogni elemento originale in A ->
            mi chiedo nel conteggio C quanti sono gli elementi minori o uguali:
            questo corrisponde alla posizione dell'elemento in B 
        */
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

int main(int argc, char **argv) {
    int i, test;
    int *A;
    int *B;
    int *C;
    int k; // valore massimo nell'array di input

    if (parse_cmd(argc, argv, stat))
        return 1;

    // allocazione array
    A = new int[max_dim];
    B = new int[max_dim];
    C = new int[MAX_COUNT]; // alloco l'array per i conteggi

    // init random
    srand((unsigned)time(NULL));

    if (graph) {
        output_graph.open(output_path);

        if (!output_graph.is_open()) {
            cerr << "Impossibile aprire il file di output" << endl;
            cerr << "Path: " << output_path << endl;
            return 1;
        }
        // preparo header
        output_graph << "digraph g" << endl;
        output_graph << "{ " << endl;
        output_graph << "node [shape=plaintext]" << endl;
    }

    if (ndiv > 1)
        printf("Dim_array,N_test,min_op,avg_op,max_op,avg_case_op\n");

    // printf("Parametri: max-dim %d, d %d, t %d, verbose %d\n",max_dim,ndiv,ntests,details);

    // inizio ciclo per calcolare ndiv dimensioni di array crescenti
    for (n = max_dim / ndiv; n <= max_dim; n += max_dim / ndiv) {
        int op_min = -1;
        int op_max = -1;
        long op_avg = 0;

        // lancio ntests volte per coprire diversi casi di input random
        for (test = 0; test < ntests; test++) {

            // inizializzazione array: numeri random con range dimensione array
            k = 0;

            for (i = 0; i < n; i++) {
                A[i]= 4;
                // A[i] = n - i - 1;
                // A[i]= rand() % (n/3);
                // A[i]= rand() % (n);

                B[i] = -1; // inizializzazione

                if (k < A[i])
                    k = A[i]; // memorizzo il massimo in k
            }

            // controllo se il massimo valore e' troppo grande
            if (k >= MAX_COUNT) {
                printf("interno in array troppo grande\n");
                return -1;
            }

            if (details) {
                printf("creato array di dimensione %d\n", n);
                print_array(A, n);
            }

            // algoritmo di sorting
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

    } // termine del loop che lavora con array di dimensione n

    if (graph) {
        /// preparo footer e chiudo file
        output_graph << "}" << endl;
        output_graph.close();
        cout << "File " << output_path << " scritto" << endl
             << "Creare il grafo con: dot " << output_path << " -Tpdf -o graph.pdf" << endl;
    }

    delete[] A;
    delete[] B;
    delete[] C; // dealloco l'array di supporto per i conteggi (dipende da k = massimo nell'array in uso)

    return 0;
}
