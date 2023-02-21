# Algoritmi di ordinamento 
In questa pagina verranno tracciati i tempi di esecuzione dei vari algoritmi di ordinamento.  

| Dimensione    | Insertion Sort    |
| ------------- | -------------     |
| 10            | 0,23              |
| 20            | 0,92              |
| 30            | 2,06              |
| 40            | 3,90              |
| 50            | 6,44              |
| 60            | 9,24              |
| 70            | 12,89             |
| 80            | 17,04             |
| 90            | 21,64             |
| 100           | 26,83             |
| 110           | 32,61             |
| 120           | 38,94             |
| 130           | 45,74             |
| 140           | 53,12             |
| 150           | 61,08             |

>La dimensione è in migliaia (es: dim = 10 -> dimensione array = 10.000).  
>I tempi sono calcolati in secondi.  
>L'array è popolato con elementi in ordine decrescente (es: dim = 5 -> array = [5, 4, 3, 2, 1]).

<p align="center">
    <img src="images/time_insertion_sort.png" width="60%">
</p>

### Complessità caso medio
- Insertion Sort: $O(n^2)$

---
_Disclaimer: questi tempi di esecuzione sono stati raccolti utilizzando una macchina con chip M2 (Apple)._