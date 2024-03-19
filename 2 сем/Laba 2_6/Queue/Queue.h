#pragma once
#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;


enum class Queue_operation {
    ADD_VALUE = 1,
    REMOVE_VALUE,
    CLEAR_QUEUE,
    PRINT_QUEUE,
    EXIT
};

class Queue {
    Node* front;
    Node* back;
    int size;

public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    void enqueue(int info);
    void dequeue();
    void clear();
    void print();
};

