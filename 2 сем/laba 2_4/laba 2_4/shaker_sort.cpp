#include "sort_functions.h"

void shaker_sort(vector<int>& arr, int size, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        // ������ ����� �������
        for (int i = start; i < end; ++i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        if (!swapped) // ���� �� ���� ������������, �� ������ ��� ������������
            break;

        swapped = false;

        // ��������� ������ �������
        --end;

        // ������ ������ ������
        for (int i = end - 1; i >= start; --i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        // ����������� ����� �������
        ++start;
    }

    steady_clock::time_point end_time = end_timer();
    cout << "����� ��������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
}
