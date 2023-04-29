#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

// compilazione: g++ lezione9-bst-rotazioni-doppie.cpp

//
// Obiettivo:
// 1) controllo di bilanciamento di un albero binario
// 2) rotazioni

// 3) sistemare rotateRight, implementare singleRotateRight
// 4) test: ricerca di una chiave (misura di quanti livelli sono esplorati)
//          node_t* find(int x) ---> return puntatore a nodo n->val==x || NULL se non esiste
// 5) test: verifica l'albero sia bilanciato (con inserimento elementi casuale)
//          for che inserisce nodi di valore casuale nell'albero
// 6) opzionale: evitare il calcolo di tutte le altezze


int ct_swap=0;
int ct_cmp=0;
int ct_op=0;  /// operazioni per la ricerca

int max_dim=0;
int ntests=1;
int ndiv=1;
int details=0;
int graph=0;


int n=0; /// dimensione dell'array

/// file di output per grafo
ofstream output_graph;
int n_operazione=0; /// contatore di operazioni per visualizzare i vari step

ofstream output_visit;
ifstream input_visit;





//////////////////////////////////////////////////
/// Definizione della struttura dati tree
//////////////////////////////////////////////////

/// struct per il nodo dell'albero
typedef struct node {
  int val;
  int h; // altezza del nodo
  struct node * L;
  struct node * R;
} node_t;



//////////////////////////////////////////////////
/// Fine Definizione della struttura dati tree
//////////////////////////////////////////////////



/// Questo e' un modo per stampare l'indirizzo node relativamente ad un altro di riferimento.
/// Permette di ottenere offset di piccola dimensione per essere facilmente visualizzati
/// Nota: il metodo non e' robusto e potrebbe avere comportamenti indesiderati su architetture diverse
/// L'alternativa corretta' e' utilizzare %p di printf: es. printf("%p\n",(void*) node);
/// con lo svantaggio di avere interi a 64 bit poco leggibili

node_t* global_ptr_ref=NULL;  /// usato per memorizzare il puntatore alla prima lista allocata

int get_address( void* node){
  if (node==NULL)
    return 0;
  return (int)((long)node-(long)global_ptr_ref);
}

/// stampa il codice del nodo per dot
void print_node_code(node_t* n){
  output_graph << "node_" << get_address(n) << "_" << n_operazione;
}

void node_print_graph(node_t *n){

  print_node_code(n);
  output_graph << "\n[label=<\n<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"4\" >\n<TR> <TD CELLPADDING=\"3\" BORDER=\"0\"  ALIGN=\"LEFT\" bgcolor=\"#f0f0f0\" PORT=\"id\">";
  output_graph << get_address(n) << "</TD> </TR><TR>\n<TD PORT=\"val\" bgcolor=\"#a0FFa0\">";
  output_graph << n->val << "</TD>\n <TD> "<< n->h << "</TD> <TD PORT=\"L\" ";
  if (n->L==NULL)
    output_graph << "bgcolor=\"#808080\"> NULL";
  else    
    output_graph << "> " << get_address(n->L);
  output_graph << "</TD>\n <TD PORT=\"R\" ";
  if (n->R==NULL)
    output_graph << "bgcolor=\"#808080\"> NULL";
  else
    output_graph << "> " << get_address(n->R);
  output_graph <<  "</TD>\n</TR></TABLE>>];\n";

  /// visualizzazione figli sullo stesso piano
  if (n->L!=NULL && n->R!=NULL){
    output_graph << "rank = same; ";
    print_node_code(n);
    output_graph <<";";
    print_node_code(n->L);
    output_graph  <<";\n";
  }

  // mostro archi uscenti
  
  if (n->L!=NULL){ /// disegno arco left
    print_node_code(n);
    output_graph  << ":L:c -> ";
    print_node_code(n->L);
    output_graph  <<":id ;\n";
  }

  if (n->R!=NULL){ /// disegno arco R
    print_node_code(n);
    output_graph << ":R:c -> ";
    print_node_code(n->R);
    output_graph <<":id ;\n";
  }
  
}

void tree_print_rec_graph(node_t* n){
  if (n!=NULL){
    node_print_graph(n);
    tree_print_rec_graph(n->L);
    tree_print_rec_graph(n->R);
  }
}

