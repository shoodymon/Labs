#include "laba_5.h"


int main() {
    setlocale(0, "");
    system("chcp 1251");
    system("cls");

    //int choice = 0;
    //bool flag = true;
    //int left = 0;
    //int right = origional_arr.size() - 1;
    //int middle = (left + right) / 2;
    //int index = 0;

    int size = get_arr_size();
    vector <int> origional_arr{};
    fill_arr_with_random(origional_arr);

    // Цикл сортировки для каждой функции сортировки
    for (int i = 0; i < 9; i++) {
        vector<int> temp_arr = origional_arr; // Копируем сгенерированный массив перед каждой сортировкой
        Actions result = { 0, 0 }; // Обнуляем счетчики операций

        print_arr(temp_arr); // Выводим неотсортированный сгенерированный массив
        cout << "\n\tСортировка " << i + 1 << ": " << endl;

        // Получаем указатель на выбранную функцию сортировки
        void (*sort_function)(vector<int>&, int, Actions&) = get_sort_function();

        // Вызываем функцию сортировки
        if (sort_function != nullptr)
            sort_function(temp_arr, size, result);
    }

    return 0;
}

