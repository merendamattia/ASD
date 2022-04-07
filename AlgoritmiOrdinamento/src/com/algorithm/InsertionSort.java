package com.algorithm;

public class InsertionSort {
    public static void calcola(int [] vet){
        int cont = 0;
        int chiave, i;
        for(int j = 1; j < vet.length; j++){
            chiave = vet[j];
            i = j - 1;
            while(i >= 0 && vet[i] > chiave){
                vet[i + 1] = vet[i];
                i--;
            }
            vet[i + 1] = chiave;
        }
    }
}
