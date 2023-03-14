allocazione:
- tramite liste di struct(valore, padre, figliodx, figliosx)
- tramite array, vale solo per alcuni tipi di alberi (binari, di ricerca)

# Alberi
```toc
```
---
## Definizione
In informatica, un <mark style="background: #FFB86CA6;">albero</mark> è una struttura dati gerarchica composta da nodi collegati tra loro da archi orientati.

L'albero è costituito da un nodo speciale, detto radice, dal quale si dipartono uno o più sotto-alberi, ovvero sottoinsiemi di nodi che a loro volta costituiscono alberi.

Ogni nodo, tranne la radice, ha esattamente un padre, ovvero il nodo da cui si origina l'arco che lo collega alla radice, e zero o più figli, ovvero i nodi ai quali sono collegati gli archi che si dipartono dal nodo.

### Livello di un nodo
Il <mark style="background: #ABF7F7A6;">livello di un nodo</mark> in un albero è la distanza tra il nodo e la radice dell'albero. 
In altre parole, il livello di un nodo è il numero di archi che devono essere attraversati per raggiungere il nodo dalla radice. Il livello della radice è $0$, mentre il livello di un nodo è uguale al livello del suo genitore più $1$.

### Numero di nodi
Il <mark style="background: #ABF7F7A6;">numero di nodi</mark> di un albero è il numero totale di nodi presenti nell'albero, compresa la radice. Il numero di nodi può variare notevolmente a seconda della forma dell'albero. 
Ad esempio, un albero lineare (lista) ha $n$ nodi, mentre un albero completo binario di altezza $h$ ha $2^{h+1}-1$ nodi. Il numero di nodi dell'albero è un fattore importante da considerare quando si sceglie un'implementazione di un algoritmo basato su un albero.

### Foglie
Le <mark style="background: #ABF7F7A6;">foglie</mark> dell'albero sono i nodi che non hanno figli, ovvero i nodi terminali dell'albero. Le foglie sono importanti in molte operazioni sull'albero, come la ricerca, la modifica o l'eliminazione di nodi. Tutti i nodi dell'ultimo livello dell'albero sono foglie.

