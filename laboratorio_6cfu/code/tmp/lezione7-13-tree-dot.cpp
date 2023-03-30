#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

// compilazione: g++ lezione7-13-tree-dot.c
//

// Alberi binari

// Obiettivo:
// 1) struttura dati, allocazione nodo, inserimento manuale nodi
// 2) creazione albero random

// 3) visita inorder
// 4) visita preorder, postorder

// 5) delete albero
// 6) euler tour: stampa e ricostruzione albero da lista nodi

// 7) flip albero

// 8) height - depth
// 9) isBalanced

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
int n_operazione = 0; /// contatore di operazioni per visualizzare i vari step

ofstream output_visit;
ifstream input_visit;

//////////////////////////////////////////////////
/// Definizione della struttura dati tree
//////////////////////////////////////////////////

/// struct per il nodo dell'albero
typedef struct node {
    int val;
    struct node *L;
    struct node *R;
} node_t;

//////////////////////////////////////////////////
/// Fine Definizione della struttura dati tree
//////////////////////////////////////////////////

/// Questo e' un modo per stampare l'indirizzo node relativamente ad un altro di riferimento.
/// Permette di ottenere offset di piccola dimensione per essere facilmente visualizzati
/// Nota: il metodo non e' robusto e potrebbe avere comportamenti indesiderati su architetture diverse
/// L'alternativa corretta' e' utilizzare %p di printf: es. printf("%p\n",(void*) node);
/// con lo svantaggio di avere interi a 64 bit poco leggibili

node_t *global_ptr_ref = NULL; /// usato per memorizzare il puntatore alla prima lista allocata

int get_address(void *node) {
    if (node == NULL)
        return 0;
    return (int)((long)node - (long)global_ptr_ref);
}

/// stampa il codice del nodo per dot
void print_node_code(node_t *n) {
    output_graph << "node_" << get_address(n) << "_" << n_operazione;
}

void node_print_graph(node_t *n) {

    print_node_code(n);
    output_graph << "\n[label=<\n<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"4\" >\n<TR> <TD CELLPADDING=\"3\" BORDER=\"0\"  ALIGN=\"LEFT\" bgcolor=\"#f0f0f0\" PORT=\"id\">";
    output_graph << get_address(n) << "</TD> </TR><TR>\n<TD PORT=\"val\" bgcolor=\"#a0FFa0\">";
    output_graph << n->val << "</TD>\n <TD PORT=\"L\" ";
    if (n->L == NULL)
        output_graph << "bgcolor=\"#808080\"> NULL";
    else
        output_graph << "> " << get_address(n->L);
    output_graph << "</TD>\n <TD PORT=\"R\" ";
    if (n->R == NULL)
        output_graph << "bgcolor=\"#808080\"> NULL";
    else
        output_graph << "> " << get_address(n->R);
    output_graph << "</TD>\n</TR></TABLE>>];\n";

    /// visualizzazione figli sullo stesso piano
    if (n->L != NULL && n->R != NULL) {
        output_graph << "rank = same; ";
        print_node_code(n);
        output_graph << ";";
        print_node_code(n->L);
        output_graph << ";\n";
    }

    // mostro archi uscenti

    if (n->L != NULL) { /// disegno arco left
        print_node_code(n);
        output_graph << ":L:c -> ";
        print_node_code(n->L);
        output_graph << ":id ;\n";
    }

    if (n->R != NULL) { /// disegno arco R
        print_node_code(n);
        output_graph << ":R:c -> ";
        print_node_code(n->R);
        output_graph << ":id ;\n";
    }
}

void tree_print_rec_graph(node_t *n) {
    if (n != NULL) {
        node_print_graph(n);
        tree_print_rec_graph(n->L);
        tree_print_rec_graph(n->R);
    }
}

void tree_print_graph(node_t *n) {
    /// stampa ricorsiva del nodo
    tree_print_rec_graph(n);
    n_operazione++;
}

void node_print(node_t *n) {
    if (n == NULL)
        printf("Puntatore vuoto\n");
    else
        printf("allocato in %d [Val: %d, L: %d, R: %d]\n",
               get_address(n),
               n->val,
               get_address(n->R),
               get_address(n->L));
}

node_t *node_new(int elem) { /// crea nuovo nodo
    node_t *t = new node_t;
    if (details) {
        printf("nodo creato\n");
    }

    t->val = elem;
    t->L = NULL;
    t->R = NULL;
    if (details) {
        printf("Imposto a NULL children\n");
    }

    return t;
}

void tree_insert_child_L(node_t *n, int elem) {
    /// inserisco il nuovo nodo con contenuto elem
    /// come figlio Left del nodo n

    /// creo nodo
    n->L = node_new(elem);
}

void tree_insert_child_R(node_t *n, int elem) {
    /// inserisco il nuovo nodo con contenuto elem
    /// come figlio Right del nodo n
    n->R = node_new(elem);
}

int max_nodes = 100;
int n_nodes = 0;

void insert_random_rec(node_t *n) {
    //// inserisce in modo random un nodo L e R e prosegue ricorsivamente
    /// limito i nodi interni totali, in modo da evitare alberi troppo grandi

    printf("inserisco %d\n", n_nodes);

    if (n_nodes++ >= max_nodes) /// limito il numero di nodi
        return;
    printf("inserisco %d\n", n_nodes);

    float probabilita = 1; /// tra 0 e 1

    if (rand() % 100 < probabilita * 100) { // se numero random e' minore della probabilita' -> aggiungo nodo R con valore a caso
        tree_insert_child_R(n, rand() % 100);
    }
    if (rand() % 100 < probabilita * 100) { // se numero random e' minore della probabilita' -> aggiungo nodo L con valore a caso
        tree_insert_child_L(n, rand() % 100);
    }
    if (n->L != NULL)
        insert_random_rec(n->L);
    if (n->R != NULL)
        insert_random_rec(n->R);
}

