/*
		������� 1.2:
	������� ���� (.txt) �� ������� 1.1.
	����������� �� ������ ����� ����.
	������������ ������ ������ � ����������.
	*��������� ���������� ����������� ����� ����� ������������ ����� ���������:
	�������� � ������������ ���������� �������� ����� �������.
	������������ ������ ����������� ���������� ����� �������.
	������ ��� ����� ��������������� �� ������ � ����, ������ ���� ����������� ������������/����� ����������� �����.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(0, "");

	// ��������
	ifstream file_1("file_1.txt");

	// ����� �����������
	if (file_1.is_open()) {
		string new_line;
		while (getline(file_1, new_line)) {
			cout << new_line << endl;
		}
		file_1.close();
	}
	else {
		cout << "���������� ������� ����";
	}

	// ���� ����� � ���������� � ������ � ����
	ofstream file_2("output.txt", ios::app);
	if (file_2.is_open()) {
		int choice;
		cout << "\n\t�������� ������� ����� �����: " << endl;
		cout << "\n\t1) ������� ����� ����� " << endl;
		cout << "\t2) ������� ���� ������ " << endl;
		cin >> choice;

		if (choice == 1) {
			int number_of_lines;
			cout << "������� ���������� ����� ��� �����: " << endl;
			cin >> number_of_lines;
			cin.ignore();

			for (int i = 0; i < number_of_lines; i++) {
				string new_line;
				cout << "������� ��������������� ������: " << i+1 << endl;
				getline(cin, new_line);
				file_2 << new_line << endl;
			}
		}
		else if (choice == 2) {
			string new_line;
			cout << "������� ������. ��� ���������� �������� 'exit': " << endl;
			while (true) {
				getline(cin, new_line);
				if (new_line == "exit")
					break;
				file_2 << new_line << endl;	
			}
		}
		else {
			cout << "�� ������� �������������� �������. �� ������!" << endl;
		}
	file_2.close();
	} else {
		cout << "���������� ������� ����" << endl;
	}
	return 0;
}
