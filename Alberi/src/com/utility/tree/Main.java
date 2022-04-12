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

        BinaryTree bt2 = new BinaryTree();
        bt2.populateByUser();
        Node n2 = bt2.getRoot();

        u.print(bt.isEquals(n1, n2));
    }
}
