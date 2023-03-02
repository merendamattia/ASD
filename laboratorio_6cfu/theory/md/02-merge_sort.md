# Merge sort
Questo algoritmo di ordinamento si basa sul metodo *"Divide et Impera"*: suddividiamo il problema principale in vari sottoproblemi, simili al problema originale, ma di dimensioni più piccole. Risolviamo questi problemi in modo ricorsivo. 

Sono presenti tre passi ad ogni livello di ricorsione:
1. ***Divide***: il problema viene diviso in un certo numero di sottoproblemi.
2. ***Impera***: i sottoproblemi vengono risolti in modo ricorsivo. Se i sottoproblemi hanno una dimensione sufficientemente piccola, possono essere risolti in maniera semplice.
3. ***Combina***: le soluzioni dei sottoproblemi vengono combinate per generare la soluzione delo problema originale.

## Pseudocodice
==TODO: da aggiungere==

## Analisi computazionale
In tutti i casi la complessità è $O(n*logn)$
==TODO: perchè?==
==TODO: fare osservazione con grafico real case - worst case==
se usiamo una dimensione con potenza di due ci avviciniamo al modello teorico perchè l'albero di ricorsione è binario