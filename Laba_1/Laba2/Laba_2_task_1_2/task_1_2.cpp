/* ���� ������ ����� �����.����� ����� ������������� �����. */

#include <iostream>

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int sum = 0;

	std::cout << "������� A: "; std::cin >> a;
	std::cout << "������� B: "; std::cin >> b;
	std::cout << "������� C: "; std::cin >> c;
	std::cout << "������� D: "; std::cin >> d;

	if (a > 0) {
		sum = sum + a;
	}
	if (b > 0) {
		sum = sum + b;
	}
	if (c > 0) {
		sum = sum + c;
	}
	if (d > 0) {
		sum = sum + d;
	}

	std::cout << "����� = " << sum << '\n';

	system("pause");
	return 0;
}