int ct_visit = 0;

void inOrder(node_t *n) {

    if (n->L != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":id:w -> ";
            print_node_code(n->L);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }

        inOrder(n->L);

        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->L);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }

    if (details)
        printf("%d ", n->val);

    if (graph) {
        node_print_graph(n);
    }

    if (n->R != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":val:s -> ";
            print_node_code(n->R);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
        inOrder(n->R);
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->R);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }
}

void preOrder(node_t *n) {

    if (details)
        printf("%d ", n->val);

    if (graph) {
        node_print_graph(n);
    }

    if (n->L != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":id:w -> ";
            print_node_code(n->L);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }

        preOrder(n->L);

        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->L);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }

    if (n->R != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":val:s -> ";
            print_node_code(n->R);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
        preOrder(n->R);
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->R);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }
}

void postOrder(node_t *n) {

    if (n->L != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":id:w -> ";
            print_node_code(n->L);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }

        postOrder(n->L);

        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->L);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }

    if (n->R != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":val:s -> ";
            print_node_code(n->R);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
        postOrder(n->R);
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->R);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }

    if (details)
        printf("%d ", n->val);

    if (graph) {
        node_print_graph(n);
    }
}

void EulerOrder(node_t *n) {

    if (details)
        printf("%d ", n->val);

    output_visit << n->val << "\n";

    if (graph) {
        node_print_graph(n);
    }

    if (n->L != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":id:w -> ";
            print_node_code(n->L);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }

        EulerOrder(n->L);

        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->L);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }

    if (details)
        printf("%d ", n->val);
    output_visit << n->val << "\n";

    if (n->R != NULL) {
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n);
            output_graph << ":val:s -> ";
            print_node_code(n->R);
            output_graph << ":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
        EulerOrder(n->R);
        if (graph) {
            // scrivo arco con numero operazione di visita
            print_node_code(n->R);
            output_graph << ":id:e -> ";
            print_node_code(n);
            output_graph << ":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \"" << ct_visit++ << "\"]\n";
        }
    }

    if (details)
        printf("%d ", n->val);
    output_visit << n->val << "\n";
}

/// crea una copia dell'albero in input, scambiando i sottoalberi L e R
node_t *flip(node_t *n) {
    node_t *n1 = node_new(n->val);

    /// chiamate ricorsive

    return n1;
}

// costruzione albero in base ai valori stampati dalla visita di eulero
// la funzione restituisce il puntatore alla radice dell'albero
// Es. input: 32 74 74 64 76 76 44 44 44 76 64 64 74 32 85 85 2 36 36 36 2 85 85 85 2 85 32
node_t *build_euler() {

    return NULL;
}

int parse_cmd(int argc, char **argv) {
    /// controllo argomenti
    int ok_parse = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][1] == 'v') {
            details = 1;
            ok_parse = 1;
        }
        if (argv[i][1] == 'g') {
            graph = 1;
            ok_parse = 1;
        }
    }

    if (argc > 1 && !ok_parse) {
        printf("Usage: %s [Options]\n", argv[0]);
        printf("Options:\n");
        printf("  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n");
        printf("  -graph: creazione file di dot con il grafo dell'esecuzione (forza d=1 t=1)\n");
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    int i, test;

    if (parse_cmd(argc, argv))
        return 1;

    // init random
    srand((unsigned)time(NULL));

    if (graph) {
        output_graph.open("graph.dot");
        /// preparo header
        output_graph << "digraph g" << endl;
        output_graph << "{ " << endl;
        output_graph << "node [shape=none]" << endl;
        output_graph << "rankdir=\"TB\"" << endl;
        ;
        output_graph << "edge[tailclip=false,arrowtail=dot];" << endl;
    }

    node_t *root = node_new(5);
    global_ptr_ref = root;

    // tree_print_graph(root);
    // tree_insert_child_L(root, 7);
    // tree_print_graph(root);
    // tree_insert_child_L(root->L, 8);
    // tree_print_graph(root);
    // tree_insert_child_L(root->L->L, 1);
    // tree_print_graph(root);
    // tree_insert_child_L(root->L->L->L, 10);
    // tree_print_graph(root);

    // creo albero random
    insert_random_rec(root);

    // ct_visit = 0;
    // inOrder(root);
    // n_operazione++;
    // printf("\n");

    // ct_visit = 0;
    // preOrder(root);
    // n_operazione++;
    // printf("\n");

    // ct_visit = 0;
    // postOrder(root);
    // n_operazione++;
    // printf("\n");

    // stampa visita di eulero
    // output_visit.open("visit.txt");
    // ct_visit = 0;
    // EulerOrder(root);
    // n_operazione++;
    // output_visit.close();
    // printf("\n");

    // stampa albero
    if (graph)
        tree_print_graph(root);
    n_operazione++;

    /* scheletro per la costruzione dell'albero a partire dalla visita di eulero
    input_visit.open("visit.txt");
    node_t* root=build_euler();
    global_ptr_ref=root;
    input_visit.close();
    tree_print_graph(root);
    */

    /*
      node_t* root1=flip(root);
      tree_print_graph(root);
    */

    if (graph) {
        /// preparo footer e chiudo file
        output_graph << "}" << endl;
        output_graph.close();
        cout << " File graph.dot scritto" << endl
             << "Creare il grafo con: dot graph.dot -Tpdf -o graph.pdf" << endl;
    }

    return 0;
}
