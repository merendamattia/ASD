package com.utility.tree;

import java.util.concurrent.ThreadLocalRandom;

public class Utility<T> {
    /**
     * Breaks a line
     */
    public static void endl(){
        System.out.println("");
    }

    /**
     * Breaks 2 line
     */
    public static void doubleEndl(){
        System.out.println("\n");
    }

    /**
     * Print generics text
     */
    public void print(T text){
        System.out.println(text);
    }

    /**
     * Generate a number with a range(from, to)
     * @param from begin range
     * @param to end range
     * @return integer generated
     */
    public static int getRandom(int from, int to){
        return ThreadLocalRandom.current().nextInt(from, to);
    }

    /**
     * Effettua lo swap dei valori di un array dati due indici di esso
     * @param arr
     * @param index1
     * @param index2
     */
    public static void swap(int[] arr, int index1, int index2) {
        int tmp;
        tmp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = tmp;
    }
}
