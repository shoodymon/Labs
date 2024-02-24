#include "func_algorithm.h"

int get_arr_size() {
	int size_arr;
	cout << "������� ������ ������� (�� ������ 100): ";	cin >> size_arr;
	return size_arr;
}

vector<int> fill_arr_with_random(int size_arr) {
	vector<int> arr(size_arr);

	int seed = time(NULL);
	srand(seed);                            // ������������� ���������� ��������� �����
	/*
		���� ������:
		��������� "���������" ����� � C/C++ rand �� ����� ���� �� �������, � ������ �������� ��������.
		�� ������� ��� ����� � ���-�� ��������� ��� ����������� ���������� ���������.
		��������� �������� � ���� ������� ������� �������� seed. ��� ��� srand �������������� ���� seed ������������ ���������.
		�� ��� �����, ����� ��� ������ seed.

		� ��� - time(NULL) - �������� ����� ������� �����. ��� "������" �������� ������������� ������� seed.
	*/

	for (int i = 0; i < size_arr; i++) {
		arr[i] = rand() % 100;              // ������������� ���������� ���������� �� 0 �� 99
	}

	return arr;
}

void print_arr(const vector<int>& arr) {
	cout << "��������������� ������:\n";

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";

		// ������� �� ����� ������ ����� ������ 10 ���������
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}

int get_user_input() {
	int value;
	cout << "������� �������� ��� ������: ";	cin >> value;
	return value;
}