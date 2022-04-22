// Source: https://www.baeldung.com/java-binary-tree
package com.utility.tree;
import java.util.*;

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
    public static Node addRecursive(Node current, int value){
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
    public static void printInOrder(Node node){
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
    public static void printPreOrder(Node node){
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
    public static void printPostOrder(Node node){
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
    public static void printBFS(){
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

    /**
     * Dato un nodo, crea un array
     * @param node root
     * @param vet
     * @return array
     */
    private ArrayList<Integer> getToArray(Node node, ArrayList<Integer> vet){
        if(node != null){
            vet = getToArray(node.left, vet);
            vet.add(node.value);
            vet = getToArray(node.right, vet);
        }

        return vet;
    }
    public ArrayList<Integer> toArray(){
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
    public boolean contains(Node node, int value){
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
    public int getMin(Node node, int min){
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
    public int min(){
        return getMin(root, root.value);
    }

    /**
     * getMax tree's value
     * @param node root
     * @param max
     * @return max
     */
    public int getMax(Node node, int max){
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
    public int max(){
        return getMax(root, root.value);
    }

    /**
     * Somma di tutti i valori dell'albero
     * @param node root
     * @return sum
     */
    public int getSum(Node node){
        if(node != null)
            return node.value + getSum(node.left) + getSum(node.right);
        else
            return 0;
    }
    public int sum(){
        return getSum(root);
    }

    /**
     * Ritorna il numero di quanti nodi sono presenti in un albero
     * @param node
     * @return
     */
    public int getSize(Node node){
        if(node != null) return 1 + getSize(node.left) + getSize(node.right);
        return 0;
    }
    public int treeSize(){
        return getSize(root);
    }

    /**
     * Ritorna la media dei valori di un albero
     * @return
     */
    public float average(){
        System.out.println(sum());
        System.out.println(treeSize());
        return (float) sum() / treeSize();
    }

    /**
     * Verifica se due alberi dati sono uguali
     * @param node1 root primo albero
     * @param node2 root secondo albero
     * @return true se sono uguali, false altrimenti
     */
    public boolean verifyIsEquals(Node node1, Node node2){
        if(node1 == null && node2 == null) return true;
        if(node1 == null || node2 == null) return false;
        if(node1.value == node2.value)
            return verifyIsEquals(node1.left, node2.left) && verifyIsEquals(node1.right, node2.right);
        else return false;
    }
    public boolean isEquals(Node node1, Node node2){
        if(getSize(node1) == getSize(node2))
            return verifyIsEquals(node1, node2);
        else return false;
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

    /**
     * Serve per trovare, se esiste, il parente di un determinato nodo
     * @param node nodo corrente
     * @param parent padre del nodo corrente
     * @param value valore da cercare
     * @return parent's value
     */
    private Node findParentByValue(Node node, Node parent, int value){
        if(node != null) {
            if (node.value == value)
                return parent;
            if(node.left != null)
                return findParentByValue(node.left, node, value);
            if(node.right != null)
                return findParentByValue(node.right, node, value);
        }
        return null;
    }
    /**
     * Avvia la procedura e i controlli per trovare un parente di un nodo
     * dato il valore di quest'ultimo
     * @param value valore da cercare
     */
    public void findParent(int value){
        Node parent1 = findParentByValue(root.left, root, value);
        if(parent1 != null)
            System.out.println("Il padre ha valore: " + parent1.value);

        Node parent2 = findParentByValue(root.right, root, value);
        if(parent2 != null)
            System.out.println("Il padre ha valore: " + parent2.value);

        if(parent1 == null && parent2 == null)
            System.out.println("Parente non trovato");
    }

    /**
     * Calcola la profondità massima di uno qualsiasi dei nodi dell'albero
     * @param node nodo corrente
     * @return profondità
     */
    private int getDepth(Node node){
        if(node != null)
            return 1 + Math.max(getDepth(node.left), getDepth(node.right));
        return 0;
    }
    public void depth(){
        System.out.println("La profondità massima è: " + getDepth(root));
    }

    /**
     * Verifica se un albero è sottoalbero di un altro
     * @param node1 root primo albero
     * @param node2 root secondo albero
     * @return true se un albero è sottoalbero di un altro, false altrimenti
     */
    public boolean isASubTree(Node node1, Node node2){
        if(node2 == null) return true;
        if(node1 == null) return false;
        if(node1.value == node2.value)
            return isASubTree(node1.left, node2.left) && isASubTree(node1.right, node2.right);
        return isASubTree(node1.left, node2) || isASubTree(node1.right, node2);
    }

    /**
     * Source: https://algorithms.tutorialhorizon.com/find-the-maximum-width-of-a-binary-tree/
     * Data una radice, restituisce la larghezza massima di un albero
     * @param root
     * @return larghezza massima
     */
    public int findMaxWidth(Node root){
        int maxWidth = 0;
        int levelNodes = 0;
        Queue q = new LinkedList<>();
        if(root == null) return 0;
        q.add(root);

        while(!q.isEmpty()){
            levelNodes = q.size();

            if(levelNodes > maxWidth)
                maxWidth = levelNodes;

            while(levelNodes > 0){
                Node n = (Node) q.remove();
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
                levelNodes --;
            }
        }
        return maxWidth;
    }

    /* Lavori in corso
    private boolean hasOnlyAChild(Node node){
        if(node == null) return false;
        if(node.left != null && node.right != null) return false;
        if(node.left != null || node.right != null) return true;
        return false;
    }

    public void deleteBranch(Node node){
        if(node != null){
            if(node.left != null){
                if(getDepth(node.left) > 1)
                    deleteBranch(node.left);
                if(hasOnlyAChild(node.left))
                 ????
            }
            if(node.right != null){
                if(getDepth(node.right) > 1 && hasOnlyAChild(node.right))
                    deleteBranch(node.right);
            }
        }

    }
    */
}