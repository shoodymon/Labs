/*
	������� 2: 
	� ��������� ����������� ������ ����� ���� ����� �� ������������ ����� cin.getline()/cin.get(). 
	� ������ � ���������� ������ �������� �����, ������������ � ������ ������. 
	������� ���������� ������� ������.
*/

#include <iostream>

using namespace std;


int main() {
    setlocale(0, "");
    const int maxLength = 100; // ������������ ����� ������

    char str1[maxLength];
    char str2[maxLength];

    // ������ ����� ������ ������
    cout << "������� ������ ������: ";
    cin.getline(str1, maxLength);

    // ������ ����� ������ ������
    cout << "������� ������ ������: ";
    cin.getline(str2, maxLength);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    // �������� ���� ����� � ���������� ����������� ����� ������ � ������
    if (length1 >= length2) {
        strcat_s(str1, str2);
        cout << "���������: " << str1 << endl;
    }
    else {
        strcat_s(str2, str1);
        cout << "���������: " << str2 << endl;
    }

    return 0;
}