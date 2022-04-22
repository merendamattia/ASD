package com.utility.tree;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinarySearchTree bst = new BinarySearchTree();
        bst.populate();

        bst.printBFS();

        u.endl();
        //u.print(bst.media(bst.getRoot()));
        u.print(bst.countMaxThen(90));
        u.print(bst.max());
    }
}
