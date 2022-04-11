package com.utility.tree;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinaryTree bt = new BinaryTree();
        bt.populateRandom();
//        bt.populateIncreasing();
//        bt.populateDecreasing();

        u.print("In Order");
        bt.printInOrder(bt.getRoot());
        Utility.endl();

        u.print(bt.sum());
        u.print(bt.size());
        u.print(bt.average());

    }
}
