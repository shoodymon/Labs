/* ������� 4: 
	��������� 1: ����������� �������, ���������� (������������ ���������) ������� �������� ����� �����, ��������� ������� ������� �������� �*� � �������.
	*����� ������ ������������������ �� �������� �*� ���������� ����������� ������� �� ����� ������ (������� �\n� ��� std::endl) */

#include <iostream>
using namespace std;

void print_stars(int count_of_stars) {
	for (int i = 0; i < count_of_stars; i++) {
		cout << " * ";
	}
	cout << endl;
}

int main() {
	setlocale(0, "");
	
	int number_of_stars;

	cout << "������� ���������� ��������� ��� ������ : ";
	cin >> number_of_stars;

	if (number_of_stars < 0) {
		cout << "��������� ���. ������� ������������� �����! " << endl;
	} 
	else {
		print_stars(number_of_stars);
	}
	
	return 0;
}