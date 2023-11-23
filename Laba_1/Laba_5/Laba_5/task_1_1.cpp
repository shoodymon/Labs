/* 
	Задание 1.1: работать со строкой через синтаксис массива 
	В программе создаётся строка, как массив символов на 20 элементов, и инициализируется как пустая строка (“” -> {‘\0’}). 
	Реализовать следующие функции, продемонстрировав их работоспособность:
		- сравнивает строки на равенство: bool userStrcmp(str1, str2)
		- записывает данные строки 2 в строку 1: void userStrcpy(str1, str2)
		- записывает n символов строки 2 в строку 1: void userStrncpy(str1, str2, n)
		- дописывает n символов строки 2 к строке 1: void userStrncat(str1, str2, n)
		- вычисляет длину строки: int userStrlen(str)
		- записывает n символов строки символом symbol: void userStrnset(str, symbol, n)
		- проверка строки на то, что она является целым числом: bool userIsTheStringANumber(str)
		- проверка строки на то, что она является двоичным значением: bool userIsTheStringABinaryValue(str)
		- проверка строки на то, что она является восьмеричным значением: bool userIsTheStringAOctalValue(str)
		- проверка строки на то, что она является шестнадцатеричным значением: bool userIsTheStringAHexadecimalValue(str)
		- преобразовывает строку в целое число: int userAtoi(str)
	Вторую строку или объявлять новой переменной, которая или инициализируется при объявлении, или вводится пользователем, 
	или в функцию передаётся строковый литерал. 
*/

/*
	1. str1: Массив символов, представляющий строку. 
	Здесь он инициализируется пустой строкой (массив символов с одним элементом - нулевым символом \0).
	2. str2: Указатель на константную строку "Hello". 
	Основное назначение этой переменной - использоваться в качестве второго аргумента при тестировании функции userStrcmp.
	3. len1: Переменная типа int, используется для хранения длины строки str1.
	4. i: Переменная типа int, используется в циклах для управления количеством итераций.
	5. symbol: Переменная типа char, используется в функции userStrnset для инициализации символов в строке str.
	6. result: Переменная типа int, используется в функции userAtoi для хранения результата преобразования строки в целое число.
*/

#include <iostream>

bool userStrcmp(const char str1[], const char str2[]);

void userStrcpy(char str1[], const char str2[]);

void userStrncpy(char str1[], const char str2[], int n);

void userStrncat(char str1[], const char str2[], int n);

int userStrlen(const char str[]);

void userStrnset(char str[], char symbol, int n);

bool userIsTheStringANumber(const char str[]);

bool userIsTheStringABinaryValue(const char str[]);

bool userIsTheStringAOctalValue(const char str[]);

bool userIsTheStringAHexadecimalValue(const char str[]);

int userAtoi(const char str[]);

int main() {
	setlocale(0, "");

	// Создаем строку, как массив символов на 20 элементов, и инициализируем как пустую строку
	char str1[20] = "";
	const char* str2 = "Hello, world!";

	// Работа с функциями
	bool equal = userStrcmp(str1, str2);
	std::cout << "Строки " << (equal ? "равны" : "не равны") << std::endl;

	userStrcpy(str1, str2);
	std::cout << "Скопированная строка: " << str1 << std::endl;

	userStrncpy(str1, str2, 7);
	std::cout << "Скопированная строка с n - символами: " << str1 << std::endl;

	userStrncat(str1, str2, 5);
	std::cout << "Объединенная строка: " << str1 << std::endl;

	int length = userStrlen(str1);
	std::cout << "Длина строки: " << length << std::endl;

	userStrnset(str1, '*', 6);
	std::cout << "Строка после установки n - символов в '*': " << str1 << std::endl;

	bool isNumber = userIsTheStringANumber("1423");
	std::cout << "Является ли '1423' числом? " << (isNumber ? "Да" : "Нет") << std::endl;

	bool isBinary = userIsTheStringABinaryValue("0b1210");
	std::cout << "Является ли '0b1211' двоичным значением? " << (isBinary ? "Да" : "Нет") << std::endl;

	bool isOctal = userIsTheStringAOctalValue("0374");
	std::cout << "Является ли '0374' восьмеричным значением? " << (isOctal ? "Да" : "Нет") << std::endl;

	bool isHexadecimal = userIsTheStringAHexadecimalValue("0xAC");
	std::cout << "Является ли '0xAC' шестнадцатеричным значением? " << (isHexadecimal ? "Да" : "Нет") << std::endl;

	int number = userAtoi("1234");
	std::cout << "Преобразованное число: " << number << std::endl;

	return 0;
}
	// char str1[] = char *str    (char* str1)
	// const char*, чтобы функция могла принимать как указатели на символы, так и массивы символов, что делает её более гибкой
