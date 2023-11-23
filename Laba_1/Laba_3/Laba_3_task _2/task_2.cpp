/* ������� 2: do-while
	���������� ���������, ���� ������� ����������� � �������� �������� ��������.
	������: ���� ���� � 4-�� ���������: ����� ����������, ���������� ����������, �������� ����������, ���������� ���������. 
	� ���� ����� ���������� ���� ����������� �������� � � ������, ���� ���� �������� ������������ (����� �� ������ � �������� ���������� ��������), 
	�� ���������� ��������� � ���, ��� ���� ������������ � ��������� ������.
*/

/* #include <iostream>

using namespace std;

int main() {
	setlocale(0, "");

	int number = 0;
	do {
		cout << "������� ����� � ��������� 1 - 100 ";
		cout << "������� ����� --> " << endl;
		cin >> number;

		if (number < 0 || number > 100) 
			cout << "�� ����� ������������ �����. ���������� ��� ���!" << endl;

	} while (number);


	system("pause");
	return 0;
} */

#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");

    int choice;

    do {
        // ����
        cout << "����:" << endl;
        cout << "1. ������� ����" << endl;
        cout << "2. �������� ����" << endl;
        cout << "3. ������� ����" << endl;
        cout << "4. ��������� ���������" << endl;
        cout << "�������� �������� (1-4): ";
        cin >> choice;

        // �������� ������
        if (choice < 1 || choice > 4) {
            cout << "������������ �����. �������� �������� �� 1 �� 4." << endl;
        }
        else {
            // ��������� ������
            switch (choice) {
            case 1:
                cout << "��������� �����-�� ����" << endl;
                break;
            case 2:
                cout << "���������� �����-�� ����" << endl;
                break;
            case 3:
                cout << "�������� ����" << endl;
                break;
            case 4:
                cout << "��������� ���������." << endl;
                break;
            }
        }

    } while (choice != 4); 

    return 0;
}