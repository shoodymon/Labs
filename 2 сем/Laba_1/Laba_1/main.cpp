#include "laba1.h"	//	Cобственный заголовочный файл


int main() {
	system("chcp1251");
	system("cls");
	setlocale(0, "");

	int choice = 0;
	bool flag = true;
	const int SIZE = 5;
	Game game[SIZE] = {};

	do {
		cout << "\t*МЕНЮ ПРОГРАММЫ*\n";
		cout << "1) Добавление элементов\n";
		cout << "2) Удаление элементов\n";
		cout << "3) Вывод одной структуры\n";
		cout << "4) Вывод массива структур\n";
		cout << "5) Сохранение в файл\n";
		cout << "6) Чтение из файла\n";
		cout << "7) Завершение программы\n\n";
		cout << "\tВыберите нужную функцию --> ";   cin >> choice;    cout << '\n';

		switch (choice) {
		case ADDING:		input(game, SIZE);				break;
		case REMOVING:		remove_element(game, SIZE);		break;
		case OUTPUT:		output(game, SIZE);				break;
		case OUTPUT_ARR:	output_arr(game, SIZE);			break;
		case SAVING:		saving(game, SIZE);				break;
		case READING:		reading(game, SIZE);			break;
		case EXIT:			flag = false;					break;
		}

	} while (flag);

	return 0;
}