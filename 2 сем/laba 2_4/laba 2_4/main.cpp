#include "laba_4.h"


int main() {
    setlocale(0, "");
    system("chcp 1251");
    system("cls");

    int choice = 0;
    bool flag = true;
    bool is_sorted = false;
    int size = get_arr_size();
    vector <int> origional_arr{};
    fill_arr_with_random(origional_arr);
    int left = 0;
    int right = origional_arr.size() - 1;
    int middle = (left + right) / 2;
    int index = 0;
    Actions result = { 0, 0 };

    do {
        vector<int> arr = origional_arr;
        print_arr(arr);
        cout << endl;
        cout << "\n\t------------Меню программы------------\n";
        cout << "\t1) Пузырьковая сортировка\n";
        cout << "\t2) Шейкерная сортировка\n";
        cout << "\t3) Гномья сортировка\n";
        cout << "\t4) Сортировка вставками\n";
        cout << "\t5) Сортировка выбором\n";
        cout << "\t6) Сортировка Шелла\n";
        cout << "\t7) Рекурсивная сортировка\n";
        cout << "\t8) Сортировка Хоара\n";
        cout << "\t9) Сортировка слиянием\n";
        cout << "\t10) Вывод массива\n";
        cout << "\t11) Завершение программы\n\n";
        cout << "\t\tВаш выбор --> ";	 cin >> choice;		cout << '\n' << '\n';

        switch (choice) {
        case static_cast<int>(Main_Menu::BUBBLE_SORT):		bubble_sort(arr, size, result);	                        break;
        case static_cast<int>(Main_Menu::SHAKER_SORT):		shaker_sort(arr, size, result);		                    break;
        case static_cast<int>(Main_Menu::DWARVES_SORT):	    dwarves_sort(arr, size, result);		                break;
        case static_cast<int>(Main_Menu::INSERTS_SORT):	    inserts_sort(arr, size, result);	                    break;
        case static_cast<int>(Main_Menu::SELECTION_SORT):	selection_sort(arr, size, result);                      break;
        case static_cast<int>(Main_Menu::SHELL_SORT):       shell_sort(arr, size, result);                          break;
        case static_cast<int>(Main_Menu::RECURSIVE_SORT):   recursive_sort_with_timer(arr, result);                 break;
        case static_cast<int>(Main_Menu::HOARA_SORT):       hoara_sort_with_timer(arr);                     break;
        case static_cast<int>(Main_Menu::MERGING_SORT):     merging_sort(arr, size);                        break;
        case static_cast<int>(Main_Menu::OUTPUT):		    print_arr(arr);				                            break;
        case static_cast<int>(Main_Menu::EXIT):			    exit(flag);		system("pause");                        break;

        default:	error();	break;
        }
    } while (flag);

    return 0;
}
