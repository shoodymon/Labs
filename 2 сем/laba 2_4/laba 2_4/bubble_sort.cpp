#include "sort_functions.h"

void bubble_sort(vector<int>& arr, int size, Actions& result) {
	steady_clock::time_point start_time = start_timer();

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			result.comparisons++;
			if (arr.at(j) > arr.at(j + 1)) {
				swap(arr.at(j), arr.at(j + 1));
				result.swaps++;
			}
		}
	}

	steady_clock::time_point end_time = end_timer();
	cout << "Время пузырьковой сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
	cout << "Сравнений: " << result.comparisons << endl;
	cout << "Перестановок: " << result.swaps << endl;
}
