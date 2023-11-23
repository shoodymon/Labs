/* 
	Задание 2: Объединение 
	Задание 2.1: 
		Реализовать объединение в качестве поля структуры.
*/

#include <iostream>

using namespace std;

struct Data {
    union {
        int intValue;
        float floatValue;
        char charValue;
    };
};

int main() {
    setlocale(0, "");

    Data data;
    data.intValue = 10;

    cout << "Int value: " << data.intValue << endl;

    data.floatValue = 5.5;

    cout << "Float value: " << data.floatValue << endl;

    data.charValue = 'F';

    cout << "Char value: " << data.charValue << endl;

    return 0;
}
