#pragma once
#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;


class Stack {
	Node* top;
	int size;
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	void push(int info);
	void pop();
	int peek() const;
	void print();
};

enum class Stack_operation {
	ADD_VALUE = 1,
	REMOVE_VALUE,
	CLEAR_STACK,
	PRINT_STACK,
	EXIT
};