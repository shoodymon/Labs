#include "func_algorithm.h"
#include "func_array.h"

int binary_search_recursive(vector<int>& arr, int &number, const int &left, const int &right, bool &flag2) {
    // const int & - исправлена ошибка с изменением левостороннего значения
    sort(arr.begin(), arr.end());

    if (left > right) {
        cout << "Элемент " << number << " не найден" << endl;
        return -1; // Если элемент не найден
    }

    int comparisons = 0;

    if (flag2) {
        number = get_user_input();
        flag2 = false;
    }
    
    while (left <= right) {
        int middle = (left + right) / 2;
        comparisons++;

        if (arr.at(middle) == number) {
            flag2 = true;
            cout << "Найден элемент " << number << " по индексу " << middle << endl;
            cout << "Количество сравнений: " << comparisons << endl;
            return middle; // Если элемент найден
        }

        if (arr.at(middle) < number)
            return binary_search_recursive(arr, number, middle + 1, right, flag2);
        else
            return binary_search_recursive(arr, number, left, middle - 1, flag2);
    }
}
