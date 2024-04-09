#include "AVL-tree.h"

int main() {
    setlocale(0, "");
    AVLTree tree;

    cout << "\t\n\n\nМое дерево: \n\n" << endl;

    tree.insert(6);
    tree.insert(3);
    tree.insert(0);
    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(4);

    tree.showSymmetricalOrder();

    AVLTree tree2;
    cout << "\t\n\n\nДерево Артура: \n\n" << endl;
    tree2.insert(2);
    tree2.insert(1);
    tree2.insert(0);
    tree2.insert(4);
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(3);

    tree2.showSymmetricalOrder();

    return 0;
}
