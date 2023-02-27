package tree;
import java.util.*;

public class BinarySearchTree {
    private Node root;
    // Counter: variabile usata per il debug
    public int counter = 0;

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
    public void printInOrder(){
        BinaryTree.printInOrder(root);
    }
    /**
     * depth-first search: pre order
     */
    public void printPreOrder(){
        BinaryTree.printPreOrder(root);
    }
    /**
     * depth-first search: post order
     */
    public void printPostOrder(){
        BinaryTree.printPostOrder(root);
    }
    /**
     * Breadth-First Search
     * Visits all the nodes of a level before going to the next level.
     */
    public void printBFS(){
        if (root == null){
            System.err.println("Attenzione!! - Albero vuoto!");
            return;
        }

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
     * @param node nodo corrente
     * @return massimo valore presente nell'albero, -1 se l'albero è null
     */
    private int maxRecursive(Node node){
        if(node == null)
            return -1;
        if(node.right != null)
            return maxRecursive(node.right);
        return node.value;
    }
    public int max(){
        return maxRecursive(getRoot());
    }

    /**
     * Trova il minimo valore dell'albero
     * @param node nodo corrente
     * @return minimo valore presente nell'albero, -1 se l'albero è null
     */
    private int minRecursive(Node node){
        if(node == null)
            return -1;
        if(node.left != null)
            return minRecursive(node.left);
        return node.value;
    }
    public int min(){
        return minRecursive(getRoot());
    }

    /**
     * Conta quanti nodi sono presenti con un valore minore di quello fornito da utente
     * @param node nodo attuale
     * @param value valore da confrontare
     * @return il numero di nodi che rispettano la condizione
     */
    private int countMinThenRicorsive(Node node, int value){
        if(node == null)
            return 0;
        if(node.value < value)
            return 1 + countMinThenRicorsive(node.left, value) + countMinThenRicorsive(node.right, value);
        return countMinThenRicorsive(node.left, value);
    }
    public int countMinThen(int value){
        return countMinThenRicorsive(getRoot(), value);
    }

    /**
     * Conta quanti nodi sono presenti con un valore maggiore di quello fornito da utente
     * @param node nodo attuale
     * @param value valore da confrontare
     * @return il numero di nodi che rispettano la condizione
     */
    private int countMaxThenRicorsive(Node node, int value){
        if(node == null)
            return 0;
        if(node.value > value)
            return 1 + countMaxThenRicorsive(node.left, value) + countMaxThenRicorsive(node.right, value);
        return countMaxThenRicorsive(node.right, value);
    }
    public int countMaxThen(int value){
        return countMaxThenRicorsive(getRoot(), value);
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
            node.value = minRecursive(node.right);
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

    /**
     * Calcola la media dei valori dell'albero
     * effettuando il rapporto tra la somma e la dimensione
     * @return
     */
    public float average(){
        return (float) BinaryTree.getSum(getRoot()) / BinaryTree.getSize(getRoot());
    }

    /**
     * Calcola la media dei valori dell'albero
     * in modo ricorsivo con una sola funzione
     * @param node nodo su cui lavora
     * @return
     */
    private float averageRecursive(Node node){
        float l = 0, r = 0;
        int divisore = 1;

        if(node == null)
            return 0;
        if(node.left != null){
            l = averageRecursive(node.left);
            divisore++;
        }
        if(node.right != null){
            r = averageRecursive(node.right);
            divisore++;
        }

        return (node.value + l + r) / divisore;
    }
    public float averageRec(){
        return averageRecursive(getRoot());
    }
}
