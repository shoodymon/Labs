#include "laba.h"


void symbol_menu() 
{
    char symbol;
    int choice;
    char symbol_encrypted = '\0';


    cout << "\nВведите символ для шифрования (первая буква фамилии на английском): ";
    cin >> symbol;

    do 
    {
        cout << "\n\tМеню шифрования и расшифрования символа:\n";
        cout << "\t1. Зашифровать символ\n";
        cout << "\t2. Зашифровать символ (с выводом промежуточных значений)\n";
        cout << "\t3. Расшифровать символ\n";
        cout << "\t4. Расшифровать символ (с выводом промежуточных значений)\n";
        cout << "\t5. Выход\n";
        cout << "\tВыберите действие: ";
        cin >> choice;

        switch (static_cast<Symbol_Menu>(choice)) 
        {
            case Symbol_Menu::Encrypt: 
            {
                bit_8_t ciphertext = encrypt_char(bit_8_t(symbol));
                symbol_encrypted = static_cast<int>(ciphertext.to_ulong());
                cout << "\nЗашифрованный символ: " << symbol_encrypted << endl;
                break;
            }
            case Symbol_Menu::Encrypt_By_Values: 
            {
                // Реализация с выводом промежуточных значений для шифрования символа
                bit_8_t plaintext_8(symbol);
                bit_8_t ciphertext = encrypt_char(plaintext_8);
                cout << "\nЗашифрованный символ: " << static_cast<char>(ciphertext.to_ulong()) << endl;
                break;
            }
            case Symbol_Menu::Decrypt: 
            {
                bit_8_t plaintext = decrypt_char(bit_8_t(symbol_encrypted));
                cout << "\nРасшифрованный символ: " << static_cast<char>(plaintext.to_ulong()) << endl;
                break;
            }
            case Symbol_Menu::Decrypt_By_Values: 
            {
                // Реализация с выводом промежуточных значений для расшифрования символа
                bit_8_t ciphertext(symbol);
                bit_8_t plaintext = decrypt_char(ciphertext);
                cout << "\nРасшифрованный символ: " << static_cast<char>(plaintext.to_ulong()) << endl;
                break;
            }
            case Symbol_Menu::EXIT:
                cout << "\nМеню шифрования и расшифрования символа --> Главное меню." << endl;
                break;
            default:
                cout << "\nНеверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);

}

void string_menu() 
{
    string str = "";
    string str_encrypted = "";
    int choice;

    cout << "\nВведите строку для шифрования: ";
    cin.clear();
    cin.ignore(); // Игнорируем символ новой строки из предыдущего ввода
    getline(cin, str); // Считываем всю строку, включая пробелы

    do 
    {
        cout << "\n\tМеню для шифрования и расшифрования строки:\n";
        cout << "\t1. Зашифровать строку\n";
        cout << "\t2. Зашифровать строку (с выводом промежуточных значений)\n";
        cout << "\t3. Расшифровать строку\n";
        cout << "\t4. Расшифровать строку (с выводом промежуточных значений)\n";
        cout << "\t5. Выход\n";
        cout << "\tВыберите действие: ";
        cin >> choice;

        switch (static_cast<String_Menu>(choice)) 
        {
            case String_Menu::Encrypt: 
            {
                str_encrypted = encrypt_string(str);
                cout << "\nЗашифрованная строка: " << str_encrypted << endl;
                break;
            }
            case String_Menu::Encrypt_By_Values: 
            {
                string ciphertext = ""; cout << endl;
                for (bit_8_t c : str) {
                    bit_8_t cipherchar = encrypt_char(bit_8_t(c));
                    cout << "Промежуточное значение для символа '" << c << "': " << static_cast<char>(cipherchar.to_ulong()) << endl;
                    ciphertext += static_cast<char>(cipherchar.to_ulong());
                }
                cout << "\nЗашифрованная строка: " << ciphertext << endl;
                break;
            }
            case String_Menu::Decrypt: 
            {
                str = decrypt_string(str_encrypted);
                cout << "\nРасшифрованная строка: " << str << endl;
                break;
            }
            case String_Menu::Decrypt_By_Values: 
            {
                string plaintext = ""; cout << endl;
                for (char c : str) {
                    bit_8_t plainchar = decrypt_char(bit_8_t(c));
                    cout << "Промежуточное значение для символа '" << c << "': " << static_cast<char>(plainchar.to_ulong()) << endl;
                    plaintext += static_cast<char>(plainchar.to_ulong());
                }
                cout << "\nРасшифрованная строка: " << plaintext << endl;
                break;
            }
            case String_Menu::EXIT:
                cout << "\nМеню для шифрования и расшифрования строки --> Главное меню." << endl;
                break;
            default:
                cout << "\nНеверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);
}

void main_menu() {
    int choice;

    do 
    {
        cout << "\n\tГлавное меню:\n";
        cout << "\t1. Работа с символом\n";
        cout << "\t2. Работа со строкой\n";
        cout << "\t3. Выход\n";
        cout << "\tВыберите действие: ";
        cin >> choice;

        switch (static_cast<Main_Menu>(choice)) 
        {
            case Main_Menu::Symbol_Menu:    symbol_menu();                                              break;
            case Main_Menu::String_Menu:    string_menu();                                              break;
            case Main_Menu::EXIT:           cout << "\n\tВыход из программы =(" << endl;                break;
            default:                        cout << "\n\tНеверный выбор. Попробуйте снова." << endl;
        }

    } while (choice != 3);
}