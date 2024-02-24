/* 
	������� 1.1: �������� �� ������� ����� ��������� ������� 
	� ��������� �������� ������, ��� ������ �������� �� 20 ���������, � ���������������� ��� ������ ������ (�� -> {�\0�}). 
	����������� ��������� �������, ����������������� �� �����������������:
		- ���������� ������ �� ���������: bool userStrcmp(str1, str2)
		- ���������� ������ ������ 2 � ������ 1: void userStrcpy(str1, str2)
		- ���������� n �������� ������ 2 � ������ 1: void userStrncpy(str1, str2, n)
		- ���������� n �������� ������ 2 � ������ 1: void userStrncat(str1, str2, n)
		- ��������� ����� ������: int userStrlen(str)
		- ���������� n �������� ������ �������� symbol: void userStrnset(str, symbol, n)
		- �������� ������ �� ��, ��� ��� �������� ����� ������: bool userIsTheStringANumber(str)
		- �������� ������ �� ��, ��� ��� �������� �������� ���������: bool userIsTheStringABinaryValue(str)
		- �������� ������ �� ��, ��� ��� �������� ������������ ���������: bool userIsTheStringAOctalValue(str)
		- �������� ������ �� ��, ��� ��� �������� ����������������� ���������: bool userIsTheStringAHexadecimalValue(str)
		- ��������������� ������ � ����� �����: int userAtoi(str)
	������ ������ ��� ��������� ����� ����������, ������� ��� ���������������� ��� ����������, ��� �������� �������������, 
	��� � ������� ��������� ��������� �������. 
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

	// ������� ������, ��� ������ �������� �� 20 ���������, � �������������� ��� ������ ������
	char str1[20] = "";
	const char* str2 = "Hello, world!";

	// ������ � ���������
	bool equal = userStrcmp(str1, str2);
	std::cout << "������ " << (equal ? "�����" : "�� �����") << std::endl;

	userStrcpy(str1, str2);
	std::cout << "������������� ������: " << str1 << std::endl;

	userStrncpy(str1, str2, 7);
	std::cout << "������������� ������ � n - ���������: " << str1 << std::endl;

	userStrncat(str1, str2, 5);
	std::cout << "������������ ������: " << str1 << std::endl;

	int length = userStrlen(str1);
	std::cout << "����� ������: " << length << std::endl;

	userStrnset(str1, '*', 6);
	std::cout << "������ ����� ��������� n - �������� � '*': " << str1 << std::endl;

	bool isNumber = userIsTheStringANumber("1423");
	std::cout << "�������� �� '1423' ������? " << (isNumber ? "��" : "���") << std::endl;

	bool isBinary = userIsTheStringABinaryValue("0b1210");
	std::cout << "�������� �� '0b1211' �������� ���������? " << (isBinary ? "��" : "���") << std::endl;

	bool isOctal = userIsTheStringAOctalValue("0374");
	std::cout << "�������� �� '0374' ������������ ���������? " << (isOctal ? "��" : "���") << std::endl;

	bool isHexadecimal = userIsTheStringAHexadecimalValue("0xAC");
	std::cout << "�������� �� '0xAC' ����������������� ���������? " << (isHexadecimal ? "��" : "���") << std::endl;

	int number = userAtoi("1234");
	std::cout << "��������������� �����: " << number << std::endl;

	return 0;
}

bool userStrcmp(const char str1[], const char str2[]) {
	int i = 0;
	while (str1[i] && str2[i]) {
		if (str1[i] != str2[i]) {
			return false; // ������� �� ���������, ������ �� �����
		}
		i++;
	}
	// ���������, ��������� �� ����� ����� ����� ������������
	if (str1[i] == '\0' && str2[i] == '\0') {
		return true; // ������ �����
	}
	else {
		return false; // ����� ����� �� ���������, ������ �� �����
	}
}

void userStrcpy(char str1[], const char str2[]) {
	int i = 0;
	while (str2[i]) {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

void userStrncpy(char str1[], const char str2[], int n) {
	int i = 0;
	while (str2[i] && i < n) {
		str1[i] = str2[i];
		i++;
	}
	while (i < n) {
		str1[i] = '\0'; // ��������� ���������� ������� �������� ���������
		i++;
	}
}

void userStrncat(char str1[], const char str2[], int n) {
	int len1 = userStrlen(str1); // ����������� ����� ������ str1 
	int i = 0;
	while (str2[i] && i < n) {
		str1[len1 + i] = str2[i]; // ����� ���������� ������� � ����� str1, ����� ��� ������� �����.
		i++;
	}
	str1[len1 + i] = '\0'; // �����������, ��� str1 ����� ��������� ����������� ����� ���������� �������� �� str2.
}

int userStrlen(const char str[]) {
	int len = 0;
	while (str[len])
		len++;
	return len;
}

void userStrnset(char str[], char symbol, int n) {
	int i = 0;
	while (str[i] && i < n) {
		str[i] = symbol;
		i++;
	}
}

bool userIsTheStringANumber(const char str[]) {
	int i = 0;
	while (str[i]) {
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

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

int userAtoi(const char str[]) {
	int result = 0;
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++; // ����� ���������� ��� �������
	while (str[i]) {
		if (!isdigit(str[i]))
			break;
		result = result * 10 + (str[i] - '0'); // ������ � �������� ��������
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return result;
}
