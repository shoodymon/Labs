#include <iostream>
#include <cmath>

int main() {
	system("chcp 1251"); // ��������� ��������� ��� ��������� ������
	system("cls"); // �������� �������
	setlocale(0, ""); // ��� ������ �������� ����� � �������
	//setlocale(LC_ALL, "rus|Russuian");

	float km = 0;
	float miles(0.0);
	float ratio(1.609);

	std::cout << "������� ����: "; std::cin >> miles;

	km = miles * ratio;

	std::cout << "��: " << km << /*std::endl*/ '\n'; // \t \b ������� ���������: __\b\b

	system("pause"); // �� ��������� ������� �����
	return 0;
}