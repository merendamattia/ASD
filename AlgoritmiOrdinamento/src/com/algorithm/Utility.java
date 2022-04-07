package com.algorithm;

public class Utility {
    /**
     * Stampa a video un qualsiasi array di interi dato
     * @param vet array su cui lavorare
     */
    public static void printArray(int[] vet){
        for(int i = 0; i < vet.length; i++)
            System.out.print(vet[i] + " ");
        System.out.println("");
    }

    /**
     * Scambia il valore di due posizioni date in un array
     * @param vet array su cui lavorare
     * @param index1 indice del primo valore da scambiare
     * @param index2 indice del secondo valore da scambiare
     */
    public static void swap(int[] vet, int index1, int index2){
        int temp = vet[index1];
        vet[index1] = vet[index2];
        vet[index2] = temp;
    }
}
