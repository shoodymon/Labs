#include "sort_functions.h"

// Функция для слияния двух отсортированных подмассивов [left, middle] и [middle+1, right] в один отсортированный массив arr[left, right]
void merge(vector<int>& arr, int left, int middle, int right, Actions& result) {
    // Вычисляем размеры двух подмассивов
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // Создаем временные массивы для хранения левого и правого подмассивов
    vector<int> left_arr(size1), right_arr(size2);

    // Копируем данные из основного массива во временные массивы
    for (int i = 0; i < size1; i++)
        left_arr.at(i) = arr.at(left + i);
    for (int j = 0; j < size2; j++)
        right_arr.at(j) = arr.at(middle + 1 + j);

    // Индексы для обхода левого, правого и основного массивов
    int i = 0, j = 0, k = left;

    // Слияние двух временных массивов в один основной массив
    while (i < size1 && j < size2) {
        result.comparisons++;
        if (left_arr.at(i) <= right_arr.at(j)) {
            arr.at(k) = left_arr.at(i);
            i++;
            result.swaps++;
        }
        else {
            arr.at(k) = right_arr.at(j);
            j++;
            result.swaps++;
        }
        k++;
    }

    // Дописываем оставшиеся элементы из левого временного массива, если такие есть
    while (i < size1) {
        arr.at(k) = left_arr.at(i);
        i++;
        k++;
        result.swaps++;
    }

    // Дописываем оставшиеся элементы из правого временного массива, если такие есть
    while (j < size2) {
        arr.at(k) = right_arr.at(j);
        j++;
        k++;
        result.swaps++;
    }
}

// Функция сортировки слиянием
void merging_sort(vector<int>& arr, int len, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    int current_size;
    int left_start;

    // Цикл по подмассивам заданного размера
    for (current_size = 1; current_size <= len - 1; current_size = 2 * current_size) {
        // Цикл по подмассивам текущего размера
        for (left_start = 0; left_start < len - 1; left_start += 2 * current_size) {
            // Находим середину и конец правого подмассива
            int middle = min(left_start + current_size - 1, len - 1);
            int right_end = min(left_start + 2 * current_size - 1, len - 1);

            // Вызываем функцию слияния для текущих подмассивов
            merge(arr, left_start, middle, right_end, result);
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(arr);
    cout << "Время сортировки слиянием: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}