void tree_print_graph(node_t *n){
  /// stampa ricorsiva del noto
  tree_print_rec_graph(n);
  n_operazione++;

}


void node_print(node_t *n){
  if (n == NULL)
    printf("Puntatore vuoto\n");  
  else
    printf("allocato in %d [Val: %d, L: %d, R: %d]\n",
	   get_address(n),
	   n->val,
	   get_address(n->R),
	   get_address(n->L));  
}

node_t* node_new(int elem){ /// crea nuovo nodo
  node_t* t=new node_t;
  if (details){
    printf("nodo creato\n");
  }
  
  t->val=elem;
  t->L=NULL;
  t->R=NULL;
  if (details){
    printf("Imposto a NULL children\n");
  }

  return t;
}


void tree_insert_child_L(node_t *n, int elem){
  /// inserisco il nuovo nodo con contenuto elem
  /// come figlio Left del nodo n

  /// creo nodo
  n->L=node_new(elem);

}
  
void tree_insert_child_R(node_t *n, int elem){
  /// inserisco il nuovo nodo con contenuto elem
  /// come figlio Right del nodo n  
  n->R=node_new(elem);
}
  

int max_nodes=8;
int n_nodes=0;

void insert_random_rec(node_t* n){
  //// inserisce in modo random un nodo L e R e prosegue ricorsivamente
  /// limito i nodi interni totali, in modo da evitare alberi troppo grandi
  
  printf("inserisco %d\n",n_nodes);
  
  if (n_nodes++ >= max_nodes) /// limito il numero di nodi
    return;
  printf("inserisco %d\n",n_nodes);
  
  float probabilita=0.5; /// tra 0 e 1
  
  if (rand()%100<probabilita*100){ // se numero random e' minore della probabilita' -> aggiungo nodo con valore a caso
    tree_insert_child_R(n,rand()%100);
  }
  if (rand()%100<probabilita*100){ // se numero random e' minore della probabilita' -> aggiungo nodo con valore a caso
    tree_insert_child_L(n,rand()%100);
  }
  if (n->L!=NULL)
    insert_random_rec(n->L);
  if (n->R!=NULL)
    insert_random_rec(n->R);
}

int ct_visit=0;

void inOrder(node_t* n){

  if (n->L!=NULL) {
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":id:w -> ";
      print_node_code(n->L);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

    inOrder(n->L);

    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->L);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

  }

  if (details)
    printf("%d ",n->val);

  if (graph){
    node_print_graph(n);
  }
  
  if (n->R!=NULL){
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":val:s -> ";
      print_node_code(n->R);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    inOrder(n->R);
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->R);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    
  }
}

void preOrder(node_t* n){

  if (details)
    printf("%d ",n->val);

  if (graph){
    node_print_graph(n);
  }
  
  if (n->L!=NULL) {
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":id:w -> ";
      print_node_code(n->L);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

    preOrder(n->L);

    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->L);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

  }

  
  
  if (n->R!=NULL){
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":val:s -> ";
      print_node_code(n->R);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    preOrder(n->R);
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->R);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    
  }
}

void postOrder(node_t* n){

  
  if (n->L!=NULL) {
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":id:w -> ";
      print_node_code(n->L);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

    postOrder(n->L);

    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->L);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

  }

  
  
  if (n->R!=NULL){
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":val:s -> ";
      print_node_code(n->R);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    postOrder(n->R);
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->R);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    
  }

  if (details)
    printf("%d ",n->val);

  if (graph){
    node_print_graph(n);
  }

  
}


void EulerOrder(node_t* n){

    if (details)
    printf("%d ",n->val);

    output_visit << n->val << "\n";
    
  if (graph){
    node_print_graph(n);
  }

  
  if (n->L!=NULL) {
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":id:w -> ";
      print_node_code(n->L);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

    EulerOrder(n->L);

    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->L);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":val:s [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }

  }

  if (details)
    printf("%d ",n->val);
    output_visit << n->val << "\n";

  
  if (n->R!=NULL){
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n);
      output_graph  << ":val:s -> ";
      print_node_code(n->R);
      output_graph  <<":id:w [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    EulerOrder(n->R);
    if (graph){
      // scrivo arco con numero operazione di visita
      print_node_code(n->R);
      output_graph  << ":id:e -> ";
      print_node_code(n);
      output_graph  <<":id:e [ color=blue, fontcolor=blue, penwidth=3, label = \""<< ct_visit++<< "\"]\n";
    }
    
  }

  if (details)
    printf("%d ",n->val);
    output_visit << n->val << "\n";
  
}



