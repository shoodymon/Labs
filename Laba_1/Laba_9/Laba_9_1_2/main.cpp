/*
		Задание 1.2:
	Открыть файл (.txt) из задания 1.1.
	Реализовать до запись строк файл.
	Пользователь вводит строки с клавиатуры.
	*Продумать реализацию ограничения ввода строк пользователю двумя способами:
	Спросить у пользователя количество вводимых строк заранее.
	Пользователь вводит неизвестное количество строк заранее.
	Прежде чем будет реализовываться до запись в файл, должна быть реализована демонстрация/вывод содержимого файла.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(0, "");

	// Открытие
	ifstream file_1("file_1.txt");

	// Вывод содержимого
	if (file_1.is_open()) {
		string new_line;
		while (getline(file_1, new_line)) {
			cout << new_line << endl;
		}
		file_1.close();
	}
	else {
		cout << "Невозможно открыть файл";
	}

	// Ввод строк с клавиатуры и запись в файл
	ofstream file_2("output.txt", ios::app);
	if (file_2.is_open()) {
		int choice;
		cout << "\n\tВыберите вариант ввода строк: " << endl;
		cout << "\n\t1) Указать число строк " << endl;
		cout << "\t2) Вводить сами строки " << endl;
		cin >> choice;

		if (choice == 1) {
			int number_of_lines;
			cout << "Введите количество строк для ввода: " << endl;
			cin >> number_of_lines;
			cin.ignore();

			for (int i = 0; i < number_of_lines; i++) {
				string new_line;
				cout << "Введите непосредственно строку: " << i+1 << endl;
				getline(cin, new_line);
				file_2 << new_line << endl;
			}
		}
		else if (choice == 2) {
			string new_line;
			cout << "Введите строки. Для завершения напишите 'exit': " << endl;
			while (true) {
				getline(cin, new_line);
				if (new_line == "exit")
					break;
				file_2 << new_line << endl;	
			}
		}
		else {
			cout << "Вы выбрали несуществующий вариант. Не чудите!" << endl;
		}
	file_2.close();
	} else {
		cout << "Невозможно открыть файл" << endl;
	}
	return 0;
}
