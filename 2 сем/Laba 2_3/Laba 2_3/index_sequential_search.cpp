#include "func_algorithm.h"
#include "func_array.h"

int index_sequential_search(vector<int>& arr, int &step, int &key) {
    sort(arr.begin(), arr.end());
    vector<int> index_table;
    int comparisons = 0;
    key = get_key();
    step = get_step();

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

