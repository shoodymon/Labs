/*
	Задание 2: Объединение
	Задание 2.2:
		Реализовать массив на основе использования объединения для создания списка, 
		в котором хранится в качестве значение элемента одна из нескольких структур (минимум 2-ух) на выбор.
*/

#include <iostream>

using namespace std;

struct Structure1 {
    int value1;
    char type_positive;
};

struct Structure2 {
    double value2;
    char type_negative;
};

union Values {
    Structure1 structure1;
    Structure2 structure2;
};

int main() {
    setlocale(0, "");
    const int LEN = 10;

    Values arr[LEN];

    // Заполнение массива значениями для первой структуры
    for (int i = 0; i < LEN; ++i) {
        arr[i].structure1.value1 = i + 1;
        arr[i].structure1.type_positive = '+';
    }

    for (int i = 0; i < LEN; ++i) {
        cout << "\n\tЭлемент " << i + 1 << ": ";
        cout << "Тип: " << arr[i].structure1.type_positive << ", Значение: " << arr[i].structure1.value1 << endl;
    }

    return 0;
}
