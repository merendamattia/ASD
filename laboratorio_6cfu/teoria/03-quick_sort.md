# Quick Sort
```toc
```

## Pseudocodice
<mark style="background: #FFF3A3A6;">TODO: da fare</mark>
$i$ indica la lunghezza del sotto-array (ultima cella valida dell'array con elementi più piccoli del _pivot_)

## Analisi
Anche questo algoritmo si basa sul paradigma "divide et impera":
1. Divide: partiziono l'array $A[p, ... , r]$ in due regioni $A[p, ... , q-1]$ e $A[q+1, ... , r]$, tali che ogni elemento di $A[p, ... , q-1]$ sia minore o uguale a $A[q]$ (detto anche _pivot_) che, a sua volta, è minore o uguale a ogni elemento di $A[q+1, ... , r]$.
2. Impera: ordino i due sotto-array chiamando ricorsivamente Quick Sort. 
3. "Combina" i sotto-array: l'array è già ordinato. Non vengo fatte operazioni di unione come il Merge Sort.

Invariante:
![[quicksort_invariante.png]]

Si creano alberi associati alle chiamate ricorsive. A seconda di come scegliamo il _pivot_, abbiamo una struttura diversa dei sotto-alberi: non si ha la certezza che l'albero sia bilanciato.
Se il _pivot_ che scegliamo è il numero più grande (caso peggiore) l'albero sarà sbilanciato su un solo lato; di conseguenza la complessità sarà $O(n^2)$.
![[albero_sbilanciato.png]]
<mark style="background: #FFF3A3A6;">TODO: da aggiungere foto migliore</mark>

## Casi peggiori
Ci sono diversi casi peggiori:
1. Se l'array è ordinato in ordine crescente (quindi sarebbe già ordinato)
2. Se l'array è ordinato in ordine decrescente


### Crescente
<mark style="background: #FFF3A3A6;">TODO: aggiungi pdf grafico e animazione con 16 elementi</mark>

### Decrescente
<mark style="background: #FFF3A3A6;">TODO: aggiungi pdf grafico e animazione con 16 elementi</mark>

## Vantaggi
A differenza del Merge Sort, questo algoritmo non utilizza strutture dati di supporto e ordina (chiamando `partition()`) prima di richiamare ricorsivamente Quick Sort.

## Animazioni 
<mark style="background: #FFF3A3A6;">TODO: da aggiungere</mark>