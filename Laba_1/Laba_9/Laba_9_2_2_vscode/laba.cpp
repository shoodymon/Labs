#include <iostream>
#include <fstream>
#include <string>
#include "functions_for_files.h"


void saving(Parents *parents, const int SIZE) {
	fstream file("Array-of-structures.txt", ios::out);
	bool is_struct_empty = false;

	if (file.is_open()) {
		file << "\t\t������ ��������:\n";

		for (int i = 0; i < SIZE; i++) {
			int numb = i + 1;

			if ((parents[numb - 1].dad.age != 0) && (parents[numb - 1].dad.sex == '�')) {
				file << "������� ����: " << parents[i].dad.age << '\n';
				file << "��� ����: " << parents[i].dad.name << '\n';
				file << "���: " << parents[i].dad.sex << '\n' << '\n';
			}
			else if ((parents[numb - 1].mum.age != 0) && (parents[numb - 1].mum.sex == '�')) {
				file << "\tC�������� �" << numb << ":\n";
				file << "������� ����: " << parents[i].mum.age << '\n';
				file << "��� ����: " << parents[i].mum.name << '\n';
				file << "���: " << parents[i].mum.sex << '\n' << '\n';
			}
			else {
				is_struct_empty = true;
			}
		}

		if (is_struct_empty)	file << "�� ���� ��������� �� ���������!\n\n";

		file.close();

		cout << "���� ������� ��������!\n\n";

	}
	else { cout << "�� ������� ������� ���� ��� ������!\n";	 return; }
}


void reading(Parents *parents, const int SIZE) {
	fstream file("Array-of-structures.txt", ios::in);	//������� ���� ��� ������
	string str = "";

	cout << "\t\t���������� ������� �����:\n\n";
	if (file.is_open()) {
		while (file) {		//���� ���� ���-��, ��� ����� ��������� � �����	
			getline(file, str);		//���������� ������ ������ � str � ����� �� ������� �
			cout << str << '\n';
		}

		file.close();		/*��������� ���������*/
	}
	else { cout << "\t�� ������� ������� ����!\n";		return; }
}