package com.utility.tree;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinaryTree bt = new BinaryTree();
//        bt.populateRandom();
//        bt.populateIncreasing();
//        bt.populateDecreasing();
        bt.populateByUser();
        Node n1 = bt.getRoot();

        u.print(bt.findMaxWidth(n1));
    }
}
