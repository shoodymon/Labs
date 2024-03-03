#include "sort_functions.h"

void shaker_sort(vector<int>& arr, int size, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        if (!swapped) // Если не было перестановок, то массив уже отсортирован
            break;

        swapped = false;

        // Уменьшаем правую границу
        --end;

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        // Увеличиваем левую границу
        ++start;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(arr);
    cout << "Время шейкерной сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
}
