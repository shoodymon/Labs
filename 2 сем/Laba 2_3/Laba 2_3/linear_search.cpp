#include "func_algorithm.h"

int linear_search(const vector<int>& arr, int target, int& count) {
    count = 0;

    for (int index = 0; index < arr.size(); index++) {
        count++;
        if (arr.at(index) == target) {
            cout << "Найден элемент " << target << " по индексу " << index << endl;
            cout << "Количество сравнений: " << count << endl;
            return index;
        }
    }
    cout << "Элемент " << target << " не найден" << endl;
    cout << "Количество сравнений: " << count << endl;
    return -1;
}