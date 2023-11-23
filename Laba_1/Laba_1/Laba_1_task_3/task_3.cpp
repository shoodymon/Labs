#include <iostream>
#include <cmath>

int main() {
	system("chcp 1251"); // изменение кодировки для избежания ошибок
	system("cls"); // очищение консоли
	setlocale(0, ""); // для вывода русского языка в консоли
	//setlocale(LC_ALL, "rus|Russuian");

	float celsius = 0;
	float kelvin(0.0);
	float ratio(273.1);

	std::cout << "Кельвины: "; std::cin >> kelvin;

	celsius = kelvin - ratio;

	std::cout << "Цельсия: " << celsius << /*std::endl*/ '\n'; // \t \b Введите значенине: __\b\b

	system("pause"); // не закрывает консоль сразу
	return 0;
}