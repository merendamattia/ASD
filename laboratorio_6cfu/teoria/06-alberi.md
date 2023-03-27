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
## Tipi di albero
Esistono diversi tipi di albero. I principali sono i seguenti:
- Alberi binari
- Alberi completi
- Alberi bilanciati

### Alberi binari
Un <mark style="background: #FFB86CA6;">albero binario</mark> è un tipo di albero in cui ogni nodo ha al massimo due figli, denominati solitamente figlio sinistro e figlio destro.

L'albero binario può essere vuoto, ovvero non contenere alcun nodo, oppure può essere composto da una radice e da uno o due sotto-alberi binari, uno a sinistra e uno a destra della radice.

La struttura a due figli permette di rappresentare e manipolare in modo efficiente diverse strutture dati come ad esempio gli alberi di ricerca binari, che permettono di eseguire ricerche in tempo logaritmico rispetto alla dimensione dell'albero.

![[albero_binario.jpeg | 200]]

[_Torna all'indice_](#alberi)

---

### Alberi completi
Un <mark style="background: #FFB86CA6;">albero binario completo</mark> è un tipo di albero binario in cui tutti i livelli dell'albero sono completamente riempiti, tranne eventualmente l'ultimo livello che può essere incompleto. In altre parole, tutti i nodi dell'albero, ad eccezione di quelli dell'ultimo livello, hanno due figli.

Le proprietà degli alberi completi includono:
1. Tutte le foglie si trovano allo stesso livello dell'albero.
2. L'altezza dell'albero è il numero di livelli presenti, che è uguale a $log_2(n) + 1$.
3. Il numero di nodi dell'albero completo con altezza $h$ è $2^{h+1}-1$.
4. Il numero di nodi dell'ultimo livello dell'albero completo può variare da $1$ a $2^h$, dove $h$ è l'altezza dell'albero.

![[albero_completo.jpeg | 300]]

[_Torna all'indice_](#alberi)

---

### Alberi bilanciati
Un <mark style="background: #FFB86CA6;">albero bilanciato</mark> è un tipo di albero in cui la differenza di altezza tra i sottoalberi sinistro e destro di ogni nodo non supera una certa costante predefinita. In altre parole, la differenza di altezza tra il sottoalbero sinistro e quello destro di un nodo non può superare un valore massimo prefissato, solitamente indicato con h.

Un albero bilanciato è una forma di ottimizzazione degli alberi binari in cui si cerca di minimizzare la complessità computazionale degli algoritmi di ricerca, inserimento e cancellazione, che dipendono in modo significativo dalla forma dell'albero.

Un esempio di albero bilanciato è l'<mark style="background: #BBFABBA6;">albero rosso-nero</mark>, un tipo di albero binario in cui ogni nodo è di colore rosso o nero. L'albero rosso-nero è bilanciato perché ogni cammino dalla radice a una foglia attraversa lo stesso numero di nodi neri. Ciò garantisce che la differenza di altezza tra i sottoalberi sinistro e destro di ogni nodo non superi una costante fissata.

Un'altra forma di albero bilanciato è l'<mark style="background: #BBFABBA6;">albero AVL</mark>, in cui la differenza di altezza tra i sottoalberi sinistro e destro di ogni nodo può essere al massimo 1. Ciò garantisce che l'altezza dell'albero sia logaritmica rispetto al numero di nodi, il che rende le operazioni sull'albero molto efficienti.

In generale, gli alberi bilanciati sono utilizzati in molte applicazioni in cui è necessario effettuare operazioni di ricerca, inserimento e cancellazione su grandi insiemi di dati, come ad esempio nelle basi di dati, negli algoritmi di ricerca di parole chiave o negli algoritmi di routing.

![[albero_bilanciato.jpeg | 350]]

[_Torna all'indice_](#alberi)

---

### Alberi binari di ricerca
Gli alberi binari di ricerca sono una struttura dati a forma di albero che consente di organizzare e gestire un insieme di dati in modo efficiente. Ogni nodo dell'albero rappresenta un elemento del set di dati e ha due figli, uno a sinistra e uno a destra, che a loro volta rappresentano elementi minori e maggiori rispetto al nodo padre.

Le <mark style="background: #FFB86CA6;">principali proprietà degli alberi binari di ricerca</mark> sono:
- In un albero binario di ricerca, ogni nodo a sinistra del nodo radice ha un valore minore del nodo radice e ogni nodo a destra ha un valore maggiore del nodo radice.
- Tutti i sottoalberi di un albero binario di ricerca sono anch'essi alberi binari di ricerca.
- La ricerca di un elemento all'interno di un albero binario di ricerca richiede un tempo proporzionale all'altezza dell'albero.

Gli alberi binari di ricerca sono importanti per diverse ragioni. In primo luogo, offrono un modo efficiente di organizzare e gestire grandi quantità di dati, <mark style="background: #FFB8EBA6;">permettendo di eseguire operazioni come l'inserimento, la cancellazione e la ricerca di elementi in tempo logaritmico.</mark>
In secondo luogo, gli alberi binari di ricerca sono alla base di molte altre strutture dati e algoritmi, come i heap binari, gli alberi AVL e i grafi binari di ricerca.

[_Torna all'indice_](#alberi)

#### Rotazioni
Per <mark style="background: #BBFABBA6;">mantenere l'invariante degli alberi binari di ricerca</mark>, cioè che ogni nodo a sinistra del nodo radice ha un valore minore del nodo radice e ogni nodo a destra ha un valore maggiore del nodo radice, è necessario eseguire delle operazioni di bilanciamento dell'albero quando si effettuano inserimenti o cancellazioni di nodi.

Una delle tecniche di bilanciamento più comuni per gli alberi binari di ricerca è l'utilizzo di rotazioni. Le rotazioni sono delle operazioni che permettono di modificare la struttura dell'albero senza alterare l'ordine dei nodi.

Esistono due tipi di rotazioni: a sinistra e a destra. La rotazione a sinistra viene utilizzata per bilanciare un nodo che ha un figlio destro più profondo del figlio sinistro, mentre la rotazione a destra viene utilizzata per bilanciare un nodo che ha un figlio sinistro più profondo del figlio destro.

Ecco come funzionano le rotazioni:
- <mark style="background: #ABF7F7A6;">Rotazione a sinistra:</mark> si prende il figlio destro del nodo non bilanciato e si fa diventare il nuovo nodo radice dell'albero. Il vecchio nodo radice diventa il figlio sinistro del nuovo nodo radice e il figlio sinistro del vecchio nodo radice diventa il figlio destro del nuovo nodo radice.
- <mark style="background: #ABF7F7A6;">Rotazione a destra:</mark> si prende il figlio sinistro del nodo non bilanciato e si fa diventare il nuovo nodo radice dell'albero. Il vecchio nodo radice diventa il figlio destro del nuovo nodo radice e il figlio destro del vecchio nodo radice diventa il figlio sinistro del nuovo nodo radice.

Dopo l'esecuzione di una rotazione, l'altezza dell'albero potrebbe essere cambiata, ma l'invariante degli alberi binari di ricerca viene mantenuta. L'utilizzo di rotazioni è importante per garantire che gli alberi binari di ricerca rimangano equilibrati e che le operazioni di ricerca, inserimento e cancellazione possano essere eseguite in modo efficiente.

![[rotazione_alberi.png]]

> Approfondimento al seguente [link](http://www.cs.ecu.edu/karl/3300/spr16/Notes/DataStructure/Tree/balance2.html).

[_Torna all'indice_](#alberi)

---

### Heap
L'heap è un tipo di struttura dati ad albero utilizzato principalmente per implementare una coda con priorità e per la ricerca del cammino più breve nei grafi. Si tratta di un albero binario (quasi) completo in cui ogni nodo rappresenta un elemento e ogni elemento è associato ad una chiave.

L'heap può essere di due tipi: <mark style="background: #FFB86CA6;">heap massimo o heap minimo</mark>. In un heap massimo, il valore del padre è maggiore o uguale al valore di entrambi i figli, mentre in un heap minimo il valore del padre è minore o uguale al valore di entrambi i figli.

La <mark style="background: #ABF7F7A6;">proprietà chiave</mark> dell'heap è che il valore di un nodo è sempre maggiore (o minore) di quelli dei suoi figli. In altre parole, il nodo radice dell'heap massimo è l'elemento con la chiave più grande, mentre il nodo radice dell'heap minimo è l'elemento con la chiave più piccola.

L'heap viene utilizzato soprattutto per implementare le code con priorità, in cui gli elementi sono processati in ordine di priorità. La priorità viene data dalle chiavi degli elementi, e gli elementi con la chiave maggiore (o minore, a seconda dell'heap) hanno una priorità più alta.

L'heap supporta diverse operazioni, tra cui:
- <mark style="background: #BBFABBA6;">Inserimento:</mark> l'elemento viene inserito nell'heap come ultimo nodo e successivamente viene ripristinata la proprietà dell'heap attraverso l'operazione di heapify, che confronta il valore del nodo con il valore del padre e, se necessario, scambia i nodi fino a quando la proprietà dell'heap non è ripristinata.
- <mark style="background: #BBFABBA6;">Estrazione:</mark> l'elemento con la chiave più alta (o più bassa) viene rimosso dalla radice dell'heap e sostituito con l'ultimo elemento dell'heap. Successivamente, l'heap viene nuovamente ripristinato tramite l'operazione di heapify, che confronta il valore del nodo con il valore dei figli e, se necessario, scambia il nodo con il figlio più grande (o più piccolo) fino a quando la proprietà dell'heap non è ripristinata.
- <mark style="background: #BBFABBA6;">Accesso all'elemento di massima (o minima) priorità:</mark> restituisce il valore dell'elemento nella radice dell'heap senza rimuoverlo.

L'heap è un'importante struttura dati utilizzata in molte applicazioni, come gli algoritmi di ordinamento (es. heap-sort), la ricerca del cammino più breve nei grafi (es. algoritmo di Dijkstra), l'ottimizzazione dei flussi di dati (es. algoritmo di Huffman), la gestione delle risorse del sistema (es. assegnazione di processi in un sistema operativo).

*Pseudocodice Max-Heapify:*
![[max_heapify.png | 350]]

[_Torna all'indice_](#alberi)

---

#### Approfondimento: heap nei grafi
L'heap viene spesso utilizzato negli algoritmi di ricerca dei cammini minimi nei grafi, come l'algoritmo di Dijkstra e l'algoritmo di Prim, perché consente di gestire in modo efficiente la coda dei nodi ancora da visitare.

L'algoritmo di Dijkstra, ad esempio, viene utilizzato per trovare il cammino più breve tra un nodo di partenza e tutti gli altri nodi del grafo. L'idea di base dell'algoritmo di Dijkstra è quella di mantenere una lista di nodi ancora da visitare, ordinata in base alla distanza dal nodo di partenza. In ogni iterazione, si seleziona il nodo con la distanza minima dalla lista e si aggiornano le distanze dei suoi nodi adiacenti.

L'heap viene utilizzato per implementare la lista dei nodi ancora da visitare, in modo tale da selezionare in modo efficiente il nodo con la distanza minima in ogni iterazione dell'algoritmo. In particolare, l'heap viene inizializzato con il nodo di partenza e la sua distanza, e gli altri nodi vengono inseriti nell'heap man mano che vengono scoperti durante l'esecuzione dell'algoritmo.

In ogni iterazione, si estrae il nodo con la distanza minima dall'heap e si aggiornano le distanze dei suoi nodi adiacenti. Se la distanza di un nodo adiacente viene aggiornata, viene inserito (o aggiornato) nell'heap. In questo modo, l'heap mantiene la lista dei nodi ancora da visitare, ordinata in base alla distanza dal nodo di partenza.

L'utilizzo dell'heap consente di ridurre la complessità dell'algoritmo di Dijkstra da $O(|V|^2)$ a $O(|E| \cdot log |V|)$, dove $|V|$ e $|E|$ sono rispettivamente il numero di nodi e di archi del grafo. Inoltre, l'utilizzo dell'heap consente di implementare l'algoritmo di Prim per trovare un albero di copertura minimo in un grafo pesato.

In generale, l'heap viene utilizzato nei problemi di ricerca dei cammini minimi nei grafi perché consente di gestire in modo efficiente la coda dei nodi ancora da visitare, permettendo di selezionare il nodo con la distanza minima (o massima) in tempo logaritmico rispetto al numero di nodi nella coda.

[_Torna all'indice_](#alberi)

---

## Implementazione di un albero
Esistono diversi tipi di implementazioni per gli alberi. Le due principali sono: 
- Allocazione tramite liste di struct.
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

---

## Visite in un albero
Come facciamo a visualizzare il contenuto di un albero?
Esistono due tipi di visite:
- Visita in profondità (DFS)
- Visita in ampiezza (BFS)

### Visita in profondità (DFS)
La <mark style="background: #FFB86CA6;">visita in profondità</mark> (Depth-First Search) è un algoritmo utilizzato per esplorare e attraversare tutti i nodi di un albero. L'algoritmo funziona in modo ricorsivo, visitando prima i nodi figli del nodo corrente, e poi esplorando ulteriormente i nodi figli dei figli, e così via, fino a quando non ha visitato tutti i nodi dell'albero.
Ci sono tre varianti principali della DFS: pre-order, post-order e in-order.

---

#### Pre-order
La visita in profondità <mark style="background: #FF5582A6;">pre-ordine</mark> (pre-order DFS) visita prima il nodo corrente, e poi visita i suoi nodi figli. Questo ordine di visita garantisce che ogni nodo dell'albero venga visitato prima dei suoi nodi figli. In pratica, l'algoritmo esegue le seguenti operazioni:
1.  Visita il nodo corrente.
2.  Applica la visita in profondità pre-ordine a ciascun nodo figlio del nodo corrente.
```cpp
visit(x) // Pre-order
	print(value(x))
	visit(x->left)
	visit(x->right)
```
Questo può essere utile quando si vuole eseguire un'operazione su ciascun nodo dell'albero in un ordine specifico, ad esempio per stampare i nodi dell'albero o per calcolare la somma dei valori dei nodi dell'albero.

[_Torna all'indice_](#alberi)

---

#### Post-order
La visita in profondità <mark style="background: #ABF7F7A6;">post-ordine</mark> (post-order DFS) visita prima i nodi figli del nodo corrente, e poi visita il nodo corrente. L'algoritmo esegue quindi le seguenti operazioni:
1.  Applica la visita in profondità post-ordine a ciascun nodo figlio del nodo corrente.
2.  Visita il nodo corrente.
```cpp
visit(x) // Post-order
	visit(x->left)
	visit(x->right)
	print(value(x))
```
Questa variante della DFS è utile quando si vuole eseguire un'operazione sul nodo solo dopo aver eseguito un'operazione su tutti i suoi nodi figli. Ad esempio, può essere utilizzato per calcolare l'altezza dell'albero o per visitare i nodi nell'ordine inverso.

[_Torna all'indice_](#alberi)

---

#### In-order
La visita in profondità <mark style="background: #BBFABBA6;">in-ordine</mark> (in-order DFS) è utilizzata principalmente per gli alberi binari, dove il sottoalbero sinistro è visitato prima del nodo corrente e il sottoalbero destro è visitato dopo il nodo corrente. 
```cpp
visit(x) // In-order
	visit(x->left)
	print(value(x))
	visit(x->right)
```
Questo ordine di visita consente di visitare i nodi dell'albero in ordine crescente (o decrescente, a seconda dell'implementazione). Tuttavia, tecnicamente è possibile applicare la visita in profondità in-ordine a qualsiasi tipo di albero, anche se il risultato potrebbe non avere un significato preciso.

> È importante notare che, se l'albero non è un albero binario, la visita in profondità non garantisce di visitare i nodi nell'ordine corretto per tutte le possibili applicazioni. 
> In questo caso, potrebbe essere necessario utilizzare altre tecniche di visita, come la visita in ampiezza (BFS, Breadth-First Search). In generale, la DFS è utile quando si vuole esplorare tutto l'albero o una parte dell'albero in profondità, mentre la BFS è utile quando si vuole esplorare l'albero in ampiezza, visitando prima i nodi più vicini alla radice.

[_Torna all'indice_](#alberi)

---

#### Esempio grafico
![[DFS.jpeg | 400]]

<mark style="background: #FF5582A6;">Pre-order</mark> (node visited at position red):  `F, B, A, D, C, E, G, I, H`.
<mark style="background: #BBFABBA6;">In-order</mark> (node visited at position green):  `A, B, C, D, E, F, G, H, I`.
<mark style="background: #ABF7F7A6;">Post-order</mark> (node visited at position blue):  `A, C, E, D, B, H, I, G, F`.

> Il percorso che seguiamo durante una DFS è noto come [*cammino eureliano*](https://it.wikipedia.org/wiki/Cammino_euleriano).

[_Torna all'indice_](#alberi)
