#include <iostream>

#include "BinarySearchTree.h"

using namespace std;


int main() {
	setlocale(0, "");

	Tree tree;
	tree.add(41);
	tree.add(20);
	tree.add(11);
	tree.add(29);
	tree.add(32);
	tree.add(65);
	tree.add(50);
	tree.add(91);
	tree.add(72);
	tree.add(99);

	//cout << "\n\t\t\t\tОбход дерева сверху вниз (в прямом порядке): A, B, C - префиксная форма: \n" << endl; tree.showDirectOrder();
	cout << "\n\t\t\t\tОбход дерева в симметричном порядке (слева направо): B, A, C - инфиксная форма: \n" << endl; tree.showSymmetricalOrder();
	//cout << "\n\t\t\t\tОбход дерева в обратном порядке (снизу вверх): B, C, A - постфиксная форма.: \n" << endl; tree.showReverseOrder();

	cout << "\n\t\t\t\tБинарное дерево поиска после удаления элементов:\n" << endl;

	tree.erase(20);
	tree.erase(65);
	tree.showSymmetricalOrder();

	cout << tree.search(50) << endl;
	cout << tree.search(20) << endl;
	cout << tree.search(11) << endl;
}
