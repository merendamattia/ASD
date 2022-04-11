package com.utility.tree;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinaryTree bt = new BinaryTree();
//        bt.populateRandom();
        bt.populateIncreasing();
//        bt.populateDecreasing();

        u.print("In Order");
        bt.printInOrder(bt.getRoot());
        Utility.endl();

        ArrayList<Integer> vet = bt.toArray();
        for (int i = 0; i < vet.size(); i++)
            System.out.print(vet.get(i) + " ");

    }
}
