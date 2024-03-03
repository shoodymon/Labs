#include "laba_4.h"

/*
void recursive_sort(vector<int>& arr, int left, int right) {
    int pivot; // разрешающий элемент
    int index; // индекс разрешающего элемента
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = arr.at(left);

    // пока границы не сомкнутся
    while (left < right) {
        while ((arr.at(right) > pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]

        // если границы не сомкнулись
        if (left != right) {
            arr.at(left) = arr.at(right); // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }

        while ((arr.at(left) < pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]

        // если границы не сомкнулись
        if (left != right) { 
            arr.at(right) = arr.at(left); // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу влево
        }
    }

    arr.at(left) = pivot; // ставим разрешающий элемент на место
    index = left;
    left = l_hold;
    right = r_hold;

    if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
        recursive_sort(arr, left, index - 1);
    if (right > index)
        recursive_sort(arr, index + 1, right);
} 
*/

int find_min_index(vector<int> arr, int left, int right, Actions& result) {
    int min_index = left; // Предполагаем, что минимальный элемент - это arr[i]

    // Идем по оставшимся элементам и обновляем min_index, если находим элемент меньше текущего минимального
    for (int k = left + 1; k < right; k++) {
        result.comparisons++;
        if (arr[k] < arr[min_index]) {
            min_index = k;
        }
    }

    return min_index;
}

void recursive_sort(vector<int> arr, int size, bool is_sorted, int index, Actions& result) {
    //steady_clock::time_point start_time = start_timer();

    int min_index = 0;

    // Выводим массив, когда index и size будут одинаковыми
    if (index == size) {
        is_sorted = true;
        return;
    }

    // Вызов функции min_index для получения минимального индекса
    min_index = find_min_index(arr, index, size, result);

    // Меняем местами, когда индекс и минимальный индекс не совпадают
    if (min_index != index) {
        swap(arr[min_index], arr[index]);
        result.swaps++;
    }

    // Рекурсивный вызов функции сортировки
    recursive_sort(arr, size, is_sorted, index + 1, result);

    //steady_clock::time_point end_time = end_timer();
    //cout << "Время рекурсивной сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
}

void recursive_sort_with_timer(vector<int>& arr, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    recursive_sort(arr, 0, arr.size() - 1, 0, result);
    steady_clock::time_point end_time = end_timer();
    cout << "Время рекурсивной сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
}
