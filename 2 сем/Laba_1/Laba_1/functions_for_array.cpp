#include <iostream>
#include <string>
#include "functions_for_array.h"

void input(Game* game, const int SIZE) {
    int choice = 0;
    fstream file_1("E:\\Microsoft Visual Studio\\Projects\\2 ���\\Laba_1\\Laba_1_2\\hero_data.txt");
    fstream file_2("E:\\Microsoft Visual Studio\\Projects\\2 ���\\Laba_1\\Laba_1_2\\item_data.txt");
    string str = "";

    cout << "\t��������, ��� ������ �� ������ ��������!\n";
    cout << "1) �����\n";
    cout << "2) �������\n\n";
    cout << "��� ����� --> ";  cin >> choice;  cout << '\n' << '\n';

    if (choice == 1) {
        cout << "\t��� ��������� ������?\n";
        cout << "1) �������\n";
        cout << "2) �� ��������� �� �����\n";
        cout << "\n\t��� ����� --> ";	cin >> choice;	cout << '\n' << '\n';

        if (choice == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "���������� ������ ��������." << endl;
                cout << "\t����� #" << i + 1 << ": " << endl;
                cout << "\t������� id �����: ";               cin >> game[i].hero.id;
                cout << "\t������� ��� �����: ";              cin >> game[i].hero.name;
                cout << "\t������� ���-�� �������� �����: ";  cin >> game[i].hero.health;
                cout << "\t������� ���-�� ���� �����: ";      cin >> game[i].hero.mana;
                cout << "\t������� ���-�� ����� �����: ";     cin >> game[i].hero.damage;
                cout << "\t������� ���-�� ����� �����: ";     cin >> game[i].hero.armor;
                game[i].hero.type = 'H';
            }
        }
        else if (choice == 2) {
            cout << "\t\t���������� ������� �����:\n\n";
            if (file_1.is_open()) {
                for (int i = 0; i < SIZE; i++) {
                    getline(file_1, str);
                    game[i].hero.id = atoi(str.c_str());

                    getline(file_1, str);
                    strcpy_s(game[i].hero.name, sizeof(game[i].hero.name), str.c_str());

                    getline(file_1, str);
                    game[i].hero.health = atoi(str.c_str());

                    getline(file_1, str);
                    game[i].hero.mana = atoi(str.c_str());

                    getline(file_1, str);
                    game[i].hero.damage = atoi(str.c_str());

                    getline(file_1, str);
                    game[i].hero.armor = atoi(str.c_str());

                    game[i].hero.type = 'H';
                }
                cout << "\t������ ������� �������!\n";
            }
            else { cout << "\t�� ������� ������� ����!\n\n"; }
        }
    }
    else if (choice == 2) {
        cout << "\t��� ��������� ������?\n";
        cout << "1) �������\n";
        cout << "2) �� ��������� �� �����\n";
        cout << "\n\t��� ����� --> ";	cin >> choice;	cout << '\n' << '\n';

        if (choice == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "���������� ������ ��������." << endl;
                cout << "\t������� #" << i + 1 << ": " << endl;
                cout << "\t������� id ��������: ";                cin >> game[i].item.id;
                cout << "\t������� ������������ ��������: ";      cin >> game[i].item.name;
                cout << "\t������� ���-�� �������� ��������: ";   cin >> game[i].item.health;
                cout << "\t������� ���-�� ���� ��������: ";       cin >> game[i].item.mana;
                cout << "\t������� ���-�� ����� ��������: ";      cin >> game[i].item.damage;
                cout << "\t������� ���-�� ����� ��������: ";      cin >> game[i].item.armor;
                game[i].item.type = 'I';
            }
        }
        else if (choice == 2) {
            cout << "\t\t���������� ������� �����:\n\n";
            if (file_2.is_open()) {
                for (int i = 0; i < SIZE; i++) {
                    getline(file_2, str);
                    game[i].item.id = atoi(str.c_str());

                    getline(file_2, str);
                    strcpy_s(game[i].item.name, sizeof(game[i].item.name), str.c_str());

                    getline(file_2, str);
                    game[i].item.health = atoi(str.c_str());

                    getline(file_2, str);
                    game[i].item.mana = atoi(str.c_str());

                    getline(file_2, str);
                    game[i].item.damage = atoi(str.c_str());

                    getline(file_2, str);
                    game[i].hero.armor = atoi(str.c_str());

                    game[i].item.type = 'I';
                }
                cout << "\t������ ������� �������!\n";
            }
            else { cout << "\t�� ������� ������� ����!\n\n"; }
        }
    }
}

