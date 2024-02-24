/*
    ������� 2.2:
  ������� �������� ���� (.dat/.bin) �� ������� 2.1.
  ������� ��� ������ �� ����� � ������ ��������:
  ������������ ������� ��������� ��������� ��� ���������� ������: ����������� �������� � �����.
  *������ ������������� ������� ��������� ��������� �������: 1) ������ ���������� � ���� �������� - ���������� ���������� ��������,
    ��� 2) �������� ��� �������� � �����, ��� 3) ���������� ���������� ���������� �������� ��� ������ sizeof().
  *������������ �� ������ ������, � ������ ���������� � ��� ������ ��������� �������� ������ ��������.
  ������� ���������� ������ ��������.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Atributes {
    int strength;
    int agility;
    int intelligence;
};

struct Hero {
    int id;
    string name;
    Atributes atributes;
    int hp;
    int mana;
    int damage;
    int armor;
};


int main() {
    setlocale(0, "");

    // ��������� �������� ���� ��� ������
    ifstream file("E:\\Microsoft Visual Studio\\Projects\\Laba_1\\Laba_9\\Laba_9_2_1\\heroes.dat", ios::binary);
    
    int number_of_heroes;

    // ������ ���������� �������� �� �����
    file.read((char*)(&number_of_heroes), sizeof(number_of_heroes));

    // ������� ������ ���������� �� ���������
    Hero** heroes_arr = new Hero*[number_of_heroes];

    // ������ ��������� �� �����
    for (int i = 0; i < number_of_heroes; i++) {
        if (file.eof()) {                               // ��� ������� ��� ����� ������ ����� ���������� ����� �����
            cerr << "End of file reached prematurely." << endl;
            break;
        }
        heroes_arr[i] = new Hero;
        file.read((char*)(heroes_arr[i]), sizeof(Hero));
    }

    file.close();

    // ����� ����������� ������� ��������
    for (int i = 0; i < number_of_heroes; i++) {
        cout << "����� " << i + 1 << ": " << heroes_arr[i]->name << endl;
        cout << "\tid: " << heroes_arr[i]->id << endl;              // (*heroes_arr[i]).id
        cout << "\t���: " << heroes_arr[i]->name << endl;
        cout << "\t-----------------------" << endl;
        cout << "\t�������� " << endl;
        cout << "\t����: " << heroes_arr[i]->atributes.strength << endl;
        cout << "\t��������: " << heroes_arr[i]->atributes.agility << endl;
        cout << "\t���������: " << heroes_arr[i]->atributes.intelligence << endl;
        cout << "\t-----------------------" << endl;
        cout << "\t��������: " << heroes_arr[i]->hp << endl;
        cout << "\t����: " << heroes_arr[i]->mana << endl;
        cout << "\t-----------------------" << endl;
        cout << "\t����: " << heroes_arr[i]->damage << endl;
        cout << "\t�����: " << heroes_arr[i]->armor << endl;
        cout << "\t-----------------------" << endl;
    }

    for (int i = 0; i < number_of_heroes; i++)
        delete heroes_arr[i];

    delete[] heroes_arr;

    return 0;
}
