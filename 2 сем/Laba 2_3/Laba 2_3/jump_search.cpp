#include "func_algorithm.h"

int jump_search(const vector<int>& arr, int target, int& comparisons) {
    int size_arr = arr.size();
    int step = sqrt(arr.size());
    int last_step = 0;

    while (arr.at(min(step, size_arr)) < target) {
        comparisons++;
        last_step = step;
        step += sqrt(arr.size());
        if (last_step >= arr.size()) {
            cout << "������� " << target << " �� ������" << endl;
            cout << "����� ���������: " << comparisons << endl;
            return -1;
        }
    }

    while (arr.at(last_step) < target) {
        comparisons++;
        last_step++;
        if (last_step == min(step, size_arr)) {
            cout << "������� " << target << " �� ������" << endl;
            cout << "����� ���������: " << comparisons << endl;
            return -1;
        }
    }

    if (arr.at(last_step) == target) {
        cout << "������ ������� " << target << " �� ������� " << last_step << endl;
        cout << "����� ���������: " << comparisons << endl;
        return last_step;
    }
}

// ������������� ���������� [] �� ����� at(), ����� ���������� ���������� ������ � ��������� ������� 
// � �������� ���������� out_of_range, ���� ������ ������� �� ������� �������.

// ??
/*
	min(step, arr.size()) - �����������!
	������, ������� �� ���������, ������� � ���, ��� ������� min() �������, ����� ��������� ���� ������ � ���� �� ����, � ��� ������ ���� ��������.
	� ����� ������, arr.size() ���������� ��� size_t, ������� �� ��������� � ����� int, ������� �� ��������� � �������� ������� ���������.

	�������������� size_t � int ����� ������� ��������, ���� ������ ������� ��������� ������������ �������� ���� int,
	��� ����� �������� � ���������������� ���������.

	����� �������� ���� ������, ����� ��������� arr.size() � ���������� ���� size_t �
	������������ �� � min() ������ ����������������� ������ arr.size().
	����� �������, ���� ����� ���������, � ������ �� ���������.
*/