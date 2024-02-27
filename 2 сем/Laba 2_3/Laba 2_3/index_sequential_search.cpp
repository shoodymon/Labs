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
    /*
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
    } */

    /*
    for (int i = 0; i < index_table.size(); i++) {
        comparisons++;

        if (index_table[i] == key) {
            int start_index = i * step;
            int end_index = min<int>((i + 1) * step, static_cast<int>(arr.size()));

            for (int j = start_index; j < end_index; j++) {
                comparisons++;

                if (arr[j] == key) {
                    cout << "������ ������� " << key << " �� ������� " << i << endl;
                    cout << "���������� ���������: " << comparisons << endl; // ������� ���������� ���������
                    return j;   // ���������� ������ ���������� ��������
                }
            }
        }
    }
    */
    // ���������� ����, � ������� ������ ���������� ����
    int block_index = 0;
    for (int i = 0; i < index_table.size(); i++) {
        if (index_table[i] <= key) {
            block_index = i;
        }
        else {
            break; // ��� ������ ������� ������ � ��������� ������� ���������� ������ �����, ���������� �����
        }
    }
    cout << "block index = " << block_index << endl;

    // ���������� �������� ���������� �������
    for (int i = 0; i < index_table.size(); i++) {
        int start_index = index_table[i]; // ��������� ������ �����
        int end_index = min<int>(start_index + step, 100); // �������� ������ �����

        cout << "start_index = " << start_index << endl;
        cout << "end_index = " << end_index << endl;

        // ���������� �������� ������ �����
        for (int j = start_index; j < end_index; j++) {
            comparisons++; // ����������� ������� ���������
            if (arr[j] == key) {
                cout << "������� " << key << " ������ �� ������� " << j << endl;
                cout << "���������� ���������: " << comparisons << endl;
                return j; // ���������� ������ ���������� ��������
            }
        }
    }

    cout << "������� " << key << " �� ������" << endl;
    cout << "���������� ���������: " << comparisons << endl; // ������� ���������� ���������
    return -1;  // ������� �� ������
}

