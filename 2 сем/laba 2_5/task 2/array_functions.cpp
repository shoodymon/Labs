#include "prototypes.h"

int get_arr_size() {
    int size_arr;
    cout << "¬ведите размер массива (не меньше 100): ";  cin >> size_arr;
    return size_arr;
}

void fill_arr_with_random(vec& main_vector) {

    main_vector.resize(get_arr_size());
    int seed = time(0);
    srand(seed);               

    for (int i = 0; i < main_vector.size(); i++) {
        main_vector[i] = rand() % 100;             
    }
}


void print_arr(vec& main_vector) {
    cout << "\n\t—генерированный массив:\n";

    for (int i = 0; i < main_vector.size(); i++) {
        cout << main_vector[i] << " ";

        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

void print_sorted_arr(vec& main_vector) {
    cout << "\n\tќтсортированный массив:\n";

    for (int i = 0; i < main_vector.size(); i++) {
        cout << main_vector[i] << " ";

        // ѕереход на новую строку после каждых 10 элементов
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

int get_user_input() {
    int value;
    cout << "¬ведите значение дл€ поиска: ";  cin >> value;
    return value;
}
