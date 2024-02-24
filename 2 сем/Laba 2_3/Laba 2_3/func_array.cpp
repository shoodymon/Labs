#include "func_algorithm.h"

int get_arr_size() {
	int size_arr;
	cout << "¬ведите размер массива (не меньше 100): ";	cin >> size_arr;
	return size_arr;
}

vector<int> fill_arr_with_random(int size_arr) {
	vector<int> arr(size_arr);

	int seed = time(NULL);
	srand(seed);                            // инициализаци€ генератора случайных чисел
	/*
		„уть теории:
		√енератор "случайных" чисел в C/C++ rand на самом деле не случаен, а обычно задаетс€ формулой.
		Ќо формула при одних и тех-же значени€х даЄт естественно одинаковый результат.
		Ќачальное значение у этой формулы прин€то называть seed. “ак вот srand инициализирует этот seed определенным значением.
		Ќо нам нужно, чтобы был разный seed.

		» вот - time(NULL) - означает вз€ть текущее врем€. „то "решает" проблему генерировани€ разного seed.
	*/

	for (int i = 0; i < size_arr; i++) {
		arr[i] = rand() % 100;              // инициализаци€ случайными значени€ми от 0 до 99
	}

	return arr;
}

void print_arr(const vector<int>& arr) {
	cout << "—генерированный массив:\n";

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";

		// ѕереход на новую строку после каждых 10 элементов
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}

int get_user_input() {
	int value;
	cout << "¬ведите значение дл€ поиска: ";	cin >> value;
	return value;
}