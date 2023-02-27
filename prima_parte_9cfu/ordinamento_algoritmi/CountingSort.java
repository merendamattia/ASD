package com.algorithm;

public class CountingSort {
    /**
     *
     * @param vet array su cui si deve lavorare
     */
    public static void calcola(int[] vet){
        int n = vet.length;

        int output[] = new int[n];

        int count[] = new int[256];
        for (int i = 0; i < 256; ++i)
            count[i] = 0;

        for (int i = 0; i < n; ++i)
            ++count[vet[i]];    //count[vet[i]] = count[vet[i]] + 1

        for (int i = 1; i <= 255; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[vet[i]] - 1] = vet[i];
            --count[vet[i]];    //count[vet[i]] = count[vet[i]] - 1
        }

        for (int i = 0; i < n; ++i)
            vet[i] = output[i];
    }
}
