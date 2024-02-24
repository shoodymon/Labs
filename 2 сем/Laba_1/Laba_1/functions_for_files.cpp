#include "functions_for_files.h"

void saving(Game* game, const int SIZE) {
	fstream file("Heroes_items.txt", ios::out);

	if (file.is_open()) {
		file << "\n\tМассив: \n";

		for (int i = 0; i < SIZE; i++) {
			int number = i + 1;
			if (game[i].hero.type == 'H') {
				file << "\n\tГерой #: " << number << endl;
				file << "\tID: " << game[i].hero.id << endl;
				file << "\tИмя: " << game[i].hero.name << endl;
				file << "\tЗдоровье: " << game[i].hero.health << endl;
				file << "\tМана: " << game[i].hero.mana << endl;
				file << "\tУрон: " << game[i].hero.damage << endl;
				file << "\tБроня: " << game[i].hero.armor << endl;
			}
			cout << "==============";
			if (game[i].item.type == 'I') {
				file << "\n\tУникальный предмет героя #" << number << ":\n";
				file << "\tID: " << game[i].item.id << endl;
				file << "\tНаименование: " << game[i].item.name << endl;
				file << "\tЗдоровье: " << game[i].item.health << endl;
				file << "\tМана: " << game[i].item.mana << endl;
				file << "\tУрон: " << game[i].item.damage << endl;
				file << "\tБроня: " << game[i].item.armor << endl;
			}
		}
		file.close();
		cout << "\tДанные в файл успешно записаны!\n";
	}
	else { cout << "\tФайл не был открыт для записи!\n"; return; }
}

void reading(Game* game, const int SIZE) {
	fstream file("Heroes_items.txt", ios::in);
	string stroka = "";

	cout << "\t\nСодержимое: \n";
	if (file.is_open()) {
		while (file) {
			getline(file, stroka);
			cout << stroka << endl;
		}
		file.close();
	}
	else { cout << "\tФайл не был открыт для записи!\n"; return; }
} 