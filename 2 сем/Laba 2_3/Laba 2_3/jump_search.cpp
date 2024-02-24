#include "func_algorithm.h"
#include "func_array.h"

int jump_search(vector<int>& arr, int &target) {
    sort(arr.begin(), arr.end());
    int size_arr = arr.size();
    int step = sqrt(arr.size());
    int last_step = 0;
    int comparisons = 0;
    target = get_user_input();

    while (arr.at(min(step, size_arr)) < target) {
        comparisons++;
        last_step = step;
        step += sqrt(arr.size());
        if (last_step >= arr.size()) {
            cout << "Ёлемент " << target << " не найден" << endl;
            cout << " оличество сравнений: " << comparisons << endl;
            return -1;
        }
    }

    while (arr.at(last_step) < target) {
        comparisons++;
        last_step++;
        if (last_step == min(step, size_arr)) {
            cout << "Ёлемент " << target << " не найден" << endl;
            cout << " оличество сравнений: " << comparisons << endl;
            return -1;
        }
    }

    if (arr.at(last_step) == target) {
        cout << "Ќайден элемент " << target << " по индексу " << last_step << endl;
        cout << " оличество сравнений: " << comparisons << endl;
        return last_step;
    }
}

// использование операторов [] на метод at(), чтобы обеспечить безопасный доступ к элементам вектора 
// и бросание исключени€ out_of_range, если индекс выходит за границы вектора.

// ??
/*
	min(step, arr.size()) - некорректно!
	ќшибка, которую вы получаете, св€зана с тем, что функци€ min() требует, чтобы аргументы были одного и того же типа, и они должны быть сравнимы.
	¬ вашем случае, arr.size() возвращает тип size_t, который не совпадает с типом int, который вы передаете в качестве второго аргумента.

	ѕреобразование size_t в int может вызвать проблемы, если размер массива превышает максимальное значение типа int,
	что может привести к непредсказуемому поведению.

	„тобы избежать этой ошибки, лучше сохранить arr.size() в переменную типа size_t и
	использовать ее в min() вместо непосредственного вызова arr.size().
	“аким образом, типы будут совпадать, и ошибка не возникнет.
*/