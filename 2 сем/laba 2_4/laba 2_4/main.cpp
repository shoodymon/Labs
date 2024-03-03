#include "laba_4.h"


int main() {
    setlocale(0, "");
    system("chcp 1251");
    system("cls");

    int choice = 0;
    bool flag = true;
    bool is_sorted = false;
    int size = get_arr_size();
    vector <int> arr{};
    fill_arr_with_random(arr);
    int left = 0;
    int right = arr.size() - 1;
    int middle = (left + right) / 2;
    int index = 0;
    Actions result = { 0, 0 };

    do {
        print_arr(arr);
        cout << endl;
        cout << "\n\t------------���� ���������------------\n";
        cout << "\t1) ����������� ����������\n";
        cout << "\t2) ��������� ����������\n";
        cout << "\t3) ������ ����������\n";
        cout << "\t4) ���������� ���������\n";
        cout << "\t5) ���������� �������\n";
        cout << "\t6) ���������� �����\n";
        cout << "\t7) ����������� ����������\n";
        cout << "\t8) ���������� �����\n";
        cout << "\t9) ���������� ��������\n";
        cout << "\t10) ����� �������\n";
        cout << "\t11) ���������� ���������\n\n";
        cout << "\t\t��� ����� --> ";	 cin >> choice;		cout << '\n' << '\n';

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
