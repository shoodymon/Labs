/* ��������� 2: ����������� �������, ���������� (������������ ���������) ������� �������� ����� �����, ��������� ����� ������� �������� ������� �� �������� �*� � �������.
		������: 
			Input Size: 4
			Print:
				****
				****
				****
				****
*/

#include <iostream>
using namespace std;

void print_square(int size_of_square) {
	for (int i = 0; i < size_of_square; i++) {
		for (int j = 0; j < size_of_square; j++) {
			cout << " * ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(0, "");

	int size_of_square;
	cout << "������� ������ �������� --> ";
	cin >> size_of_square;

	if (size_of_square <= 0) {
		cout << "������ �������� �� ����� ���� ������������� " << endl;
	}

	print_square(size_of_square);

	return 0;

}