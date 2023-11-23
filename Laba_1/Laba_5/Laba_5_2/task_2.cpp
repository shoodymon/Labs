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
    std::cout << "������� ������ ������: ";
    std::cin.getline(str1, maxLength);

    // ������ ����� ������ ������
    std::cout << "������� ������ ������: ";
    std::cin.getline(str2, maxLength);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    // �������� ���� ����� � ���������� ����������� ����� ������ � ������
    if (length1 >= length2) {
        strcat_s(str1, str2);
        std::cout << "���������: " << str1 << std::endl;
    }
    else {
        strcat_s(str2, str1);
        std::cout << "���������: " << str2 << std::endl;
    }

    return 0;
}