/*
директив препроцессора
#include "название файла.h"
#include <iostream>
#include <cmath>
#include <math.h>

объ€вление пользовотельских типов данных

объ€вление прототипов функций

объ€вление глобальных переменных

main

описание функций

*/

#include <iostream>
#include <cmath>

int main() {
	system("chcp 1251"); // изменение кодировки дл€ избежани€ ошибок
	system("cls"); // очищение консоли
	setlocale(0, ""); // дл€ вывода русского €зыка в консоли
	//setlocale(LC_ALL, "rus|Russuian");

	float kilo = 0;
	float pound(0.0);
	float ratio(0.4536);

	std::cout << "¬ведите фунты: "; std::cin >> pound;

	kilo = pound * ratio;

	std::cout << " г: " << kilo << /*std::endl*/ '\n'; // \t \b ¬ведите значенине: __\b\b

	system("pause"); // не закрывает консоль сразу
	return 0;
}