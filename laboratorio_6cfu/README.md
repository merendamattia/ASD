## Note sul calcolo della complessità 
La **complessità** di un algoritmo può far riferimento a diversi tipi di fattori:
- letture/scritture in memoria
- operazioni aritmetico/logiche
- spazio occupato in memoria
- numero di chiamate a funzioni

Tipicamente, nelle soluzioni viste a lezione non teniamo traccia del costo degli assegnamenti (scelta personale) ma sommiamo il numero di **letture/scritture** in memoria e di **operazioni** effettuate (confronti, somme, decrementi, $\ldots$ ).

## Complessità algoritmi caso medio
- Insertion Sort: $O(n^2)$
- Merge Sort: $O\left({ n \cdot \log(n) }\right)$

---

## Recall notazione O
$O(g(n))$ è l'insieme di tutte le funzioni $f(n)$ per cui esistono due costanti positive $c$ e $n_0$ tali che $f(n) ≤ c*g(n)$ per tutti gli $n≥n_0$. 

## Recall invariante di ciclo
L'invariante di ciclo è una proprietà che rimane invariata. Per far si che l'algoritmo sia corretto, dobbiamo verificare che questa proprietà sia valida all'inizio, alla fine di ogni iterazione e alla fine della funzione.

---

# Wiki 
Ecco un semplice elenco di linee guida da seguire per partecipare alla stesura degli appunti e per mantenere il codice il più ordinato e leggibile possibile.
1. Per visualizzare bene gli appunti utilizzeremo _Obsidian_: software che permette di prendere appunti che opera su file Markdown `.md`. La preview che si vede su Github può risultare incompleta o non leggibile.
2. Plugin utilizzati su _Obsidian_:
	- [table-editor-obsidian](https://github.com/tgrosinger/advanced-tables-obsidian)
	- [highlightr-plugin](https://github.com/chetachiezikeuzor/Highlightr-Plugin)
	- [obsidian-dynamic-toc](https://github.com/aidurber/obsidian-plugin-dynamic-toc)
3. Effettuare un `git fork` della repository in questione, nella quale poi si andranno a modificare / aggiungere appunti
4. Effettuare sempre un `git fetch` e successivamente un `git pull` prima di qualsiasi `git push` e/o `git commit`
5. Non utilizzare caratteri in stampato e caratteri speciali nel nome dei file
6. Utilizzare il carattere `_` al posto degli "spazi" nel nome dei file
7. Utilizzare sempre la numerazione dei file nel nome (i numeri indicano l'ordine degli argomenti trattati a lezione) 
8. Nel file `.md` inserire sempre un indice dinamico (utilizzando il plugin) e un "ritorna all'indice" alla fine di ogni paragrafo / argomento
9. Nel titolo dei `commit` e della  `pull request`, oltre ad inserire il tema trattato, aggiungere anche il proprio username. Ad esempio il titolo di questa `pull request` sarà: `Aggiornamento wiki (@merendamattia)`

### Esempio 
Il primo argomento trattato a lezione è stato quello del significato di _"Hello, world!"_.
Il nome file sarà: `01-helloworld.md`.
Il titolo del commit sarà: `"Aggiunti appunti lezione 01-helloworld @merendamattia"`.
Il titolo della pull request sarà: `"Appunti lezione 26-02-2023 @merendamattia"`.

> Altri appunti: _[merendamattia.com/uni](https://www.merendamattia.com/uni.html)_
