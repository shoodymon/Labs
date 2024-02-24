#include "func_algorithm.h"
#include "func_array.h"

int linear_search(const vector<int>& arr, int &target) {
    int count = 0;
    target = get_user_input();

    for (int index = 0; index < arr.size(); index++) {
        count++;
        if (arr.at(index) == target) {
            cout << "������ ������� " << target << " �� ������� " << index << endl;
            cout << "���������� ���������: " << count << endl;
            return index;
        }
    }
    cout << "������� " << target << " �� ������" << endl;
    cout << "���������� ���������: " << count << endl;
    return -1;
}