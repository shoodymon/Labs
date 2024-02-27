#include "func_array.h"

/*
int get_arr_size() {
	int size_arr;
	cout << "Введите размер массива (не меньше 100): ";	cin >> size_arr;
	return size_arr;
} */

/*
vector<int> fill_arr_with_random(int size_arr) {
	vector<int> arr(size_arr);

	int seed = time(NULL);
	srand(seed);                            // инициализация генератора случайных чисел
	/*
		Чуть теории:
		Генератор "случайных" чисел в C/C++ rand на самом деле не случаен, а обычно задается формулой.
		Но формула при одних и тех-же значениях даёт естественно одинаковый результат.
		Начальное значение у этой формулы принято называть seed. Так вот srand инициализирует этот seed определенным значением.
		Но нам нужно, чтобы был разный seed.

		И вот - time(NULL) - означает взять текущее время. Что "решает" проблему генерирования разного seed.
	*/

/*
	for (int i = 0; i < size_arr; i++) {
		arr[i] = rand() % 100;              // инициализация случайными значениями от 0 до 99
	}

	return arr;
}
*/

/*
void print_arr(const vector<int>& arr) {
	cout << "\n\tСгенерированный массив:\n";

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";

		// Переход на новую строку после каждых 10 элементов
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}
*/

int get_user_input() {
	int value;
	cout << "Введите значение для поиска: ";	cin >> value;
	return value;
}

int get_key() {
	int key;
	cout << "Введите элемент для поиска: ";	cin >> key;
	return key;
}

int get_step() {
	int step;
	cout << "Введите размер шага: ";	cin >> step;
	return step;
}

int random(int min, int max){
	int number = min + rand() % (max - min + 1);
	return number;
}


void get_len_and_volume(vector<int> &arr,int &len, int &width) {
	cout << "Введите длину и ширину: ";
	cin >> len >> width;

	int volume = len * width;
	arr.resize(volume);
}

void fill_arr_with_random(vector<int>&arr,int &min, int &max) {
	cout << "Выберите диапазон рандомных чисел: ";
	cin >> min >> max;

	for (int index = 0; index < arr.size(); index++)
		arr[index] = random(min, max);
}

void print_arr(vector<int> const &arr, int len) {
	cout << "\n\tСгенерированный массив:\n\n\t";
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
