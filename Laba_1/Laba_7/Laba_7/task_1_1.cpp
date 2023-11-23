/*
	Задание 1: Перечисление 
	Задание 1.1: 
		Определить именованный набор целочисленных констант (не менее 3-ёх), которые используются в операторе switch-case.
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
		std::cout << "Ваш цвет - красный!" << std::endl;
		break;
	case GREEN:
		std::cout << "Ваш цвет - зеленый!" << std::endl;
		break;
	case BLUE:
		std::cout << "Ваш цвет - синий!" << std::endl;
		break;
	default:
		std::cout << "Неизвестный цвет!" << std::endl;
		break;
	}

	return 0;
}