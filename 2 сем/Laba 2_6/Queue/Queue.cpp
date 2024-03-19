#include "Queue.h"


Queue::Queue() : front(nullptr), back(nullptr), size(0) {}


Queue::~Queue() {
    clear();
}


bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::enqueue(int info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }

    size++;
}

void Queue::dequeue() {
    if (!isEmpty()) {
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (front == nullptr) {
            back = nullptr;
        }
    }
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::print() {
    if (isEmpty()) {
        cout << "\n\tОчередь пуста!." << endl;
    }
    else {
        cout << "\n\tQueue: ";
        for (Node* current = front; current != nullptr; current = current->next) {
            cout << current->info << " ";
            if (current->next != nullptr)
                cout << "<--- ";
        }
        cout << endl;
    }
}
