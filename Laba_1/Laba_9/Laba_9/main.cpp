/*
		������� 1.1:
	������� ����� ��������� ���� (.txt) ��� ������.
	������� ������ ����� � ������������������� ���, �������� �������� ������ ������������� (��� ������ ������� �������������).
	������ ��������� ������������ �� ����� ������ ���������.
	����������� ������ ������� ����� � ���� �� ������ 1.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(0, "");

	string poem[] = {
		"����� ������ ������,",
		"� ���� � �������� �������.",
		"���� ������ ����� �������,",
		"� ���� ������ ������."
	};

	ofstream file_1("file_1.txt");

	if (file_1.is_open()) {
		for (int i = 0; i < sizeof(poem) / sizeof(poem[0]); ++i)
			file_1 << poem[i] << endl;
		file_1.close();
	}
	else {
		cout << "���������� ������� ����!" << endl;
	}
	
	return 0;
}
