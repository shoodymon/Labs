/* Реализовать функцию, параметром (передаваемым значением) которой является целое число, говорящее какой шириной выводить квадрат из чисел в консоле.
		Пример: 
			Input Size: 4
			Print:
				1 3 5 7 
				9 11 13 15
				17 19 21 23
				25 27 29 31
*/

#include <iostream>
using namespace std;

void print_number_square(int size_of_square) {
	int number = 1;
	for (int i = 0; i < size_of_square; i++) {
		for (int j = 0; j < size_of_square; j++) {
			cout << number << " ";
			number += 2;
		}
		cout << endl;
	}
}

int main() {
	setlocale(0, "");

	int size_of_square;
	cout << "Введите размер квадрата --> ";
	cin >> size_of_square;

	if (size_of_square <= 0) {
		cout << "Размер квадрата не может быть отрицательным " << endl;
	}

	print_number_square(size_of_square);

	return 0;

}