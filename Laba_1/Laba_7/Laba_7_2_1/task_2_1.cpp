/* 
	Задание 2: Объединение 
	Задание 2.1: 
		Реализовать объединение в качестве поля структуры.
*/

#include <iostream>

using namespace std;

struct Data {
    union {
        int int_value;
        float float_value;
        char char_value;
    };
};

int main() {
    setlocale(0, "");

    Data data;
    data.int_value = 10;

    cout << "Int value: " << data.int_value << endl;

    data.float_value = 5.5;

    cout << "Float value: " << data.float_value << endl;

    data.char_value = 'F';

    cout << "Char value: " << data.char_value << endl;

    return 0;
}