[_Torna all'indice_](#alberi)

---

## Alberi binari
Un <mark style="background: #FFB86CA6;">albero binario</mark> è un tipo di albero in cui ogni nodo ha al massimo due figli, denominati solitamente figlio sinistro e figlio destro.

L'albero binario può essere vuoto, ovvero non contenere alcun nodo, oppure può essere composto da una radice e da uno o due sotto-alberi binari, uno a sinistra e uno a destra della radice.

La struttura a due figli permette di rappresentare e manipolare in modo efficiente diverse strutture dati come ad esempio gli alberi di ricerca binari, che permettono di eseguire ricerche in tempo logaritmico rispetto alla dimensione dell'albero.

![[albero_binario.jpeg | 200]]

[_Torna all'indice_](#alberi)

---

## Alberi completi
Un <mark style="background: #FFB86CA6;">albero binario completo</mark> è un tipo di albero binario in cui tutti i livelli dell'albero sono completamente riempiti, tranne eventualmente l'ultimo livello che può essere incompleto. In altre parole, tutti i nodi dell'albero, ad eccezione di quelli dell'ultimo livello, hanno due figli.

Le proprietà degli alberi completi includono:
1. Tutte le foglie si trovano allo stesso livello dell'albero.
2. L'altezza dell'albero è il numero di livelli presenti, che è uguale a $log_2(n) + 1$.
3. Il numero di nodi dell'albero completo con altezza $h$ è $2^{h+1}-1$.
4. Il numero di nodi dell'ultimo livello dell'albero completo può variare da $1$ a $2^h$, dove $h$ è l'altezza dell'albero.

![[albero_completo.jpeg | 300]]

[_Torna all'indice_](#alberi)

---

## Alberi bilanciati
Un <mark style="background: #FFB86CA6;">albero bilanciato</mark> è un tipo di albero in cui la differenza di altezza tra i sottoalberi sinistro e destro di ogni nodo non supera una certa costante predefinita. In altre parole, la differenza di altezza tra il sottoalbero sinistro e quello destro di un nodo non può superare un valore massimo prefissato, solitamente indicato con h.

Un albero bilanciato è una forma di ottimizzazione degli alberi binari in cui si cerca di minimizzare la complessità computazionale degli algoritmi di ricerca, inserimento e cancellazione, che dipendono in modo significativo dalla forma dell'albero.

Un esempio di albero bilanciato è l'<mark style="background: #BBFABBA6;">albero rosso-nero</mark>, un tipo di albero binario in cui ogni nodo è di colore rosso o nero. L'albero rosso-nero è bilanciato perché ogni cammino dalla radice a una foglia attraversa lo stesso numero di nodi neri. Ciò garantisce che la differenza di altezza tra i sottoalberi sinistro e destro di ogni nodo non superi una costante fissata.

Un'altra forma di albero bilanciato è l'<mark style="background: #BBFABBA6;">albero AVL</mark>, in cui la differenza di altezza tra i sottoalberi sinistro e destro di ogni nodo può essere al massimo 1. Ciò garantisce che l'altezza dell'albero sia logaritmica rispetto al numero di nodi, il che rende le operazioni sull'albero molto efficienti.

In generale, gli alberi bilanciati sono utilizzati in molte applicazioni in cui è necessario effettuare operazioni di ricerca, inserimento e cancellazione su grandi insiemi di dati, come ad esempio nelle basi di dati, negli algoritmi di ricerca di parole chiave o negli algoritmi di routing.

![[albero_bilanciato.jpeg | 350]]

[_Torna all'indice_](#alberi)

---

## Implementazione di un albero
Esistono diversi tipi di implementazioni per gli alberi. Le due principali sono: 
- Allocazione tramite liste di struct .
- Allocazione tramite array.

### Liste di struct
<mark style="background: #FFB8EBA6;">L'allocazione di un albero tramite liste di struct</mark> prevede la creazione di una struttura che rappresenta il nodo dell'albero. Questa struttura contiene un valore intero e tre puntatori, rispettivamente al padre, al figlio destro e al figlio sinistro. Ogni nodo dell'albero viene rappresentato da un'istanza della struttura. 

Una volta creato il nodo, è necessario collegarlo correttamente ai nodi esistenti dell'albero modificando i puntatori di padre, figlio destro e figlio sinistro. In questo modo, si ottiene un albero dinamico, in cui è possibile aggiungere o eliminare nodi in qualsiasi momento.

![[albero_implementazione_struct.jpeg | 400]]

### Array
L'allocazione di un albero tramite array prevede la creazione di un array di nodi dell'albero, dove ogni nodo è rappresentato da un elemento dell'array. L'allocazione del nuovo nodo avviene tramite l'incremento di un contatore che tiene traccia del numero di nodi presenti nell'albero. In questo modo, il nuovo nodo viene allocato nell'elemento successivo dell'array e viene collegato correttamente ai nodi esistenti dell'albero. 
<mark style="background: #FFF3A3A6;">TODO: è da sistemare, non ne avevo voglia e ho fatto un gran copia e incolla :)</mark>

L'allocazione di un albero tramite array è più efficiente in termini di spazio, in quanto non è necessario allocare memoria per i puntatori di ogni nodo, ma solo per il valore intero che rappresenta il nodo. Inoltre, l'allocazione tramite array può essere più efficiente in termini di tempo di accesso ai nodi dell'albero, in quanto i nodi sono memorizzati in modo contiguo in memoria e quindi l'accesso ai nodi è più veloce.

Tuttavia, l'allocazione tramite array presenta anche alcuni svantaggi: è adatta solo per alberi di dimensioni prefissate e con una struttura fissa, in cui la modifica dei nodi è limitata. Inoltre, la gestione dei puntatori tra i nodi dell'albero può essere più complicata rispetto all'allocazione tramite liste di struct.

![[albero_implementazione_array.jpg | 400]]

[_Torna all'indice_](#alberi)