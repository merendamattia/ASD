#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

// compilazione: g++ lezione4-8-quicksort3-dot.c
//
// Obiettivo:

// osservazione con input random con range molto limitato (es. rand() % (n/3) )
// quicksort a tre vie
/// https://en.wikipedia.org/wiki/Dutch_national_flag_problem

// ./a.out 16 -graph; dot graph.dot -Tpdf -o graph.pdf

// confrontare il numero di swap e confronti usando 3 vie o partition semplice

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

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    /// aggiorno contatore globale di swap
    ct_swap++;
}

struct my_pair {
    int x, y;
};

my_pair partition3(int *A, int p, int r) {
    /// la funzione implementa il problema della bandiera olandese (Dutch Flag problem)
    /// https://en.wikipedia.org/wiki/Dutch_national_flag_problem
    /// identifica
    /// p..i-1 valori minori del pivot
    /// i..j-1 valori uguali al pivot
    /// j..k valori non ancora elaborati
    /// k+1..r valori maggiori del pivot

    int x = A[r];
    int i = p;
    int j = p;
    int k = r;

    /// situazione iniziale
    if (graph) {
        output_graph << "<TR>";
        for (int t = p; t <= r; t++) {
            output_graph << "<TD";
            if (t < k)
                output_graph << " bgcolor=\"#ffffff\""; /// non ancora controllati
            if (t == k)
                output_graph << " bgcolor=\"#ff8080\""; /// pivot
            output_graph << ">" << A[t] << "</TD>" << endl;
        }
        output_graph << "</TR>" << endl;
    }

    while (j <= k) {
        if (A[j] < x) {
            swap(A[i], A[j]);
            i++;
            j++;
        } else if (A[j] > x) {
            swap(A[j], A[k]);
            k--;
        } else
            j++;

        if (graph) {
            output_graph << "<TR>";
            for (int t = p; t <= r; t++) {
                output_graph << "<TD";
                if (t < i)
                    output_graph << " bgcolor=\"#e0e0e0\""; /// minori pivot
                if (t >= i && t < j)
                    output_graph << " bgcolor=\"#ff8080\""; /// uguali pivot
                if (t > j && t <= k)
                    output_graph << " bgcolor=\"#ffffff\""; /// non ancora controllati
                if (t > k)
                    output_graph << " bgcolor=\"#a0a0a0\""; /// maggiori pivot
                output_graph << ">" << A[t] << "</TD>" << endl;
            }
            output_graph << "</TR>" << endl;
        }
    }

    /// creo il paio di indici da restituire
    my_pair p2;
    p2.x = i;
    p2.y = k;
    return p2;
}

