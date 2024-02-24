#include "laba_1_2.h"

int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");

	fstream file_1("hero_data.txt", ios::out);
	fstream file_2("item_data.txt", ios::out);
	string str = "";


	file_1 << 1 << '\n';
	file_1 << "Morphling" << '\n';
	file_1 << 626 << '\n';
	file_1 << 303 << '\n';
	file_1 << 42 << '\n';
	file_1 << 2 << '\n';

	file_1 << 2 << '\n';
	file_1 << "Terrorblade" << '\n';
	file_1 << 472 << '\n';
	file_1 << 303 << '\n';
	file_1 << 56 << '\n';
	file_1 << 9 << '\n';

	file_1 << 3 << '\n';
	file_1 << "Io" << '\n';
	file_1 << 494 << '\n';
	file_1 << 351 << '\n';
	file_1 << 47 << '\n';
	file_1 << 3 << '\n';

	file_1 << 4 << '\n';
	file_1 << "Mars" << '\n';
	file_1 << 626 << '\n';
	file_1 << 327 << '\n';
	file_1 << 57 << '\n';
	file_1 << 2 << '\n';

	file_1 << 5 << '\n';
	file_1 << "Dark Willow" << '\n';
	file_1 << 560 << '\n';
	file_1 << 327 << '\n';
	file_1 << 54 << '\n';
	file_1 << 3 << '\n';

	file_1.close();		

	file_1.open("hero_data.txt");

	
	cout << "\t\tСтруктура героев #1:\n\n";
	if (file_1.is_open()) {
		while (file_1) {		
			getline(file_1, str);		
			cout << str << '\n';
		}

		file_1.close();		

		cout << "\n\tДанные записаны!\n\n\n";	
	}
	else { cout << "\tДанные не записаны!\n"; }


	file_2 << 1 << '\n';
	file_2 << "Monkey King Bar" << '\n';
	file_2 << 123 << '\n';
	file_2 << 120 << '\n';
	file_2 << 40 << '\n';
	file_2 << 45 << '\n';

	file_2 << 2 << '\n';
	file_2 << "Iron Branch" << '\n';
	file_2 << 1 << '\n';
	file_2 << 1 << '\n';
	file_2 << 1 << '\n';
	file_2 << 1 << '\n';

	file_2 << 3 << '\n';
	file_2 << "Daedalus" << '\n';
	file_2 << 312 << '\n';
	file_2 << 323 << '\n';
	file_2 << 81 << '\n';
	file_2 << 31 << '\n';

	file_2 << 4 << '\n';
	file_2 << "Disperser" << '\n';
	file_2 << 90 << '\n';
	file_2 << 30 << '\n';
	file_2 << 46 << '\n';
	file_2 << 42 << '\n';

	file_2 << 5 << '\n';
	file_2 << "Desolator" << '\n';
	file_2 << 54 << '\n';
	file_2 << 15 << '\n';
	file_2 << 76 << '\n';
	file_2 << 50 << '\n';

	file_2.close();		

	file_2.open("item_data.txt");


	cout << "\t\tСтруктура предметов #2:\n\n";
	if (file_2.is_open()) {
		while (file_2) {		
			getline(file_2, str);		
			cout << str << '\n';
		}

		file_2.close();		

		cout << "\n\tДанные записаны!\n\n\n";	
	}
	else { cout << "\tДанные не записаны!\n"; }

	system("pause");

	return 0;
}