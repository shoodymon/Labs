#include <iostream>
#include <cmath>

//using std::cout;
using namespace std;

int main() {
	system("chcp 1251"); // изменение кодировки для избежания ошибок
	system("cls"); // очищение консоли
	setlocale(0, ""); // для вывода русского языка в консоли
	//setlocale(LC_ALL, "rus|Russuian");

	float Z(0.0);
	float x(0.0);
	float pi = 3.141592;

	cout << " X --> "; cin >> x;

	Z = cos(x) + sin(x) + cos(3 * x) + sin(3 * x); cout << "Z1(2) --> " << Z << endl;
	Z = (pow(2, 0.5) * sin(x / 2)) / 2; cout << "Z2(1) --> " << Z << endl;
	Z = 1 / tan(((3 * pi) / 2) - x); cout << "Z2(3) --> " << Z << endl;
	/*  Z = pow(x, 2); cout << "Z1 --> " << Z << endl;
	Z = pow(x, 0.5); cout << "Z2(1) --> " << Z << endl;
	Z = sin(x); cout << "Z2(3) --> " << Z << endl;
	Z = tan(x); cout << "Z1 --> " << Z << endl; */

	system("pause");
	return 0;
}