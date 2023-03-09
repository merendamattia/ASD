# Counting Sort
```toc
```
---

## Pseudocodice
![[counting_pseudocodice.jpeg | 600]]

---

## Analisi computazionale
Il Counting Sort è un algoritmo di ordinamento utilizzato per ordinare una sequenza di numeri interi positivi. <mark style="background: #ABF7F7A6;">È particolarmente utile quando la sequenza di numeri da ordinare ha un intervallo limitato e noto, e quando la sequenza contiene molti duplicati.</mark>

<mark style="background: #BBFABBA6;">Il Counting Sort funziona contando il numero di elementi di un certo valore nella sequenza, e quindi posizionandoli in ordine in base al loro valore.</mark> In altre parole, l'algoritmo "conta" quante volte ogni valore appare nella sequenza e per poi posizionare gli elementi in ordine crescente.

Il Counting Sort ha una complessità temporale lineare $O(n + k)$, dove $n$ è la lunghezza della sequenza e $k$ è l'intervallo di valori possibili nella sequenza. Questo lo rende un algoritmo efficiente per sequenze di grandi dimensioni e con un intervallo limitato di valori possibili.
[Esempio di esecuzione (caso medio).](obsidian://open?vault=ASD&file=laboratorio_6cfu%2Fdata%2Fpdf%2Fcounting_sort_caso_medio.pdf)

<mark style="background: #FFB86CA6;">È un algoritmo stabile</mark>: un algoritmo di ordinamento si dice stabile se non altera l'ordine relativo di oggetti distinti che sono uguali rispetto alla relazione d'ordine, ad esempio l'ordine relativo di elementi con chiavi uguali.

[_Torna all'indice_](#counting%20sort)

---

### Complessità
In questo algoritmo ci sono principalmente quattro loop:
1. Il primo (***for*** $i \leftarrow 0$ ***to*** $k$) avrà tempo di esecuzione pari a $O(k)$. 
2. Il secondo (***for*** $j \leftarrow 1$ ***to*** $lunghezza[A]$) avrà tempo di esecuzione pari a $O(n)$.
3. Il terzo (***for*** $i \leftarrow 1$ ***to*** $k$) avrà di nuovo tempo di esecuzione pari a $O(k)$. 
4. Il quarto (***for*** $j \leftarrow lunghezza[A]$ ***downto*** $1$) avrà tempo di esecuzione pari a $O(n)$.

> $k$ è l'intervallo di valori possibili nella sequenza (aka il numero più grande della sequenza).
> $n$ è la lunghezza della sequenza.

Quindi avremo una complessità complessiva in tutti e tre i casi pari a: 
$$=O(k)+O(n)+O(k)+O(n) =$$
$$= 2\cdot O(k)+ 2\cdot O(n) = $$
$$ = O(n+k)$$

[_Torna all'indice_](#counting%20sort)

---

## Funzionamento
Ecco un esempio di Counting Sort che ordina la sequenza `[4, 2, 5, 1, 3, 5, 1, 3]`:
1.  Inizializzare l'array di conteggio con tutti gli elementi impostati a zero: `[0, 0, 0, 0, 0, 0]`
2.  Contare il numero di volte che ogni valore appare nella sequenza, incrementando il valore corrispondente nell'array di conteggio: `[0, 2, 1, 2, 1, 2]`
3.  Calcolare la posizione in cui ogni elemento deve essere inserito nell'array ordinato, mantenendo un'indicizzazione cumulativa dell'array di conteggio: `[0, 2, 3, 5, 6, 8]`
4.  Inserire ogni elemento nella sua posizione corretta nell'array ordinato: `[1, 1, 2, 3, 3, 4, 5, 5]`

[_Torna all'indice_](#counting%20sort)

---

## Svantaggi
Nonostante il Counting Sort sia un algoritmo molto efficiente per alcune specifiche situazioni, ha anche alcuni svantaggi che limitano la sua applicabilità in altri contesti.

Ecco alcuni degli svantaggi del Counting Sort:
1. <mark style="background: #FF5582A6;">Limitato ad interi positivi:</mark> il Counting Sort può essere applicato solo a sequenze di numeri interi positivi. Questo significa che non è possibile utilizzarlo per ordinare sequenze di numeri negativi o con numeri in virgola mobile.
2. <mark style="background: #FF5582A6;">Richiede spazio extra:</mark> il Counting Sort richiede l'utilizzo di spazio extra per memorizzare l'array di conteggio. La dimensione di quest'ultimo dipende dall'intervallo di valori possibili nella sequenza. In altre parole, se l'intervallo di valori è molto grande, l'array di conteggio può diventare molto grande e richiedere una grande quantità di spazio di memoria.
3. <mark style="background: #FF5582A6;">Non adatto a sequenze con valori non uniformemente distribuiti:</mark> se la sequenza da ordinare contiene valori che non sono uniformemente distribuiti, l'array di conteggio potrebbe non essere sufficiente per gestire alcuni valori e quindi comportarsi in modo inefficiente. [Un esempio di questo caso.](obsidian://open?vault=ASD&file=laboratorio_6cfu%2Fdata%2Fpdf%2Fcounting_sort_caso_peggiore.pdf)
	In questi casi, sarebbe preferibile utilizzare altri algoritmi di ordinamento come il [Quicksort](03-quick_sort) o il [Merge Sort](02-merge_sort). 

[_Torna all'indice_](#counting%20sort)
