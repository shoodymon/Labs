/* ��������� 1(���������� ����������): �������� ���������, ������� ����������� � ������������ ����� � ��������� ��������� ����� �����.
		* n! = 1*2*�*n; */
/*
#include <iostream>

int main() {
	setlocale(0, "");
	
	int number = 0;
	int result = 1;
	std::cout << "������� ����� --> ";
	std::cin >> number;
		for (int i = 1; i <= number; i++) {
			result = result * i;
	}
		std::cout << "��������� ����� --> " << result << std::endl;
		return 0;
}
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    int number = 0;
    cout << "������� �����: ";
    cin >> number;

    if (number < 0) {
        cout << "��������� �������������� ����� �� ���������." << endl;
    }
    else {
        long factorial = 1; // ��� �������� ������� �������� ����������
        int i = 1;
        while (i <= number) {
            factorial *= i;
            i++;
        }
        cout << "��������� ����� " << number << " = " << factorial << endl;
    }

    return 0;
}