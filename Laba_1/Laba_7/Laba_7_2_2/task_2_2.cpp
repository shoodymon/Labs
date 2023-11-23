/*
	Задание 2: Объединение
	Задание 2.2:
		Реализовать массив на основе использования объединения для создания списка, 
		в котором хранится в качестве значение элемента одна из нескольких структур (минимум 2-ух) на выбор.
*/

#include <iostream>

using namespace std;

/*
   Структура UnionExample содержит два поля:
   - data - это объединение (union) с именованными полями для хранения разных типов данных
   - dataType - это целое число, которое будет использоваться для определения типа данных, хранящегося в объединении data.
*/
union Data {
    int intValue;
    double doubleValue;
    char stringValue[20];
};

struct UnionExample {
    Data data;
    int dataType; // 0 for int, 1 for double, 2 for string
};

int main() {
    setlocale(0, "");

    // массив list из структур UnionExample с тремя элементами
    UnionExample list[3];

    // Для каждого элемента массива list задаем dataType, чтобы указать, какой тип данных мы хотим хранить в объединении data.
    list[0].dataType = 0;
    list[0].data.intValue = 42;

    list[1].dataType = 1;
    list[1].data.doubleValue = 3.14;

    list[2].dataType = 2;
    strcpy_s(list[2].data.stringValue, "Hello, World!"); // так как поле data объединения Data имеет разные варианты типов данных 

    /*
        Для каждого элемента мы проверяем значение dataType и в зависимости от этого типа выводим данные, 
        которые хранятся в объединении data.Выводимое сообщение зависит от типа данных, который мы хотим отобразить.    
    */ 

    for (int i = 0; i < 3; i++) {
        switch (list[i].dataType) {
        case 0:
            cout << "Целое число: " << list[i].data.intValue << endl;
            break;
        case 1:
            cout << "Десятичное число: " << list[i].data.doubleValue << endl;
            break;
        case 2:
            cout << "Строка: " << list[i].data.stringValue << endl;
            break;
        default:
            cout << "Неизвестный тип данных." << endl;
        }
    }

    return 0;
}
