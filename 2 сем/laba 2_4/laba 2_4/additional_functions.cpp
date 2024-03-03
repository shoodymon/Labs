#include "additional_functions.h"


void exit(bool& flag) {
	cout << "\t���������� ����������...\n";
	flag = false;
}

void error() {
	cout << "������!\n\n";
}

// ������� �������� ������ �������
steady_clock::time_point start_timer() {
	return steady_clock::now();
}

// ������� ����������� ������ �������
steady_clock::time_point end_timer() {
	return steady_clock::now();
}

// ������� ������� ������� �� �������
long duration_time(steady_clock::time_point start, steady_clock::time_point end) {
	return duration_cast<microseconds>(end - start).count();
}
