/*
	������� �������� ��� ��������:
		[�������� ���������]: [������������ �����]
	�������: ���, ����� ������, ���������, ������� ����.
	�������������: ���, ����� ������, �������, ������������� ����������.
	���������: ���, ���������, ��� ����������� �� ������, �����.
	���������: ���, ����� ��������, ����� �����, �������������.
	�����: ���, ���, ��������� �����, ����� ��������.
	SMS-banking: ����, ����� ��������, ����� ��������, ���������� ����� �� �����.
	�������: �������� �������, ����� � ������ �������, �������� �����.
	�������: ��������� ������, ��/���, ����������, �������������.

	������� 2: ��������� � ���������
	1.	�� ��������� ������� 1.1 ����������� ��������� �������:
	1.1.	���������� ���������:
	1.1.1.	struct input();
	1.1.2.	void input(struct*);
	1.2.	���������� ������� ��������:
	1.2.1.	void input(struct[], const int);
	1.3.	���������� ������� �� ������ �� �����:
	1.3.1.	void sort(struct[], const int);
	1.4.	����� ���������:
	1.4.1.	void print(struct);
	1.5.	����� ������� ��������:
	1.5.1.	void print(struct[], const int);
	1.6.	����� �������� �� ������ �� �����:
	1.6.1.	void printSearch(struct[], const int, [?]);
*/

#include <iostream>

using namespace std;


struct Student {
    char name[100];
    int number_of_group;
    int faculty;
    float average_mark;
};

void input(Student& student);

void input(Student arr[], const int len);

void sort(Student arr[], const int len);

void print(Student student);

void print(Student arr[], const int len);

void printSearch(Student arr[], const int len, int number);

int main() {
    system("chcp1251");
    system("cls");
    setlocale(0, "");

    const int LEN = 5;
    Student arr[LEN];

    cout << "\t\t   *������ ��������*" << endl;

    // ���� ������ ���������
    input(arr, LEN);

    cout << "\n\t\t*����������\*" << endl;

    // ���������� �� ���
    sort(arr, LEN);

    cout << "\n\t\t  *����� ���� �������*" << endl;

    // ����� ���� �������
    print(arr, LEN);

    cout << "\n\t*�����*" << endl;

    int number = 0;

    cout << "\n������� ����� ������: ";
    cin >> number;

    // ����� �� ������ ������
    printSearch(arr, LEN, number);

    return 0;
}

// ������� ��� ����� ������ � ���� ���������
void input(Student& student) {
    cout << "������� ������ ��������: " << endl;
    cout << "��� --> "; cin.getline(student.name, 100);
    cout << "����� ������ --> "; cin >> student.number_of_group;
    cout << "��������� --> "; cin >> student.faculty;
    cout << "������ --> "; cin >> student.average_mark;
}

// ������� ��� ����� ������ � ������ ��������
void input(Student arr[], const int len) {
    for (int i = 0; i < len; i++) {
        cout << "������� ������ ��� �������� " << i + 1 << ": " << endl;
        input(arr[i]);
        cin.ignore();
    }
}

// ������� ��� ���������� ������� �������� �� ���� "name"
void sort(Student arr[], const int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� ��� ������ ������ ����� ���������
void print(Student student) {
    cout << "\n������ ��������: " << endl;
    cout << "��� --> " << student.name << endl;
    cout << "����� ������ --> " << student.number_of_group << endl;
    cout << "��������� --> " << student.faculty << endl;
    cout << "������ --> " << student.average_mark << endl;
}

// ������� ��� ������ ������� ��������
void print(Student arr[], const int len) {
    for (int i = 0; i < len; i++) {
        print(arr[i]);
    }
}

// ������� ������
void printSearch(Student arr[], const int len, int number) {
    bool flag = true;

    for (int i = 0; i < len; i++) {
        if (number == arr[i].number_of_group) {
            flag = false;
            print(arr[i]);
        }
    }

    if (flag) {
        cout << "\n����� ������ ���" << endl;
    }
}
