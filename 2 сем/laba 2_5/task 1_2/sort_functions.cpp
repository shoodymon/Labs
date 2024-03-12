#include "sort_functions.h"
#include "laba_5.h"

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
    print_sorted_arr(arr);
    cout << "Время пузырьковой сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

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
    reset(result);
}

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
    print_sorted_arr(arr);
    cout << "Время гномьей сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

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
    reset(result);
}

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
    print_sorted_arr(arr);
    cout << "Время сортировки выбором: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

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
    print_sorted_arr(arr);
    cout << "Время сортировки Шелла: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void recursive_sort(vector<int>& arr, int left, int right, Actions& result) {
    int pivot; // разрешающий элемент
    int index; // индекс разрешающего элемента
    int l_hold = left; // левая граница
    int r_hold = right; // правая граница
    pivot = arr.at(left);

    // пока границы не сомкнутся
    while (left < right) {
        while ((arr.at(right) > pivot) && (left < right)) {
            result.comparisons++; // увеличиваем счетчик сравнений
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        }

        // если границы не сомкнулись
        if (left != right) {
            arr.at(left) = arr.at(right); // перемещаем элемент [right] на место разрешающего
            result.swaps++; // увеличиваем счетчик перестановок
            left++; // сдвигаем левую границу вправо
        }

        while ((arr.at(left) < pivot) && (left < right)) {
            result.comparisons++; // увеличиваем счетчик сравнений
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        }

        // если границы не сомкнулись
        if (left != right) {
            arr.at(right) = arr.at(left); // перемещаем элемент [left] на место [right]
            result.swaps++; // увеличиваем счетчик перестановок
            right--; // сдвигаем правую границу влево
        }
    }

    arr.at(left) = pivot; // ставим разрешающий элемент на место
    index = left;
    left = l_hold;
    right = r_hold;

    if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
        recursive_sort(arr, left, index - 1, result);
    if (right > index)
        recursive_sort(arr, index + 1, right, result);
}

void recursive_sort_with_timer(vector<int>& arr, int size, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    recursive_sort(arr, 0, arr.size() - 1, result);
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(arr);
    cout << "Время рекурсивной сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

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

void hoara_sort_with_timer(vector<int>& arr, int size, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    hoara_sort(arr, 0, arr.size() - 1, result);
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(arr);
    cout << "Время сортировки Хоара: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

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
