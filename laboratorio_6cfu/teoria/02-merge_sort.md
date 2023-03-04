# Merge sort
```toc
```
--- 

Il Merge Sort si basa sul metodo *"Divide et Impera"*: suddividiamo il problema principale in vari sottoproblemi, simili al problema originale, ma di dimensioni più piccole. Risolviamo questi problemi in modo ricorsivo. 

Il modello teorico del Merge Sort può essere descritto come segue:
1. <mark style="background: #FFF3A3A6;">Divide:</mark> la lista non ordinata viene divisa in due parti uguali, o quasi uguali, fino a quando ogni parte non può più essere divisa in parti più piccole.
2. <mark style="background: #FFF3A3A6;">Impera:</mark> ordina ricorsivamente ogni parte divisa utilizzando lo stesso algoritmo Merge Sort, continuando a dividere ogni parte in parti sempre più piccole e ordinandole fino a quando non si può più dividere ulteriormente.
3. <mark style="background: #FFF3A3A6;">Combina:</mark> unisce le due parti ordinate per creare una nuova lista ordinata. Questa operazione di unione viene eseguita utilizzando un'operazione di confronto tra gli elementi della lista, prendendo il valore più piccolo di ogni lista e aggiungendolo alla nuova lista ordinata, fino a quando tutti gli elementi della lista originale non sono stati inseriti nella nuova lista ordinata.

_[Torna all'indice](#merge%20sort)_

---

## Pseudocodice
$\text{Merge-Sort}(A,\,p,\,r):$
	**if** $p<r$ **then**
		$q \leftarrow \lfloor{ \frac{p+q}{2} }\rfloor$
		$\text{Merge-Sort}(A,\,p,\,q)$
		$\text{Merge-Sort}(A,\,q+1,\,r)$
		$\text{Merge}(A,\,p,\,q,\,r)$

$\text{Merge}(A,\,p,\,q,\,r):$
	$n_1 \leftarrow q-p+1$
	$n_2 \leftarrow r-q$
	$\text{crea gli array } L[1 \dots n_1+1] \text{ e } R[1 \dots n_2+1]$ <br>
	**for** $i \leftarrow 1$ **to** $n_1$
		**do** $L[i] \leftarrow A[p+i-1]$
	**for** $j \leftarrow 1$ **to** $n_2$
		**do** $R[j] \leftarrow A[q+j]$
	$L[n_1+1] \leftarrow \infty$
	$R[n_2+1] \leftarrow \infty$ <br>
	$i \leftarrow 1$
	$j \leftarrow 1$
	**for** $k \leftarrow p$ **to** $r$ **do**
		**if** $L[i] \leq R[j]$ **then**
			$A[k] \leftarrow L[i]$
			$i \leftarrow i+1$
		**else**
			$A[k] \leftarrow R[j]$
			$j \leftarrow j+1$

_[Torna all'indice](#merge%20sort)_

---

## Analisi computazionale
- <mark style="background: #FFB86CA6;">Tempo di esecuzione:</mark> il Merge Sort ha un tempo di esecuzione medio e peggiore dei casi di $O\left({ n \cdot \log(n) }\right)$. Questo significa che il tempo di esecuzione dell'algoritmo cresce in modo logaritmico rispetto alla dimensione dell'input. Questa complessità di tempo rende il Merge Sort un algoritmo efficiente per ordinare grandi quantità di dati.
- <mark style="background: #FFB86CA6;">Spazio di memoria:</mark> il Merge Sort richiede un'area di memoria ausiliaria per la fase di unione delle liste divise, in cui si memorizzano temporaneamente gli elementi ordinati. L'area di memoria ausiliaria richiesta dall'algoritmo è di $O(n)$, dove $n$ rappresenta la lunghezza della lista da ordinare. Ciò significa che l'algoritmo richiede un quantitativo di memoria aggiuntiva proporzionale alla dimensione dell'input.

Di seguito il grafico che mette a confronto il <mark style="background: #ADCCFFA6;">numero di comparazioni medie</mark> e il <mark style="background: #FF5582A6;">numero delle comparazioni nel modello teorico nel caso peggiore</mark> (_worst case_: array ordinato in ordine decrescente).
![[merge_worst_avg.png]]

Possiamo notare che in alcuni punti il numero di comparazioni medie supera il numero delle comparazioni nel modello teorico nel caso peggiore. Se mettiamo in un grafico la differenza di questi valori (`avg_cmp - worst_case_cmp`) otteniamo il seguente risultato:

![[merge_differenze.png]]

### Perchè otteniamo questo grafico?
Il modello teorico del Merge Sort si basa su un <mark style="background: #BBFABBA6;">albero di ricorsione binario</mark>, in cui ogni nodo ha esattamente due figli. Questo modello si basa sul fatto che ogni lista viene suddivisa in due parti uguali, e ogni parte viene ordinata e unita insieme. Il tempo di esecuzione dell'algoritmo cresce in modo logaritmico rispetto alla dimensione dell'input, il che lo rende uno degli algoritmi di ordinamento più efficienti.

Tuttavia, se la dimensione della lista da ordinare non è una potenza di due, il processo di divisione della lista in parti più piccole potrebbe non essere bilanciato e simmetrico, il che potrebbe comportare una maggiore complessità dell'algoritmo e un tempo di esecuzione peggiore rispetto al modello teorico.

Invece, se la dimensione della lista da ordinare è una potenza di due (si <mark style="background: #FF5582A6;">noti</mark> nel nostro caso che la curva si avvicina a 0 laddove la dimensione dell'array si avvicina a una potenza del due), il processo di divisione della lista in parti più piccole si svolge in modo bilanciato e simmetrico. Ciò crea un albero di ricorsione binario, che corrisponde al <mark style="background: #FFB8EBA6;">modello teorico del Merge Sort</mark>.

Quindi, in <mark style="background: #FFB86CA6;">sintesi</mark>, se usiamo una dimensione della lista da ordinare che è una potenza di due, il processo di divisione della lista sarà bilanciato e simmetrico, il che si avvicina di più al modello teorico del Merge Sort e rende l'algoritmo più efficiente.

_[Torna all'indice](#merge%20sort)_


### Caso peggiore
![[worst_merge.gif]]
### Caso medio
![[common_merge.gif]]

_[Torna all'indice](#merge%20sort)_