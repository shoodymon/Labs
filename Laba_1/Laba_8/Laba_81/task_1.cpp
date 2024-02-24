/*
		Задание 1: Динамический одномерный массив  
	Реализуйте следующие действия:
		- запрос у пользователя размерности массива (len);
		- создание динамического одномерного массива;
		- нахождение минимального элемента массива;
		- нахождение максимального элемента массива;
		- нахождения количества элементов между максимальным и минимальным элементами массивами при помощи указателей.
	Все действия реализовать через функции.

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

	cout << "Enter an array: " << endl;

	for (int i = 0; i < length; i++) {
		cin >> dyn_array[i];
	}

	cout << "Minimum element - " << find_min_element(dyn_array, length) << endl;
	cout << "Maximum element - " << find_max_element(dyn_array, length) << endl;

	// указатели на min и max элементы вручную
	int* ptr_min = dyn_array;
	int* ptr_max = dyn_array;

	// так как первый элемент уже рассматривается как текущий минимальный и максимальный
	for (int i = 1; i < length; i++) {
		if (dyn_array[i] < *ptr_min)
			ptr_min = dyn_array + i;
		if (dyn_array[i] > *ptr_max)
			ptr_max = dyn_array + i;
	}

	cout << "Elements between - " << count_elements_between(ptr_min, ptr_max) << endl;

	delete[] dyn_array;

	return 0;
}

// запрос у пользователя размерности массива (len)
int get_array_size() {
	int length;
	cout << "Enter the dimension of the array:";
	cin >> length;
	return length;
}

// создание динамического одномерного массива
int* create_dynamic_array(int length) {
	return new int[length];
}

// нахождение минимального элемента массива
int find_min_element(const int* arr, int length) {
	int min_element = arr[0];

	for (int i = 1; i < length; ++i) {
		if (arr[i] < min_element)
			min_element = arr[i];
	}
	return min_element;
}

// нахождение максимального элемента массива
int find_max_element(const int* arr, int length) {
	int max_element = arr[0];

	for (int i = 1; i < length; ++i) {
		if (arr[i] > max_element)
			max_element = arr[i];
	}
	return max_element;
}

/* нахождение количества элементов между максимальным и минимальным элементами массивами
	ЧЕРЕЗ МОДУЛЬ ОТ РАЗНОСТИ ДВУХ УКАЗАТЕЛЕЙ (ВЛАД МОГЁТ!)
*/
int count_elements_between(const int* start_point, const int* end_point) {
	return abs(start_point - end_point) - 1;
}
