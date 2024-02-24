#include "func_algorithm.h"

int index_sequential_search(const vector<int>& arr, int step, int key, int& comparisons) {
    vector<int> index_table;

    // �������� �� ��������� ������� ������ � ����� � ��������� ��������� �������
    for (int i = 0; i < arr.size(); i += step) {
        index_table.push_back(arr[i]);
    }

    // ������� ����, � ������� ����� ���������� ����
    int block_index = key / index_table.size();

    comparisons = 0; // ���������� ��� �������� ���������� ���������

    // ���������� �������� � �����
    for (int i = block_index * index_table.size(); i < min<int>((block_index + 1) * index_table.size(), static_cast<int>(arr.size())); i++) {
        comparisons++; // ����������� ������� ���������
        if (arr[i] == key) {
            cout << "������ ������� " << key << " �� ������� " << i << endl;
            cout << "���������� ���������: " << comparisons << endl; // ������� ���������� ���������
            return i;   // ���������� ������ ���������� ��������
        }
    }
    cout << "������� " << key << " �� ������" << endl;
    cout << "���������� ���������: " << comparisons << endl; // ������� ���������� ���������
    return -1;  // ������� �� ������
}

