#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

// compilazione: g++ lezione17-grafi-bfs.cpp
//
// Obiettivo:
// 1) visita in ampiezza (BFS)

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

int ct_visit=0; // contatore durante visita 




//////////////////////////////////////////////////
/// Definizione della struttura dati lista
//////////////////////////////////////////////////

/// struct per il nodo della lista
typedef struct node {
    int val;
    struct node * next;
} node_t;


/// struct per la lista
/// struct per la lista
typedef struct list {
  node *head;
  node* tail; 
} list_t;

//////////////////////////////////////////////////
/// Fine Definizione della struttura dati lista
//////////////////////////////////////////////////


typedef struct list my_queue;


//////////////////////////////////////////////////
/// Definizione della struttura dati grafo
//////////////////////////////////////////////////

int* V; // elenco dei nodi del grafo
int* V_visitato; // nodo visitato?
int* V_in_coda; // nodo inserito in coda?
int* V_genitore; // eventuale "causa" di inserimento nella coda -> usato per disegnare l'ordine di visita del grafo

//list_t* E;  /// array con le liste di adiacenza per ogni nodo
list_t** E;  /// array di puntatori a le liste di adiacenza per ogni nodo
int n_nodi;


//////////////////////////////////////////////////
/// Fine Definizione della struttura dati grafo
//////////////////////////////////////////////////


/// Questo e' un modo per stampare l'indirizzo node relativamente ad un altro di riferimento.
/// Permette di ottenere offset di piccola dimensione per essere facilmente visualizzati
/// Nota: il metodo non e' robusto e potrebbe avere comportamenti indesiderati su architetture diverse
/// L'alternativa corretta' e' utilizzare %p di printf: es. printf("%p\n",(void*) node);
/// con lo svantaggio di avere interi a 64 bit poco leggibili

list_t* global_ptr_ref=NULL;  /// usato per memorizzare il puntatore alla prima lista allocata

int get_address( void* node){
  return (int)((long)node-(long)global_ptr_ref);
}

void node_print(int n){

  output_graph << "node_" << n << "_" << n_operazione <<  endl;
  output_graph << "[ shape = oval; ";
  if (V_visitato[n])
    output_graph << "fillcolor = red; style=filled; ";
  output_graph << "label = " << "\"Idx: " << n << ", val: " << V[n] << "\" ];\n";

  node_t* elem=E[n]->head;
  while (elem!=NULL){ /// disegno arco
    output_graph << "node_" << n << "_" << n_operazione << " -> ";
    output_graph << "node_" << elem->val << "_" << n_operazione <<" [  color=gray ]\n";
    elem=elem->next;
  }
  
}


void graph_print(){
  for (int i=0;i<n_nodi;i++)
    node_print(i);
  n_operazione++;
}


void list_print(list_t *l){
  printf("Stampa lista\n");
  
  if (l->head == NULL){
    printf("Lista vuota\n");
  }
  else{
    node_t* current = l->head;

    while (current != NULL) {
      if (!details)
      printf("%d, ", current->val);
      else{ /// stampa completa 
	if (current->next==NULL)
	printf("allocato in %d [Val: %d, Next: NULL]\n",
	       get_address(current),
	       current->val);
	  else
	printf("allocato in %d [Val: %d, Next: %d]\n",
	       get_address(current),
	       current->val,
	       get_address(current->next)
	       );
      }
      current = current->next;
    }
    printf("\n");
  }
  
}



list_t * list_new(void){
  list_t* l=new list;
  if (details){
    printf("Lista creata\n");
  }
  
  l->head=NULL;   
  l->tail=NULL;   
  if (details){
    printf("Imposto a NULL head\n");
    printf("Imposto a NULL tail\n");
  }

  return l;
}


void list_insert_front(list_t *l, int elem){
  /// inserisce un elemento all'inizio della lista
  node_t* new_node = new node_t;
  new_node->next=NULL;
  
  //if (graph) print_status(l,new_node,"INS FRONT: nuovo nodo");
  
  new_node->val=elem;

  //if (graph) print_status(l,new_node,"INS FRONT: assegno valore");
  
  new_node->next=l->head;

  //if (graph) print_status(l,new_node,"INS FRONT: next agganciato a lista");

  l->head = new_node;

  if (l->tail == NULL){ /// lista era vuota -> aggiorno tail con il nuovo e primo elemento
    l->tail = new_node;
  }
  
}


