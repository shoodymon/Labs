/* Даны три числа x, y, z. Выяснить, верно ли, что x > y > z. Ответ вывести в текстовой форму “Верно” или “Неверно”. */

#include <iostream>

int main() {
	system("chcp 1251"); // отображение нормальное криллицы в консоли 
	system("cls"); // очищение консоли 
	setlocale(0, ""); 

	int x, y ,z = 0;

	std::cout << "Введите X: "; std::cin >> x;
	std::cout << "Введите Y: "; std::cin >> y;
	std::cout << "Введите Z: "; std::cin >> z;

	if (x > y && y > z) {
		std::cout << "Верно" << '\n';
	}
	else {
		std::cout << "Неверно" << '\n';
	}
	
	system("pause");
	return 0;
}