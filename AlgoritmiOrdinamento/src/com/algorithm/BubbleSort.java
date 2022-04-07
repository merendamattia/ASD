package com.algorithm;

public class BubbleSort {
    public static void calcola(int[] vet){
        for(int i = 0; i < vet.length; i++)
            for(int j = vet.length - 1; j > i; j--)
                if(vet[j] < vet[j - 1])
                    Utility.swap(vet, j, j - 1);
    }
}
