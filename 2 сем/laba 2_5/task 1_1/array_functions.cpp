#include "array_functions.h"

int get_arr_size() {
    int size_arr;
    cout << "Введите размер массива (не меньше 100): ";  cin >> size_arr;
    return size_arr;
}

void fill_arr_with_random(vector<int>& arr) {

    arr.resize(get_arr_size());
    int seed = time(0);
    srand(seed);                            // инициализация генератора случайных чисел
    /*
      Чуть теории:
      Генератор "случайных" чисел в C/C++ rand на самом деле не случаен, а обычно задается формулой.
      Но формула при одних и тех-же значениях даёт естественно одинаковый результат.
      Начальное значение у этой формулы принято называть seed. Так вот srand инициализирует этот seed определенным значением.
      Но нам нужно, чтобы был разный seed.

      И вот - time(NULL) - означает взять текущее время. Что "решает" проблему генерирования разного seed.
    */


    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 100;              // инициализация случайными значениями от 0 до 99
    }
}


void print_arr(vector<int>& arr) {
    cout << "\n\tСгенерированный массив:\n";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";

        // Переход на новую строку после каждых 10 элементов
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

void print_sorted_arr(vector<int>& arr) {
    cout << "\n\tОтсортированный массив:\n";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";

        // Переход на новую строку после каждых 10 элементов
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

int get_user_input() {
    int value;
    cout << "Введите значение для поиска: ";  cin >> value;
    return value;
}
