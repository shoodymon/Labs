/* ������ ���� �� ������ ��������� �� �����, �������� ������ ��� ������ ���������� � ������������ */

#include <iostream>

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");

	float a, b, c, x = 0.0;
	float F = 0.0;

	std::cout << "������� A: "; std::cin >> a;
	std::cout << "������� B: "; std::cin >> b;
	std::cout << "������� C: "; std::cin >> c;
	std::cout << "������� X: "; std::cin >> x;

	if (x < 0 && b != 0) {
		F = -((2 * x - c) / (c * x - a));
	}
	else if (x > 0 && b == 0) {
		F = (x - a) / (x - c);
	}
	else {
		F = - x / c + (-b) / (2 * x);
	}

	std::cout << "F = " << F << '\n';

	system("pause");
	return 0;
}