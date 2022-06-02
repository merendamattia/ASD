package com.algorithm;

public class Main {
    /**
     * Funzione Main su cui eseguire gli algoritmi di ordinamento
     * @param args
     */
    public static void main(String[] args) {
        //int[] vet = {2,3,8,1,9,4,6,5,7,0};          //caso medio
        int[] vet = {9,8,7,6,5,4,3,2,1,0};          //caso peggiore
        //int[] vet = {7,6,7,2,3,1,3,2,4};            //caso con ripetizioni

        System.out.print("Array non ordinato: ");
        Utility.printArray(vet);

//        System.out.println("Insertion Sort");
//        InsertionSort.calcola(vet);

//        System.out.println("Merge Sort");
//        MergeSort.calcola(vet, 0, vet.length - 1);

//        System.out.println("Bubble Sort");
//        BubbleSort.calcola(vet);

//        System.out.println("Quick Sort");
//        QuickSort.calcola(vet, 0, vet.length - 1);

        System.out.println("Counting Sort");
        CountingSort.calcola(vet);

//        System.out.println("Heap Sort");
//        HeapSort.calcola(vet);

        System.out.print("Array ordinato: ");
        Utility.printArray(vet);
    }
}
