#include <iostream>


bool userStrcmp(char* str1, const char* str2);
void userStrcpy(char* str1, const char* str2);
void userStrncpy(char* str1, const char* str2, int n);
void userStrncat(char* str1, const char* str2, int n);
int userStrlen(const char* str);
void userStrnset(char* str, char symbol, int n);
bool userIsTheStringANumber(const char* str);
bool userIsTheStringABinaryValue(const char* str);
bool userIsTheStringAOctalValue(const char* str);
bool userIsTheStringAHexadecimalValue(const char* str);
int userAtoi(const char* str);

int main() {
	setlocale(0, "");

	// Создаем строку, как массив символов на 20 элементов, и инициализируем как пустую строку
	char str1[20] = "";
	const char* str2 = "Hello, world!";

	// Работа с функциями
	bool equal = userStrcmp(str1, str2);
	std::cout << "Strings are " << (equal ? "equal" : "not equal") << std::endl;

	userStrcpy(str1, str2);
	std::cout << "Copied string: " << str1 << std::endl;

	userStrncpy(str1, str2, 5);
	std::cout << "Copied string with n characters: " << str1 << std::endl;

	userStrncat(str1, str2, 3);
	std::cout << "Concatenated string: " << str1 << std::endl;

	int length = userStrlen(str1);
	std::cout << "Length of string: " << length << std::endl;

	userStrnset(str1, '*', 5);
	std::cout << "String after setting n characters to '*': " << str1 << std::endl;

	bool isNumber = userIsTheStringANumber("1234");
	std::cout << "Is '1234' a number? " << (isNumber ? "Yes" : "No") << std::endl;

	bool isBinary = userIsTheStringABinaryValue("0b1010");
	std::cout << "Is '0b1010' a binary value? " << (isBinary ? "Yes" : "No") << std::endl;

	bool isOctal = userIsTheStringAOctalValue("0777");
	std::cout << "Is '0777' an octal value? " << (isOctal ? "Yes" : "No") << std::endl;

	bool isHexadecimal = userIsTheStringAHexadecimalValue("0xFF");
	std::cout << "Is '0xFF' a hexadecimal value? " << (isHexadecimal ? "Yes" : "No") << std::endl;

	int number = userAtoi("1234");
	std::cout << "Converted number: " << number << std::endl;

	return 0;
}

bool userStrcmp(char* str1, const char* str2) {
    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return true;
}

void userStrcpy(char* str1, const char* str2) {
	while (*str2) {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
}

void userStrncpy(char* str1, const char* str2, int n) {
	while (*str2 && n > 0) {
		*str1++ = *str2++;
		n--;
	}
	while (n > 0) {
		*str1++ = '\0';
		n--;
	}
}

void userStrncat(char* str1, const char* str2, int n) {
	int len1 = userStrlen(str1);
	while (*str2 && n > 0) {
		*(str1 + len1) = *str2++;
		str1++;
		n--;
	}
	*(str1 + len1) = '\0';
}

int userStrlen(const char* str) {
	int len = 0;
	while (*str) {
		len++;
		str++;
	}
	return len;
}

void userStrnset(char* str, char symbol, int n) {
	while (*str && n > 0) {
		*str = symbol;
		str++;
		n--;
	}
}

bool userIsTheStringANumber(const char* str) {
	const char* i = str;
	while (*i) {
		if (!isdigit(*i))
			return false;
		i++;
	}
	return true;
}

bool userIsTheStringABinaryValue(const char* str) {
	const char* i = str;
	if (*i == '0' && *(i + 1) == 'b')
		i += 2;
	while (*i) {
		if (*i != '0' && *i != '1')
			return false;
		i++;
	}
	return true;
}

bool userIsTheStringAOctalValue(const char* str) {
	const char* i = str;
	if (*i == '0')
		i++;
	while (*i) {
		if (*i < '0' || *i > '7')
			return false;
		i++;
	}
	return true;
}

bool userIsTheStringAHexadecimalValue(const char* str) {
	const char* i = str;
	if (*i == '0' && (*(i + 1) == 'x' || *(i + 1) == 'X'))
		i += 2;
	while (*i) {
		if (!isxdigit(*i))
			return false;
		i++;
	}
	return true;
}

int userAtoi(const char* str) {
	int result = 0;
	const char* i = str;
	if (*i == '-' || *i == '+')
		i++; 
	while (*i) {
		if (!isdigit(*i))
			break;
		result = result * 10 + (*i - '0'); 
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return result;
}
