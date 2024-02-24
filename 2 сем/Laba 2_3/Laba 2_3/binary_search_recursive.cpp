#include "func_algorithm.h"

int binary_search_recursive(const vector<int>& arr, int number, int left, int right, int& comparisons) {
    if (left > right) {
        cout << "Элемент " << number << " не найден" << endl;
        return -1; // Если элемент не найден
    }

    while (left <= right) {
        int middle = (left + right) / 2;
        comparisons++;

        if (arr.at(middle) == number) {
            cout << "Найден элемент " << number << " по индексу " << middle << endl;
            cout << "Количество сравнений: " << comparisons << endl;
            return middle; // Если элемент найден
        }

        if (arr.at(middle) < number)
            return binary_search_recursive(arr, number, middle + 1, right, comparisons);
        else
            return binary_search_recursive(arr, number, left, middle - 1, comparisons);
    }
}
