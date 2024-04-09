#include <iostream>

#include "BinarySearchTree.h"

using namespace std;


int main() {
	setlocale(0, "");

	Tree tree;
	tree.add(5);
	tree.add(7);
	tree.add(4);
	tree.add(8);
	tree.add(2);
	tree.add(9);
	tree.add(1);
	tree.add(6);
	tree.add(3);

	//cout << "\n\t\t\t\t����� ������ ������ ���� (� ������ �������): A, B, C - ���������� �����: \n" << endl; tree.showDirectOrder();
	cout << "\n\t\t\t\t����� ������ � ������������ ������� (����� �������): B, A, C - ��������� �����: \n" << endl; tree.showSymmetricalOrder();
	//cout << "\n\t\t\t\t����� ������ � �������� ������� (����� �����): B, C, A - ����������� �����.: \n" << endl; tree.showReverseOrder();
}
