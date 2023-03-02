# Insertion sort
1. [Pseudocodice](#pseudocodice)
2. [Analisi computazionale](#analisi%20computazionale)
3. [Caso peggiore](#caso%20peggiore%20o(n^2))
4. [Caso migliore](#caso%20migliore%20o(n))
5. [Recall notazione O](#recall%20notazione%20o)
6. [Recall invariante di ciclo](#recall%20invariante%20di%20ciclo)

## Pseudocodice
``` bash
for i=2 to lenght[A] do
	key = A[i]
	# Inserisce A[i] nella sequenza ordinata A[1 ... i-1]
	j = j-1
	while j>0 and A[j]>key do
			A[j+1] = A[j]
			j = j - 1
	A[j+1] = key
```

## Analisi computazionale
Nella soluzione non teniamo traccia del costo degli assegnamenti ma solo del numero di **letture/scritture** in memoria e di **operazioni** effettuate (confronti, somme, decrementi, $\ldots$ ). 

Contiamo il numero di *swap* e di *confronti/incrementi* che vengono eseguiti nel codice tramite due variabili globali: `ct_op` e `ct_swap`, inizializzate a `0`.

_[Ritorna all'indice](#insertion%20sort)_

## Caso peggiore $O(n^2)$
L'array $A$ è ordinato in senso decrescente.
`ct_op` e `ct_swap` a meno di una costante sono proporzionali a $n^2$ , infatti vengono eseguite
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

### _Curiosità storica_
La formula delle chiamate a `swap()` è la formula di _Gauss_ per la somma dei primi $n$ numeri naturali.

_[Ritorna all'indice](#insertion%20sort)_

## Caso migliore $O(n)$
L'array $A$ è già ordinato in senso crescente.
`ct_op` e `ct_swap` a meno di una costante sono proporzionali a $n$ (stesso ragionamento del precedente paragrafo).

_[Ritorna all'indice](#insertion%20sort)_

## Recall notazione $O$
$O(g(n))$ è l'insieme di tutte le funzioni $f(n)$ per cui esistono due costanti positive $c$ e $n_0$ tali che $f(n) ≤ c*g(n)$ per tutti gli $n≥n_0$. 

## Recall invariante di ciclo
L'invariante di ciclo è una proprietà che rimane invariata. Per far si che l'algoritmo sia corretto, dobbiamo verificare che questa proprietà sia valida all'inizio, alla fine di ogni iterazione e alla fine della funzione.