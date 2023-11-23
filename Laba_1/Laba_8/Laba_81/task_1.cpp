/*
		������� 1: ������������ ���������� ������  
	���������� ��������� ��������:
		- ������ � ������������ ����������� ������� (len);
		- �������� ������������� ����������� �������;
		- ���������� ������������ �������� �������;
		- ���������� ������������� �������� �������;
		- ���������� ���������� ��������� ����� ������������ � ����������� ���������� ��������� ��� ������ ����������.
	��� �������� ����������� ����� �������.

*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int get_array_size();
int* create_dynamic_array(int length);
int find_min_element(const int* arr, int length);
int find_max_element(const int* arr, int length);
int count_elements_between(const int* start_point, const int* end_point);

int main() {
	setlocale(0, "");

	int length = get_array_size();

	int* dyn_array = create_dynamic_array(length);

	cout << "������� ������: " << endl;

	for (int i = 0; i < length; i++) {
		cin >> dyn_array[i];
	}

	int min_element = find_min_element(dyn_array, length);
	cout << "����������� ������� - " << min_element << endl;

	int max_element = find_max_element(dyn_array, length);
	cout << "������������ ������� - " << max_element << endl;

	// ��������� �� min � max �������� �������
	int* ptr_min = dyn_array;
	int* ptr_max = dyn_array;

	// ��� ��� ������ ������� ��� ��������������� ��� ������� ����������� � ������������
	for (int i = 1; i < length; i++) {
		if (dyn_array[i] < *ptr_min)
			ptr_min = dyn_array + i;
		if (dyn_array[i] > *ptr_max)
			ptr_max = dyn_array + i;
	}

	int count = count_elements_between(ptr_min, ptr_max);
	cout << "��������� ����� - " << count << endl;

	delete[] dyn_array;

	return 0;
}

// ������ � ������������ ����������� ������� (len)
int get_array_size() {
	int length;
	cout << "������� ����������� �������: ";
	cin >> length;
	return length;
}

// �������� ������������� ����������� �������
int* create_dynamic_array(int length) {
	return new int[length];
}

// ���������� ������������ �������� �������
int find_min_element(const int* arr, int length) {
	int min_element = arr[0];

	for (int i = 1; i < length; ++i) {
		if (arr[i] < min_element)
			min_element = arr[i];
	}
	return min_element;
}

// ���������� ������������� �������� �������
int find_max_element(const int* arr, int length) {
	int max_element = arr[0];

	for (int i = 1; i < length; ++i) {
		if (arr[i] > max_element)
			max_element = arr[i];
	}
	return max_element;
}

/* ���������� ���������� ��������� ����� ������������ � ����������� ���������� ���������
	����� ������ �� �������� ���� ���������� (���� ��è�!)
*/
int count_elements_between(const int* start_point, const int* end_point) {
	return abs(start_point - end_point) - 1;
}
