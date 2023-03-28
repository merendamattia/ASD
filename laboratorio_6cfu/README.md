## Note sul calcolo della complessità 
La <mark style="background: #FFB86CA6;">complessità</mark> di un algoritmo può far riferimento a diversi tipi di fattori:
- letture/scritture in memoria
- operazioni aritmetico/logiche
- spazio occupato in memoria
- numero di chiamate a funzioni

Tipicamente, nelle soluzioni viste a lezione non teniamo traccia del costo degli assegnamenti (scelta personale) ma sommiamo il numero di **letture/scritture** in memoria e di **operazioni** effettuate (confronti, somme, decrementi, $\ldots$ ).

## Complessità algoritmi caso medio
- Insertion Sort: $O(n^2)$
- Merge Sort: $O\left({ n \cdot \log(n) }\right)$
- Quicksort: $O\left({ n \cdot \log(n) }\right)$
- Counting Sort: $O(n)$

---

## Recall notazione $O$
$O(g(n))$ è l'insieme di tutte le funzioni $f(n)$ per cui esistono due costanti positive $c$ e $n_0$ tali che $f(n) ≤ c*g(n)$ per tutti gli $n≥n_0$. 

## Recall invariante di ciclo
<mark style="background: #ABF7F7A6;">L'invariante di ciclo</mark> è una proprietà che rimane invariata. Per far si che l'algoritmo sia corretto, dobbiamo verificare che questa proprietà sia valida all'inizio, alla fine di ogni iterazione e alla fine della funzione.

> Altri appunti: _[merendamattia.com/uni](https://www.merendamattia.com/uni.html)_
