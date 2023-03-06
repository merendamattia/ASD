# Quick Sort
```toc
```

## Pseudocodice
<mark style="background: #FFF3A3A6;">TODO: da fare</mark>
$i$ indica la lunghezza del sotto-array (ultima cella valida dell'array con elementi più piccoli del _pivot_)

[_Torna all'indice_](#quick%20sort)

---

## Analisi computazionale
Anche questo algoritmo si basa sul paradigma "divide et impera":
1. Divide: partiziono l'array $A[p, ... , r]$ in due regioni $A[p, ... , q-1]$ e $A[q+1, ... , r]$, tali che ogni elemento di $A[p, ... , q-1]$ sia minore o uguale a $A[q]$ (detto anche _pivot_) che, a sua volta, è minore o uguale a ogni elemento di $A[q+1, ... , r]$.
2. Impera: ordino i due sotto-array chiamando ricorsivamente Quick Sort. 
3. "Combina" i sotto-array: l'array è già ordinato. Non vengo fatte operazioni di unione come il Merge Sort.

L'<mark style="background: #ABF7F7A6;">analisi computazionale</mark> del Quick Sort dipende dal tipo di partizione utilizzata e dalla scelta del pivot. In generale, se la partizione è equilibrata (cioè divide l'array in parti approssimativamente uguali) e il pivot è scelto in modo casuale o in base a una strategia intelligente, il Quick Sort ha una complessità media di $O\left({ n \cdot \log(n) }\right)$, dove $n$ è la dimensione dell'array. Tuttavia, nel caso peggiore (ad esempio se l'array è già ordinato o inversamente ordinato) la complessità può raggiungere $O(n^2)$, rendendo il Quick Sort meno efficiente rispetto ad altri algoritmi di ordinamento come il [Merge Sort](02-merge_sort).

Il <mark style="background: #BBFABBA6;">vantaggio</mark> principale del Quick Sort rispetto al Merge Sort è che richiede meno spazio in memoria, poiché l'ordinamento viene eseguito direttamente sull'array di input senza creare array temporanei (ordina con `partition()` prima di richiamare ricorsivamente Quick Sort). Inoltre, il Quick Sort ha una complessità in tempo medio migliore rispetto al Merge Sort, soprattutto su array di grandi dimensioni. 

![[quick_common_many.gif | 400]]

Quando l'array è di grandi dimensioni, la <mark style="background: #FFB86CA6;">differenza di efficienza</mark> tra Quick Sort e Merge Sort diventa più evidente. Poiché il Quick Sort lavora sull'array di input direttamente, senza creare array temporanei come fa il Merge Sort, il Quick Sort ha meno overhead di memoria e può essere più veloce del Merge Sort in alcune situazioni.

Inoltre, il Quick Sort sfrutta la <mark style="background: #FFB86CA6;">località dei dati</mark>, ovvero la tendenza degli elementi vicini nell'array a essere acceduti in modo sequenziale, per ridurre il numero di accessi alla memoria e migliorare le prestazioni. Poiché il Merge Sort richiede di creare array temporanei e di copiare i dati da un array all'altro, non può sfruttare questa località dei dati in modo efficiente come fa il Quick Sort.

Tuttavia, sono presenti diversi <mark style="background: #FF5582A6;">svantaggi</mark> rispetto al Merge Sort: il Merge Sort ha il vantaggio di avere una complessità in tempo garantita $\Theta\left({ n \cdot \log(n) }\right)$ in tutti i casi, senza dipendere dalle scelte di pivot o di partizione. Inoltre, il Merge Sort è stabile, ovvero mantiene l'ordine relativo degli elementi con chiave uguale, mentre il Quick Sort può alterare l'ordine relativo degli elementi con la stessa chiave.

