/*
		������� 3: ����������� ���������� � ��������
	�������� ������� ��� ����������, �� ������������ ��������, ��� ������ ������ ���������� �Good morning!�, 
	��� ������ � �Good afternoon!�, ��� ������� � �Good evening!�, ��� ��������� � ����� �Good morning!�, � ����� �� �����.
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
