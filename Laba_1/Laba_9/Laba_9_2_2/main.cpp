/*
    Задание 2.2:
  Открыть бинарный файл (.dat/.bin) из задания 2.1.
  Считать все записи из файла в массив структур:
  Пользоваться заранее известным значением при считывания данных: количеством структур в файле.
  *вместо использования заранее известным значением сделать: 1) первое записанное в файл значение - количество записанных структур,
    или 2) записать это значение в конце, или 3) определять количество записанных структур при помощи sizeof().
  *Использовать не просто массив, а массив указателей и под каждую структуру выделять память отдельно.
  Вывести полученный массив структур.
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

    // Открываем бинарный файл для чтения
    ifstream file("E:\\Microsoft Visual Studio\\Projects\\Laba_1\\Laba_9\\Laba_9_2_1\\heroes.dat", ios::binary);
    
    int number_of_heroes;

    // Читаем количество структур из файла
    file.read((char*)(&number_of_heroes), sizeof(number_of_heroes));

    // Создаем массив указателей на структуры
    Hero** heroes_arr = new Hero*[number_of_heroes];

    // Читаем структуры из файла
    for (int i = 0; i < number_of_heroes; i++) {
        if (file.eof()) {                               // нет ошибкам при вводе данных после достижения конца файла
            cerr << "End of file reached prematurely." << endl;
            break;
        }
        heroes_arr[i] = new Hero;
        file.read((char*)(heroes_arr[i]), sizeof(Hero));
    }

    file.close();

    // Вывод полученного массива структур
    for (int i = 0; i < number_of_heroes; i++) {
        cout << "Герой " << i + 1 << ": " << heroes_arr[i]->name << endl;
        cout << "\tid: " << heroes_arr[i]->id << endl;              // (*heroes_arr[i]).id
        cout << "\tИмя: " << heroes_arr[i]->name << endl;
        cout << "\t-----------------------" << endl;
        cout << "\tАтрибуты " << endl;
        cout << "\tСила: " << heroes_arr[i]->atributes.strength << endl;
        cout << "\tЛовкость: " << heroes_arr[i]->atributes.agility << endl;
        cout << "\tИнтеллект: " << heroes_arr[i]->atributes.intelligence << endl;
        cout << "\t-----------------------" << endl;
        cout << "\tЗдоровье: " << heroes_arr[i]->hp << endl;
        cout << "\tМана: " << heroes_arr[i]->mana << endl;
        cout << "\t-----------------------" << endl;
        cout << "\tУрон: " << heroes_arr[i]->damage << endl;
        cout << "\tБроня: " << heroes_arr[i]->armor << endl;
        cout << "\t-----------------------" << endl;
    }

    for (int i = 0; i < number_of_heroes; i++)
        delete heroes_arr[i];

    delete[] heroes_arr;

    return 0;
}