Tuttavia, è importante notare che il Quick Sort può avere una [complessità in tempo peggiore](#casi%20peggiori) di $O(n^2)$ in alcuni casi, ad esempio se l'array è già ordinato o inversamente ordinato e il pivot è scelto in modo subottimale. In questi casi, il Merge Sort può essere una scelta migliore in quanto ha una complessità in tempo garantita di $\Theta\left({ n \cdot \log(n) }\right)$ in tutti i casi.

Si creano alberi associati alle chiamate ricorsive. <mark style="background: #FFB8EBA6;">A seconda di come scegliamo il <i>pivot</i>, abbiamo una struttura diversa dei sotto-alberi: non si ha la certezza che l'albero sia bilanciato</mark>.
Un esempio grafico di un albero sbilanciato:
![[albero_sbilanciato.png | 400]]

[_Torna all'indice_](#quick%20sort)

### Invariante di ciclo
1. Se $p≤k≤i$, allora $A[k]≤x$
2. Se $i+1≤k≤j-1$, allora $A[k]>x$
3. Se $k=r$, allora $A[k]=x$
![[quicksort_invariante.png | 400]]

[_Torna all'indice_](#quick%20sort)

---

## Casi peggiori
Ci sono diversi casi peggiori:
1. [Se l'array è ordinato in ordine crescente (quindi sarebbe già ordinato).](#crescente)
2. [Se l'array è ordinato in ordine decrescente.](#decrescente)
3. [Se l'array contiene valori ripetuti.](#valori%20ripetuti)

### Crescente
Nel caso in cui l'array è già ordinato in ordine crescente e il pivot iniziale viene scelto come ultimo elemento dell'array, ad ogni iterazione della ricorsione il pivot sarà il massimo degli elementi restanti, e la partizione del sottoarray non dividerà l'array in due parti approssimativamente uguali. Questo comporta che una delle due parti sarà vuota e l'altra contenente $n-1$ elementi. In questo caso il Quick Sort avrà una complessità di $O(n^2)$.

Infatti, se ad ogni iterazione il pivot è il massimo degli elementi restanti, allora il sottoarray che contiene il pivot sarà sempre di dimensione $1$, e l'altro sottoarray conterrà tutti gli altri elementi. Di conseguenza, il Quick Sort dovrà ordinare un sottoarray con $n-1$ elementi, e poiché la partizione non è equilibrata, la complessità in tempo sarà $O(n^2)$.

![[quick_sort_crescente.gif | 450]]

Un esempio grafico:
![[quick_sort_crescente.pdf]]

[_Torna all'indice_](#quick%20sort)

---

### Decrescente
Nel caso in cui l'array è ordinato in ordine decrescente e il pivot iniziale viene scelto come ultimo elemento dell'array, ad ogni iterazione della ricorsione il pivot sarà il minimo degli elementi restanti, e la partizione del sottoarray non dividerà l'array in due parti approssimativamente uguali. Questo comporta che una delle due parti sarà vuota e l'altra contenente $n-1$ elementi, proprio come nel [caso dell'array già ordinato in ordine crescente](#crescente). Anche in questo caso il Quick Sort avrà una complessità di $O(n^2)$.

![[quick_sort_decrescente.gif | 450]]

Un esempio grafico:
![[quick_sort_decrescente.pdf]]

[_Torna all'indice_](#quick%20sort)

---
 
### Valori ripetuti
Nel caso in cui l'array contiene molti valori ripetuti, la scelta del pivot può avere un impatto significativo sulle prestazioni del Quick Sort.

Se il pivot viene scelto in modo da dividere l'array in modo diseguale, cioè se ci sono molte ripetizioni di valori uguali al pivot e la partizione non è equilibrata, allora il Quick Sort può avere una complessità peggiore di $O(n^2)$, come nel caso in cui l'array è già ordinato in ordine crescente.

In particolare, se ci sono molte ripetizioni di valori uguali al pivot, il Quick Sort potrebbe dover ordinare molti sotto-array di dimensione $1$, rendendo inefficiente l'algoritmo.

Per minimizzare questo problema, esistono diverse strategie per la scelta del pivot che tengono conto della presenza di valori ripetuti nell'array. Ad esempio, si può scegliere il pivot come il valore mediano tra tre elementi dell'array, scelti in modo casuale o ordinati. In questo modo, la probabilità di avere molte ripetizioni di valori uguali al pivot è ridotta, e la partizione dell'array è più equilibrata. In alternativa, si può utilizzare l'algoritmo di [Quick Sort a tre vie](#quick%20sort%20a%20tre%20vie) (o Quick Sort con partition a tre parti), che è in grado di gestire efficacemente la presenza di valori ripetuti nell'array.

![[quick_sim.gif | 450]]

Un esempio grafico:
![[quick_sort_tanti_pivot_uguali.pdf]]

[_Torna all'indice_](#quick%20sort)

---

## Quick Sort a tre vie
<mark style="background: #FFF3A3A6;">TODO: lo faremo a lezione il 09/03/2023</mark>

[_Torna all'indice_](#quick%20sort)








