/*
	Задание 2.1:
	Создать новый бинарный файл (.dat/.bin) для записи.
	Создать массив структур и проинициализировать его.
	Массив создавать размерностью не менее пяти элементов.
	Записать массив структур в файл.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Atributes {
	int strength;
	int agility;
	int intelligence;
};

struct Hero {
	int id;
	string name;
	Atributes atributes;
	int hp;
	int mana;
	int damage;
	int armor;
};


int main() {
	setlocale(0, "");

	const int LEN = 5;
	Hero arr[LEN] = {
		{ 1, "Morphling", 22, 24, 19, 604, 303, 64, 2 },
		{ 2, "Terrorblade", 16, 22, 19, 472, 303, 63, 9 },
		{ 3, "Anti-Mage", 19, 24, 12, 538, 219, 49, 5 },
		{ 4, "Juggernaut", 20, 34, 14, 560, 243, 56, 6 },
		{ 5, "Faceless Void", 20, 19, 15, 560, 255, 53, 4 },
	};

	ofstream output_file("heroes.dat", ios::out | ios::binary);

	// Записываем количество структур в файл
	output_file.write((char*)(&LEN), sizeof(LEN));

	// Записываем массив структур в файл
	output_file.write((char*)(&arr), sizeof(Hero) * LEN);
	output_file.close();

	cout << "Массив структур записан в бинарный файл." << endl;

	return 0;
}
