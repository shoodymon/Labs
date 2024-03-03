#include "sort_functions.h"

void hoara_sort(vector<int>& arr, int first, int last, Actions& result) {
    int i = first, j = last;
    int pivot = arr.at((first + last) / 2); // Выбор опорного элемента посередине вектора

    do {
        // Поиск элемента в левой части, который больше или равен опорному
        while (arr.at(i) < pivot) {
            i++;
            result.comparisons++;
        }

        // Поиск элемента в правой части, который меньше или равен опорному
        while (arr.at(j) > pivot) {
            j--;
            result.comparisons++;
        }

        // Производим обмен элементов
        if (i <= j) {
            if (i < j) {
                swap(arr.at(i), arr.at(j));
                result.swaps++;
            }
            i++;
            j--;
        }
    } while (i <= j);

    // Рекурсивный вызов для сортировки правой части вектора
    if (i < last)
        hoara_sort(arr, i, last, result);

    // Рекурсивный вызов для сортировки левой части вектора
    if (first < j)
        hoara_sort(arr, first, j, result);
}

void hoara_sort_with_timer(vector<int>& arr, Actions& result) {
    steady_clock::time_point start_time = start_timer(); 
    hoara_sort(arr, 0, arr.size() - 1, result); 
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(arr);
    cout << "Время сортировки Хоара: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
}
