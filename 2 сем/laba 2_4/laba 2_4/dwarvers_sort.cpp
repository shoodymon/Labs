#include "sort_functions.h"

void dwarves_sort(vector<int>& arr, int size, Actions& result) {
	steady_clock::time_point start_time = start_timer();

	int index = 0;  while (index < size) {
		if (index == 0)
			index++;
		if (arr[index] >= arr[index - 1]) {
			index++;
			result.comparisons++;
		}
		
		else {
			swap(arr[index], arr[index - 1]);
			index--;
			result.swaps++;
		}
	}

	steady_clock::time_point end_time = end_timer();
	cout << "Время гномьей сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
	cout << "Сравнений: " << result.comparisons << endl;
	cout << "Перестановок: " << result.swaps << endl;
}