/*  
	Функция userStrcmp сравнивает строки str1 и str2 на равенство, перебирая символы обеих строк и проверяя их на соответствие. 
	Если встречается несовпадение символов, функция возвращает false, означающее, что строки не равны. 
	Если обе строки заканчиваются одновременно нулевым символом, то функция возвращает true, что означает, что строки равны. 
	Если длины строк не совпадают, то функция также возвращает false, так как строки не могут быть равными. 
*/
	// Cравнивает строки на равенство
bool userStrcmp(const char str1[], const char str2[]) {
/*  
	Проверяет, не достигнут ли конец строк. Если символ не является нулевым символом, 
	то условие считается истинным и цикл будет исполняться. Когда достигается нулевой символ, 
	условие становится ложным и цикл завершается. 
*/
	int i = 0;
	while (str1[i] && str2[i]) {
		if (str1[i] != str2[i]) {
			return false; // символы не совпадают, строки не равны
		}
		i++;
	}
	// проверяем, достигнут ли конец обеих строк одновременно
	if (str1[i] == '\0' && str2[i] == '\0') {
		return true; // строки равны
	}
	else {
		return false; // длины строк не совпадают, строки не равны
	}
}

/*  
	Функция userStrcpy копирует содержимое строки str2 в строку str1.
	Она выполняет это, перебирая символы строки str2 и записывая их в str1, пока не достигнет нулевого символа (конца строки).
	Затем она добавляет нулевой символ в конце строки str1, чтобы указать конец строки. 
*/
	// Записывает данные строки 2 в строку 1
void userStrcpy(char str1[], const char str2[]) {
	int i = 0;
	while (str2[i]) {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

/*
	Функция userStrncpy копирует первые n символов строки str2 в строку str1. 
	Она выполняет это, перебирая символы строки str2 и записывая их в str1, пока не достигнет n символов или конца строки str2. 
	Если str2 содержит менее n символов, то оставшиеся символы str1 заполняются нулевыми символами.
*/
	// Записывает n символов строки 2 в строку 1
void userStrncpy(char str1[], const char str2[], int n) {
	int i = 0;
	while (str2[i] && i < n) {
		str1[i] = str2[i];
		i++;
	}
	while (i < n) {
		str1[i] = '\0'; // заполняем оставшиеся символы нулевыми символами
		i++;
	}
}

/*
	Функция userStrncat добавляет первые n символов строки str2 к концу строки str1. 
	Она находит длину строки str1 с помощью функции strlen. 
	Затем перебирает символы строки str2, добавляя их к концу str1, пока не достигнет n символов или конца строки str2. 
	Наконец, к концу строки str1 добавляется нулевой символ.
*/
	// Дописывает n символов строки 2 к строке 1
void userStrncat(char str1[], const char str2[], int n) {
	int len1 = userStrlen(str1); // сохраняется длина строки str1 
	int i = 0;
	while (str2[i] && i < n) {
		str1[len1 + i] = str2[i]; // чтобы записывать символы в конец str1, после его текущей длины.
		i++;
	}
	str1[len1 + i] = '\0'; // гарантирует, что str1 будет корректно завершаться после добавления символов из str2.
}

/*
	Функция userStrlen принимает указатель на строку str и возвращает целочисленное значение - длину указанной строки.
*/
	// Вычисляет длину строки
int userStrlen(const char str[]) {
	int len = 0;
	while (str[len])
		len++;
	return len;
}

// Записывает n символов строки символом symbol
void userStrnset(char str[], char symbol, int n) {
	int i = 0;
	while (str[i] && i < n) {
		str[i] = symbol;
		i++;
	}
}

// Проверка строки на то, что она является целым числом
bool userIsTheStringANumber(const char str[]) {
	int i = 0;
	while (str[i]) {
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

// Проверка строки на то, что она является двоичным значением
bool userIsTheStringABinaryValue(const char str[]) {
	int i = 0;
	if (str[i] == '0' && str[i + 1] == 'b')
		i = 2;
	while (str[i]) {
		if (str[i] != '0' && str[i] != '1')
			return false;
		i++;
	}
	return true;
}

// Проверка строки на то, что она является восьмеричным значением
bool userIsTheStringAOctalValue(const char str[]) {
	int i = 0;
	if (str[i] == '0')
		i = 1;
	while (str[i]) {
		if (str[i] < '0' || str[i] > '7')
			return false;
		i++;
	}
	return true;
}

// Проверка строки на то, что она является шестнадцатеричным значением
bool userIsTheStringAHexadecimalValue(const char str[]) {
	int i = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i = 2;
	while (str[i]) {
		if (!isxdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

/*
	Функция userAtoi преобразует строковое представление целого числа в фактическое целое число. 
	Он использует значение символов ASCII для выполнения преобразования.
*/
	// Преобразовывает строку в целое число
int userAtoi(const char str[]) {
	int result = 0;
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++; // чтобы пропустить эти символы
	while (str[i]) {
		if (!isdigit(str[i]))
			break;
		result = result * 10 + (str[i] - '0'); // символ в числовое значение
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return result;
}
