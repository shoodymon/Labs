#include "func_algorithm.h"

int binary_search(const vector<int> &arr, int number, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    comparisons = 0;

    while (left <= right) {
        int middle = (left + right) / 2;
        comparisons++;

        if (arr.at(middle) == number) {
            cout << "Найден элемент " << number << " по индексу " << middle << endl;
            cout << "Количество сравнений: " << comparisons << endl;
            return middle;
        }

        if (arr.at(middle) < number)
            left = middle + 1;
        else
            right = middle - 1;
    }
    cout << "Элемент " << number << " не найден" << endl;
    cout << "Количество сравнений: " << comparisons << endl;
}

