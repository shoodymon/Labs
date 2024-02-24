#include <iostream>
#include <fstream>
#include <string>
#include "functions_for_files.h"


void saving(Parents *parents, const int SIZE) {
	fstream file("Array-of-structures.txt", ios::out);
	bool is_struct_empty = false;

	if (file.is_open()) {
		file << "\t\tМассив структур:\n";

		for (int i = 0; i < SIZE; i++) {
			int numb = i + 1;

			if ((parents[numb - 1].dad.age != 0) && (parents[numb - 1].dad.sex == 'М')) {
				file << "Возраст папы: " << parents[i].dad.age << '\n';
				file << "ФИО папы: " << parents[i].dad.name << '\n';
				file << "Пол: " << parents[i].dad.sex << '\n' << '\n';
			}
			else if ((parents[numb - 1].mum.age != 0) && (parents[numb - 1].mum.sex == 'Ж')) {
				file << "\tCтруктура №" << numb << ":\n";
				file << "Возраст мамы: " << parents[i].mum.age << '\n';
				file << "ФИО мамы: " << parents[i].mum.name << '\n';
				file << "Пол: " << parents[i].mum.sex << '\n' << '\n';
			}
			else {
				is_struct_empty = true;
			}
		}

		if (is_struct_empty)	file << "Ни одна структура не заполнена!\n\n";

		file.close();

		cout << "Файл успешно сохранен!\n\n";

	}
	else { cout << "Не удалось открыть файл для записи!\n";	 return; }
}


void reading(Parents *parents, const int SIZE) {
	fstream file("Array-of-structures.txt", ios::in);	//Открыли файл для чтения
	string str = "";

	cout << "\t\tСодержимое данного файла:\n\n";
	if (file.is_open()) {
		while (file) {		//Пока есть что-то, что можно прочитать в файле	
			getline(file, str);		//Записываем первую строку в str и сразу же выводим её
			cout << str << '\n';
		}

		file.close();		/*Сохраянем изменения*/
	}
	else { cout << "\tНе удалось открыть файл!\n";		return; }
}