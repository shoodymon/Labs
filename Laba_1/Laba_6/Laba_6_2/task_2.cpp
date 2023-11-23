/*
	Примеры структур для описания:
		[Название структуры]: [перечисление полей]
	Студент: фио, номер группы, факультет, средний балл.
	Преподаватель: фио, номер табеля, степень, преподаваемая дисциплина.
	Сотрудник: фио, должность, год поступления на работу, оклад.
	Слушатель: фио, номер паспорта, место учёбы, специальность.
	Птицы: вид, вес, дальность полёта, ареал обитания.
	SMS-banking: банк, номер карточки, номер телефона, количество денег на счёте.
	Картина: название картины, длина и ширина картины, материал рамки.
	Монитор: диагональ экрана, ЖК/ЭЛТ, разрешение, производитель.

	Задание 2: структуры с функциями
	1.	На основании задания 1.1 реализовать следующие функции:
	1.1.	заполнения структуры:
	1.1.1.	struct input();
	1.1.2.	void input(struct*);
	1.2.	заполнения массива структур:
	1.2.1.	void input(struct[], const int);
	1.3.	сортировку массива по одному из полей:
	1.3.1.	void sort(struct[], const int);
	1.4.	вывод структуры:
	1.4.1.	void print(struct);
	1.5.	вывод массива структур:
	1.5.1.	void print(struct[], const int);
	1.6.	поиск структур по одному из полей:
	1.6.1.	void printSearch(struct[], const int, [?]);
*/

#include <iostream>

using namespace std;


struct Student {
    char name[100];
    int number_of_group;
    int faculty;
    float average_mark;
};

void input(Student& student);

void input(Student arr[], const int len);

void sort(Student arr[], const int len);

void print(Student student);

void print(Student arr[], const int len);

void printSearch(Student arr[], const int len, int number);

int main() {
    system("chcp1251");
    system("cls");
    setlocale(0, "");

    const int LEN = 5;
    Student arr[LEN];

    cout << "\t\t   *Запись структур*" << endl;

    // Ввод данных студентов
    input(arr, LEN);

    cout << "\n\t\t*Сортировка\*" << endl;

    // Сортировка по ФИО
    sort(arr, LEN);

    cout << "\n\t\t  *Вывод всех записей*" << endl;

    // Вывод всех записей
    print(arr, LEN);

    cout << "\n\t*Поиск*" << endl;

    int number = 0;

    cout << "\nВведите номер группы: ";
    cin >> number;

    // Поиск по номеру группы
    printSearch(arr, LEN, number);

    return 0;
}

// Функция для ввода данных в одну структуру
void input(Student& student) {
    cout << "Введите данные студента: " << endl;
    cout << "ФИО --> "; cin.getline(student.name, 100);
    cout << "Номер группы --> "; cin >> student.number_of_group;
    cout << "Факультет --> "; cin >> student.faculty;
    cout << "Оценка --> "; cin >> student.average_mark;
}

// Функция для ввода данных в массив структур
void input(Student arr[], const int len) {
    for (int i = 0; i < len; i++) {
        cout << "Введите данные для студента " << i + 1 << ": " << endl;
        input(arr[i]);
        cin.ignore();
    }
}

// Функция для сортировки массива структур по полю "name"
void sort(Student arr[], const int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция для вывода данных одной структуры
void print(Student student) {
    cout << "\nДанные студента: " << endl;
    cout << "ФИО --> " << student.name << endl;
    cout << "Номер группы --> " << student.number_of_group << endl;
    cout << "Факультет --> " << student.faculty << endl;
    cout << "Оценка --> " << student.average_mark << endl;
}

// Функция для вывода массива структур
void print(Student arr[], const int len) {
    for (int i = 0; i < len; i++) {
        print(arr[i]);
    }
}

// Функция поиска
void printSearch(Student arr[], const int len, int number) {
    bool flag = true;

    for (int i = 0; i < len; i++) {
        if (number == arr[i].number_of_group) {
            flag = false;
            print(arr[i]);
        }
    }

    if (flag) {
        cout << "\nТакой записи нет" << endl;
    }
}
