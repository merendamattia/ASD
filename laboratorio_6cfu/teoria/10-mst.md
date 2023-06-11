# MST
```toc
```
---

## Minimum spanning tree
Un albero di copertura minimo (MST) è un sottoinsieme degli archi di un grafo non orientato pesato connessi che collega tutti i vertici insieme, senza alcun ciclo e con il peso degli archi totale minimo possibile. 
In altre parole, è uno spanning tree la cui somma dei pesi degli archi è la più piccola possibile. Più in generale, qualsiasi grafo non orientato pesato sugli archi (non necessariamente connesso) ha una foresta di copertura minima, che è un'unione degli alberi di copertura minimi per i suoi componenti connessi.

![[Minimum_spanning_tree.jpg]]

[_Torna all'indice_](#mst)

---

### Esempio di utilizzo
Esistono molti casi d'uso per gli alberi di copertura minimi. Un esempio è una società di telecomunicazioni che cerca di posare cavi in un nuovo quartiere. Se si è vincolati ad interrare il cavo solo lungo determinati percorsi (es. strade), allora ci sarebbe un grafico contenente i punti (es. case) collegati da quei percorsi. 

Alcuni dei percorsi potrebbero essere più costosi, perché sono più lunghi o richiedono che il cavo sia interrato più in profondità; questi percorsi sarebbero rappresentati da archi con pesi maggiori.

Uno spanning tree per questo grafico sarebbe un sottoinsieme di quei percorsi che non ha cicli ma collega comunque ogni casa. Potrebbero esserci diversi spanning tree possibili. 
Un albero di copertura minimo sarebbe quello con il costo totale più basso, che rappresenta il percorso meno costoso per la posa del cavo.

[_Torna all'indice_](#mst)

---

### Proprietà
Alcune delle proprietà importanti degli MST:
1. <mark style="background: #FFB86CA6;">Connessione:</mark> Un MST connette tutti i nodi del grafo senza creare cicli. Questo significa che ci sarà un percorso tra qualsiasi coppia di nodi all'interno dell'MST.
2.  <mark style="background: #FFB86CA6;">Aciclicità:</mark> Un MST non contiene cicli. Questo è ciò che lo distingue da un generico albero di copertura che potrebbe contenere cicli.
3.  <mark style="background: #FFB86CA6;">Peso minimo:</mark> L'MST ha il peso totale più basso rispetto a tutti gli altri possibili alberi di copertura del grafo. La somma dei pesi degli archi nell'MST è minima.
4.  <mark style="background: #FFB86CA6;">Unicità del peso:</mark> Se i pesi degli archi nel grafo sono tutti distinti, allora l'MST è unico. Non ci sono altri alberi di copertura con lo stesso peso totale.
5.  <mark style="background: #FFB86CA6;">Numero di archi:</mark> L'MST contiene esattamente $n-1$ archi, dove $n$ è il numero di nodi nel grafo. Questo è il numero minimo di archi richiesto per collegare tutti i nodi senza creare cicli.
6.  <mark style="background: #FFB86CA6;">Taglio sicuro:</mark> Se consideriamo un qualsiasi taglio del grafo (una partizione dei nodi in due insiemi disgiunti), l'arco di peso minimo che attraversa quel taglio farà sicuramente parte dell'MST. Questa proprietà è conosciuta come "taglio sicuro" o "cut property".
7.  <mark style="background: #FFB86CA6;">Sottografo dell'MST:</mark> Qualsiasi sottografo di un MST che copre tutti i nodi del grafo è anche un MST per quel sottografo. In altre parole, se rimuoviamo un nodo o un insieme di archi dall'MST, otterremo ancora un albero di copertura minimo per il grafo residuo.

[_Torna all'indice_](#mst)

---

## Prim's Algorithm
L'algoritmo di Prim è un algoritmo greedy utilizzato per trovare il Minimum Spanning Tree (MST) di un grafo non orientato pesato. I passaggi principali di questo algoritmo sono:

1.  <mark style="background: #BBFABBA6;">Inizializzazione:</mark> Iniziamo selezionando casualmente un nodo di partenza come radice dell'MST.
2.  <mark style="background: #BBFABBA6;">Seleziona l'arco di peso minimo:</mark> A ogni iterazione, selezioniamo l'arco di peso minimo che collega un nodo dell'MST con un nodo esterno ad esso. Inizialmente, tutti i nodi sono considerati esterni all'MST.
3.  <mark style="background: #BBFABBA6;">Aggiungi il nodo e l'arco all'MST:</mark> Una volta selezionato l'arco di peso minimo, viene aggiunto il nodo esterno e l'arco all'MST. Questo nodo esterno diventa parte dell'MST, e ora viene considerato come un nodo interno.
4.  <mark style="background: #BBFABBA6;">Aggiorna i nodi esterni:</mark> Dopo aver aggiunto il nuovo nodo all'MST, aggiorniamo la lista dei nodi esterni considerando solo i nodi che non sono ancora stati inclusi nell'MST e che sono collegati all'ultimo nodo aggiunto.
5.  <mark style="background: #BBFABBA6;">Ripeti fino a completamento:</mark> I passaggi 2, 3 e 4 vengono ripetuti fino a quando non sono stati inclusi tutti i nodi nell'MST. L'algoritmo termina quando tutti i nodi del grafo sono stati aggiunti all'MST.

Alla fine dell'algoritmo di Prim, avremo costruito un MST che copre tutti i nodi del grafo, con il peso totale minimo. L'algoritmo seleziona sempre l'arco di peso minimo tra i nodi interni ed esterni, garantendo così che l'MST sia sempre un albero di copertura minimo.

L'algoritmo di Prim può essere implementato utilizzando diverse strutture dati, come una coda di priorità (heap) per selezionare l'arco di peso minimo in ogni iterazione. La complessità dell'algoritmo di Prim è di $O(E \cdot log(V))$, dove $E$ è il numero di archi e $V$ è il numero di nodi nel grafo.

Esempio di esecuzione:

![[prim_algorithm.gif]]

[_Torna all'indice_](#mst)

---

## Kruskal's algorithm
L'algoritmo di Kruskal è un algoritmo greedy utilizzato per trovare il Minimum Spanning Tree (MST) di un grafo non orientato pesato. I passaggi principali di questo algoritmo sono:

1.  <mark style="background: #ABF7F7A6;">Ordinamento degli archi:</mark> Iniziamo ordinando tutti gli archi del grafo in ordine crescente di peso.   
2.  <mark style="background: #ABF7F7A6;">Creazione dell'MST vuoto:</mark> Creiamo un MST vuoto inizialmente, che conterrà gli archi selezionati durante l'esecuzione dell'algoritmo.
3.  <mark style="background: #ABF7F7A6;">Seleziona l'arco di peso minimo:</mark> A partire dall'arco di peso minimo, prendiamo in considerazione gli archi in ordine crescente di peso.
4.  <mark style="background: #ABF7F7A6;">Verifica se l'aggiunta dell'arco crea un ciclo:</mark> Per ogni arco, verifichiamo se l'aggiunta di quell'arco all'MST crea un ciclo. Se l'arco non crea un ciclo, viene aggiunto all'MST.
5.  <mark style="background: #ABF7F7A6;">Ripeti fino a completamento:</mark> Ripetiamo i passaggi 3 e 4 fino a quando non abbiamo esaminato tutti gli archi del grafo o fino a quando l'MST contiene tutti i nodi del grafo.

Alla fine dell'algoritmo di Kruskal, avremo costruito un MST che copre tutti i nodi del grafo, con il peso totale minimo. L'algoritmo seleziona gli archi in base al loro peso minimo e assicura che l'MST non contenga cicli. La caratteristica chiave di Kruskal è che verifica l'assenza di cicli utilizzando una struttura dati chiamata Disjoint Set (insieme disgiunto).

L'algoritmo di Kruskal ha una complessità di tempo di $O(E \cdot log(E))$, dove $E$ è il numero di archi nel grafo. Utilizzando delle strutture [Disjoint Set](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) possiamo ottenere una complessità $O(E \cdot log(V))$.

Esempio di esecuzione:

![[kruskal_algorithm.gif]]

[_Torna all'indice_](#mst)