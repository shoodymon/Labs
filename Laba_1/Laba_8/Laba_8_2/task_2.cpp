/*
		Задание 2: Динамический двумерный массив  
	Реализуйте следующие действия:
		- запрос у пользователя размерности массива (row, column);
		- создание динамического двумерного массива;
		- создание динамического двумерного массива длиною равной 2*row и заполнить минимальными и 
		  максимальными значениями из строк двумерного массива;
		- нахождение минимального элемента среди всех значений двумерного массива;
		- нахождение максимального элемента среди всех значений двумерного массива;
		- создать транспортированный двумерный массив.
	Все действия реализовать через функции.
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

	cout << "\n\tИсходный массив: " << endl;
	print_array(arr, row, column);

	int** extended_array;

	create_extended_array(arr, row, column, extended_array);

	cout << "\n\tРасширенный массив: " << endl;
	print_array(extended_array, 2 * row, column);

	int min_value = find_min_element(arr, row, column);
	cout << "\n\tМинимальное значение: " << min_value << endl;

	int max_value = find_max_element(arr, row, column);
	cout << "\n\tМаксимальное значение: " << max_value << endl;

	int** trans_array = create_transposed_array(arr, row, column);

	cout << "\n\tТранспонированный массив: " << endl;
	print_array(trans_array, column, row);

	delete_array_clear_memory(arr, row);
	delete_array_clear_memory(extended_array, 2 * row);
	delete_array_clear_memory(trans_array, column);

	return 0;
}

// запрос у пользователя размерности массива (row, column)
void get_array_size(int &row, int &column) {
	cout << "\tКоличество строк: ";
	cin >> row;

	cout << "\n\tКоличество столбцов: ";
	cin >> column;
}

// создание динамического двумерного массива
int** create_array(int row, int column) {
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column];
	return arr;
}

// заполнение массива 
void fill_array(int** arr, int row, int column) {
	cout << "\n\tВведите элементы массива: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "\tarr[" << i+1 << "][" << j+1 << "] = ";
			cin >> arr[i][j];
		}
	}
}

/* создание динамического двумерного массива длиною равной 2 * row и заполнить минимальными и максимальными значениями 
из строк двумерного массива */
void create_extended_array(int** arr, int row, int column, int**& extended_array) {
	extended_array = new int* [2 * row];

	for (int i = 0; i < 2 * row; i++)
		extended_array[i] = new int[column];

	// Находим минимальное и максимальное значения в каждой строке
	for (int i = 0; i < row; i++) {
		int min_value_in_row = arr[i][0];
		int max_value_in_row = arr[i][0];

		// Находим минимальное и максимальное значения в текущей строке
		for (int j = 0; j < column; j++) {
			if (arr[i][j] < min_value_in_row)
				min_value_in_row = arr[i][j];
			if (arr[i][j] > max_value_in_row)
				max_value_in_row = arr[i][j];
		}

		// Заполняем расширенный массив минимальными и максимальными значениями
		for (int j = 0; j < column; ++j) {
			extended_array[i][j] = min_value_in_row;
			extended_array[row + i][j] = max_value_in_row;
		}
	}
}

// нахождение минимального элемента среди всего массива при помощи указателя
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

// нахождение максимального элемента среди всего массива при помощи указателя
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

// создать транспортированный массив
int** create_transposed_array(int** arr, int row, int column) {
	int** trans_array = create_array(column, row);

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++)
			trans_array[i][j] = arr[j][i];
	}
	return trans_array;
}

// освобождение памяти, выделенной под массив
void delete_array_clear_memory(int** arr, int row) {
	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
}

// принт массива
void print_array(int** arr, int row, int column) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
