#include "functions_for_files.h"

void saving(Game* game, const int SIZE) {
	fstream file("Heroes_items.txt", ios::out);

	if (file.is_open()) {
		file << "\n\t������: \n";

		for (int i = 0; i < SIZE; i++) {
			int number = i + 1;
			if (game[i].hero.type == 'H') {
				file << "\n\t����� #: " << number << endl;
				file << "\tID: " << game[i].hero.id << endl;
				file << "\t���: " << game[i].hero.name << endl;
				file << "\t��������: " << game[i].hero.health << endl;
				file << "\t����: " << game[i].hero.mana << endl;
				file << "\t����: " << game[i].hero.damage << endl;
				file << "\t�����: " << game[i].hero.armor << endl;
			}
			cout << "==============";
			if (game[i].item.type == 'I') {
				file << "\n\t���������� ������� ����� #" << number << ":\n";
				file << "\tID: " << game[i].item.id << endl;
				file << "\t������������: " << game[i].item.name << endl;
				file << "\t��������: " << game[i].item.health << endl;
				file << "\t����: " << game[i].item.mana << endl;
				file << "\t����: " << game[i].item.damage << endl;
				file << "\t�����: " << game[i].item.armor << endl;
			}
		}
		file.close();
		cout << "\t������ � ���� ������� ��������!\n";
	}
	else { cout << "\t���� �� ��� ������ ��� ������!\n"; return; }
}

void reading(Game* game, const int SIZE) {
	fstream file("Heroes_items.txt", ios::in);
	string stroka = "";

	cout << "\t\n����������: \n";
	if (file.is_open()) {
		while (file) {
			getline(file, stroka);
			cout << stroka << endl;
		}
		file.close();
	}
	else { cout << "\t���� �� ��� ������ ��� ������!\n"; return; }
} 