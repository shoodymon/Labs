#include "prototypes.h"
#include "pack.h"

void bubble_sort(vec& main_vector, Actions& result) {
   steady_clock::time_point start_time = start_timer();

    for (int i = 0; i < main_vector.size() - 1; i++) {
        for (int j = 0; j < main_vector.size() - i - 1; j++) {
            result.comparisons++;
            if (main_vector.at(j) > main_vector.at(j + 1)) {
                swap(main_vector.at(j), main_vector.at(j + 1));
                result.swaps++;
            }
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время пузырьковой сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void shaker_sort(vec& main_vector,  Actions& result) {
    steady_clock::time_point start_time = start_timer();

    bool swapped = true;
    int start = 0;
    int end = main_vector.size() - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (main_vector.at(i) > main_vector.at(i + 1)) {
                swap(main_vector.at(i), main_vector.at(i + 1));
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
            if (main_vector.at(i) > main_vector.at(i + 1)) {
                swap(main_vector.at(i), main_vector.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        // Увеличиваем левую границу
        ++start;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время шейкерной сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void dwarves_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    int index = 0;  while (index < main_vector.size()) {
        if (index == 0)
            index++;
        if (main_vector[index] >= main_vector[index - 1]) {
            index++;
            result.comparisons++;
        }

        else {
            swap(main_vector[index], main_vector[index - 1]);
            index--;
            result.swaps++;
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время гномьей сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void inserts_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int i = 1; i < main_vector.size(); i++) {
        int key = main_vector.at(i);
        int j = i - 1;
        while (j >= 0 && main_vector.at(j) > key) {
            main_vector.at(j + 1) = main_vector.at(j);
            j--;
            result.comparisons++;
            result.swaps++;
        }
        main_vector.at(j + 1) = key;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время сортировки вставками: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void selection_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int i = 0; i < main_vector.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < main_vector.size(); j++) {
            if (main_vector.at(j) < main_vector.at(min_index)) {
                min_index = j;
                result.comparisons++;
            }
        }
        swap(main_vector.at(i), main_vector.at(min_index));
        result.swaps++;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время сортировки выбором: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void shell_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int step = main_vector.size() / 2; step > 0; step /= 2) {
        for (int i = step; i < main_vector.size(); i++) {
            for (int j = i; j >= step && main_vector.at(j - step) > main_vector.at(j); j -= step) {
                swap(main_vector[j], main_vector[j - step]);
                result.swaps++;
                result.comparisons++;
            }
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время сортировки Шелла: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void recursive_sort(vec& main_vector, int left, int right, Actions& result) {
    int pivot; // разрешающий элемент
    int index; // индекс разрешающего элемента
    int l_hold = left; // левая граница
    int r_hold = right; // правая граница
    pivot = main_vector.at(left);

    // пока границы не сомкнутся
    while (left < right) {
        while ((main_vector.at(right) > pivot) && (left < right)) {
            result.comparisons++; // увеличиваем счетчик сравнений
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        }

        // если границы не сомкнулись
        if (left != right) {
            main_vector.at(left) = main_vector.at(right); // перемещаем элемент [right] на место разрешающего
            result.swaps++; // увеличиваем счетчик перестановок
            left++; // сдвигаем левую границу вправо
        }

        while ((main_vector.at(left) < pivot) && (left < right)) {
            result.comparisons++; // увеличиваем счетчик сравнений
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        }

        // если границы не сомкнулись
        if (left != right) {
            main_vector.at(right) = main_vector.at(left); // перемещаем элемент [left] на место [right]
            result.swaps++; // увеличиваем счетчик перестановок
            right--; // сдвигаем правую границу влево
        }
    }

    main_vector.at(left) = pivot; // ставим разрешающий элемент на место
    index = left;
    left = l_hold;
    right = r_hold;

    if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
        recursive_sort(main_vector, left, index - 1, result);
    if (right > index)
        recursive_sort(main_vector, index + 1, right, result);
}

void recursive_sort_with_timer(vec& main_vector,  Actions& result) {
    steady_clock::time_point start_time = start_timer();
    recursive_sort(main_vector, 0, main_vector.size() - 1, result);
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время рекурсивной сортировки: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void hoara_sort(vec& main_vector, int first, int last, Actions& result) {
    int i = first, j = last;
    int pivot = main_vector.at((first + last) / 2); // Выбор опорного элемента посередине вектора

    do {
        // Поиск элемента в левой части, который больше или равен опорному
        while (main_vector.at(i) < pivot) {
            i++;
            result.comparisons++;
        }

        // Поиск элемента в правой части, который меньше или равен опорному
        while (main_vector.at(j) > pivot) {
            j--;
            result.comparisons++;
        }

        // Производим обмен элементов
        if (i <= j) {
            if (i < j) {
                swap(main_vector.at(i), main_vector.at(j));
                result.swaps++;
            }
            i++;
            j--;
        }
    } while (i <= j);

    // Рекурсивный вызов для сортировки правой части вектора
    if (i < last)
        hoara_sort(main_vector, i, last, result);

    // Рекурсивный вызов для сортировки левой части вектора
    if (first < j)
        hoara_sort(main_vector, first, j, result);
}

void hoara_sort_with_timer(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    hoara_sort(main_vector, 0, main_vector.size() - 1, result);
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время сортировки Хоара: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void merge(vec& main_vector, int left, int middle, int right, Actions& result) {
    // Вычисляем размеры двух подмассивов
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // Создаем временные массивы для хранения левого и правого подмассивов
    vector<int> left_arr(size1), right_arr(size2);

    // Копируем данные из основного массива во временные массивы
    for (int i = 0; i < size1; i++)
        left_arr.at(i) = main_vector.at(left + i);
    for (int j = 0; j < size2; j++)
        right_arr.at(j) = main_vector.at(middle + 1 + j);

    // Индексы для обхода левого, правого и основного массивов
    int i = 0, j = 0, k = left;

    // Слияние двух временных массивов в один основной массив
    while (i < size1 && j < size2) {
        result.comparisons++;
        if (left_arr.at(i) <= right_arr.at(j)) {
            main_vector.at(k) = left_arr.at(i);
            i++;
            result.swaps++;
        }
        else {
            main_vector.at(k) = right_arr.at(j);
            j++;
            result.swaps++;
        }
        k++;
    }

    // Дописываем оставшиеся элементы из левого временного массива, если такие есть
    while (i < size1) {
        main_vector.at(k) = left_arr.at(i);
        i++;
        k++;
        result.swaps++;
    }

    // Дописываем оставшиеся элементы из правого временного массива, если такие есть
    while (j < size2) {
        main_vector.at(k) = right_arr.at(j);
        j++;
        k++;
        result.swaps++;
    }
}

void merging_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    int len = main_vector.size();

    int current_size;
    int left_start;

    // Цикл по подмассивам заданного размера
    for (current_size = 1; current_size <= main_vector.size() - 1; current_size = 2 * current_size) {
        // Цикл по подмассивам текущего размера
        for (left_start = 0; left_start < main_vector.size() - 1; left_start += 2 * current_size) {
            // Находим середину и конец правого подмассива
            int middle = min(left_start + current_size - 1,len - 1);
            int right_end = min(left_start + 2 * current_size - 1, len - 1);

            // Вызываем функцию слияния для текущих подмассивов
            merge(main_vector, left_start, middle, right_end, result);
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "Время сортировки слиянием: " << duration_time(start_time, end_time) << " микросекунд" << endl;
    cout << "Сравнений: " << result.comparisons << endl;
    cout << "Перестановок: " << result.swaps << endl;
    reset(result);
}

void null_sort(vec& main_vector, Actions& result)
{

}

void set_sort(arr& sort_array)
{
    sort_array = 
    {
        null_sort,
        bubble_sort,
        shaker_sort,
        dwarves_sort,
        inserts_sort,
        selection_sort,
        shell_sort,
        recursive_sort_with_timer,
        hoara_sort_with_timer,
        merging_sort
    };
}

void sorting(vec& main_vector, arr& sort_array, Actions actions)
{
    int choice{};
    do
    {
        print_sorted_arr(main_vector);

        cout << "\n\tВыберите функцию сортировки:" << endl;
        cout << "\t1. Сортировка пузырьком" << endl;
        cout << "\t2. Шейкерная сортировка" << endl;
        cout << "\t3. Гномья сортировка" << endl;
        cout << "\t4. Сортировка вставками" << endl;
        cout << "\t5. Сортировка выбором" << endl;
        cout << "\t6. Сортировка Шелла" << endl;
        cout << "\t7. Рекурсивная сортировка" << endl;
        cout << "\t8. Сортировка Хоара" << endl;
        cout << "\t9. Сортировка слиянием" << endl;
        cout << "\t10. Выход в меню" << endl;
        cout << "\tВведите номер (1-9): \t";

        std::cin >> choice;

        if (choice > 0 and choice < sort_array.size())
        {
            Sort_func fcn = sort_array.at(choice);
            fcn(main_vector, actions);
        }
        else if (choice == 10)
            break;
        else std::cout << "Неверный индекс!";

        fill_arr_with_random(main_vector);

    } while (choice != 10);
}






