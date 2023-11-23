/* «адание 4: 
	ѕрограмма 1: –еализовать функцию, параметром (передаваемым значением) которой €вл€етс€ целое число, говор€щее сколько вывести символов С*Т в консоле.
	*после вывода последовательности из символов С*Т необходимо реализовать переход на новую строку (вписать С\nТ или std::endl) */

#include <iostream>
using namespace std;

void print_stars(int count_of_stars) {
	for (int i = 0; i < count_of_stars; i++) {
		cout << " * ";
	}
	cout << endl;
}

int main() {
	setlocale(0, "");
	
	int number_of_stars;

	cout << "¬ведите количество звездочек дл€ вывода : ";
	cin >> number_of_stars;

	if (number_of_stars < 0) {
		cout << "«вездочек нет. ¬ведите положительное число! " << endl;
	} 
	else {
		print_stars(number_of_stars);
	}
	
	return 0;
}