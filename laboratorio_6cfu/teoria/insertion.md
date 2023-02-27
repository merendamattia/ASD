## Pseudocodice insection sort


insection-sort(A) <br>&nbsp;&nbsp;&nbsp;&nbsp; 
    for j = 2 to A.lenght do<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        key = A[j] <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        //inserisce A[j] nella sequenza ordinata A[1..j-1]<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        i = j - 1 <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        while i > 0 and A[i] > key do<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        A[i + 1] = A[i] <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        i = i - 1 <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        end while<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        A[i + 1] = key<br>&nbsp;&nbsp;&nbsp;&nbsp;
        end for

<br><br>
### Nozioni importanti

- È importante saper utilizzare correttamente le stampe a schermo all'interno del codice, per riuscire ad essere in grado di svolgere un buon debugging. Però non bisogna eccedere con le stampe presenti, perché quantitativo eccessivo comporta solo confusione.
- Per una buona dimostrazione sulla correttezza di un algoritmo sono necessari molti test
- È molto importate la rappresentazione e la visualizzazione di un algoritmo per riuscire a comprendere al meglio il suo funzionameto

### Cosa rappresenta la complessità?

La complessità può essere relativa a molte informazioni del programma, quante, quali e come tenerne conto dipende dal criterio di **scelta** che viene ritenuto più opportuno, alcuni esempi di informazioni che possono essere tenute in considerazione possono essere:
- accessi in memoria, sia letture che scritture, comunemente il costo di queste operazioni è di 1, ma in modelli rari il costo può essere maggiore, questa dipende dalla dimensio dei dati e dalla capacità di trasferimento del bus.
- operazioni elementari effettuate, le operazioni effettuate dalla ALU.
- chiamate di funzione, questa informazione risulta molto interessante se calcolata nel caso di funzioni ricorsive

