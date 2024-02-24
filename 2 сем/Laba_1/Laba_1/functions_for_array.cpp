#include <iostream>
#include <string>
#include "functions_for_array.h"

void input(Game* game, const int SIZE) {
    int choice = 0;
    fstream file_1("E:\\Microsoft Visual Studio\\Projects\\2 сем\\Laba_1\\Laba_1_2\\hero_data.txt");
    fstream file_2("E:\\Microsoft Visual Studio\\Projects\\2 сем\\Laba_1\\Laba_1_2\\item_data.txt");
    string str = "";

    cout << "\tВыберите, что именно вы хотите добавить!\n";
    cout << "1) Герой\n";
    cout << "2) Предмет\n\n";
    cout << "Ваш выбор --> ";  cin >> choice;  cout << '\n' << '\n';

    if (choice == 1) {
        cout << "\tКак заполняем данные?\n";
        cout << "1) Вручную\n";
        cout << "2) По умолчанию из файла\n";
        cout << "\n\tВаш выбор --> ";	cin >> choice;	cout << '\n' << '\n';

        if (choice == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "Добавление нового элемента." << endl;
                cout << "\tГерой #" << i + 1 << ": " << endl;
                cout << "\tВведите id героя: ";               cin >> game[i].hero.id;
                cout << "\tВведите имя героя: ";              cin >> game[i].hero.name;
                cout << "\tВведите кол-во здоровья героя: ";  cin >> game[i].hero.health;
                cout << "\tВведите кол-во маны героя: ";      cin >> game[i].hero.mana;
                cout << "\tВведите кол-во урона героя: ";     cin >> game[i].hero.damage;
                cout << "\tВведите кол-во брони героя: ";     cin >> game[i].hero.armor;
                game[i].hero.type = 'H';
            }
        }
        else if (choice == 2) {
            cout << "\t\tСодержимое данного файла:\n\n";
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
                cout << "\tДанные успещно внесены!\n";
            }
            else { cout << "\tНе удалось открыть файл!\n\n"; }
        }
    }
    else if (choice == 2) {
        cout << "\tКак заполняем данные?\n";
        cout << "1) Вручную\n";
        cout << "2) По умолчанию из файла\n";
        cout << "\n\tВаш выбор --> ";	cin >> choice;	cout << '\n' << '\n';

        if (choice == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "Добавление нового элемента." << endl;
                cout << "\tПредмет #" << i + 1 << ": " << endl;
                cout << "\tВведите id предмета: ";                cin >> game[i].item.id;
                cout << "\tВведите наименование предмета: ";      cin >> game[i].item.name;
                cout << "\tВведите кол-во здоровья предмета: ";   cin >> game[i].item.health;
                cout << "\tВведите кол-во маны предмета: ";       cin >> game[i].item.mana;
                cout << "\tВведите кол-во урона предмета: ";      cin >> game[i].item.damage;
                cout << "\tВведите кол-во брони предмета: ";      cin >> game[i].item.armor;
                game[i].item.type = 'I';
            }
        }
        else if (choice == 2) {
            cout << "\t\tСодержимое данного файла:\n\n";
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
                cout << "\tДанные успещно внесены!\n";
            }
            else { cout << "\tНе удалось открыть файл!\n\n"; }
        }
    }
}

void remove_element(Game* game, const int& SIZE) {
    int size = SIZE; // Создаем временную переменную для хранения изменяемого значения SIZE
    int index;
    cout << "Введите id элемента для удаления: "; cin >> index; index -= 1;
    if (index > 0 && index <= size) {
        // Сдвигаем элементы влево, чтобы удалить элемент
        for (int i = index + 1; i < size; i++) {
            game[i - 1] = game[i];
            size--;
        }
        // Помечаем элемент как удаленный
        if (game[index].hero.id != 0)
            game[index].hero.deleted = true;
        else if (game[index].item.id != 0)
            game[index].item.deleted = true;
        cout << "Элемент успешно удалён!" << endl;
    }
    else {
        cout << "Неверный индекс элемента." << endl;
    }
}

void output(Game* game, const int SIZE) {
    int numb = 0;

    cout << "Введите номер героя и предмета, данные которых вы хотите вывести: ";
    cin >> numb;    cout << endl;

    if ((game[numb - 1].hero.id != 0)) {
        cout << "\tГерой #" << numb << ":\n";
        cout << "\tИмя: " << game[numb - 1].hero.name << endl;
        cout << "\tЗдоровье: " << game[numb - 1].hero.health << endl;
        cout << "\tМана: " << game[numb - 1].hero.mana << endl;
        cout << "\tУрон: " << game[numb - 1].hero.damage << endl;
        cout << "\tБроня: " << game[numb - 1].hero.armor << endl << endl;
    }
    else if ((game[numb - 1].item.id != 0)) {
        cout << "\tПредмет #" << numb << ":\n";
        cout << "\tИмя: " << game[numb - 1].item.name << endl;
        cout << "\tЗдоровье: " << game[numb - 1].item.health << endl;
        cout << "\tМана: " << game[numb - 1].item.mana << endl;
        cout << "\tУрон: " << game[numb - 1].item.damage << endl;
        cout << "\tБроня: " << game[numb - 1].item.armor << endl << endl;
    }
    else {
        cout << "Данные не заполнены!\n\n";
    }
}

void output_arr(Game* game, const int SIZE) {
    if (SIZE == 0) {
        cout << "Массив пуст." << endl;
    }
    else {
        cout << "Массив структур: " << endl;
        for (int i = 0; i < SIZE; i++) {
            if (!game[i].hero.deleted || !game[i].item.deleted) {
                // Выводим данные о герое или предмете в зависимости от заполненной структуры
                if (game[i].hero.type == 'H') {
                    cout << "\tГерой #" << i + 1 << ": " << game[i].hero.name << endl;
                    cout << "\tЕго характеристики: " << endl;
                    cout << "\tЗдоровье: " << game[i].hero.health << endl;
                    cout << "\tМана: " << game[i].hero.mana << endl;
                    cout << "\tУрон: " << game[i].hero.damage << endl;
                    cout << "\tБроня: " << game[i].hero.armor << endl;
                    cout << endl;
                }
                else if (game[i].item.type == 'I') {
                    cout << "\tПредмет #" << i + 1 << ": " << game[i].item.name << endl;
                    cout << "\tЕго характеристики: " << endl;
                    cout << "\tЗдоровье: " << game[i].item.health << endl;
                    cout << "\tМана: " << game[i].item.mana << endl;
                    cout << "\tУрон: " << game[i].item.damage << endl;
                    cout << "\tБроня: " << game[i].item.armor << endl;
                    cout << endl;
                }
            }
        }
    }
}
