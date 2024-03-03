#include "laba_4.h"

/*
void recursive_sort(vector<int>& arr, int left, int right) {
    int pivot; // ����������� �������
    int index; // ������ ������������ ��������
    int l_hold = left; //����� �������
    int r_hold = right; // ������ �������
    pivot = arr.at(left);

    // ���� ������� �� ���������
    while (left < right) {
        while ((arr.at(right) > pivot) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]

        // ���� ������� �� ����������
        if (left != right) {
            arr.at(left) = arr.at(right); // ���������� ������� [right] �� ����� ������������
            left++; // �������� ����� ������� ������
        }

        while ((arr.at(left) < pivot) && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]

        // ���� ������� �� ����������
        if (left != right) { 
            arr.at(right) = arr.at(left); // ���������� ������� [left] �� ����� [right]
            right--; // �������� ������ ������� �����
        }
    }

    arr.at(left) = pivot; // ������ ����������� ������� �� �����
    index = left;
    left = l_hold;
    right = r_hold;

    if (left < index) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        recursive_sort(arr, left, index - 1);
    if (right > index)
        recursive_sort(arr, index + 1, right);
} 
*/

int find_min_index(vector<int> arr, int left, int right, Actions& result) {
    int min_index = left; // ������������, ��� ����������� ������� - ��� arr[i]

    // ���� �� ���������� ��������� � ��������� min_index, ���� ������� ������� ������ �������� ������������
    for (int k = left + 1; k < right; k++) {
        result.comparisons++;
        if (arr[k] < arr[min_index]) {
            min_index = k;
        }
    }

    return min_index;
}

void recursive_sort(vector<int> arr, int size, bool is_sorted, int index, Actions& result) {
    //steady_clock::time_point start_time = start_timer();

    int min_index = 0;

    // ������� ������, ����� index � size ����� �����������
    if (index == size) {
        is_sorted = true;
        return;
    }

    // ����� ������� min_index ��� ��������� ������������ �������
    min_index = find_min_index(arr, index, size, result);

    // ������ �������, ����� ������ � ����������� ������ �� ���������
    if (min_index != index) {
        swap(arr[min_index], arr[index]);
        result.swaps++;
    }

    // ����������� ����� ������� ����������
    recursive_sort(arr, size, is_sorted, index + 1, result);

    //steady_clock::time_point end_time = end_timer();
    //cout << "����� ����������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
}

void recursive_sort_with_timer(vector<int>& arr, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    recursive_sort(arr, 0, arr.size() - 1, 0, result);
    steady_clock::time_point end_time = end_timer();
    cout << "����� ����������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
}
