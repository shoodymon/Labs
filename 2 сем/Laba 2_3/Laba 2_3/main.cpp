#include "laba_3.h"
/*
int main() {
    setlocale(0, "");
    system("chcp 1251");
    system("cls");

    int choice = 0;
    bool flag = true;
    bool flag2 = true;
    int size_arr = get_arr_size(); 
    vector <int> arr = fill_arr_with_random(size_arr);
    int key = 0;
    int step = 0;
    int search_value = 0;
    const int left = 0;
    const int right = arr.size() - 1;

    do {
        print_arr(arr);
        cout << endl;
        cout << "\n\t*Меню программы*\n";
        cout << "1) Ввод значения для поиска\n";
        cout << "2) Последовательный поиск\n";
        cout << "3) Поиск прыжками\n";
        cout << "4) Индексно-последовательный поиск\n";
        cout << "5) Бинарный поиск\n";
        cout << "6) Бинарный поиск через рекурсию\n";
        cout << "7) Вывод массива\n";
        cout << "8) Завершение программы\n\n";
        cout << "\tВаш выбор --> ";	 cin >> choice;		cout << '\n' << '\n';

        switch (choice) {
        case static_cast<int>(Main_Menu::INPUT):                    search_value = get_user_input();                                break;
        case static_cast<int>(Main_Menu::LINEAR_SEARCH):		    linear_search(arr, search_value);	                            break;
        case static_cast<int>(Main_Menu::JUMP_SEARCH):		        jump_search(arr, search_value);		                            break;
        case static_cast<int>(Main_Menu::INDEX_SEQUENTIAL_SEARCH):	index_sequential_search(arr, step, key);		                break;
        case static_cast<int>(Main_Menu::BINARY_SEARCH):	        binary_search(arr, search_value);			                    break;
        case static_cast<int>(Main_Menu::BINARY_SEARCH_RECURSIVE):	binary_search_recursive(arr, search_value, left, right, flag2); break;
        case static_cast<int>(Main_Menu::OUTPUT):		            print_arr(arr);				                                    break;
        case static_cast<int>(Main_Menu::EXIT):			            exit(flag);		system("pause");                                break;

        default:	error();	break;
        }
    } while (flag);

    return 0;
}
*/

int main() {
    setlocale(0, "");
    system("cls");
    system("chcp1251");
    srand(time(0));

    vector <int> arr;

    int choice = 0;
    bool flag = true;
    bool flag2 = true;

    int len{};
    int width{};
    int min{};
    int max{};
    
    int key = 0;
    int step = 0;
    int search_value = 0;
    const int left = 0;
    const int right = arr.size() - 1;

    system("cls"); //èñïîëüçóþ, òê â êîíñîëè ïèøåò êàêóþ-òî õðåíü ïðî chcp1251

    get_len_and_volume(arr, len, width); //â ôóíêöèè ÷åðåç ññûëêè ìåíÿþ len è width
    fill_arr_with_random(arr, min, max);

    do {
        print_arr(arr, len);
        cout << endl;
        cout << "\n\t*Меню программы*\n";
        cout << "1) Ввод значения для поиска\n";
        cout << "2) Последовательный поиск\n";
        cout << "3) Поиск прыжками\n";
        cout << "4) Индексно-последовательный поиск\n";
        cout << "5) Бинарный поиск\n";
        cout << "6) Бинарный поиск через рекурсию\n";
        cout << "7) Вывод массива\n";
        cout << "8) Завершение программы\n\n";
        cout << "\tВаш выбор --> ";	 cin >> choice;		cout << '\n' << '\n';

        switch (choice) {
        case static_cast<int>(Main_Menu::INPUT):                        search_value = get_user_input();                                break;
        case static_cast<int>(Main_Menu::LINEAR_SEARCH):		        linear_search(arr, search_value);	                            break;
        case static_cast<int>(Main_Menu::JUMP_SEARCH):		            jump_search(arr, search_value);		                            break;
        case static_cast<int>(Main_Menu::INDEX_SEQUENTIAL_SEARCH):	    index_sequential_search(arr, step, key);		                break;
        case static_cast<int>(Main_Menu::BINARY_SEARCH):	            binary_search(arr, search_value);			                    break;
        case static_cast<int>(Main_Menu::BINARY_SEARCH_RECURSIVE):	    binary_search_recursive(arr, search_value, left, right, flag2); break;
        case static_cast<int>(Main_Menu::OUTPUT):		                print_arr(arr, len);				                            break;
        case static_cast<int>(Main_Menu::EXIT):			                exit(flag);		system("pause");                                break;

        default:	                                                    error();	                                                    break;
        }
    } while (flag);

    return 0;
}
