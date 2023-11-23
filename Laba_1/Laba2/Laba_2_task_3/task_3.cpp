/* Решить задание 1 используя тернарный оператор. */

#include <iostream>

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");

	int x, y, z = 0;

	std::cout << "Введите X: "; std::cin >> x;
	std::cout << "Введите Y: "; std::cin >> y;
	std::cout << "Введите Z: "; std::cin >> z;

	(x > y && y > z) ? std::cout << "Верно" << '\n' : std::cout << "Неверно" << '\n';
	
	system("pause");
	return 0;
}