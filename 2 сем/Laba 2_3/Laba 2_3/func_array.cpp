#include "func_array.h"

/*
int get_arr_size() {
	int size_arr;
	cout << "������� ������ ������� (�� ������ 100): ";	cin >> size_arr;
	return size_arr;
} */

/*
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

/*
	for (int i = 0; i < size_arr; i++) {
		arr[i] = rand() % 100;              // ������������� ���������� ���������� �� 0 �� 99
	}

	return arr;
}
*/

/*
void print_arr(const vector<int>& arr) {
	cout << "\n\t��������������� ������:\n";

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";

		// ������� �� ����� ������ ����� ������ 10 ���������
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}
*/

int get_user_input() {
	int value;
	cout << "������� �������� ��� ������: ";	cin >> value;
	return value;
}

int get_key() {
	int key;
	cout << "������� ������� ��� ������: ";	cin >> key;
	return key;
}

int get_step() {
	int step;
	cout << "������� ������ ����: ";	cin >> step;
	return step;
}

int random(int min, int max){
	int number = min + rand() % (max - min + 1);
	return number;
}


void get_len_and_volume(vector<int> &arr,int &len, int &width) {
	cout << "������� ����� � ������: ";
	cin >> len >> width;

	int volume = len * width;
	arr.resize(volume);
}

void fill_arr_with_random(vector<int>&arr,int &min, int &max) {
	cout << "�������� �������� ��������� �����: ";
	cin >> min >> max;

	for (int index = 0; index < arr.size(); index++)
		arr[index] = random(min, max);
}

void print_arr(vector<int> const &arr, int len) {
	cout << "\n\t��������������� ������:\n\n\t";
	int counter = 0;
	for (int index = 0; index < arr.size(); index++) {
		if (counter == len) {
			cout << "\n\n\t";
			counter = 0;
		}

		if (arr[index] > 99)
			cout << arr[index] << "\t";
		else if (arr[index] > 9 and arr[index] < 100)
			cout << arr[index] << " \t";
		else if (arr[index] < 10)
			cout << " " << arr[index] << " \t";
		counter++;
	}
}
