// Source: https://www.geeksforgeeks.org/building-heap-from-array/
package com.utility.tree;

public class Heap {
    private static int[] arr;
    private static int size;

    /**
     * Costruttore
     * @param arr array non ordinato contenente valori nodi
     */
    public Heap(int arr[]){
        this.arr = arr;
        this.size = arr.length;
    }

    /**
     * Stampa a video Heap
     */
    public static void printHeap() {
        printHeapToArray();
        for(int i = 0; i < arr.length / 2; i++) {
            System.out.print("Parent Node: " + arr[i]);
            if (leftChild(i) < arr.length) //if the child is out of the bound of the array
                System.out.print("\n\tLeft Child: " + arr[leftChild(i)]);
            if (rightChild(i) < arr.length) //if the right child index must not be out of the index of the array
                System.out.print("\n\tRight Child: " + arr[rightChild(i)]);
            Utility.endl();
        }
        Utility.endl();
    }

    /**
     * Stampa a video Heap come array
     */
    public static void printHeapToArray(){
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

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
    public static void maxHeapify(int i) {
        int largest = i; // Initialize largest as root
        int l = leftChild(i);
        int r = rightChild(i);

        // If left child is larger than root
        if (l < size && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < size && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            Utility.swap(arr, i, largest);
            maxHeapify(largest);
        }
    }

    /**
     * Costruisce un Heap da un array
     */
    public static void buildMaxHeap() {
        int start = (size / 2) - 1;
        for (int i = start; i >= 0; i--)
            maxHeapify(i);
    }

    /**
     * Heapsort: algoritmo di ordinamento degli heap
     * Source: https://www.geeksforgeeks.org/heap-sort/
     */
    public void heapSort(){
        buildMaxHeap();
        for(int i = size - 1; i > 0; i--){
            Utility.swap(arr, 0, i);
            maxHeapify(0);
        }
    }
}
