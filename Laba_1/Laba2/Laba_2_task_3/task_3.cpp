/* ������ ������� 1 ��������� ��������� ��������. */

#include <iostream>

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");

	int x, y, z = 0;

	std::cout << "������� X: "; std::cin >> x;
	std::cout << "������� Y: "; std::cin >> y;
	std::cout << "������� Z: "; std::cin >> z;

	(x > y && y > z) ? std::cout << "�����" << '\n' : std::cout << "�������" << '\n';
	
	system("pause");
	return 0;
}