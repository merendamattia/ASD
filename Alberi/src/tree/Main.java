package tree;

public class Main {
    public static void main(String[] args) {
        Utility u = new Utility();

        BinarySearchTree bst = new BinarySearchTree();
        bst.populate();

        bst.printBFS();

        u.endl();

        u.print(bst.average());
        u.print(bst.averageRec());
    }
}
