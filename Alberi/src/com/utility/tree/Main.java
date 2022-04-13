package com.utility.tree;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinarySearchTree bst = new BinarySearchTree();
        bst.populate();

        bst.printBFS();

        u.endl();
        bst.delete(5);
        bst.printBFS();

    }
}
