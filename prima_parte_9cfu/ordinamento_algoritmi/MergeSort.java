package com.algorithm;

public class MergeSort {
    public static void merge(int[] arr, int begin, int mid, int end) {
        int n1 = mid - begin + 1;
        int n2 = end - mid;

        int[] L = new int[n1];
        int[] M = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[begin + i];
        for (int j = 0; j < n2; j++)
            M[j] = arr[mid + 1 + j];

        // Maintain current index of sub-arrays and main array
        int i = 0, j = 0, k = begin;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2) {
            if (L[i] <= M[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = M[j];
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = M[j];
            j++;
            k++;
        }
    }

    public static void mergeSort(int[] vet, int begin, int end){
        if(begin < end){
            int mid = (begin + end) / 2;
            mergeSort(vet, begin, mid);
            mergeSort(vet, mid + 1, end);
            merge(vet, begin, mid, end);
        }
    }

    /**
     * Nella prima chiamata bisogna fornire:
     * @param vet array di interi su cui lavorare
     * @param begin indice inizio -> 0
     * @param end indice di fine -> Dimendione array - 1
     */
    public static void calcola(int[] vet, int begin, int end){
        mergeSort(vet, begin, end);
    }
}
