#include <iostream>
#include <cmath>

int main() {
	system("chcp 1251"); // ��������� ��������� ��� ��������� ������
	system("cls"); // �������� �������
	setlocale(0, ""); // ��� ������ �������� ����� � �������
	//setlocale(LC_ALL, "rus|Russuian");

	float celsius = 0;
	float kelvin(0.0);
	float ratio(273.1);

	std::cout << "��������: "; std::cin >> kelvin;

	celsius = kelvin - ratio;

	std::cout << "�������: " << celsius << /*std::endl*/ '\n'; // \t \b ������� ���������: __\b\b

	system("pause"); // �� ��������� ������� �����
	return 0;
}