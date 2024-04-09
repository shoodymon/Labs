#pragma once

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

struct Node {
    int info;
    int height;
    Node* left;
    Node* right;
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* newNode(int info) {
        Node* node = new Node;
        node->info = info;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* insert(Node* node, int info) {
        if (node == nullptr)
            return newNode(info);

        if (info < node->info)
            node->left = insert(node->left, info);
        else if (info > node->info)
            node->right = insert(node->right, info);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && info < node->left->info)
            return rightRotate(node);

        if (balance < -1 && info > node->right->info)
            return leftRotate(node);

        if (balance > 1 && info > node->left->info) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && info < node->right->info) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


public:
    AVLTree() : root(nullptr) {}

    void insert(int info) {
        root = insert(root, info);
    }

    void showDirectOrder(Node* node, int indent) {
        if (node != nullptr) {
            cout << "\t\t\t\t" << setw(indent) << node->info << " (" << getBalance(node) << ")" << endl;
            showDirectOrder(node->left, indent + 6);
            showDirectOrder(node->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + 7) << "- nullptr" << endl;
        }
    }

    void showDirectOrder(int indent = 5) {
        if (root != nullptr) {
            cout << "\t\t\t\t" << setw(indent + 5) << root->info << " (" << getBalance(root) << ")" << endl;
            showDirectOrder(root->left, indent + 12);
            showDirectOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << endl;
        }
    }

    void showSymmetricalOrder(Node* node, int indent) {
        if (node != nullptr) {
            showSymmetricalOrder(node->left, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << node->info << " (" << getBalance(node) << ")" << endl;
            showSymmetricalOrder(node->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + 7) << "- nullptr" << endl;
        }
    }

    void showSymmetricalOrder(int indent = 5) {
        if (root != nullptr) {
            showSymmetricalOrder(root->left, indent + 12);
            cout << "\t\t\t\t" << setw(indent + 5) << root->info << " (" << getBalance(root) << ")" << endl;
            showSymmetricalOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << endl;
        }
    }

    void showReverseOrder(Node* node, int indent) {
        if (node != nullptr) {
            showReverseOrder(node->left, indent + 6);
            showReverseOrder(node->right, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << node->info << " (" << getBalance(node) << ")" << endl;
        }
        else {
            cout << "\t\t\t\t" << setw(indent + 7) << "- nullptr" << endl;
        }
    }

    void showReverseOrder(int indent = 5) {
        if (root != nullptr) {
            showReverseOrder(root->left, indent + 12);
            showReverseOrder(root->right, indent + 12);
            cout << "\t\t\t\t" << setw(indent + 5) << root->info << " (" << getBalance(root) << ")" << endl;
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << endl;
        }
    }
};
