#pragma once

#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;


enum class Deque_operation {
    PUSH_FRONT = 1,
    PUSH_BACK,
    INSERT,
    POP_FRONT,
    POP_BACK,
    ERASE,
    CLEAR_DEQUE,
    PRINT_DEQUE,
    EXIT
};

class Deque {
    Node* front;
    Node* back;
    int size;

public:
    Deque();
    ~Deque();
    bool isEmpty() const;
    void pushFront(int info);
    void pushBack(int info);
    void insert(int info, int position);
    void popFront();
    void popBack();
    void erase(int position);
    void clear();
    void print();
};