void quick_sort(int *A, int p, int r) {

    printf("hi: %d %d\n", p, r);
    if (p < r) {

        if (graph) {
            output_graph << "node_before" << p << "_" << r << " [label=<" << endl
                         << "<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" ";
            output_graph << "> " << endl;
        }
        my_pair p2 = partition3(A, p, r);
        /// p..p2.x-1 valori piu' piccoli del pivot
        /// p2-y+1..r valori piu' grandi del pivot

        printf("%d %d %d %d\n", p, p2.x, p2.y, r);

        /// p2.x primo valore uguale al pivot
        //  p2.y ultimo valore uguale al pivot
        if (graph) {
            output_graph << " </TABLE>>];" << endl;

            /// disegna arco p_r -> p_p2.x-1 (se array non vuoto)
            if (p <= p2.x - 1) {
                // print_array_graph(A,p,q-1,"node_before",0);
                output_graph << "node_before" << p << "_" << r << " -> ";
                output_graph << "node_before" << p << "_" << p2.x - 1 << endl;
            }

            /// disegna arco p_r -> p2.x_p2.y 1=pivot
            if (p2.x <= p2.y) {
                print_array_graph(A, p2.x, p2.y, "node_before", 1);
                if (p != p2.x || r != p2.y) {
                    output_graph << "node_before" << p << "_" << r << " -> ";
                    output_graph << "node_before" << p2.x << "_" << p2.y << endl;
                }

                /// disegna arco blocco costante = pivot
                output_graph << "node_before" << p2.x << "_" << p2.y << " -> ";
                output_graph << "node_after" << p2.x << "_" << p2.y << endl;
            }

            /// disegna arco p_r -> p2.y+1_r
            if (p2.y + 1 <= r) {
                // print_array_graph(A,q+1,r,"node_before",0);
                output_graph << "node_before" << p << "_" << r << " -> ";
                output_graph << "node_before" << p2.y + 1 << "_" << r << endl;
            }

            /// per visualizzazione ben organizzata a livelli
            output_graph << "{rank = same; ";
            if (p <= p2.x - 1)
                output_graph << "node_before" << p << "_" << p2.x - 1 << "; ";
            output_graph << "node_before" << p2.x << "_" << p2.y << "; ";
            if (p2.y + 1 <= r)
                output_graph << "node_before" << p2.y + 1 << "_" << r << ";";
            output_graph << "}" << endl;
        }

        quick_sort(A, p, p2.x - 1);
        quick_sort(A, p2.y + 1, r);

        if (graph) {
            /// disegna arco p_p2.y-1 -> p_r
            if (p <= p2.x - 1) {
                print_array_graph(A, p, p2.x - 1, "node_after", 0);
                output_graph << "node_after" << p << "_" << p2.x - 1 << " -> ";
                output_graph << "node_after" << p << "_" << r << "\n";
            }

            if (p2.x <= p2.y)
                if (p != p2.x || r != p2.y) {
                    print_array_graph(A, p2.x, p2.y, "node_after", 0);
                    /// disegna arco p2.x_p2.y -> p_r
                    output_graph << "node_after" << p2.x << "_" << p2.y << " -> ";
                    output_graph << "node_after" << p << "_" << r << "\n";
                }

            /// disegna arco p2.y+1_r -> p_r
            if (p2.y + 1 <= r) {
                print_array_graph(A, p2.y + 1, r, "node_after", 0);
                output_graph << "node_after" << p2.y + 1 << "_" << r << " -> ";
                output_graph << "node_after" << p << "_" << r << "\n";
            }
            /// per visualizzazione ben organizzata a livelli
            output_graph << "{rank = same; ";
            if (p <= p2.x - 1)
                output_graph << "node_after" << p << "_" << p2.x - 1 << "; ";
            output_graph << "node_after" << p2.x << "_" << p2.y << "; ";
            if (p2.y + 1 <= r)
                output_graph << "node_after" << p2.y + 1 << "_" << r << ";";
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
    int *B; /// buffer per visualizzazione algoritmo

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
        output_graph << "{ rankdir = TB;" << endl;
        output_graph << "node [shape=plaintext]" << endl;
    }

    if (ndiv > 1)
        printf("Dim_array,N_test,min_swap,avg_swap,max_swap,worst_case_swap,min_cmp,avg_cmp,max_cmp,worst_case_cmp,avg_case_cmp\n");

    // printf("Parametri: max-dim %d, d %d, t %d, verbose %d\n",max_dim,ndiv,ntests,details);

    //// inizio ciclo per calcolare ndiv dimensioni di array crescenti
    for (n = max_dim / ndiv; n <= max_dim; n += max_dim / ndiv) {

        //// lancio ntests volte per coprire diversi casi di input random
        for (test = 0; test < ntests; test++) {

            /// inizializzazione array: numeri random con range dimensione array
            for (i = 0; i < n; i++) {
                A[i] = n - i;
                // A[i]= rand() % (n*10);
                // A[i] = rand() % (n*5);
            }

            printf("creato array di dimensione %d\n", n);
            print_array(A, n);

            ct_swap = 0;
            ct_cmp = 0;

            /// algoritmo di sorting
            if (graph)
                print_array_graph(A, 0, n - 1, "node_before", 0);

            quick_sort(A, 0, n - 1);

            if (graph)
                print_array_graph(A, 0, n - 1, "node_after", 0);

        }

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