void list_delete_front(list_t *l){
  /// elimina il primo elemento della lista
  node_t* node = l->head; // il nodo da eliminare

  if (node==NULL)  // lista vuota
    return;

  l->head=node->next;
    
  //if (graph) print_status(l,node,"DEL FRONT: aggancio lista a nodo successivo");

  node->next=NULL;

  //if (graph) print_status(l,node,"DEL FRONT: sgancio puntatore da nodo da cancellare");

  if (l->head == NULL){ /// lista diventa vuota -> anche tail ora punta a NULL
    l->tail = NULL;
  }

  delete node;


}


void list_insert_tail(list_t *l, int elem){
  /// inserisce un elemento alla fine della lista
  /// uso tail per accedere all'ultimo elemento!
  
  node_t* new_node = new node_t;
  new_node->next=NULL;    
  new_node->val=elem;

  node_t* last_node = l->tail;

  if (last_node==NULL){ // lista vuota -> aggiungo
    l->head=new_node;
    l->tail=new_node;
  }
  else{
    last_node->next=new_node;
    l->tail=new_node;
  }
      
}




////////// operazioni queue

my_queue* queue_new(){
  return list_new();
}

int queue_is_empty(my_queue* s){
  return s->head == NULL;
}

int queue_front(my_queue* s){
  if (s->head!=NULL)
    return s->head->val;
  printf("ERRORE: stack vuoto!\n");
  return -1;
}

int queue_dequeue(my_queue* s){
  if (s->head!=NULL){
    int v=s->head->val;
    list_delete_front((list_t*)s);
    return v;
  }
  printf("ERRORE: queue vuota!\n");
  return -1;
}

void queue_enqueue(my_queue* s, int v){
  list_insert_tail((list_t*)s,v);
}

void queue_print(my_queue* s){
  list_print((list_t*)s);
}




void print_array(int* A, int dim){
  for (int j=0; j<dim; j++) {
    printf("%d ",A[j]);
  }
  printf("\n");
}

void print_array_graph(int* A, int n, string c, int a, int l,int m, int r){
  /// prepara il disegno dell'array A ed il suo contenuto (n celle)
  /// a e' il codice del nodo e c la stringa
  /// l,m,r i tre indici della bisezione

  //return ;
  
  output_graph << c << a << " [label=<"<<endl;

  /// tabella con contenuto array
  output_graph <<"<TABLE BORDER=\"0\" CELLBORDER=\"0\" CELLSPACING=\"0\" > "<<endl;
  /// indici
  output_graph <<"<TR  >";
  for (int j=0; j<n; j++) {
    output_graph << "<TD ";
    output_graph <<  ">" << j << "</TD>"<<endl;
  }
  output_graph << "</TR>"<<endl;
  output_graph <<"<TR>";
  //contenuto
  for (int j=0; j<n; j++) {
    output_graph << "<TD BORDER=\"1\"";
    if (j==m) output_graph << " bgcolor=\"#00a000\"";  /// valore testato
    else
      if (j>=l && j<=r ) output_graph << " bgcolor=\"#80ff80\""; /// range di competenza
    output_graph <<  ">" << A[j] << "</TD>"<<endl;
  }
  output_graph << "</TR>"<<endl;
  output_graph << "</TABLE> "<<endl;
  
  output_graph << ">];"<<endl;
	  
}


void DFS(int n){

  //graph_print();

  if (details)
    printf("DFS: lavoro sul nodo %d (visitato %d)\n",n,V_visitato[n]);
  
  if (V_visitato[n])
    return;
  
  V_visitato[n]=1;   // prima volta che incontro questo nodo

  if (details)
    printf("Visito il nodo %d (val %d)\n",n,V[n]);

  /// esploro la lista di adiacenza
  node_t* elem=E[n]->head;
  while (elem!=NULL){ /// elenco tutti i nodi nella lista

    /// espando arco  n --> elem->val
    /// quindi DFS(elem->val)
    output_graph << "dfs_"<< n << " -> dfs_"<< elem->val;
    if (V_visitato[elem->val])
      output_graph << "[color=gray, label = \""<< ct_visit++<< "\"]";
    else
      output_graph << "[color=red, penwidth=5, label = \""<< ct_visit++<< "\"]";
    output_graph  <<endl;
    
    DFS(elem->val);

    
    elem=elem->next;
  }
  
}