/// crea una copia dell'albero in input, scambiando i sottoalberi L e R 
node_t* flip(node_t* n){
  node_t* n1 = node_new(n->val);

  /// chiamate ricorsive

  
  return n1;
}

// costruzione albero in base ai valori stampati dalla visita di eulero
// la funzione restituisce il puntatore alla radice dell'albero
// Es. input: 32 74 74 64 76 76 44 44 44 76 64 64 74 32 85 85 2 36 36 36 2 85 85 85 2 85 32
node_t* build_euler(node_t* nodo){

  int v;
  input_visit >> v;
  printf("letto valore %d\n",v);

  /// sottoalbero LEFT
  if (v != nodo->val){ // c'e' un sottoalbero
    node_t* nodoL = node_new(v);
    nodo->L=nodoL;
    build_euler(nodoL);
    input_visit >> v;
    printf("letto valore %d dopo la visita ricorsiva L\n",v);
  }

  /// ritorno a visitare la radice
  if (v != nodo->val){ // c'e' un errore
    printf("errore\n");
    return NULL;
  }

  /// sottoalbero RIGHT
  input_visit >> v;
  printf("letto valore %d\n",v);
  if (v != nodo->val){ // c'e' un sottoalbero
    node_t* nodoR = node_new(v);
    nodo->R=nodoR;
    build_euler(nodoR);
    input_visit >> v;
    printf("letto valore %d dopo la visita ricorsiva R\n",v);
  }
  
  /// ritorno a visitare la radice
  if (v != nodo->val){ // c'e' un errore
    printf("errore\n");
    return NULL;
  }


  return nodo;
}


node_t* search(int y,node_t* node){
  

  if (node == NULL){
    printf("Raggiunto un nodo nullo\n");
    return NULL;
  }

  int x=node->val;
  printf("Analizzo nodo con valore %d -- cerco %d\n",x,y);

  if (x==y) {
    printf("trovato il valore\n");
    return node;
  }
  if (y < x) {
    printf("Scendo a sinistra\n");
    return search(y,node->L);
  }
  if (y > x) {
    printf("Scendo a destra\n");
    return search(y,node->R);
  }

  printf("Non dovevo arrivare qui!\n");
  return NULL;
}

// restituisce il valore di altezza calcolato
// se nodo==NULL -> restituisce 0
int get_height(node_t* nodo){
  if (nodo==NULL)
    return 0;
  return nodo->h;
}

// calcolo ricorsivo
int altezza(node_t* nodo){
  if (nodo==NULL){    
    return 0;
  }
  
  int l=0,r=0;   /// valori di default se trovo foglia
  l= altezza(nodo->L);
  r= altezza(nodo->R);

  int massimo=l;
  if (r>massimo) massimo=r;
  nodo->h = 1 + massimo;
    
  return nodo->h;  
}


void  singleRotateLeft(node_t*& T){
  node_t* r = T->R;
  T->R = r->L;
  r->L = T;
  T = r;  
}

void  singleRotateRight(node_t*& T){
  /// todo
}

void doubleRotateLeft(node_t*& T){
  singleRotateRight(T->R);
  singleRotateLeft(T);
}

void rotateLeft(node_t*& T){
  printf("Rotate Left: root %d\n",T->val);
  node_t* r   = T->R;
  printf("Rotate Left: root->R %d\n",r->val);
  
  int  zag = get_height(r->L);
  int  zig = get_height(r->R);
  printf("confronto zig %d, zag %d\n",zig,zag);
  if(zig > zag)
    singleRotateLeft(T);
  else
    doubleRotateLeft(T);
 
}

void rotateRight(node_t*& T){

  /// da fare!!!
   
}

