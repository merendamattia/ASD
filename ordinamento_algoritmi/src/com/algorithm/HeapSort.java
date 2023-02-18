package com.algorithm;


public class HeapSort {
    /**
     * Ritorna il figlio sinistro
     * @param pos indice nodo
     * @return
     */
    private static int leftChild(int pos) {
        return (2 * pos) + 1;
    }
    /**
     * Ritorna il figlio destro
     * @param pos indice nodo
     * @return
     */
    private static int rightChild(int pos) {
        return (2 * pos) + 2;
    }

    // -------------------------------- METHODS --------------------------------
    /**
     * Verifica la condizione del max-heap sul nodo i.
     * Se non è verificata, esegue degli scambi affinchè la
     * condizione sia verificata.
     * @param i indice dell'array che rappresenta la posizione del nodo su cui lavorare
     */
    public static void maxHeapify(int[] arr, int n, int i) {
        int largest = i; // Initialize largest as root
        int l = leftChild(i);
        int r = rightChild(i);

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            Utility.swap(arr, i, largest);
            maxHeapify(arr, n, largest);
        }
    }

    /**
     * Costruisce un Heap da un array
     */
    public static void buildMaxHeap(int[] arr) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i);
    }

    /**
     * Heapsort: algoritmo di ordinamento degli heap
     * Source: https://www.geeksforgeeks.org/heap-sort/
     */
    public static void calcola(int[] arr){
        buildMaxHeap(arr);
        for(int i = arr.length - 1; i >= 0; i--){
            Utility.swap(arr, 0, i);
            maxHeapify(arr, i, 0);
        }
    }
}
