#pragma once	/*директива для предотвращения многократного включения заголовочных файлов*/
#include <string>

struct Hero {
	char type{ 'H' };
	int id{ 0 };
	char name[50];
	int health;
	int mana;
	int damage;
	int armor;
	bool deleted{ false };
};

struct Item {
	char type{ 'I' };
	int id{ 0 };
	char name[50];
	int health;
	int mana;
	int damage;
	int armor;
	bool deleted{ false };
};

union Game {
	Hero hero{'H', 0, "", 0, 0, 0, 0, false};
	Item item;
};
