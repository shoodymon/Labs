/*
	������� *1.3:
	������� ���� (.txt) �� ������� 1.1.
	������� ����� ��������� ���� (.txt).
	����������� ���������� ����� �� ������ 2 ���������� �� ����� ������ 1 � �������� �������.
	������ ���������� ������ ���������:
	123			987
	456   -->   654
	789			321
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	const int array_size = 4;

	ifstream file("file_1.txt");
	ofstream file_2("file_2.txt");

	/*
	vector<string> arr;
	
	string new_line;

	while (getline(file, new_line)) {
		arr.push_back(new_line);
	}	

	for (int i = arr.size() - 1; i >= 0; i--) {
		reverse(arr[i].begin(), arr[i].end());
		string line = arr[i];
		file_2 << line << endl;
	}
	*/

	string arr[array_size];

	for (int i = 0; i < array_size; i++) {
		getline(file, arr[i]);
	}

	for (int i = array_size - 1; i >= 0; i--) {
		reverse(arr[i].begin(), arr[i].end());
		file_2 << arr[i] << endl;
	}

	file.close();
	file_2.close();

	return 0;
}
