# Grafi
```toc
```
---
## Definizione
In informatica, un grafo è una struttura dati utilizzata per rappresentare le relazioni tra gli oggetti. Un grafo è costituito da un insieme di vertici (o nodi) e da un insieme di archi che connettono i vertici tra loro.

## Proprietà
Le proprietà dei grafi sono:
- <mark style="background: #FFB86CA6;">Vertici:</mark> ogni grafo ha un insieme di vertici, che possono essere collegati da archi.
- <mark style="background: #FFB86CA6;">Archi:</mark> gli archi rappresentano le relazioni tra i vertici del grafo. Ogni arco ha un punto di partenza (vertice di origine) e un punto di arrivo (vertice di destinazione).
- <mark style="background: #FFB86CA6;">Direzione:</mark> un grafo può essere diretto o non diretto. In un grafo diretto, gli archi hanno una direzione definita, mentre in un grafo non diretto gli archi non hanno una direzione.
- <mark style="background: #FFB86CA6;">Peso:</mark> un grafo può avere un peso assegnato a ciascun arco, che rappresenta una misura di costo o di distanza tra i vertici collegati dall'arco.

[_Torna all'indice_](#grafi)

---

### Tipi di grafi
Ci sono vari tipi di grafi, tra cui:
- <mark style="background: #ABF7F7A6;">Grafi non orientati:</mark> in un grafo non orientato, gli archi non hanno una direzione. Ciò significa che una relazione tra due vertici è simmetrica, cioè vale sia da A a B che da B ad A.
- <mark style="background: #ABF7F7A6;">Grafi orientati:</mark> in un grafo orientato, gli archi hanno una direzione definita. Ciò significa che una relazione tra due vertici può essere unidirezionale.
- <mark style="background: #ABF7F7A6;">Grafi pesati:</mark> in un grafo pesato, gli archi hanno un peso assegnato.
- <mark style="background: #ABF7F7A6;">Grafi connessi:</mark> un grafo connesso è un grafo in cui esiste almeno un cammino tra ogni coppia di vertici.
- <mark style="background: #ABF7F7A6;">Grafi aciclici:</mark> un grafo aciclico è un grafo che non ha cicli, cioè non è possibile partire da un vertice e tornare ad esso passando attraverso una serie di archi.
- <mark style="background: #ABF7F7A6;">Grafi completi:</mark> un grafo completo è un grafo in cui ogni vertice è collegato a tutti gli altri vertici. In un grafo completo non ci sono vertici isolati e il numero di archi è massimo, pari a $n*(n-1)/2$ dove $n$ è il numero di vertici del grafo.

[_Torna all'indice_](#grafi)

---

## Differenza tra grafi e alberi
Le principali differenze tra i grafi e le strutture di alberi sono:
- <mark style="background: #FFB8EBA6;">Struttura gerarchica:</mark> un albero è una struttura gerarchica in cui ogni nodo ha un solo padre, ad eccezione della radice che non ha un padre. In un grafo, invece, i vertici possono essere collegati in modi diversi, senza rispettare una gerarchia.
- <mark style="background: #FFB8EBA6;">Direzione degli archi:</mark> un albero ha un flusso di dati unidirezionale, cioè dall'alto verso il basso. In un grafo, gli archi possono essere orientati in modo unidirezionale o bidirezionale.
- <mark style="background: #FFB8EBA6;">Ciclicità:</mark> un albero non può avere cicli, mentre un grafo può avere cicli.
- <mark style="background: #FFB8EBA6;">Numero di figli:</mark> ogni nodo in un albero può avere al massimo un certo numero di figli. In un grafo, i vertici possono essere collegati a un numero variabile di altri vertici.

[_Torna all'indice_](#grafi)

---

## Rappresentazione di un grafo
Ci sono diversi modi di rappresentare un grafo, i principali sono:
- <mark style="background: #BBFABBA6;">Matrice di adiacenza:</mark> in questa rappresentazione, viene utilizzata una matrice n x n dove n è il numero di vertici del grafo. Se esiste un arco che collega il vertice i con il vertice j, allora l'elemento della matrice nella riga i e nella colonna j è pari a 1, altrimenti è pari a 0. Se il grafo è pesato, l'elemento della matrice corrispondente all'arco può contenere il valore del peso.
- <mark style="background: #BBFABBA6;">Lista di adiacenza:</mark> in questa rappresentazione, per ogni vertice viene memorizzata una lista dei suoi vertici adiacenti, ovvero i vertici collegati a esso da un arco. Inoltre, se il grafo è pesato, per ogni arco viene memorizzato il valore del peso.
- <mark style="background: #BBFABBA6;">Matrice di incidenza:</mark> una matrice bidimensionale booleana, nella quale le righe rappresentano i vertici e le colonne gli archi. Gli ingressi indicano se il vertice in una riga è incidente con l'arco in una colonna.

![[grafi_liste_vs_matrici.png]]

[_Torna all'indice_](#grafi)

---

### Operazioni
Le operazioni che possono essere eseguite su un grafo includono:
- <mark style="background: #D2B3FFA6;">Inserimento</mark> di un nuovo vertice o arco.
- <mark style="background: #D2B3FFA6;">Eliminazione</mark> di un vertice o arco.
- <mark style="background: #D2B3FFA6;">Ricerca</mark> di un vertice o arco.
- <mark style="background: #D2B3FFA6;">Trasformazione</mark> del grafo in una sua forma equivalente (ad esempio, un grafo non orientato può essere trasformato in un grafo orientato e viceversa).
- <mark style="background: #D2B3FFA6;">Calcolo di algoritmi</mark> di percorso più breve tra due vertici, di algoritmi di ricerca in profondità o in ampiezza e di algoritmi di ricerca del minimo albero ricoprente.

![[grafi_complessita.png]]

[_Torna all'indice_](#grafi)

---

## Classificazione

![[grafi_gerarchia.jpg]]

[_Torna all'indice_](#grafi)

---

### DAG
Un grafo aciclico diretto (DAG) <mark style="background: #ABF7F7A6;">è un tipo di grafo diretto in cui non ci sono cicli</mark>, ovvero non esiste alcun percorso che riporta al punto di partenza. I DAG sono utilizzati in diversi contesti, come ad esempio nell'analisi dei flussi di lavoro, nell'analisi dei dati, nell'informatica teorica, e così via.

Uno degli utilizzi più comuni dei DAG è nella rappresentazione di relazioni di dipendenza tra oggetti, dove i nodi rappresentano gli oggetti e gli archi rappresentano le dipendenze tra di essi. Ad esempio, in un'analisi dei flussi di lavoro, i nodi possono rappresentare le attività da svolgere, mentre gli archi possono rappresentare le dipendenze tra di esse, ovvero le relazioni di "predecessore" e "successore".

Una proprietà importante dei DAG è che permettono di definire un ordine parziale tra i nodi. In altre parole, se esiste un arco diretto da un nodo A a un nodo B, allora il nodo A viene considerato "precedente" al nodo B. Tuttavia, non è possibile stabilire un ordine definito tra nodi che non sono collegati da un arco.

In un DAG è possibile identificare uno o più nodi di partenza, ovvero nodi senza archi entranti, e uno o più nodi di arrivo, ovvero nodi senza archi uscenti. Questi nodi sono utilizzati per definire il punto di partenza e il punto di arrivo del grafo, e possono essere utilizzati per l'analisi del flusso dei dati e delle informazioni.

Esistono diverse tecniche per lavorare con i DAG, come ad esempio l'ordinamento topologico, che permette di trovare un ordine lineare tra i nodi del grafo che rispetti le dipendenze tra di essi. L'ordinamento topologico è utilizzato ad esempio per il calcolo delle dipendenze tra variabili in un programma, e per la risoluzione di problemi di programmazione dinamica.

<mark style="background: #FF5582A6;">Svantaggi:</mark> la visita è esponenziale in $n$: $2^n$.

Un esempio grafico di DAG:

![[dag_esempio.png]]

[_Torna all'indice_](#grafi)

---

### Foresta
Una foresta è un insieme di alberi non necessariamente connessi tra di loro. In una foresta, ogni nodo ha esattamente un arco entrante, tranne per un nodo speciale chiamato radice, che non ha archi entranti. I nodi possono avere più di un arco uscente e il numero di alberi presenti in una foresta può essere variabile.

Un esempio grafico di Foresta:

![[foresta_esempio.png]]

[_Torna all'indice_](#grafi)

---

### Lista semplice
Una lista semplice è una struttura dati simile alla lista doppia collegata, ma in cui ogni nodo ha solo un campo per il puntatore al nodo successivo. Questo significa che è possibile attraversare la lista solo in una direzione. In un grafo, una lista semplice può essere utilizzata per rappresentare una lista di adiacenza per ogni nodo, ma la ricerca di un arco richiede di attraversare l'intera lista partendo dal nodo di origine.

Un esempio grafico di Lista semplice:

![[lista_semplice_esempio.png]]

[_Torna all'indice_](#grafi)

---

### Lista doppia collegata
Una lista doppia collegata è una struttura dati che permette di memorizzare un insieme di elementi in una sequenza ordinata. Ogni elemento della lista è rappresentato da un nodo che contiene un campo per il valore dell'elemento, un campo per il puntatore al nodo precedente e un campo per il puntatore al nodo successivo. In un grafo, una lista doppia collegata può essere utilizzata per rappresentare una lista di adiacenza per ogni nodo, in modo da memorizzare i nodi adiacenti in entrambe le direzioni.

<mark style="background: #FF5582A6;">Svantaggi:</mark> la visita non termina perchè sono presenti dei cicli.

Un esempio grafico di Lista doppia collegata:

![[lista_doppia_collegata_esempio.png]]

[_Torna all'indice_](#grafi)

---

### Lista circolare
Una lista circolare è una struttura dati simile alla lista doppia collegata, ma in cui l'ultimo nodo punta al primo nodo, creando un ciclo. Questo significa che è possibile attraversare la lista in entrambe le direzioni senza mai arrivare alla fine. In un grafo, una lista circolare può essere utilizzata per rappresentare una lista di adiacenza per ogni nodo, creando un circuito che rappresenta la connessione tra i nodi.

<mark style="background: #FF5582A6;">Svantaggi:</mark> la visita non termina perchè sono presenti dei cicli.

Un esempio grafico di Lista circolare:

![[lista_circolare_esempio.png]]

[_Torna all'indice_](#grafi)

---

## Visite
Per visitare un grafo, ci sono due principali algoritmi che possono essere utilizzati: la [Breadth-First Search (BFS)](#bfs) e la [Depth-First Search (DFS)](#dfs). Entrambi gli algoritmi attraversano il grafo in modo sistematico e visitano tutti i suoi nodi, ma utilizzano approcci diversi.

[_Torna all'indice_](#grafi)

---

### BFS
<mark style="background: #ABF7F7A6;">La Breadth-First Search (BFS) è un algoritmo di visita dei grafi che esplora tutti i nodi del grafo in ordine di distanza dalla sorgente, cioè il nodo di partenza.</mark> In pratica, la BFS visita tutti i nodi che possono essere raggiunti dal nodo di partenza, poi tutti i nodi a distanza 2 dal nodo di partenza, poi quelli a distanza 3 e così via, fino a visitare tutti i nodi del grafo.

L'algoritmo BFS utilizza una coda FIFO (First-In, First-Out) per memorizzare i nodi del grafo che devono essere visitati. Inizialmente, il nodo di partenza viene inserito nella coda. Successivamente, finché la coda non è vuota, l'algoritmo rimuove il primo elemento della coda e lo visita. Poi, tutti i vicini di quel nodo che non sono ancora stati visitati vengono inseriti nella coda. Il processo viene ripetuto finché non vengono visitati tutti i nodi del grafo.

Per evitare di visitare più volte lo stesso nodo, l'algoritmo BFS mantiene un elenco dei nodi già visitati. Inoltre, per tenere traccia del percorso tra il nodo di partenza e ogni altro nodo, l'algoritmo memorizza un elenco dei predecessori di ogni nodo visitato.

L'implementazione dell'algoritmo BFS richiede spazio lineare rispetto alla dimensione del grafo, cioè $O(|V|+|E|)$, dove $|V|$ è il numero di nodi del grafo e $|E|$ è il numero di archi del grafo. Inoltre, il tempo di esecuzione dell'algoritmo BFS è proporzionale al numero di nodi e archi del grafo, cioè $O(|V|+|E|)$.

Pseudocodice:

![[bfs_pseudocode.png]]

Animazione:

![[bfs_graph.gif]]

[_Torna all'indice_](#grafi)

---

### DFS
<mark style="background: #BBFABBA6;">La Depth-First Search (DFS) è un algoritmo di visita dei grafi che esplora tutti i nodi del grafo seguendo un percorso fino a raggiungere un nodo terminale, quindi torna indietro e ripete il processo per tutti gli altri nodi del grafo.</mark>

L'algoritmo DFS utilizza uno stack per mantenere i nodi da visitare. Inizialmente, il nodo di partenza viene inserito nello stack. Successivamente, finché lo stack non è vuoto, l'algoritmo rimuove il primo elemento dello stack e lo visita. Poi, uno dei suoi vicini viene scelto e inserito nello stack. Se il nodo visitato non ha più vicini, l'algoritmo torna indietro al nodo precedente e ripete il processo per un altro vicino. Il processo viene ripetuto finché non vengono visitati tutti i nodi del grafo.

Per evitare di visitare più volte lo stesso nodo, l'algoritmo DFS mantiene un elenco dei nodi già visitati. Inoltre, per tenere traccia del percorso tra il nodo di partenza e ogni altro nodo, l'algoritmo memorizza un elenco dei predecessori di ogni nodo visitato.

L'algoritmo DFS può essere utilizzato per risolvere una varietà di problemi sui grafi, come ad esempio trovare cicli nel grafo, identificare le componenti connesse del grafo, trovare il percorso più breve tra due nodi in un grafo non pesato, e molti altri.

L'implementazione dell'algoritmo DFS richiede spazio lineare rispetto alla dimensione del grafo, cioè $O(|V|+|E|)$. Inoltre, il tempo di esecuzione dell'algoritmo DFS è proporzionale al numero di nodi e archi del grafo, quindi $O(|V|+|E|)$.

L'algoritmo DFS può essere implementato in diversi modi, tra cui il DFS ricorsivo e il DFS iterativo. Il DFS ricorsivo utilizza la ricorsione per implementare la ricerca in profondità, mentre il DFS iterativo utilizza uno stack per implementare la ricerca in profondità in modo iterativo. In generale, il DFS ricorsivo è più facile da implementare e capire, ma può causare problemi di stack overflow su grafi molto grandi. Il DFS iterativo, d'altra parte, è più efficiente e può essere utilizzato per grafi molto grandi.

Pseudocodice:

![[dfs_pseudocode.png]]

Animazione:

![[dfs_graph.gif]]

[_Torna all'indice_](#grafi)

---

## Cammini minimi
<mark style="background: #FFB86CA6;">I cammini minimi nei grafi sono i percorsi tra due nodi del grafo che richiedono il minor costo possibile.</mark> Il costo di un percorso può essere definito come la somma dei pesi degli archi che compongono il percorso. L'obiettivo dei cammini minimi è quindi quello di trovare il percorso con il costo minore tra due nodi specifici.

I cammini minimi sono importanti perché vengono utilizzati in molti problemi di ottimizzazione che coinvolgono i grafi. Ad esempio, possono essere utilizzati per trovare la strada più veloce per raggiungere una destinazione, il percorso più breve tra due città o il flusso di costo minimo attraverso una rete.

Esistono diversi algoritmi per trovare i cammini minimi nei grafi, ma i due algoritmi più comuni sono [l'algoritmo di Dijkstra](#dijkstra) e [l'algoritmo di Bellman-Ford](#bellman-ford).

[_Torna all'indice_](#grafi)

---

### Dijkstra
<mark style="background: #D2B3FFA6;">L'algoritmo di Dijkstra è un algoritmo greedy per trovare il cammino minimo tra un nodo di partenza e un nodo di destinazione all'interno di un grafo orientato con pesi sugli archi non negativi.</mark> L'algoritmo mantiene un insieme di nodi visitati e un insieme di nodi ancora da visitare, inizialmente vuoti. Inoltre, mantiene un vettore `dist` che tiene traccia della distanza minima tra il nodo di partenza e tutti gli altri nodi del grafo, inizializzato a un valore infinito per tutti i nodi tranne che per il nodo di partenza, il cui valore è impostato a 0.

L'algoritmo di Dijkstra utilizza una coda di priorità per selezionare il nodo con la distanza minima dal nodo di partenza da esaminare. Inizialmente, il nodo di partenza viene inserito nella coda di priorità con una priorità pari a 0. Ad ogni iterazione, il nodo con la priorità più bassa viene rimosso dalla coda di priorità e aggiunto all'insieme dei nodi visitati.

Successivamente, l'algoritmo esamina tutti i nodi adiacenti al nodo appena visitato e aggiorna la distanza minima se trova un percorso migliore attraverso il nodo corrente. Se la nuova distanza minima è inferiore alla distanza attualmente registrata per il nodo adiacente, il valore `dist` viene aggiornato con la nuova distanza minima. Infine, il nodo adiacente viene inserito nella coda di priorità con la sua nuova priorità pari alla distanza minima appena aggiornata.

L'algoritmo continua a esaminare i nodi nella coda di priorità in ordine di priorità crescente finché non raggiunge il nodo di destinazione o fino a quando la coda di priorità diventa vuota. Una volta raggiunto il nodo di destinazione, l'algoritmo può terminare e restituire il valore di `dist` registrato per il nodo di destinazione.

Se il nodo di destinazione non è raggiungibile dal nodo di partenza, la coda di priorità diventerà vuota senza che la destinazione sia stata raggiunta, e il valore di dist registrato per la destinazione rimarrà infinito. In questo caso, si può concludere che non esiste alcun cammino tra il nodo di partenza e il nodo di destinazione.

L'algoritmo di Dijkstra ha una complessità computazionale di $O(|E|+|V| \cdot log|V|)$, dove $|E|$ è il numero di archi del grafo e $|V|$ è il numero di nodi del grafo. L'algoritmo è efficiente per grafi con un grande numero di nodi ma un basso numero di archi, ma può diventare inefficiente per grafi con un elevato numero di archi. In questi casi, può essere preferibile utilizzare un algoritmo come l'algoritmo di Bellman-Ford che ha una complessità computazionale peggiore ma che è più adatto per grafi densi.

Pseudocodice:

![[dijkstra_pseudocode.png]]

[_Torna all'indice_](#grafi)

---

### Bellman-Ford
<mark style="background: #FFB8EBA6;">L'algoritmo di Bellman-Ford è un algoritmo dinamico di programmazione dinamica utilizzato per trovare il cammino minimo tra un nodo di partenza e tutti gli altri nodi in un grafo orientato o non orientato con pesi sugli archi arbitrari, anche negativi.</mark> L'algoritmo utilizza una tecnica chiamata "rilassamento" degli archi per  aggiornare iterativamente le distanze minime tra il nodo di partenza e gli altri nodi del grafo.

L'algoritmo mantiene un vettore `dist` che tiene traccia della distanza minima tra il nodo di partenza e tutti gli altri nodi del grafo. Inizialmente, tutti i valori di `dist` sono impostati a un valore infinito, tranne che per il nodo di partenza, il cui valore dist è impostato a 0.

L'algoritmo esegue $|V| - 1$ iterazioni, dove $|V|$ è il numero di nodi del grafo. Ad ogni iterazione, l'algoritmo rilassa tutti gli archi del grafo, aggiornando i valori di `dist` per i nodi raggiungibili tramite gli archi rilassati. L'algoritmo quindi aggiorna il vettore `dist` con i nuovi valori di `dist` calcolati.

Il rilassamento di un arco $(u, v)$ significa verificare se la distanza minima tra il nodo di partenza e il nodo $v$ può essere migliorata passando attraverso il nodo $u$. Se la distanza minima tra il nodo di partenza e il nodo $u$ sommata al peso dell'arco $(u, v)$ è inferiore alla distanza attualmente registrata per il nodo $v$, il valore di `dist` per il nodo $v$ viene aggiornato con il nuovo valore di `dist` calcolato. L'algoritmo di Bellman-Ford esegue questo rilassamento per tutti gli archi del grafo ad ogni iterazione.

Se dopo l'ultima iterazione del ciclo, ci sono ancora archi che possono essere rilassati, ciò significa che il grafo contiene un ciclo di peso negativo. In tal caso, l'algoritmo non può determinare il cammino minimo tra il nodo di partenza e il nodo di destinazione, e l'algoritmo termina restituendo un messaggio di errore.

L'algoritmo di Bellman-Ford ha una complessità computazionale di $O(|E| \cdot |V|)$, dove $|E|$ è il numero di archi del grafo e $|V|$ è il numero di nodi del grafo. Tuttavia, l'algoritmo di Bellman-Ford è l'unico algoritmo che funziona con grafi che contengono cicli di peso negativo.

Pseudocodice:

![[bellman-ford_pseudocode.png]]

[_Torna all'indice_](#grafi)

---

## Componenti fortemente connessi
In un grafo orientato, <mark style="background: #ABF7F7A6;">una componente fortemente connessa è un sottografo massimale in cui ogni coppia di nodi è raggiungibile dall'altro.</mark> In altre parole, una componente fortemente connessa è un insieme di nodi in cui c'è un percorso da ogni nodo di quell'insieme ad ogni altro nodo di quell'insieme.

Più formalmente, una componente fortemente connessa può essere definita come un insieme di nodi $C$ di un grafo orientato tale che per ogni coppia di nodi $u$ e $v$ in $C$, esiste un percorso da $u$ a $v$ e un percorso da $v$ a $u$ nel grafo orientato.

![[componenti_fortemente_connessi.png]]

Le componenti fortemente connesse sono importanti perché possono essere utilizzate per risolvere problemi come la determinazione dell'esistenza di percorsi tra due nodi in un grafo orientato e l'individuazione di cicli in un grafo orientato.

Esistono diversi algoritmi per trovare le componenti fortemente connesse in un grafo orientato, tra cui l'algoritmo di Kosaraju e [l'algoritmo di Tarjan](#tarjan). L'algoritmo di Kosaraju utilizza una combinazione di DFS e DFS invertita (ovvero, l'ordine in cui si visitano i nodi del grafo è invertito rispetto alla DFS normale), mentre l'algoritmo di Tarjan utilizza una DFS con la creazione di una pila di nodi visitati e la definizione di una variabile `lowlink` per ogni nodo visitato. Entrambi gli algoritmi hanno una complessità temporale di $O(|V| + |E|)$.

[_Torna all'indice_](#grafi)

---

### Tarjan
<mark style="background: #BBFABBA6;">L'algoritmo di Tarjan è un algoritmo per trovare le componenti fortemente connesse in un grafo orientato.</mark> Esso utilizza una visita in profondità (DFS) del grafo, creando una pila di nodi visitati e definendo una variabile `lowlink` per ogni nodo visitato.

L'algoritmo di Tarjan può essere descritto come segue:
1.  Inizializzare un contatore per i nodi visitati e una pila vuota di nodi.
2.  Iniziare la visita in profondità dal primo nodo del grafo.
3.  Per ogni nodo visitato durante la DFS, assegnare un numero crescente di ordine di visita e inserire il nodo nella pila.
4.  Per ogni arco $(u, v)$ attraversato durante la DFS, se $v$ non è ancora stato visitato, continuare la DFS dal nodo v.
5.  Per ogni arco $(u, v)$ attraversato durante la DFS, se $v$ è già stato visitato e non è ancora stato inserito nella componente fortemente connessa corrente, aggiornare la variabile `lowlink` di $u$ al minimo tra il suo valore corrente e il numero di ordine di visita di $v$. Questo passaggio identifica i nodi che sono raggiungibili attraverso un arco all'indietro (_back edge_) dal nodo corrente $u$.
6.  Dopo che sono state visitate tutte le adiacenze di un nodo u, se il suo valore di `lowlink` è uguale al suo numero di ordine di visita, allora è stato trovato un insieme completo di nodi fortemente connessi. Estrai tutti i nodi dalla pila fino a quando non si raggiunge il nodo u e aggiungili all'insieme delle componenti fortemente connesse correnti.

L'algoritmo di Tarjan ha una complessità temporale di $O(|V| + |E|)$.

Pseudocodice:

![[tarjan_pseudocode.png]]

Animazione:

![[Tarjan's_Algorithm_Animation.gif]]

> Maggiori dettagli su [Wikipedia](https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm).

[_Torna all'indice_](#grafi)