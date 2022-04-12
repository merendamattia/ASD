// Source: https://www.baeldung.com/java-binary-tree
package com.utility.tree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BinaryTree {

    private static Node root;

    /**
     * Getter
     * @return root
     */
    public Node getRoot() {
        return this.root;
    }

    // ------------------------ CONSTRUCTOR ------------------------
    /**
     * Constructor
     */
    public BinaryTree(){
        this.root = null;
    }
    /**
     * Constructor with a given root
     * @param root type Node
     */
    public BinaryTree(Node root){
        this.root = root;
    }

    // ------------------------ INPUT ------------------------
    /**
     * insertion of new nodes
     * if the new node's value is lower than the current node's, we go to the left child
     * if the new node's value is greater than the current node's, we go to the right child
     * when the current node is null, we've reached a leaf node and we can insert the new node in that position
     * @param current node
     * @param value of node
     * @return the node
     */
    private Node addRecursive(Node current, int value){
        if(current == null)
            return new Node(value);

        if(value < current.value)
            current.left = addRecursive(current.left, value);
        if(value > current.value)
            current.right = addRecursive(current.right, value);

        return current;
    }
    /**
     * starts the recursion from the root node
     * @param value of node
     */
    public void add(int value){
        this.root = addRecursive(root, value);
    }

    /**
     * Method to populate a tree
     */
    public void populateIncreasing(){
        for(int i = 0; i < 10; i++)
            add(i + 1);
    }
    public void populateDecreasing(){
        for(int i = 0; i < 10; i++)
            add(10 - i);
    }
    public void populateRandom(){
        for(int i = 0; i < 10; i++)
            add(Utility.getRandom(1, 10));
    }
    public void populateByUser(){
        int value;
        do{
            System.out.print("Inserire valore (<0 per terminare): ");
            Scanner sc = new Scanner(System.in);
            value = sc.nextInt();
            if(value >= 0)
                add(value);
        } while(value >= 0);
    }

    // ------------------------ OUTPUT ------------------------
    /**
     * depth-first search: in order
     * @param node
     */
    public void printInOrder(Node node){
        if(node != null){
            printInOrder(node.left);
            System.out.print(node.value + " ");
            printInOrder(node.right);
        }
    }
    /**
     * depth-first search: pre order
     * @param node
     */
    public void printPreOrder(Node node){
        if(node != null){
            System.out.print(node.value + " ");
            printPreOrder(node.left);
            printPreOrder(node.right);
        }
    }
    /**
     * depth-first search: post order
     * @param node
     */
    public void printPostOrder(Node node){
        if(node != null){
            printPostOrder(node.left);
            printPostOrder(node.right);
            System.out.print(node.value + " ");
        }
    }
    /**
     * Breadth-First Search
     * Visits all the nodes of a level before going to the next level.
     */
    public void printBFS(){
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

    /**
     * Dato un nodo, crea un array
     * @param node root
     * @param vet
     * @return array
     */
    private static ArrayList<Integer> getToArray(Node node, ArrayList<Integer> vet){
        if(node != null){
            vet = getToArray(node.left, vet);
            vet.add(node.value);
            vet = getToArray(node.right, vet);
        }

        return vet;
    }
    public static ArrayList<Integer> toArray(){
        ArrayList<Integer> vet = new ArrayList<Integer>(treeSize());
        return getToArray(root, vet);
    }

    // ------------------------ METHODS ------------------------
    /**
     * Verifica se un albero contiene un determinato valore
     * @param node tree's root
     * @param value to find
     * @return true se il valore è contenuto, false altrimenti
     */
    public static boolean contains(Node node, int value){
        if(node == null)
            return false;
        if(node.value == value)
            return true;
        else if(contains(node.left, value))
            return true;
        else if(contains(node.right, value))
            return true;
        else
            return false;
    }
    public boolean containsNode(int value) {
        return contains(root, value);
    }

    /**
     * getMin tree's value
     * @param node root
     * @param min
     * @return min
     */
    private static int getMin(Node node, int min){
        if(node == null)
            return min;
        if(node.value < min)
            min = node.value;
        int minLeft = getMin(node.left, min);
        int minRight = getMin(node.right, min);

        if(minLeft <= minRight)
            return minLeft;
        else
            return minRight;
    }
    public static int min(){
        return getMin(root, root.value);
    }

    /**
     * getMax tree's value
     * @param node root
     * @param max
     * @return max
     */
    private static int getMax(Node node, int max){
        if(node == null)
            return max;
        if(node.value > max)
            max = node.value;
        int maxLeft = getMax(node.left, max);
        int maxRight = getMax(node.right, max);

        if(maxLeft >= maxRight)
            return maxLeft;
        else
            return maxRight;
    }
    public static int max(){
        return getMax(root, root.value);
    }

    /**
     * Somma di tutti i valori dell'albero
     * @param node root
     * @return sum
     */
    private static int getSum(Node node){
        if(node != null)
            return node.value + getSum(node.left) + getSum(node.right);
        else
            return 0;
    }
    public static int sum(){
        return getSum(root);
    }

    /**
     * Ritorna il numero di quanti nodi sono presenti in un albero
     * @param node
     * @return
     */
    private static int getSize(Node node){
        if(node != null)
            return 1 + getSize(node.left) + getSize(node.right);
        else
            return 0;
    }
    public static int treeSize(){
        return getSize(root);
    }

    /**
     * Ritorna la media dei valori di un albero
     * @return
     */
    public static float average(){
        System.out.println(sum());
        System.out.println(treeSize());
        return (float) sum() / treeSize();
    }

    /**
     * Verifica se due alberi sono uguali (nodi nella stessa posizione)
     * @param other altro albero
     * @return true se sono uguali, false altrimenti
     */
    public static boolean isEquals(BinaryTree other){
        if(treeSize() != other.treeSize())
            return false;

        ArrayList<Integer> vet1 = toArray();
        ArrayList<Integer> vet2 = other.toArray();

        for(int i = 0; i < treeSize(); i++)
            if(vet1.get(i) != vet2.get(i))
                return false;

        return true;
    }

    /**
     * Serve per trovare, e in seguito eliminare i figli, i parenti che hanno figli foglie
     * @param node nodo corrente
     * @param parent padre del nodo corrente
     */
    public void findParentLeaves(Node node, Node parent){
        if(node != null) {
            if (node.right == null && node.left == null)
                deleteChildren(parent);
            if(node.left != null)
                findParentLeaves(node.left, node);
            if(node.right != null)
                findParentLeaves(node.right, node);
        }
    }

    /**
     * Elimina i figli di un nodo dato
     * @param node
     */
    private void deleteChildren(Node node) {
        node.left = null;
        node.right = null;
    }

    /**
     * Avvia le procedure per l'eliminazione delle foglie
     */
    public void deleteLeaves(){
        findParentLeaves(root.left, root);
        findParentLeaves(root.right, root);
    }

}