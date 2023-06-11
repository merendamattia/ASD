# Flow Networks
```toc
```
---

## Che cosa sono?
Un Flow Network $G = (V,\;E)$ è un grafo orientato nel quale ogni arco ha una capacità (peso) maggiore o uguale di zero.

Un grafo di flusso di rete è costituito da un insieme di nodi e archi direzionati. I nodi rappresentano le sorgenti, le destinazioni e i punti intermedi attraverso i quali il flusso può passare. Gli archi rappresentano i canali attraverso i quali il flusso può essere inviato da un nodo all'altro.

Ogni arco nel grafo di flusso di rete ha una capacità, che rappresenta la quantità massima di flusso che può passare attraverso quell'arco. Questa capacità può rappresentare, ad esempio, la larghezza di banda di una connessione di rete o la capacità di trasporto di un sistema di trasporto.

$$
0 ≤ \text{ Flusso } ≤ \text{ Capacità }
$$

L'obiettivo in un grafo di flusso di rete è quello di massimizzare il flusso totale che può essere inviato dalla sorgente alle destinazioni, rispettando le capacità degli archi e le restrizioni di flusso.

Per calcolare il flusso massimo in un grafo di flusso di rete, si utilizzano algoritmi noti come algoritmi di flusso di rete, come l'algoritmo di [Ford-Fulkerson](#Ford-Fulkerson%20Algorithm) o l'algoritmo di [Edmonds-Karp](#Edmonds–Karp%20Algorithm). Questi algoritmi determinano un flusso massimo trovando iterativamente percorsi di aumento nel grafo, ovvero percorsi che permettono di incrementare il flusso totale.

È un algoritmo greedy.
> Un algoritmo greedy è un algoritmo che fa scelte localmente ottimali in ogni passo, sperando che la soluzione globale sia ottimale. Non sempre garantisce la soluzione ottima globale, ma spesso è veloce ed efficiente.

[_Torna all'indice_](#flow%20networks)

---

### Proprietà
- <mark style="background: #FFB86CA6;">Capacità:</mark> $\displaystyle \forall (u,v)\in E:\ 0 \leq f(u,v)\leq c(u,v)$ 
Il flusso lungo un bordo non può superare la sua capacità.
- <mark style="background: #FFB86CA6;">Simmetria distorta:</mark> $\displaystyle \forall (u,v)\in E:\ f(u,v)=-f(v,u)$
Il flusso netto da $u$ a $v$ deve essere l'opposto del flusso netto da $v$ a $u$.
- <mark style="background: #FFB86CA6;">Conservazione del flusso:</mark> $\forall u\in V:u\neq s{\text{ and }}u\neq t\Rightarrow \sum_{w\in V}f(u,w)=0$
Il flusso netto verso un nodo è zero, ad eccezione della sorgente, che "produce" flusso, e del pozzo, che "consuma" flusso.
- <mark style="background: #FFB86CA6;">Value(f):</mark> $\sum_{(s,u)\in E}f(s,u)=\sum_{(v,t)\in E}f(v,t)$
Il flusso in partenza da $s$ deve essere uguale al flusso in arrivo a $t$.

[_Torna all'indice_](#flow%20networks)

---

## Ford-Fulkerson Algorithm
L'idea alla base dell'algoritmo è la seguente: fintanto che esiste un percorso dalla sorgente (nodo iniziale) al sink (nodo finale), con capacità disponibile su tutti i bordi del percorso, inviamo il flusso lungo uno dei percorsi. Quindi troviamo un altro percorso e così via. Un cammino con capacità disponibile è detto <mark style="background: #BBFABBA6;">cammino aumentante</mark> (augmenting path).

Definiamo come <mark style="background: #ABF7F7A6;">Residual Networks</mark> $G_{f}(V,E_{f})$ la rete con capacità $c_{f}(u,v)=c(u,v)-f(u,v)$ e nessun flusso.

![[flow_networks.jpg]]

---

### Pseudocodice
![[ford-fulkerson.png]]

La ricerca viene fatta mediante una DFS.

---

### Complessità
Quando le capacità sono numeri interi, il tempo di esecuzione di Ford-Fulkerson è limitato da $O(E \cdot f)$, dove $E$ è il numero di archi nel grafico e $f$ è il flusso massimo nel grafico. Questo perché ogni cammino aumentante può essere trovato nel tempo $O(E)$ e aumenta il flusso di una quantità intera di almeno $1$, con il limite superiore $f$.

[_Torna all'indice_](#flow%20networks)

---

## Edmonds–Karp Algorithm
L'algoritmo è identico all'algoritmo Ford-Fulkerson, tranne per il fatto che l'ordine di ricerca quando si trova il percorso aumentante è definito. 

Il percorso trovato deve essere un percorso più breve con capacità disponibile. Questo può essere trovato con una BFS, dove applichiamo un peso di 1 a ciascun arco. 

Il tempo di esecuzione di $\displaystyle O(|V||E|^{2})$ si trova mostrando che ogni cammino aumentante può essere trovato in tempo $O(|E|)$, che ogni volta almeno uno degli $E$ i archi diventano saturi (un arco che ha il flusso massimo possibile), che la distanza dall'arco saturato alla sorgente lungo il percorso aumentante deve essere maggiore dell'ultima volta che è stato saturato, e che la lunghezza è al massimo $|V|$.

Un'altra proprietà di questo algoritmo è che la lunghezza del cammino aumentante minimo aumenta in modo monotono.

[_Torna all'indice_](#flow%20networks)