#include "func_algorithm.h"
#include "func_array.h"

int index_sequential_search(vector<int>& arr, int &step, int &key) {
    sort(arr.begin(), arr.end());
    vector<int> index_table;
    int comparisons = 0;
    key = get_key();
    step = get_step();

    // Проходим по основному массиву данных с шагом и заполняем индексную таблицу
    for (int i = 0; i < arr.size(); i += step) {
        index_table.push_back(arr[i]);
    }
    /*
    // Находим блок, в котором может находиться ключ
    int block_index = key / index_table.size();

    comparisons = 0; // Переменная для подсчёта количества сравнений

    // Перебираем элементы в блоке
    for (int i = block_index * index_table.size(); i < min<int>((block_index + 1) * index_table.size(), static_cast<int>(arr.size())); i++) {
        comparisons++; // Увеличиваем счётчик сравнений
        if (arr[i] == key) {
            cout << "Найден элемент " << key << " по индексу " << i << endl;
            cout << "Количество сравнений: " << comparisons << endl; // Выводим количество сравнений
            return i;   // Возвращаем индекс найденного элемента
        }
    } */

    /*
    for (int i = 0; i < index_table.size(); i++) {
        comparisons++;

        if (index_table[i] == key) {
            int start_index = i * step;
            int end_index = min<int>((i + 1) * step, static_cast<int>(arr.size()));

            for (int j = start_index; j < end_index; j++) {
                comparisons++;

                if (arr[j] == key) {
                    cout << "Найден элемент " << key << " по индексу " << i << endl;
                    cout << "Количество сравнений: " << comparisons << endl; // Выводим количество сравнений
                    return j;   // Возвращаем индекс найденного элемента
                }
            }
        }
    }
    */
    // Определяем блок, в котором должен находиться ключ
    int block_index = 0;
    for (int i = 0; i < index_table.size(); i++) {
        if (index_table[i] <= key) {
            block_index = i;
        }
        else {
            break; // Как только текущий индекс в индексном массиве становится больше ключа, прекращаем поиск
        }
    }
    cout << "block index = " << block_index << endl;

    // Перебираем элементы индексного массива
    for (int i = 0; i < index_table.size(); i++) {
        int start_index = index_table[i]; // Начальный индекс блока
        int end_index = min<int>(start_index + step, 100); // Конечный индекс блока

        cout << "start_index = " << start_index << endl;
        cout << "end_index = " << end_index << endl;

        // Перебираем элементы внутри блока
        for (int j = start_index; j < end_index; j++) {
            comparisons++; // Увеличиваем счетчик сравнений
            if (arr[j] == key) {
                cout << "Элемент " << key << " найден по индексу " << j << endl;
                cout << "Количество сравнений: " << comparisons << endl;
                return j; // Возвращаем индекс найденного элемента
            }
        }
    }

    cout << "Элемент " << key << " не найден" << endl;
    cout << "Количество сравнений: " << comparisons << endl; // Выводим количество сравнений
    return -1;  // Элемент не найден
}