void remove_element(Game* game, const int& SIZE) {
    int size = SIZE; // ������� ��������� ���������� ��� �������� ����������� �������� SIZE
    int index;
    cout << "������� id �������� ��� ��������: "; cin >> index; index -= 1;
    if (index > 0 && index <= size) {
        // �������� �������� �����, ����� ������� �������
        for (int i = index + 1; i < size; i++) {
            game[i - 1] = game[i];
            size--;
        }
        // �������� ������� ��� ���������
        if (game[index].hero.id != 0)
            game[index].hero.deleted = true;
        else if (game[index].item.id != 0)
            game[index].item.deleted = true;
        cout << "������� ������� �����!" << endl;
    }
    else {
        cout << "�������� ������ ��������." << endl;
    }
}

void output(Game* game, const int SIZE) {
    int numb = 0;

    cout << "������� ����� ����� � ��������, ������ ������� �� ������ �������: ";
    cin >> numb;    cout << endl;

    if ((game[numb - 1].hero.id != 0)) {
        cout << "\t����� #" << numb << ":\n";
        cout << "\t���: " << game[numb - 1].hero.name << endl;
        cout << "\t��������: " << game[numb - 1].hero.health << endl;
        cout << "\t����: " << game[numb - 1].hero.mana << endl;
        cout << "\t����: " << game[numb - 1].hero.damage << endl;
        cout << "\t�����: " << game[numb - 1].hero.armor << endl << endl;
    }
    else if ((game[numb - 1].item.id != 0)) {
        cout << "\t������� #" << numb << ":\n";
        cout << "\t���: " << game[numb - 1].item.name << endl;
        cout << "\t��������: " << game[numb - 1].item.health << endl;
        cout << "\t����: " << game[numb - 1].item.mana << endl;
        cout << "\t����: " << game[numb - 1].item.damage << endl;
        cout << "\t�����: " << game[numb - 1].item.armor << endl << endl;
    }
    else {
        cout << "������ �� ���������!\n\n";
    }
}

void output_arr(Game* game, const int SIZE) {
    if (SIZE == 0) {
        cout << "������ ����." << endl;
    }
    else {
        cout << "������ ��������: " << endl;
        for (int i = 0; i < SIZE; i++) {
            if (!game[i].hero.deleted || !game[i].item.deleted) {
                // ������� ������ � ����� ��� �������� � ����������� �� ����������� ���������
                if (game[i].hero.type == 'H') {
                    cout << "\t����� #" << i + 1 << ": " << game[i].hero.name << endl;
                    cout << "\t��� ��������������: " << endl;
                    cout << "\t��������: " << game[i].hero.health << endl;
                    cout << "\t����: " << game[i].hero.mana << endl;
                    cout << "\t����: " << game[i].hero.damage << endl;
                    cout << "\t�����: " << game[i].hero.armor << endl;
                    cout << endl;
                }
                else if (game[i].item.type == 'I') {
                    cout << "\t������� #" << i + 1 << ": " << game[i].item.name << endl;
                    cout << "\t��� ��������������: " << endl;
                    cout << "\t��������: " << game[i].item.health << endl;
                    cout << "\t����: " << game[i].item.mana << endl;
                    cout << "\t����: " << game[i].item.damage << endl;
                    cout << "\t�����: " << game[i].item.armor << endl;
                    cout << endl;
                }
            }
        }
    }
}
