/* ������� 3: for
	�������� ������, ����� ����������� ����������� ����������. ���������� ��������� ��������:
1)	����������� ���� ������ � ������;
2)	����������� ����� �������� � �������
*������� �������� ��� ������ ����������� � ������������ */

#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    const int array_size = 10; // ������ ������ ������� ��� ���������
    int arr[array_size];

    // ���� ������ � ������
    cout << "������� " << array_size << " ��������� � ������:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << "������� ������� [" << i << "] : ";
        cin >> arr[i];
    }

    // ����� �������� � �������
    int search_value;
    cout << "������� �������� ��� ������: ";
    cin >> search_value;

    bool flag = false;
    for (int i = 0; i < array_size; i++) {
        if (arr[i] == search_value) {
            cout << "�������� " << search_value << " ������� � ������� �� ������� " << i << endl;
            flag = true;
            break; // �� ����� ��������, ����� ����� �� �����
        }
    }

    if (!flag) {
        cout << "�������� " << search_value << " �� ������� � �������." << endl;
    }

    return 0;
}