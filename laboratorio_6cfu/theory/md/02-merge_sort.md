f# Merge sort
Questo algoritmo di ordinamento si basa sul metodo *"Divide et Impera"*: suddividiamo il problema principale in vari sottoproblemi, simili al problema originale, ma di dimensioni più piccole. Risolviamo questi problemi in modo ricorsivo. 

Sono presenti tre passi ad ogni livello di ricorsione:
1. ***Divide***: il problema viene diviso in un certo numero di sottoproblemi.
2. ***Impera***: i sottoproblemi vengono risolti in modo ricorsivo. Se i sottoproblemi hanno una dimensione sufficientemente piccola, possono essere risolti in maniera semplice.
3. ***Combina***: le soluzioni dei sottoproblemi vengono combinate per generare la soluzione delo problema originale.

## Pseudocodice
$\text{MERGE-SORT}(A,\,p,\,r):$
	**if** $p<r$ **then**
		$q \leftarrow \lfloor{ \frac{p+q}{2} }\rfloor$
		$\text{MERGE-SORT}(A,\,p,\,q)$
		$\text{MERGE-SORT}(A,\,q+1,\,r)$
		$\text{MERGE}(A,\,p,\,q,\,r)$

$\text{MERGE}(A,\,p,\,q,\,r):$
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

## Analisi computazionale
In tutti i casi la complessità è $O\left({ n \cdot \log(n) }\right)$.
==TODO: perchè?==
==TODO: fare osservazione con grafico real case - worst case==
se usiamo una dimensione con potenza di due ci avviciniamo al modello teorico perchè l'albero di ricorsione è binario