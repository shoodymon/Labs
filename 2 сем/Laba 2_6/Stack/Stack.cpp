#include "Stack.h"


Stack::Stack() : top(nullptr) {}


Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


bool Stack::isEmpty() const {
    return top == nullptr;
}


void Stack::push(int info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = top;
    top = newNode;
}


void Stack::pop() {
    if (!isEmpty()) {
        Node* buffer = top;
        top = top->next;
        delete buffer;
    }
}


int Stack::peek() const {
    return (!isEmpty()) ? top->info : -1;
}


void Stack::print() {

    std::string str = "";
    std::string cursor = " ---> ";
    std::string stdNullptr = "nullptr";

    std::cout << "\nStack: ";

    for (Node* buffer = top; buffer != nullptr; buffer = buffer->next) {
        std::cout << buffer->info << cursor;
    }

    std::cout << stdNullptr << std::endl;
}
