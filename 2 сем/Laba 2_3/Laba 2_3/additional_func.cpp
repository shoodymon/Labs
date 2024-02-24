#include "additional_func.h"


void exit(bool& flag) {
	cout << "\tЗавершение программы...\n";
	flag = false;
}


void error() {
	cout << "Неверный выбор! Напишите только ЦИФРУ вашего выбора (без скобки)\n\n";
}