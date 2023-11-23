/*
	������� 2: �����������
	������� 2.2:
		����������� ������ �� ������ ������������� ����������� ��� �������� ������, 
		� ������� �������� � �������� �������� �������� ���� �� ���������� �������� (������� 2-��) �� �����.
*/

#include <iostream>

using namespace std;

/*
   ��������� UnionExample �������� ��� ����:
   - data - ��� ����������� (union) � ������������ ������ ��� �������� ������ ����� ������
   - dataType - ��� ����� �����, ������� ����� �������������� ��� ����������� ���� ������, ����������� � ����������� data.
*/
union Data {
    int intValue;
    double doubleValue;
    char stringValue[20];
};

struct UnionExample {
    Data data;
    int dataType; // 0 for int, 1 for double, 2 for string
};

int main() {
    setlocale(0, "");

    // ������ list �� �������� UnionExample � ����� ����������
    UnionExample list[3];

    // ��� ������� �������� ������� list ������ dataType, ����� �������, ����� ��� ������ �� ����� ������� � ����������� data.
    list[0].dataType = 0;
    list[0].data.intValue = 42;

    list[1].dataType = 1;
    list[1].data.doubleValue = 3.14;

    list[2].dataType = 2;
    strcpy_s(list[2].data.stringValue, "Hello, World!"); // ��� ��� ���� data ����������� Data ����� ������ �������� ����� ������ 

    /*
        ��� ������� �������� �� ��������� �������� dataType � � ����������� �� ����� ���� ������� ������, 
        ������� �������� � ����������� data.��������� ��������� ������� �� ���� ������, ������� �� ����� ����������.    
    */ 

    for (int i = 0; i < 3; i++) {
        switch (list[i].dataType) {
        case 0:
            cout << "����� �����: " << list[i].data.intValue << endl;
            break;
        case 1:
            cout << "���������� �����: " << list[i].data.doubleValue << endl;
            break;
        case 2:
            cout << "������: " << list[i].data.stringValue << endl;
            break;
        default:
            cout << "����������� ��� ������." << endl;
        }
    }

    return 0;
}
