#include "laba_3.h"

int main() {
    setlocale(0, "");
    system("cls");
    system("chcp1251");

    int choice = 0;
    bool flag = true;
    int size_arr = get_arr_size(); 
    vector <int> arr = fill_arr_with_random(size_arr);
    int search_value = 0;
    int comparasion = 0;
    int key = 10;
    int step = 8;
    int left = 12;
    int right = 37;


    do {
        cout << "\n\t*���� ���������*\n";
        cout << "1) ���� �������� ��� ������\n";
        cout << "2) ���������������� �����\n";
        cout << "3) ����� ��������\n";
        cout << "4) ��������-���������������� �����\n";
        cout << "5) �������� �����\n";
        cout << "6) �������� ����� ����� ��������\n";
        cout << "7) ����� �������\n";
        cout << "8) ���������� ���������\n\n";
        cout << "\t��� ����� --> ";	 cin >> choice;		cout << '\n' << '\n';

        switch (choice) {
        case static_cast<int>(Main_Menu::INPUT):                        search_value = get_user_input();                                break;
        case static_cast<int>(Main_Menu::LINEAR_SEARCH):		        linear_search(arr, search_value, comparasion);	                break;
        case static_cast<int>(Main_Menu::JUMP_SEARCH):		            jump_search(arr, search_value, comparasion);		            break;
        case static_cast<int>(Main_Menu::INDEX_SEQUENTIAL_SEARCH):		index_sequential_search(arr, step, key, comparasion);		    break;
        case static_cast<int>(Main_Menu::BINARY_SEARCH):	            binary_search(arr, search_value, comparasion);			        break;
        case static_cast<int>(Main_Menu::BINARY_SEARCH_RECURSIVE):	    binary_search_recursive(arr, search_value, left, right, comparasion);		    break;
        case static_cast<int>(Main_Menu::OUTPUT):		                print_arr(arr);				        break;
        case static_cast<int>(Main_Menu::EXIT):			                exit(flag);		system("pause");    break;

        default:	error();	break;
        }
    } while (flag);

    return 0;
}