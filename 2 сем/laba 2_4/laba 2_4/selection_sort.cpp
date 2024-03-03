#include "sort_functions.h"

void selection_sort(vector<int>& arr, int size, Actions& result) {
	steady_clock::time_point start_time = start_timer();

	for (int i = 0; i < size - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr.at(j) < arr.at(min_index)) {
				min_index = j;
				result.comparisons++;
			}
		}
		swap(arr.at(i), arr.at(min_index));
		result.swaps++;
	}

	steady_clock::time_point end_time = end_timer();
	cout << "Время сортировки выбором: " << duration_time(start_time, end_time) << " микросекунд" << endl;
	cout << "Сравнений: " << result.comparisons << endl;
	cout << "Перестановок: " << result.swaps << endl;
}
