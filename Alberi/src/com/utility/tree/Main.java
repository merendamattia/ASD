package com.utility.tree;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinaryTree bt = new BinaryTree();
//        bt.populateRandom();
        bt.populateIncreasing();
//        bt.populateDecreasing();
//        bt.populateByUser();

        u.print("In Order");
        bt.printInOrder(bt.getRoot());
        Utility.endl();

        bt.findParent(12);


    }
}
