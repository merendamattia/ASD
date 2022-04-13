package com.utility.tree;
import java.util.*;

public class BinarySearchTree {
    private static Node root;

    /**
     * Getter
     * @return root
     */
    public Node getRoot() {
        return this.root;
    }
    public int getRootValue() {
        return this.root.value;
    }

    // ------------------------ CONSTRUCTOR ------------------------
    /**
     * Constructor
     */
    public BinarySearchTree(){
        this.root = null;
    }
    /**
     * Constructor with a given value
     * @param value of first Node (root)
     */
    public BinarySearchTree(int value){
        this.root = new Node(value);
    }

    // ------------------------ INPUT ------------------------
    public void add(int value){
        root = BinaryTree.addRecursive(root, value);
    }
    public void populate(){
        add(50);
        add(30);
        add(70);
        add(20);
        add(40);
        add(80);
        add(60);
    }

    // ------------------------ OUTPUT ------------------------
    /**
     * depth-first search: in order
     */
    public static void printInOrder(){
        BinaryTree.printInOrder(root);
    }
    /**
     * depth-first search: pre order
     */
    public static void printPreOrder(){
        BinaryTree.printPreOrder(root);
    }
    /**
     * depth-first search: post order
     */
    public static void printPostOrder(){
        BinaryTree.printPostOrder(root);
    }
    /**
     * Breadth-First Search
     * Visits all the nodes of a level before going to the next level.
     */
    public static void printBFS(){
        if (root == null) return;

        Queue<Node> nodes = new LinkedList<>();
        nodes.add(root);

        while (!nodes.isEmpty()) {
            Node node = nodes.remove();

            System.out.print(node.value + " ");

            if (node.left != null)
                nodes.add(node.left);

            if (node.right != null)
                nodes.add(node.right);
        }
    }

    // ------------------------ METHODS ------------------------
    /**
     * Controlla se un dato valore è contenuto nell'albero
     * @param node nodo da cui far partire la ricerca
     * @param value valore da cercare
     * @return !null se esiste, null se non esiste
     */
    public Node search(Node node, int value){
        if(node == null || node.value == value)
            return node;
        if(value < node.value)
            return search(node.left, value);
        return search(node.right, value);
    }
    /**
     * Chiama la funzione search
     * @param value valore da cercare
     * @return true se esiste, false altrimenti
     */
    public boolean contains(int value){
        return search(root, value) != null;
    }

    /**
     * Trova il massimo valore dell'albero
     * @param node nodo da cui far partire la ricerca
     * @return massimo valore
     */
    public int max(Node node){
        int massimo = node.value;
        while(node != null){
            massimo = node.value;
            node = node.right;
        }
        return massimo;
    }
    /**
     * Trova il minimo valore dell'albero
     * @param node nodo da cui far partire la ricerca
     * @return minimo valore
     */
    public int min(Node node){
        int minimo = node.value;
        while(node != null){
            minimo = node.value;
            node = node.left;
        }
        return minimo;
    }

    /**
     * Cerca e in seguito elimina il nodo trovato
     * @param node interessato
     * @param value valore da cercare
     * @return la nuova root
     */
    public Node deleteRecursive(Node node, int value){
        if(node == null)
            return null;
        if(value < node.value)
            node.left = deleteRecursive(node.left, value);
        else if(value > node.value)
            node.right = deleteRecursive(node.right, value);
        else{
            if(node.left == null)
                return node.right;
            if(node.right == null)
                return node.left;
            node.value = min(node.right);
            node.right = deleteRecursive(node.right, node.value);
        }
        return node;
    }
    /**
     * Fa controlli preliminari e chiama la funzione deleteRecursive
     * @param value valore da ricercare
     */
    public void delete(int value){
        if(contains(value))
            root = deleteRecursive(root, value);
        else System.err.println("\nElemento non trovato! Impossibile eliminare.");
    }

}
