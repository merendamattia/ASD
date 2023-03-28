# Ricerca Binaria
```toc
```
---
## Pseudocodice
```cpp
bool binary_search(int *A, int n, int t) {
	int left = 0;
	int right = n - 1;

	while (left <= r) {
		int mid = (left + right) / 2;
		if (A[mid] < t)
			left = mid + 1;
		else if (A[mid] > t)
			right = mid - 1;
		else
			return true; // trovato
	}
	return false; // non trovato
}
```
> $t:$ elemento da cercare
> $n:$ dimensione array

## Che cos'è?
<mark style="background: #BBFABBA6;">La ricerca binaria è un algoritmo di ricerca che viene utilizzato per trovare un elemento all'interno di un insieme ordinato di elementi.</mark> Questo algoritmo è molto efficiente e ha una complessità logaritmica.

## Come funziona?
<mark style="background: #FFB86CA6;">Il principio alla base della ricerca binaria è di dividere ripetutamente l'insieme in due parti uguali e di eliminare la metà dell'insieme in cui l'elemento cercato non può trovarsi.</mark> Ciò viene fatto confrontando l'elemento cercato con l'elemento nel mezzo dell'insieme. Se l'elemento cercato è uguale all'elemento nel mezzo dell'insieme, allora la ricerca è terminata. In caso contrario, si restringe l'intervallo di ricerca a una delle due metà dell'insieme, a seconda che l'elemento cercato sia maggiore o minore dell'elemento nel mezzo dell'insieme. Questo processo viene ripetuto finché l'elemento cercato non viene trovato o finché l'intervallo di ricerca non si riduce a zero.

### Esempio
Per esempio, se si vuole cercare un numero all'interno di un array ordinato di numeri, si può iniziare prendendo l'elemento nel mezzo dell'array e confrontarlo con il numero cercato. Se il numero cercato è maggiore dell'elemento nel mezzo, si può ignorare la metà inferiore dell'array e ripetere la ricerca sulla metà superiore dell'array. Se invece il numero cercato è minore dell'elemento nel mezzo, si può ignorare la metà superiore dell'array e ripetere la ricerca sulla metà inferiore dell'array. Si continua a ripetere questo processo finché non si trova l'elemento cercato o finché l'intervallo di ricerca si riduce a zero.
[Un esempio grafico reale (pdf)](obsidian://open?vault=ASD&file=laboratorio_6cfu%2Fdata%2Fpdf%2Fricerca_binaria_esempio.pdf)

## Efficienza
<mark style="background: #ABF7F7A6;">La ricerca binaria è molto efficiente rispetto ad altri algoritmi di ricerca, in quanto riduce drasticamente il numero di elementi che devono essere confrontati. </mark>
Ad esempio, in un array di un milione di elementi, la ricerca binaria richiede al massimo 20 confronti per trovare un elemento ($log_2(1000000) \cong 19,9$), mentre una ricerca lineare richiederebbe fino a un milione di confronti. Questo rende la ricerca binaria particolarmente utile per grandi insiemi di dati ordinati.

[_Torna all'indice_](#ricerca%20binaria)