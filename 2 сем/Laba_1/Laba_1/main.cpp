#include "laba1.h"	//	C���������� ������������ ����


int main() {
	system("chcp1251");
	system("cls");
	setlocale(0, "");

	int choice = 0;
	bool flag = true;
	const int SIZE = 5;
	Game game[SIZE] = {};

	do {
		cout << "\t*���� ���������*\n";
		cout << "1) ���������� ���������\n";
		cout << "2) �������� ���������\n";
		cout << "3) ����� ����� ���������\n";
		cout << "4) ����� ������� ��������\n";
		cout << "5) ���������� � ����\n";
		cout << "6) ������ �� �����\n";
		cout << "7) ���������� ���������\n\n";
		cout << "\t�������� ������ ������� --> ";   cin >> choice;    cout << '\n';

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