void BFS(int n){

  graph_print();
  
  my_queue* q = queue_new();

  //V_visitato[i]=0

  printf("BFS parto da nodo %d (visitato %d)\n",n,V_visitato[n]);
  
  /// accodo il nodo di partenza
  queue_enqueue(q,n);
  V_in_coda[n]=1;
  
  /// ciclo (se coda non vuota):
  while ( !queue_is_empty(q) ){

    queue_print(q);
    
  /// 1) estraggo un nodo dalla coda
    int corrente = queue_dequeue(q);
    if (V_visitato[corrente]==0){
      V_visitato[corrente]=1;
      printf("visito il nodo %d (val %d)\n",corrente,V[corrente]);
      
      /// 2) aggiungo i vicini in coda
      node_t* elem=E[corrente]->head;
      while (elem!=NULL){ /// elenco tutti i nodi nella lista

	
	/// elem->val = il nodo nella lista di adiacenza
	// il nodo viene accodato
	
	if (V_in_coda[elem->val]==0) {
	  printf("   aggiungo nodo %d in coda\n",elem->val);
	  V_in_coda[elem->val]=1;
	  queue_enqueue(q,elem->val);

	  //V_genitore[elem->val]=corrente;

	  output_graph << "bfs_"<< corrente << " -> bfs_"<< elem->val;
	  output_graph << "[color=red, penwidth=5, label = \""<< ct_visit++<< "\"]";
	  output_graph  <<endl;

	  
	}
	/*
	  else{
	  //V_visitato[corrente]
	  output_graph << "bfs_"<< corrente << " -> bfs_"<< elem->val;
	  output_graph << "[color=gray]";
	  output_graph  <<endl;
	}
	*/
	
	// vado avanti nella lista di adiacenza
	elem=elem->next;
      }
      
    }
  }

  if (0)
  for (int i=0;i<n_nodi;i++){
    if (V_genitore[i]>=0){
      output_graph << "dfs_"<< V_genitore[i] << " -> dfs_"<< i;
      //      output_graph << "[color=red, penwidth=5, label = \""<< ct_visit++<< "\"]";
      output_graph << "[color=red, penwidth=5]";
      output_graph  <<endl;
    }
  }

  
}


void swap(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
  /// aggiorno contatore globale di swap 
  ct_swap++;
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

  if (graph){
    output_graph.open("graph.dot");
    /// preparo header
    output_graph << "digraph g"<<endl; 
    output_graph << "{ "<<endl;
    output_graph << "node [shape=none]"<<endl;
    output_graph << "rankdir=\"LR\""<<endl;;
    //    output_graph << "edge[tailclip=false,arrowtail=dot];"<<endl;    
  }



  //int* V; // elenco dei nodi del grafo
  //list_t* E;  /// array con le liste di adiacenza per ogni nodo
  
  n_nodi=15;
  V=(int*)malloc(n_nodi*sizeof(int));
  V_visitato=(int*)malloc(n_nodi*sizeof(int));
  V_in_coda=(int*)malloc(n_nodi*sizeof(int));
  V_genitore=(int*)malloc(n_nodi*sizeof(int));
  
  E=(list_t**)malloc(n_nodi*sizeof(list_t*));

  // inizializzazione
  for (int i=0;i<n_nodi;i++){
    V[i]=2*i;
    V_visitato[i]=0;  // flag = non visitato
    V_in_coda[i]=0;  // flag = non in coda
    V_genitore[i]=-1;  // il nodo non ha un genitore di visita

    E[i]=list_new();

    if (i==0)
      global_ptr_ref=E[i];

    for (int j=0;j<n_nodi;j++){
      //if (rand()%2==0)
      if (j/2==i)
    	list_insert_front( E[i] , j);
    }
    
  }

  graph_print();
  
  list_insert_front( E[1] , 14);
  /*
  list_insert_front( E[1] , 3);
  list_insert_front( E[2] , 4);
  list_insert_front( E[3] , 4);
  list_insert_front( E[4] , 5);
  list_insert_front( E[4] , 0);
  */

  //graph_print();
  
  for (int i=0;i<n_nodi;i++){

    printf("Sono il nodo di indice %d nell'array\n",i);
    printf("Il valore del nodo e' %d\n",V[i]);
    printf("La lista di adiacenza e'\n");  
    list_print(E[i]);
  }


  //DFS(1);

  BFS(0);
 

  
    
  // init random
  srand((unsigned) time(NULL));

  if (graph){
    /// preparo footer e chiudo file
    output_graph << "}"<<endl; 
    output_graph.close();
    cout << " File graph.dot scritto" << endl<< "Creare il grafo con: dot graph.dot -Tpdf -o graph.pdf"<<endl;
  }



  return 0;
}