void rebalance(node_t*& T){
  printf("Rebalance: lavoro con il nodo %d\n",T->val);

  int hl = altezza(T->L); // inefficiente
  int hr = altezza(T->R); // inefficiente

  if (hr > hl + 1){
    printf("devo fare rotazione sinistra\n");
    tree_print_graph(T);
    n_operazione++;
    printf("chiamo rotateLeft\n");
    rotateLeft(T);

    tree_print_graph(T);
    n_operazione++;
  }

  if (hl > hr + 1){
    printf("devo fare rotazione destra\n");
    tree_print_graph(T);
    n_operazione++;

    rotateRight(T);

    tree_print_graph(T);
    n_operazione++;
  }
  
  
}


void bst_insert(int x,node_t*& T){
  /// x e' il nuovo valore da inserire
  /// node e' passato per riferimento
  /// creo il nodo se node e' NULL
  
  if (T == NULL){
    printf("Devo inserire il nodo %d: inserisco\n",x);
    T = node_new(x);
    return;
  }

  if (T->val == x) {
    printf("Valore gia' presente\n");
    return;
  }

  if (x < T->val){
    /// mi occupo della parte left del sottoalbero
    printf("Devo inserire il nodo %d: proseguo nel sottoalbero L\n",x);
    bst_insert(x,T->L);
    rebalance(T);
    return;
  }

  if (x > T->val){
    /// mi occupo della parte right del sottoalbero
    printf("Devo inserire il nodo %d: proseguo nel sottoalbero R\n",x);
    bst_insert(x,T->R);
    rebalance(T);
    return;
  }  
}




int bilanciato(node_t* nodo){

  if (nodo==NULL){    
    return 1;  //vero
  }

  /// carico bilanciamento dei sottoalberi (includono il calcolo delle altezze)
  int bl=bilanciato(nodo->L);
  int br=bilanciato(nodo->R);
  
  int l=0,r=0;  
  if (nodo->L != NULL) l=nodo->L->h;
  if (nodo->R != NULL) r=nodo->R->h;

  int massimo=l;
  if (r>massimo) massimo=r;
  nodo->h = 1 + massimo;
    
  return bl & br & abs(l-r)<=1;  
}




int parse_cmd(int argc, char **argv){
  /// controllo argomenti
  int ok_parse=0;
  for (int i=1;i<argc;i++){
    if (argv[i][1]=='v'){
      details=1;
      ok_parse=1;
    }
    if (argv[i][1]=='g'){
      graph=1;
      ok_parse=1;
    }
  }

  if (argc > 1 && !ok_parse) {
    printf("Usage: %s [Options]\n",argv[0]);
    printf("Options:\n");
    printf("  -verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n");
    printf("  -graph: creazione file di dot con il grafo dell'esecuzione (forza d=1 t=1)\n");
    return 1;
  }

  return 0;
}

int main(int argc, char **argv) {
  int i,test;

  if (parse_cmd(argc,argv))
    return 1;

  // init random
  srand((unsigned) time(NULL));

  if (graph){
    output_graph.open("graph.dot");
    /// preparo header
    output_graph << "digraph g"<<endl; 
    output_graph << "{ "<<endl;
    output_graph << "node [shape=none]"<<endl;
    output_graph << "rankdir=\"TB\""<<endl;;
    output_graph << "edge[tailclip=false,arrowtail=dot];"<<endl;    
  }
  
  node_t* root = NULL;
  
  bst_insert(40,root);
  global_ptr_ref=root; /// per manipolare i riferimenti relativi in memoria
  
  bst_insert(50,root);
  bst_insert(60,root);
  bst_insert(70,root);

  tree_print_graph(root);
  n_operazione++;

  //singleRotateLeft(root);
  
  
  inOrder(root);
  printf("\n");

  //node_t* result=search(8,root);

  //int a=altezza(root);
  //printf("L'albero ha altezza %d\n",a);
  
  printf("L'albero e' bilanciato? %d\n",bilanciato(root));

  tree_print_graph(root);
  n_operazione++;
  
  /*
    node_t* root1=flip(root);  
    tree_print_graph(root);
  */

  
  

  if (graph){
    /// preparo footer e chiudo file
    output_graph << "}"<<endl; 
    output_graph.close();
    cout << " File graph.dot scritto" << endl<< "Creare il grafo con: dot graph.dot -Tpdf -o graph.pdf"<<endl;
  }



  return 0;
}
