#include "sort_functions.h"

void inserts_sort(vector<int>& arr, int size, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int i = 1; i < size; i++) {
        int key = arr.at(i);
        int j = i - 1;
        while (j >= 0 && arr.at(j) > key) {
            arr.at(j + 1) = arr.at(j);
            j--;
            result.comparisons++;
            result.swaps++;
        }
        arr.at(j + 1) = key;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(arr);
    cout << "Время сортировки вставками: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
}
