#include "pack.h"
#include "prototypes.h"

int get_arr_size() {
    int size_arr;
    cout << "������� ������ ������� (�� ������ 100): "; 
    cin >> size_arr;
    return size_arr;
}

void fill_arr_with_random(vec& main_vector) {

    for (int i = 0; i < main_vector.size(); i++) {
        main_vector[i] = rand() % 100;             
    }
}


void print_sorted_arr(vec& main_vector) {
    cout << "\n\t������� �����:\n";

    for (int i = 0; i < main_vector.size(); i++) {
        cout << main_vector[i] << " ";

        // ������� �� ����� ������ ����� ������ 10 ���������
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

int get_user_input() {
    int value;
    cout << "������� �������� ��� ������: ";  cin >> value;
    return value;
}
