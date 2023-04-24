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

## Tipi di grafi
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

## Operazioni
Le operazioni che possono essere eseguite su un grafo includono:
- <mark style="background: #D2B3FFA6;">Inserimento</mark> di un nuovo vertice o arco.
- <mark style="background: #D2B3FFA6;">Eliminazione</mark> di un vertice o arco.
- <mark style="background: #D2B3FFA6;">Ricerca</mark> di un vertice o arco.
- <mark style="background: #D2B3FFA6;">Trasformazione</mark> del grafo in una sua forma equivalente (ad esempio, un grafo non orientato può essere trasformato in un grafo orientato e viceversa).
- <mark style="background: #D2B3FFA6;">Calcolo di algoritmi</mark> di percorso più breve tra due vertici, di algoritmi di ricerca in profondità o in ampiezza e di algoritmi di ricerca del minimo albero ricoprente.

![[grafi_complessita.png]]

[_Torna all'indice_](#grafi)

---

## Classificazione dei grafi

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
