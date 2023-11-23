/*
	������� 1: ������������
	������� 1.2: 
		����������� ������������ � �������� ���� ���������
*/

#include <iostream>
#include <string>

using namespace std;


struct Person {
	string name;
	int age;
	enum Gender {
		MALE,
		FEMALE
	} gender;
};

int main() {
	setlocale(0, "");

	Person person = { "John", 25, Person::MALE };

	cout << "��� --> " << person.name << endl;
	cout << "��� --> " << person.age << endl;

	if (person.gender == Person::MALE) {
		cout << "������ --> �" << endl;
	}
	else if (person.gender == Person::FEMALE) {
		cout << "������ --> �" << endl;
	}
	else {
		cout << "����������! ������������� �����???" << endl;
	}

	return 0;
}