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
    }
    cout << "Элемент " << key << " не найден" << endl;
    cout << "Количество сравнений: " << comparisons << endl; // Выводим количество сравнений
    return -1;  // Элемент не найден
}

