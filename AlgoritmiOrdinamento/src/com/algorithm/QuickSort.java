package com.algorithm;

public class QuickSort {
    public static int partition(int[] vet, int begin, int end){
        int pivot = vet[end];
        int i = begin - 1;
        for(int j = begin; j < end; j++)
            if(vet[j] <= pivot){
                i++;
                Utility.swap(vet, j, i);
            }
        Utility.swap(vet, i + 1, end);
        return i + 1;
    }

    public static void quicksort(int[] vet, int begin, int end){
        if(begin < end){
            int mid = partition(vet, begin, end);
            quicksort(vet, begin, mid - 1);
            quicksort(vet, mid + 1, end);
        }
    }

    /**
     * Nella prima chiamata bisogna fornire:
     * @param vet array di interi su cui lavorare
     * @param begin indice inizio -> 0
     * @param end indice di fine -> Dimendione array - 1
     */
    public static void calcola(int[] vet, int begin, int end){
        quicksort(vet, begin, end);
    }
}
