/*
	Задание:
	Описать структуру на тему любой предметной области с минимумом двумя полями, одно из которых будет шаблонным.
Реализуйте следующие шаблонные функции для работы с массивом любого типа (int, short, char, double, bool, string, структура с шаблонным полем):
		обобщенную функцию сортировки: void mySort(T* arr, const int LEN);
		обобщенную функцию поиска: bool myFind(T* arr, const int LEN, T desired);
		обобщенную функцию обмена: void mySwap(T* leftElement, T* rightElement);
		обобщенную функцию сравнения: bool myCompare (T source, T compared);
		обобщенную функцию вывода: void myPrint(T* arr, const int LEN).
	В программе для шаблонных функций реализовать специализацию для работы с данными структурного типа.
*/

#include <iostream>
#include <string>

using namespace std;


template <typename T>
struct Hero {
    T name;
    int hp;
    int mana;
};

template <typename T> void mySwap(T* left_element, T* right_element);
template <typename T> bool myCompare(T source, T compared);
template <typename T> bool myFind(T* arr, const int LEN, T desired);
template <typename T> void mySort(T* arr, const int LEN);
template <typename T> void myPrint(T* arr, const int LEN);

template <>
void myPrint(Hero<string>* arr, const int LEN) {
    for (int i = 0; i < LEN; i++) {
        cout << "\n\tName: " << arr[i].name << ", Hp: " << arr[i].hp << ", Mana: " << arr[i].mana << endl;
    }
}

int main() {
    setlocale(0, "");

    const int arr_size = 5;

    Hero<string> arr_heroes[arr_size] = {
        {"Morphling", 604, 303},
        {"Anti-Mage", 538, 219},
        {"Terrorblade", 472, 303},
        {"Faceless Void", 565, 255},
        {"Juggernaut", 560, 243}
    };

    cout << "Массив героев: " << endl;
    myPrint(arr_heroes, arr_size);

    mySort(arr_heroes, arr_size);

    cout << "\nОтсортированный массив героев по здоровью: " << endl;
    myPrint(arr_heroes, arr_size);

    Hero<string> desired_hero = { "Invoker", 630, 350 };
    bool found = myFind(arr_heroes, arr_size, desired_hero);

    cout << "\nПроверка наличия героя: " << endl;

    if (found) {
        cout << "\n\tГерой найден!" << endl;
    }
    else {
        cout << "\n\tТакого героя нет!" << endl;
    }

    return 0;
}

template <typename T>
void mySwap(T* left_element, T* right_element) {
    T temp = *left_element;
    *left_element = *right_element;
    *right_element = temp;
}

template <typename T>
bool myCompare(T source, T compared) {
    return source.hp > compared.hp;
}

template <typename T>
bool myFind(T* arr, const int LEN, T desired) {
    for (int i = 0; i < LEN; i++) {
        if (myCompare(arr[i], desired)) {
            return true;
        }
    }
    return false;
}

template <typename T>
void mySort(T* arr, const int LEN) {
    for (int i = 0; i < LEN - 1; ++i) {
        for (int j = 0; j < LEN - i - 1; j++) {
            if (myCompare(arr[j], arr[j + 1])) {
                mySwap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

template <typename T>
void myPrint(T* arr, const int LEN) {
    for (int i = 0; i < LEN; i++) {
        cout << "\n\tName: " << arr[i].name << ", Hp: " << arr[i].hp << ", Mana: " << arr[i].mana << endl;
    }
}
