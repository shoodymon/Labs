/*
	Задание 2: 
	В программе реализуется запрос ввода двух строк от пользователя через cin.getline()/cin.get(). 
	К строке с наибольшей длиной добавить текст, содержащийся в другой строке. 
	Вывести содержимое большей строки.
*/

#include <iostream>

using namespace std;


int main() {
    setlocale(0, "");
    const int maxLength = 100; // Максимальная длина строки

    char str1[maxLength];
    char str2[maxLength];

    // Запрос ввода первой строки
    cout << "Введите первую строку: ";
    cin.getline(str1, maxLength);

    // Запрос ввода второй строки
    cout << "Введите вторую строку: ";
    cin.getline(str2, maxLength);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    // Проверка длин строк и добавление содержимого одной строки к другой
    if (length1 >= length2) {
        strcat_s(str1, str2);
        cout << "Результат: " << str1 << endl;
    }
    else {
        strcat_s(str2, str1);
        cout << "Результат: " << str2 << endl;
    }

    return 0;
}