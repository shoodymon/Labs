#include "array_functions.h"

int get_arr_size() {
    int size_arr;
    cout << "Введите размер массива (не меньше 100): ";  cin >> size_arr;
    return size_arr;
}

void fill_arr_with_random(vector<int>& arr) {

    arr.resize(get_arr_size());
    int seed = time(0);
    srand(seed);                            

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 100;            
    }
}


void print_arr(const vector<int>& arr) {
    cout << "\n\tСгенерированный массив:\n";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

void print_sorted_arr(vector<int>& arr) {
    cout << "\n\tОтсортированный массив:\n";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";

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
