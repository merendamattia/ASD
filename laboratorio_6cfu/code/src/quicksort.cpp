/* 
    compilazione: 
        g++ quicksort.cpp ordinamento.cpp -I../include
    esecuzione:
        ./a.out 20 -g && dot graph.dot -Tpdf -o graph.pdf && open graph.pdf
        ./a.out 1000 -d 100 -t 50

    Obiettivo:
        esecuzioni (per osservare struttura ricorsiva), sia con input random che ordine decrescente
        ./a.out 16 -graph; dot graph.dot -Tpdf -o graph.pdf

        osservazione con input random con range molto limitato (es. rand() % (n/3) )
        molti pivot uguali ---> quicksort a tre vie
        ./a.out 16 -graph; dot graph.dot -Tpdf -o graph.pdf
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/ordinamento.hh"

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

void print_array_graph(int *A, int p, int r, string s, int pivot) {
    /// prepara il disegno dell'array A ed il suo contenuto dall'indice a all'indice b inclusi
    /// usa la stringa c per stampare il nome del nodo
    /// se pivot = 1 -> colora di rosso lo sfondo

    /// uso codice HTML per creare una tabella con il contenuto dell'array

    // return ;

    output_graph << s << p << "_" << r << " [label=<" << endl
                 << "<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" ";
    if (pivot)
        output_graph << "bgcolor=\"#ff8080\"";
    output_graph << "> <TR>" << endl;
    for (int j = p; j <= r; j++) {
        output_graph << "<TD>" << A[j] << "</TD>" << endl;
    }
    output_graph << "</TR> </TABLE>>];" << endl;
}

int partition(int *A, int p, int r) {

    /// copia valori delle due meta p..q e q+1..r

    int indicerandom = rand() % (r - p + 1) + p;
    swap(A[indicerandom], A[r], ct_swap);
    
    int x = A[r];

    int i = p - 1;

    for (int j = p; j < r; j++) {
        ct_cmp++;
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j], ct_swap);
        }

        if (graph) {
            output_graph << "<TR>";
            for (int k = p; k <= r; k++) {
                output_graph << "<TD";
                if (k <= i)
                    output_graph << " bgcolor=\"#e0e0e0\"";
                if (k > i && k <= j)
                    output_graph << " bgcolor=\"#a0a0a0\"";
                if (k == r)
                    output_graph << " bgcolor=\"#ff8080\"";
                output_graph << ">" << A[k] << "</TD>" << endl;
            }
            output_graph << "</TR>" << endl;
        }
    }
    swap(A[i + 1], A[r], ct_swap);

    if (graph) {
        output_graph << "<TR>";
        for (int k = p; k <= r; k++) {
            output_graph << "<TD";
            if (k <= i)
                output_graph << " bgcolor=\"#e0e0e0\"";
            if (k > i + 1)
                output_graph << " bgcolor=\"#a0a0a0\"";
            if (k == i + 1)
                output_graph << " bgcolor=\"#ff8080\"";
            output_graph << ">" << A[k] << "</TD>" << endl;
        }
        output_graph << "</TR>" << endl;
    }

    return i + 1;
}

void quick_sort(int *A, int p, int r) {

    if (p < r) {

        if (graph) {
            output_graph << "node_before" << p << "_" << r << " [label=<" << endl
                         << "<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" ";
            output_graph << "> " << endl;
        }
        int q = partition(A, p, r);

        if (graph) {
            output_graph << " </TABLE>>];" << endl;

            /// disegna arco p_r -> p_q (se array non vuoto)
            if (p <= q - 1) {
                // print_array_graph(A,p,q-1,"node_before",0);
                output_graph << "node_before" << p << "_" << r << " -> ";
                output_graph << "node_before" << p << "_" << q - 1 << endl;
            }

            /// disegna arco p_r -> q_q 1=pivot
            print_array_graph(A, q, q, "node_before", 1);
            output_graph << "node_before" << p << "_" << r << " -> ";
            output_graph << "node_before" << q << "_" << q << endl;

            /// disegna arco q_q -> q_q
            output_graph << "node_before" << q << "_" << q << " -> ";
            output_graph << "node_after" << q << "_" << q << endl;

            /// disegna arco p_r -> q+1_r
            if (q + 1 <= r) {
                // print_array_graph(A,q+1,r,"node_before",0);
                output_graph << "node_before" << p << "_" << r << " -> ";
                output_graph << "node_before" << q + 1 << "_" << r << endl;
            }

            /// per visualizzazione ben organizzata a livelli
            output_graph << "{rank = same; ";
            if (p <= q - 1)
                output_graph << "node_before" << p << "_" << q - 1 << "; ";
            output_graph << "node_before" << q << "_" << q << "; ";
            if (q + 1 <= r)
                output_graph << "node_before" << q + 1 << "_" << r << ";";
            output_graph << "}" << endl;
        }

        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);

        if (graph) {
            /// disegna arco p_q-1 -> p_r
            if (p <= q - 1) {
                print_array_graph(A, p, q - 1, "node_after", 0);
                output_graph << "node_after" << p << "_" << q - 1 << " -> ";
                output_graph << "node_after" << p << "_" << r << "\n";
            }
            print_array_graph(A, q, q, "node_after", 1);
            /// disegna arco q_q -> p_r
            output_graph << "node_after" << q << "_" << q << " -> ";
            output_graph << "node_after" << p << "_" << r << "\n";

            /// disegna arco q+1_r -> p_r
            if (q + 1 <= r) {
                print_array_graph(A, q + 1, r, "node_after", 0);
                output_graph << "node_after" << q + 1 << "_" << r << " -> ";
                output_graph << "node_after" << p << "_" << r << "\n";
            }
            /// per visualizzazione ben organizzata a livelli
            output_graph << "{rank = same; ";
            if (p <= q - 1)
                output_graph << "node_after" << p << "_" << q - 1 << "; ";
            output_graph << "node_after" << q << "_" << q << "; ";
            if (q + 1 <= r)
                output_graph << "node_after" << q + 1 << "_" << r << ";";
            output_graph << "}" << endl;
        }
    }

    if (p == r) {
        /// disegno archi nodi singoli (non pivot)
        print_array_graph(A, p, p, "node_before", 0);
        output_graph << "node_before" << p << "_" << r << " -> ";
        output_graph << "node_after" << p << "_" << r << endl;
    }
}

int main(int argc, char **argv) {
    int i, test;
    int *A;
    int *B; // buffer per visualizzazione algoritmo

    if (parse_cmd(argc, argv, stat))
        return 1;

    /// allocazione array
    A = new int[max_dim];

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
        output_graph << "{ rankdir = TB;" << endl;
        output_graph << "node [shape=plaintext]" << endl;
    }

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
                // A[i] = n - i;
                A[i] = rand() % (n*10);
                // A[i] = rand() % (n / 4);
            }

            if (details) {
                cout << "creato array di dimensione " << n << "\n";
                print_array(A, n);
            }

            ct_swap = 0;
            ct_cmp = 0;

            /// algoritmo di sorting
            if (graph)
                print_array_graph(A, 0, n - 1, "node_before", 0);

            quick_sort(A, 0, n - 1);

            if (graph)
                print_array_graph(A, 0, n - 1, "node_after", 0);

            if (details) {
                cout << "Array ordinato: " << endl;;
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

    if (graph) {
        /// preparo footer e chiudo file
        output_graph << "}" << endl;
        output_graph.close();
        cout << "File " << output_path << " scritto" << endl
             << "Creare il grafo con: dot " << output_path << " -Tpdf -o graph.pdf" << endl;
    }

    delete[] A;

    return 0;
}
