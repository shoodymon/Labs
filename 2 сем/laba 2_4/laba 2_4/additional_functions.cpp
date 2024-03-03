#include "additional_functions.h"


void exit(bool& flag) {
	cout << "\tЗавершение программмы...\n";
	flag = false;
}

void error() {
	cout << "Ошибка!\n\n";
}

// Функция начинает отсчет времени
steady_clock::time_point start_timer() {
	return steady_clock::now();
}

// Функция заканчивает отсчет времени
steady_clock::time_point end_timer() {
	return steady_clock::now();
}

// Функция считает разницу во времени
long duration_time(steady_clock::time_point start, steady_clock::time_point end) {
	return duration_cast<microseconds>(end - start).count();
}
