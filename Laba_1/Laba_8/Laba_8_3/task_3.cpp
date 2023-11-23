/*
		Задание 3: Статические переменные в функциях
	Написать функцию без параметров, не возвращающую значения, при первом вызове печатающую «Good morning!», 
	при втором — «Good afternoon!», при третьем — «Good evening!», при четвертом — снова «Good morning!», и далее по циклу.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void hello();

int main() {
	setlocale(0, "");

	for (int i = 0; i < 10; i++)
		hello();

	return 0;
}

void hello() {
	static int count = 0;

	const char* hello_array[] = { "Good morning!", "Good afternoon!", "Good evening!" };

	const char* current_hello = hello_array[count % 3];

	cout << current_hello << endl;
	count++;
}
