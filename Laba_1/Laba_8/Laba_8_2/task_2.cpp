/*
		������� 2: ������������ ��������� ������  
	���������� ��������� ��������:
		- ������ � ������������ ����������� ������� (row, column);
		- �������� ������������� ���������� �������;
		- �������� ������������� ���������� ������� ������ ������ 2*row � ��������� ������������ � 
		  ������������� ���������� �� ����� ���������� �������;
		- ���������� ������������ �������� ����� ���� �������� ���������� �������;
		- ���������� ������������� �������� ����� ���� �������� ���������� �������;
		- ������� ������������������ ��������� ������.
	��� �������� ����������� ����� �������.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void get_array_size(int &row, int &column);
int** create_array(int row, int column);
void fill_array(int** arr, int row, int column);
void create_extended_array(int** arr, int row, int column, int** &extended_array);
int find_min_element(int** arr, int row, int column);
int find_max_element(int** arr, int row, int column);
int** create_transposed_array(int** arr, int row, int column);
void delete_array_clear_memory(int** arr, int row);
void print_array(int** arr, int row, int column);

int main() {
	setlocale(0, "");

	int row,column;

	get_array_size(row, column);

	int** arr = create_array(row, column);

	fill_array(arr, row, column);

	cout << "\n\t�������� ������: " << endl;
	print_array(arr, row, column);

	int** extended_array;

	create_extended_array(arr, row, column, extended_array);

	cout << "\n\t����������� ������: " << endl;
	print_array(extended_array, 2 * row, column);

	int min_value = find_min_element(arr, row, column);
	cout << "\n\t����������� ��������: " << min_value << endl;

	int max_value = find_max_element(arr, row, column);
	cout << "\n\t������������ ��������: " << max_value << endl;

	int** trans_array = create_transposed_array(arr, row, column);

	cout << "\n\t����������������� ������: " << endl;
	print_array(trans_array, column, row);

	delete_array_clear_memory(arr, row);
	delete_array_clear_memory(extended_array, 2 * row);
	delete_array_clear_memory(trans_array, column);

	return 0;
}

// ������ � ������������ ����������� ������� (row, column)
void get_array_size(int &row, int &column) {
	cout << "\t���������� �����: ";
	cin >> row;

	cout << "\n\t���������� ��������: ";
	cin >> column;
}

// �������� ������������� ���������� �������
int** create_array(int row, int column) {
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column];
	return arr;
}

// ���������� ������� 
void fill_array(int** arr, int row, int column) {
	cout << "\n\t������� �������� �������: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "\tarr[" << i+1 << "][" << j+1 << "] = ";
			cin >> arr[i][j];
		}
	}
}

/* �������� ������������� ���������� ������� ������ ������ 2 * row � ��������� ������������ � ������������� ���������� 
�� ����� ���������� ������� */
void create_extended_array(int** arr, int row, int column, int**& extended_array) {
	extended_array = new int* [2 * row];

	for (int i = 0; i < 2 * row; i++)
		extended_array[i] = new int[column];

	// ������� ����������� � ������������ �������� � ������ ������
	for (int i = 0; i < row; i++) {
		int min_value_in_row = arr[i][0];
		int max_value_in_row = arr[i][0];

		// ������� ����������� � ������������ �������� � ������� ������
		for (int j = 0; j < column; j++) {
			if (arr[i][j] < min_value_in_row)
				min_value_in_row = arr[i][j];
			if (arr[i][j] > max_value_in_row)
				max_value_in_row = arr[i][j];
		}

		// ��������� ����������� ������ ������������ � ������������� ����������
		for (int j = 0; j < column; ++j) {
			extended_array[i][j] = min_value_in_row;
			extended_array[row + i][j] = max_value_in_row;
		}
	}
}

// ���������� ������������ �������� ����� ����� ������� ��� ������ ���������
int find_min_element(int** arr, int row, int column) {
	int min_element = arr[0][0];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (arr[i][j] < min_element)
				min_element = arr[i][j];
		}
	}
	return min_element;
}

// ���������� ������������� �������� ����� ����� ������� ��� ������ ���������
int find_max_element(int** arr, int row, int column) {
	int max_element = arr[0][0];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (arr[i][j] > max_element)
				max_element = arr[i][j];
		}
	}
	return max_element;
}

// ������� ������������������ ������
int** create_transposed_array(int** arr, int row, int column) {
	int** trans_array = create_array(column, row);

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++)
			trans_array[i][j] = arr[j][i];
	}
	return trans_array;
}

// ������������ ������, ���������� ��� ������
void delete_array_clear_memory(int** arr, int row) {
	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
}

// ����� �������
void print_array(int** arr, int row, int column) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
