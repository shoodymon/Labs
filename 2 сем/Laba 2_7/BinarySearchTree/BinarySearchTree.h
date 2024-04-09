#pragma once

#include <iostream> 
#include <iomanip> // Включение стандартной библиотеки для манипуляций с выводом

using std::cout;
using std::endl;
using std::setw;

struct Node {
    int info;
    Node* left = nullptr;
    Node* right = nullptr;
};

/*
Обход дерева сверху вниз (в прямом порядке): A, B, C - префиксная форма.
Обход дерева в симметричном порядке (слева направо): B, A, C - инфиксная форма.
Обход дерева в обратном порядке (снизу вверх): B, C, A - постфиксная форма.
*/

/*
void treeprint(tnode* tree) {
  if (tree != NULL) { //Пока не встретится пустой узел
    cout << tree->field; //Отображаем корень дерева
    treeprint(tree->left); //Рекурсивная функция для левого поддерева
    treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}

void treeprint(tnode* tree) {
  if (tree != NULL) { //Пока не встретится пустой узел
    treeprint(tree->left); //Рекурсивная функция для левого поддерева
    cout << tree->field; //Отображаем корень дерева
    treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}

void treeprint(tnode* tree) {
  if (tree != NULL) { //Пока не встретится пустой узел
    treeprint(tree->left); //Рекурсивная функция для левого поддерева
    treeprint(tree->right); //Рекурсивная функция для правого поддерева
    cout << tree->field; //Отображаем корень дерева
  }
}

*/

class Tree {

    Node* root = nullptr; // Указатель на корневой узел

public:

    Tree() {
        cout << "\t\t\t\tДерево создано :)" << endl;
    }

    Tree(int root) {
        this->root = new Node; // Создание нового корневого узла
        this->root->info = root; // Присвоение значению корневого узла
    }

    ~Tree() {
        dell(root);
        cout << "\n\t\t\t\tДерево удалено :(" << endl;
    }

    void add(int info) {
        if (root == nullptr) {
            root = new Node; // Создание нового корневого узла
            root->info = info; // Присвоение значению корневого узла
        }
        else {
            root = add(info, root); // Добавление узла
        }
    }

    Node* add(int info, Node* tree) {
        // Рекурсивное добавление узла в дерево
        if (tree == nullptr) {
            tree = new Node;
            tree->info = info;
        }
        else  if (info < tree->info) tree->left = add(info, tree->left);
        else  if (info > tree->info) tree->right = add(info, tree->right);
        else cout << "\t\t\t\tПовторилось, " << info << " уже есть." << endl;

        return tree;
    }

    // Методы удаления узлов из дерева
    void dell(Node* tree) {
        // Рекурсивное удаление узлов из дерева
        if (tree != nullptr) {
            dell(tree->left);
            dell(tree->right);
            delete tree; // Удаление текущего узла
            tree = nullptr;
        }
    }

    void dell(int info, Node* tree, Node* tree_pred, char leftOrRight) {
        // Удаление узла по значению
        if (tree == nullptr) {
            cout << "\t\t\t\tУдаление невозможно, элемент отсутствует :(" << endl;
        }
        else {
            if (info == tree->info) {
                dell(tree->left);
                dell(tree->right);
                delete tree;

                switch (leftOrRight) {
                case 'l': tree_pred->left = nullptr; break;
                case 'r': tree_pred->right = nullptr; break;
                default: cout << "\t\t\t\tError."; break;
                }
            }
            else if (info < tree->info) dell(info, tree->left, tree, 'l');
            else if (info > tree->info) dell(info, tree->right, tree, 'r');
            else cout << "\t\t\t\tError." << endl;
        }
    }

    void dell(int info) {
        // Удаление узла по значению
        if (root == nullptr) {
            cout << "\t\t\t\tУдаление невозможно, 0 узлов :(" << endl;
        }
        else {
            if (info == root->info) {
                dell(root->left);
                dell(root->right);
                delete root;
                root = nullptr;
            }
            else if (info < root->info) dell(info, root->left, root, 'l');
            else if (info > root->info) dell(info, root->right, root, 'r');
            else cout << "\t\t\t\tError." << endl;
        }
    }

    bool search(int info) {
        if (root == nullptr) {
            return false;
        }
        else if (info == root->info) {
            return true;
        }
        else if (info < root->info) return search(info, root->left);
        else if (info > root->info) return search(info, root->right);
        else cout << "\t\t\t\tError." << endl;
    }

    bool search(int info, Node* tree) {
        if (tree == nullptr) {
            return false;
        }
        else if (info == tree->info) {
            return true;
        }
        else if (info < tree->info) return search(info, tree->left);
        else if (info > tree->info) return search(info, tree->right);
        else cout << "\t\t\t\tError." << endl;
    }

    void showDirectOrder(Node* tree, int indent) {

        if (tree != nullptr) {
            cout << "\t\t\t\t" << setw(indent) << tree->info << /*" " << tree << " " << tree->left << " " << tree->right <<*/ endl;
            showDirectOrder(tree->left, indent + 6);
            showDirectOrder(tree->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + 7) << "- nullptr" << endl;
        }
    }

    void showDirectOrder(int indent = 5) {

        if (root != nullptr) {
            cout << "\t\t\t\t" << setw(indent + 5) << root->info << /*" " << root << " " << root->left << " " << root->right <<*/ endl;
            showDirectOrder(root->left, indent + 12);
            showDirectOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << endl;
        }
    }

    void showSymmetricalOrder(Node* tree, int indent) {

        if (tree != nullptr) {
            showSymmetricalOrder(tree->left, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << tree->info << /*" " << tree << " " << tree->left << " " << tree->right <<*/ endl;
            showSymmetricalOrder(tree->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + 7) << "- nullptr" << endl;
        }
    }

    void showSymmetricalOrder(int indent = 5) {

        if (root != nullptr) {
            showSymmetricalOrder(root->left, indent + 12);
            cout << "\t\t\t\t" << setw(indent + 5) << root->info << /*" " << root << " " << root->left << " " << root->right <<*/ endl;
            showSymmetricalOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << endl;
        }
    }

    void showReverseOrder(Node* tree, int indent) {

        if (tree != nullptr) {
            showReverseOrder(tree->left, indent + 6);
            showReverseOrder(tree->right, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << tree->info << /*" " << tree << " " << tree->left << " " << tree->right <<*/ endl;
        }
        else {
            cout << "\t\t\t\t" << setw(indent + 7) << "- nullptr" << endl;
        }
    }

    void showReverseOrder(int indent = 5) {

        if (root != nullptr) {
            showReverseOrder(root->left, indent + 12);
            showReverseOrder(root->right, indent + 12);
            cout << "\t\t\t\t" << setw(indent + 5) << root->info << /*" " << root << " " << root->left << " " << root->right <<*/ endl;
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << endl;
        }
    }

};
