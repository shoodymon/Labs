/*
	������� 1: ������������ 
	������� 1.1: 
		���������� ����������� ����� ������������� �������� (�� ����� 3-��), ������� ������������ � ��������� switch-case.
*/

#include <iostream>

using namespace std;


enum Color {
	RED,
	GREEN,
	BLUE
};

int main() {
	setlocale(0, "");

	Color color = RED;

	switch (color) {
	case RED:
		std::cout << "��� ���� - �������!" << std::endl;
		break;
	case GREEN:
		std::cout << "��� ���� - �������!" << std::endl;
		break;
	case BLUE:
		std::cout << "��� ���� - �����!" << std::endl;
		break;
	default:
		std::cout << "����������� ����!" << std::endl;
		break;
	}

	return 0;
}