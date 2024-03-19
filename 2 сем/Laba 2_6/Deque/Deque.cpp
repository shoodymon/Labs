#include "Deque.h"

Deque::Deque() : front(nullptr), back(nullptr), size(0) {}

Deque::~Deque() {
    clear();
}

bool Deque::isEmpty() const {
    return front == nullptr;
}

void Deque::pushFront(int info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = front;
    newNode->prev = nullptr;

    if (isEmpty()) {
        back = newNode;
    }
    else {
        front->prev = newNode;
    }

    front = newNode;
    size++;
}

void Deque::pushBack(int info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;
    newNode->prev = back;

    if (isEmpty()) {
        front = newNode;
    }
    else {
        back->next = newNode;
    }

    back = newNode;
    size++;
}

void Deque::insert(int info, int position) {
    if (position < 0 || position > size) {
        cout << "\n\tНеверный индекс." << endl;
        return;
    }

    if (position == 0) {
        pushFront(info);
    }
    else if (position == size) {
        pushBack(info);
    }
    else {
        Node* newNode = new Node;
        newNode->info = info;

        Node* current = front;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }
}

void Deque::popFront() {
    if (!isEmpty()) {
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        else {
            back = nullptr;
        }
        delete temp;
        size--;
    }
}

void Deque::popBack() {
    if (!isEmpty()) {
        Node* temp = back;
        back = back->prev;
        if (back != nullptr) {
            back->next = nullptr;
        }
        else {
            front = nullptr;
        }
        delete temp;
        size--;
    }
}

void Deque::erase(int position) {
    if (isEmpty() || position < 0 || position >= size) {
        cout << "\n\tНеверный индекс." << endl;
        return;
    }

    if (position == 0) {
        popFront();
    }
    else if (position == size - 1) {
        popBack();
    }
    else {
        Node* current = front;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}

void Deque::clear() {
    while (!isEmpty()) {
        popFront();
    }
}

void Deque::print() {
    if (isEmpty()) {
        cout << "\n\tДек пуст." << endl;
    }
    else {
        cout << "\n\tDeque: ";
        for (Node* current = front; current != nullptr; current = current->next) {
            cout << current->info;
            if (current->next != nullptr) {
                cout << " <---> ";
            }
        }
        cout << endl;
    }
}