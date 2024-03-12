#include "laba_5.h"

// typedef void (*sort_function)(vector<int>&, int, Actions&);
using sort_function = void (*)(vector<int>&, int, Actions&);

// Функция для получения указателя на функцию сортировки
sort_function get_sort_function() {
    int choice;
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
    cout << "\tВведите номер (1-9): \t";    cin >> choice;

    // Массив указателей на функции сортировки
    sort_function sort_functions[] = {
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

    int num_sort_functions = sizeof(sort_functions) / sizeof(sort_functions[0]);

    if (choice >= 1 && choice <= num_sort_functions) {
        return sort_functions[choice - 1];
    }
    else {
        cout << "Неверный выбор. Будет использована сортировка пузырьком по умолчанию." << endl;
        return bubble_sort;
    }
}