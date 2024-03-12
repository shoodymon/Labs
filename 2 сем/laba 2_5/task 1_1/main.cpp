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
    Actions result = { 0, 0 };

    // Массив указателей на функции сортировки
    void (*sort_functions[])(vector<int>&, int, Actions&) = { 
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

    for (int i = 0; i < num_sort_functions; i++) {
        
        vector<int> temp_arr = origional_arr;       // Копируем сгенерированный массив перед каждой сортировкой

        print_arr(temp_arr);
        cout << "\n\tСортировка " << i + 1 << ": " << endl;
        sort_functions[i](temp_arr, size, result);
    }

    return 0;
}
