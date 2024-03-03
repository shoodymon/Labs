#include "sort_functions.h"

void shell_sort(vector<int>& arr, int size, Actions& result) {
	steady_clock::time_point start_time = start_timer();

	for (int step = size / 2; step > 0; step /= 2) {
		for (int i = step; i < size; i++) {
			for (int j = i; j >= step && arr.at(j - step) > arr.at(j); j -= step) {
				swap(arr[j], arr[j - step]);
				result.swaps++;
				result.comparisons++;
			}
		}
	}

	steady_clock::time_point end_time = end_timer();
	cout << "Время сортировки Шелла: " << duration_time(start_time, end_time) << " микросекунд" << endl;
	cout << "Сравнений: " << result.comparisons << endl;
	cout << "Перестановок: " << result.swaps << endl;
}