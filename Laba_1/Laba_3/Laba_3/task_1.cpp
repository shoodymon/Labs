/* Программа 1(вычисление факториала): Напишите программу, которая запрашивает у пользователя число и вычисляет факториал этого числа.
		* n! = 1*2*…*n; */
/*
#include <iostream>

int main() {
	setlocale(0, "");
	
	int number = 0;
	int result = 1;
	std::cout << "Введите число --> ";
	std::cin >> number;
		for (int i = 1; i <= number; i++) {
			result = result * i;
	}
		std::cout << "Факториал числа --> " << result << std::endl;
		return 0;
}
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    int number = 0;
    cout << "Введите число: ";
    cin >> number;

    if (number < 0) {
        cout << "Факториал отрицательного числа не определен." << endl;
    }
    else {
        long factorial = 1; // для хранения больших значений факториала
        int i = 1;
        while (i <= number) {
            factorial *= i;
            i++;
        }
        cout << "Факториал числа " << number << " = " << factorial << endl;
    }

    return 0;
}