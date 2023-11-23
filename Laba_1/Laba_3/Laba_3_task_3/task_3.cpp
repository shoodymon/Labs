/* Задание 3: for
	Объявить массив, задав размерность константной переменной. Реализуйте следующие действия:
1)	реализовать ввод данных в массив;
2)	реализовать поиск значения в массиве
*искомое значение для поиска запрашивать у пользователя */

#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    const int array_size = 10; // Задаем размер массива как константу
    int arr[array_size];

    // Ввод данных в массив
    cout << "Введите " << array_size << " элементов в массив:" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << "Введите элемент [" << i << "] : ";
        cin >> arr[i];
    }

    // Поиск значения в массиве
    int search_value;
    cout << "Введите значение для поиска: ";
    cin >> search_value;

    bool flag = false;
    for (int i = 0; i < array_size; i++) {
        if (arr[i] == search_value) {
            cout << "Значение " << search_value << " найдено в массиве на позиции " << i << endl;
            flag = true;
            break; // Мы нашли значение, можно выйти из цикла
        }
    }

    if (!flag) {
        cout << "Значение " << search_value << " не найдено в массиве." << endl;
    }

    return 0;
}