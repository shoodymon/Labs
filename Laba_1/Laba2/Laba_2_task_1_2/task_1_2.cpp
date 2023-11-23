/* Даны четыре целых числа.Найти сумму положительных чисел. */

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

	std::cout << "Введите A: "; std::cin >> a;
	std::cout << "Введите B: "; std::cin >> b;
	std::cout << "Введите C: "; std::cin >> c;
	std::cout << "Введите D: "; std::cin >> d;

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

	std::cout << "Сумма = " << sum << '\n';

	system("pause");
	return 0;
}