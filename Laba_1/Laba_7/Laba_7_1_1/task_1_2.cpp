/*
	Задание 1: Перечисление
	Задание 1.2: 
		Определение перечисления в качестве поля структуры
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

	cout << "Имя --> " << person.name << endl;
	cout << "Лет --> " << person.age << endl;

	if (person.gender == Person::MALE) {
		cout << "Гендер --> М" << endl;
	}
	else if (person.gender == Person::FEMALE) {
		cout << "Гендер --> Ж" << endl;
	}
	else {
		cout << "Неизвестно! Инопланетянин чтоль???" << endl;
	}

	return 0;
}