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
    std::cout << "Введите первую строку: ";
    std::cin.getline(str1, maxLength);

    // Запрос ввода второй строки
    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, maxLength);

    int length1 = strlen(str1);
    int length2 = strlen(str2);

    // Проверка длин строк и добавление содержимого одной строки к другой
    if (length1 >= length2) {
        strcat_s(str1, str2);
        std::cout << "Результат: " << str1 << std::endl;
    }
    else {
        strcat_s(str2, str1);
        std::cout << "Результат: " << str2 << std::endl;
    }

    return 0;
}