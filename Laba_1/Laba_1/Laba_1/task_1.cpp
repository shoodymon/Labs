/*
�������� �������������
#include "�������� �����.h"
#include <iostream>
#include <cmath>
#include <math.h>

���������� ���������������� ����� ������

���������� ���������� �������

���������� ���������� ����������

main

�������� �������

*/

#include <iostream>
#include <cmath>

int main() {
	system("chcp 1251"); // ��������� ��������� ��� ��������� ������
	system("cls"); // �������� �������
	setlocale(0, ""); // ��� ������ �������� ����� � �������
	//setlocale(LC_ALL, "rus|Russuian");

	float kilo = 0;
	float pound(0.0);
	float ratio(0.4536);

	std::cout << "������� �����: "; std::cin >> pound;

	kilo = pound * ratio;

	std::cout << "��: " << kilo << /*std::endl*/ '\n'; // \t \b ������� ���������: __\b\b

	system("pause"); // �� ��������� ������� �����
	return 0;
}