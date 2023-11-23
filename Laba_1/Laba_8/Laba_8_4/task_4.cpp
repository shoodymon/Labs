/*
		Задание 4: Статические поля структуры 
	Реализуйте структуру любой предметной области с минимум 3-мя полями, 
	реализовав дополнительно статические поля int count и int count_all, 
	которые считают количество существующих объектов на данный момент и количество всего созданных объектов.
		*реализовать при помощи конструкторов и деструкторов
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct DotaHero {
	int id;
	string name;
	int strength;
	int agility;
	int intelligence;
	int speed;
	int health;
	int mana;
	int armor;

	static int count;		// Количество существующих объектов
	static int count_All;	// Общее количество созданных объектов

	// конструктор увеличивает 2 счетчика, деструктор - уменьшает 1
	
	DotaHero(int id, string name, int str, int agil, int intl, int spd, int hp, int mp, int arm)
		: id(id), name(name), strength(str), agility(agil), intelligence(intl), speed(spd), health(hp), mana(mp), armor(arm) {
		count_All++;		// Увеличиваем общий счетчик объектов 
		count++;			// Увеличиваем счетчик существующих объектов
	}

	~DotaHero() {
		count--;			// Уменьшаем счетчик существующих объектов при удалении объекта
	}
};

int DotaHero::count = 0;
int DotaHero::count_All = 0;

int main() {
	setlocale(0, "");

	DotaHero hero1 = { 1, "Morphling", 22, 24, 19, 285, 604, 303, 2 };
	DotaHero hero2 = { 2, "Terrorblade", 16, 22, 19, 315, 472, 303, 9 };
	DotaHero hero3 = { 3, "Anti-Mage", 19, 24, 12, 310, 538, 219, 5 };
	DotaHero hero4 = { 4, "Juggernaut", 20, 34, 14, 300, 560, 243, 6 };

	cout << "\n\tСуществующих героев: " << DotaHero::count << endl;
	cout << "\tВсего создано героев: " << DotaHero::count_All << endl;

	DotaHero* hero5 = new DotaHero{ 5, "Faceless Void", 20, 19, 15, 300, 560, 255, 4 };

	cout << "\n\tСуществующих героев: " << DotaHero::count << endl;
	cout << "\tВсего создано героев: " << DotaHero::count_All << endl;

	delete hero5;

	cout << "\n\tСуществующих героев: " << DotaHero::count << endl;
	cout << "\tВсего создано героев: " << DotaHero::count_All << endl;

	return 0;
}
