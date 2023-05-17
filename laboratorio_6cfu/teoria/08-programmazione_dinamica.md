# Programmazione Dinamica
```toc
```
---

## Che cos'è?
La programmazione dinamica è una tecnica utilizzata per risolvere problemi complessi scomponendoli in una serie di sottoproblemi più piccoli e risolvendo o memorizzando le soluzioni dei sottoproblemi per ottenere la soluzione finale del problema originale. 

L'approccio si basa sull'idea di sfruttare la ricorrenza dei sottoproblemi e di evitare di risolverli ripetutamente, ma piuttosto di memorizzare i loro risultati e riutilizzarli quando necessario.

## Memoization
La programmazione dinamica è molto importante perché consente di risolvere efficientemente problemi complessi che altrimenti richiederebbero un tempo di esecuzione esponenziale o combinatoriale. Attraverso la scomposizione dei problemi in sottoproblemi più piccoli, la programmazione dinamica permette di ridurre il tempo di esecuzione utilizzando la tecnica del <mark style="background: #BBFABBA6;">*"memoization"*</mark> (ovvero memorizzazione dei risultati dei sottoproblemi) o utilizzando tabelle per memorizzare i risultati intermedi.

Ci sono diversi aspetti chiave che caratterizzano l'approccio della programmazione dinamica:
1.  <mark style="background: #ABF7F7A6;">Sottoproblemi sovrapposti:</mark> I problemi complessi possono essere scomposti in una serie di sottoproblemi più piccoli che si sovrappongono. Ciò significa che i sottoproblemi condividono la stessa struttura ricorsiva e possono essere risolti una volta sola e i risultati possono essere memorizzati per essere riutilizzati in futuro.

2.  <mark style="background: #FFB8EBA6;">Proprietà di sottostruttura ottima:</mark> La soluzione ottima di un problema globale può essere ottenuta combinando le soluzioni ottime dei sottoproblemi associati. Ciò implica che, una volta determinata la soluzione ottima di un sottoproblema, non è necessario riesaminarlo in seguito.

3.  <mark style="background: #FFB86CA6;">Ordine di calcolo:</mark> La soluzione dei sottoproblemi deve essere calcolata in un ordine specifico, in modo che i sottoproblemi necessari siano già stati risolti quando si calcola la soluzione di un determinato sottoproblema.

[_Torna all'indice_](#Programmazione%20Dinamica)

---

## Esempio classico - Fibonacci
La sequenza di Fibonacci è fatta nel seguente modo:
- $fib(1) = 1$
- $fib(2) = 1$
- $fib(3) = fib(2) + fib(1)$
- $fib(n) = fib(n-2) + fib(n - 1) \;=\; fib(n-2) + fib(n - 2) + fib(n - 3) \;= \;\cdots$

Come si può notare, osservando la definizione ricorsiva, avremo più ripetizione di chiamate. Di conseguenza avremo una complessità esponenziale: $O(n!)$.

Rappresentazione in $C$++:
```cpp
int fib(int n) {
	if(n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
```

Applicando il principio di _"Memoization"_, otterremo la seguente versione modificata:
```cpp
int V[n]; // Utilizzo una struttura dati di appoggio, inizializzato a `0`

int fib(int n) {	
	if (V[n] != 0)
		return V[n];
	
	int res = 0; // non conosco la risposta
	
	if (n <= 2)
		res = 1;
	else
		res = fib(n - 1) + fib(n - 2);
	
	V[n] = res;

	return res;
}
```

In questo modo, avremo una complessità lineare: $O(n)$.

> Esempio pratico con `n = 30`:
> Numero di accessi alla funzione senza *Memoization*: `1664079`
> Numero di accessi alla funzione con *Memoization*: `57`

[_Torna all'indice_](#Programmazione%20Dinamica)

---

## Levenshtein Distance
La Levenshtein Distance, nota anche come distanza di edit o distanza di editing, è una misura della differenza tra due stringhe di caratteri. Misura il numero minimo di operazioni necessarie per trasformare una stringa nella seconda stringa, dove le operazioni consentite sono l'inserimento di un carattere, la cancellazione di un carattere o la sostituzione di un carattere.

Immagina di avere due parole, ad esempio "casa" e "cane". La distanza di Levenshtein tra queste due parole è 2, perché devi sostituire la "s" con la "n" e aggiungere una "e" alla fine per ottenere la seconda parola.

Questo concetto è utile in diverse situazioni. Ad esempio, può aiutare a correggere gli errori di battitura o a confrontare testi per trovare parole simili. Viene anche utilizzato nella bioinformatica per confrontare sequenze di DNA.

L'algoritmo che calcola la distanza di Levenshtein confronta le lettere delle due parole e calcola il numero minimo di operazioni necessarie per trasformare una parola nell'altra. Può essere calcolato utilizzando una matrice e confrontando i valori nelle posizioni corrispondenti. Alla fine, il valore nella parte inferiore destra della matrice rappresenterà la distanza di Levenshtein tra le due parole.

> Approfondimento su [Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance).

[_Torna all'indice_](#Programmazione%20Dinamica)