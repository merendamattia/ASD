# Insertion sort
```toc
```
---
*Insertion sort* è uno degli algoritmi di ordinamento più semplici, basato sui confronti.

## Pseudocodice
<!--
$\text{INSERTION-SORT}(A,\,n):$
	**for** $i \leftarrow 2$ **to** $\text{lenght}[A]$ **do**
		$\text{key} \leftarrow A[i]$ <br>
		// Inserisce A[i] nella sequenza ordinata A[1 ... i-1]
		$j \leftarrow j-1$
		**while** $j>0$ and $A[j]>key$ **do**
			$A[j+1] \leftarrow A[j]$
			$j \leftarrow j - 1$
		$A[j+1] \leftarrow \text{key}$
-->
![[insertion_pseudocodice.png | 450]]

## Analisi computazionale
Nella soluzione non teniamo traccia del costo degli assegnamenti ma solo del numero di **letture/scritture** in memoria e di **operazioni** effettuate (confronti, somme, decrementi, $\ldots$ ). 

Contiamo il numero di *swap* e di *confronti/incrementi* che vengono eseguiti nel codice tramite due variabili globali: `ct_op` e `ct_swap`, inizializzate a `0`.

_[Ritorna all'indice](#insertion%20sort)_

---

### Caso peggiore
L'array $A$ è ordinato in senso decrescente.
`ct_op` e `ct_swap`, a meno di una costante, sono proporzionali a $n^2$ , infatti vengono eseguite
$$	
	\sum_{i=0}^{n-1}{i} = 
	\sum_{i=1}^{n-1}{i} = 
	\frac{n \cdot (n-1)}{2} = O(n^2)
$$ 
chiamate a `swap()` e    
$$
	\sum_{i=0}^{n-1}{\left( 2 + 7i \right)} =
	\sum_{i=0}^{n-1}{2} + \sum_{i=1}^{n-1}{7i} =
	2n + \frac{7n \cdot (n-1)}{2} =
	\frac{n \cdot (7n - 3)}{2} = O(n^2)
$$ 
operazioni aritmetico-logiche.
Quindi la complessità nel caso perggiore è: $O(n^2)$.

#### Curiosità storica
La formula delle chiamate a `swap()` è la formula di _Gauss_ per la somma dei primi $n$ numeri naturali.

_[Ritorna all'indice](#insertion%20sort)_

---

### Caso migliore
L'array $A$ è già ordinato in senso crescente.
`ct_op` e `ct_swap` a meno di una costante sono proporzionali a $n$ (stesso ragionamento del precedente paragrafo).
Quindi la complessità nel caso migliore è: $O(n)$.

_[Ritorna all'indice](#insertion%20sort)_

---

## Animazioni

![[insertion_common.gif]]
![[insertion_worst.gif]]

_[Ritorna all'indice](#insertion%20sort)_

