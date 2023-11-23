/*
Задание:
В программе создаётся массив на 15 элементов типа integer и инициализируется нулями, реализовать следующие функции, продемонстрировав их работоспособность:
    - заполнение массивами пользовательскими значениями: void input(arr, LEN)
    - вывод значений массива: void print(arr, LEN)
    - нахождение минимального значения: int min(arr, LEN)
    - нахождение максимального значения: int max(arr, LEN)
    - сортировку массива (“пузырьковую”): void sort(arr, LEN)
    - подсчёт суммы значений элементов массива: int sum(arr, LEN)
    - нахождения среднего значения элементов массива: float sr(arr, LEN)
*/

#include <iostream>

using namespace std;


void input(int arr[], int LEN);
void print(int arr[], int LEN);
int min(int arr[], int LEN);
int max(int arr[], int LEN);
void sort(int arr[], int LEN);
int sum(int arr[], int LEN);
float sr(int arr[], int LEN);


int main() {

    setlocale(0, "");

    const int LEN = 15;
    int arr[LEN] = {}; // Инициализация массива нулями

    input(arr, LEN);
    print(arr, LEN);

    cout << "Минимальное значение: " << min(arr, LEN) << endl;
    cout << "Максимальное значение: " << max(arr, LEN) << endl;

    sort(arr, LEN);
    cout << "Отсортированный массив: ";
    print(arr, LEN);

    int sumValue = sum(arr, LEN);
    cout << "Сумма значений: " << sumValue << endl;

    float avgValue = sr(arr, LEN);
    cout << "Среднее значение: " << avgValue << endl;

    return 0;
}

// Ввод пользовательских значений
void input(int arr[], int LEN) {
    cout << "Введите " << LEN << " элементов массива: " << endl;
    for (int i = 0; i < LEN; i++) {
        cin >> arr[i];
    }
}

// Вывод значений массива 
void print(int arr[], int LEN) {
    cout << "Элементы массива: ";
    for (int i = 0; i < LEN; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Нахождение минимального значения в массиве
int min(int arr[], int LEN) {
    int min = arr[0];
    for (int i = 1; i < LEN; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Нахождение максимального значения в массиве
int max(int arr[], int LEN) {
    int max = arr[0];
    for (int i = 1; i < LEN; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Cортирует массив, используя алгоритм "пузырьковой" сортировки
void sort(int arr[], int LEN) {
    for (int i = 0; i < LEN - 1; i++) {
        for (int j = 0; j < LEN - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Вычисляет сумму значений элементов массива
int sum(int arr[], int LEN) {
    int sum = 0;
    for (int i = 0; i < LEN; i++) {
        sum += arr[i];
    }
    return sum;
}

// Вычисляет среднее значение элементов массива
float sr(int arr[], int LEN) {
    return (float)sum(arr, LEN) / LEN;
}
