#include "sort_functions.h"

// ������� ��� ������� ���� ��������������� ����������� [left, middle] � [middle+1, right] � ���� ��������������� ������ arr[left, right]
void merge(vector<int>& arr, int left, int middle, int right) {
    // ��������� ������� ���� �����������
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // ������� ��������� ������� ��� �������� ������ � ������� �����������
    vector<int> left_arr(size1), right_arr(size2);

    // �������� ������ �� ��������� ������� �� ��������� �������
    for (int i = 0; i < size1; i++)
        left_arr.at(i) = arr.at(left + i);
    for (int j = 0; j < size2; j++)
        right_arr.at(j) = arr.at(middle + 1 + j);

    // ������� ��� ������ ������, ������� � ��������� ��������
    int i = 0, j = 0, k = left;

    // ������� ���� ��������� �������� � ���� �������� ������
    while (i < size1 && j < size2) {
        if (left_arr.at(i) <= right_arr.at(j)) {
            arr.at(k) = left_arr.at(i);
            i++;
        }
        else {
            arr.at(k) = right_arr.at(j);
            j++;
        }
        k++;
    }

    // ���������� ���������� �������� �� ������ ���������� �������, ���� ����� ����
    while (i < size1) {
        arr.at(k) = left_arr.at(i);
        i++;
        k++;
    }

    // ���������� ���������� �������� �� ������� ���������� �������, ���� ����� ����
    while (j < size2) {
        arr.at(k) = right_arr.at(j);
        j++;
        k++;
    }
}

// ������� ���������� ��������
void merging_sort(vector<int>& arr, int len) {
    steady_clock::time_point start_time = start_timer();

    int current_size;
    int left_start;

    // ���� �� ����������� ��������� �������
    for (current_size = 1; current_size <= len - 1; current_size = 2 * current_size) {
        // ���� �� ����������� �������� �������
        for (left_start = 0; left_start < len - 1; left_start += 2 * current_size) {
            // ������� �������� � ����� ������� ����������
            int middle = min(left_start + current_size - 1, len - 1);
            int right_end = min(left_start + 2 * current_size - 1, len - 1);

            // �������� ������� ������� ��� ������� �����������
            merge(arr, left_start, middle, right_end);
        }
    }

    steady_clock::time_point end_time = end_timer();
    cout << "����� ���������� ��������: " << duration_time(start_time, end_time) << " �����������" << endl;
}
