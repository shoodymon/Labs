#include <iostream>
#include <cmath>

int main() {
	system("chcp 1251"); // изменение кодировки для избежания ошибок
	system("cls"); // очищение консоли
	setlocale(0, ""); // для вывода русского языка в консоли
	//setlocale(LC_ALL, "rus|Russuian");

	float km = 0;
	float miles(0.0);
	float ratio(1.609);

	std::cout << "Введите мили: "; std::cin >> miles;

	km = miles * ratio;

	std::cout << "Км: " << km << /*std::endl*/ '\n'; // \t \b Введите значенине: __\b\b

	system("pause"); // не закрывает консоль сразу
	return 0;
}