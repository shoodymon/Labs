#include "laba.h"


void symbol_menu() 
{
    char symbol;
    int choice;

    cout << "\n������� ������ ��� ���������� (������ ����� ������� �� ����������): ";
    cin >> symbol;

    char symbol_encrypted = '\0';
    do 
    {
        cout << "\n\t���� ���������� � ������������� �������:\n";
        cout << "\t1. ����������� ������\n";
        cout << "\t2. ����������� ������ (� ������� ������������� ��������)\n";
        cout << "\t3. ������������ ������\n";
        cout << "\t4. ������������ ������ (� ������� ������������� ��������)\n";
        cout << "\t5. �����\n";
        cout << "\t�������� ��������: ";
        cin >> choice;

        switch (static_cast<Symbol_Menu>(choice)) 
        {
            case Symbol_Menu::Encrypt: 
            {
                bit_8_t ciphertext = encrypt_char(bit_8_t(symbol));
                symbol_encrypted = static_cast<int>(ciphertext.to_ulong());
                cout << "\n������������� ������: " << symbol_encrypted << endl;
                break;
            }
            case Symbol_Menu::Encrypt_By_Values: 
            {
                // ���������� � ������� ������������� �������� ��� ���������� �������
                bit_8_t plaintext_8(symbol);
                bit_8_t ciphertext = encrypt_char(plaintext_8);
                cout << "\n������������� ������: " << static_cast<char>(ciphertext.to_ulong()) << endl;
                break;
            }
            case Symbol_Menu::Decrypt: 
            {
                bit_8_t plaintext = decrypt_char(bit_8_t(symbol_encrypted));
                cout << "\n�������������� ������: " << static_cast<char>(plaintext.to_ulong()) << endl;
                break;
            }
            case Symbol_Menu::Decrypt_By_Values: 
            {
                // ���������� � ������� ������������� �������� ��� ������������� �������
                bit_8_t ciphertext(symbol);
                bit_8_t plaintext = decrypt_char(ciphertext);
                cout << "\n�������������� ������: " << static_cast<char>(plaintext.to_ulong()) << endl;
                break;
            }
            case Symbol_Menu::EXIT:
                cout << "\n���� ���������� � ������������� ������� --> ������� ����." << endl;
                break;
            default:
                cout << "\n�������� �����. ���������� �����." << endl;
        }
    } while (choice != 5);

}

void string_menu() 
{
    string str = "";
    string str_encrypted = "";
    int choice;

    cout << "\n������� ������ ��� ����������: ";
    cin.clear();
    cin.ignore(); // ���������� ������ ����� ������ �� ����������� �����
    getline(cin, str); // ��������� ��� ������, ������� �������

    do 
    {
        cout << "\n\t���� ��� ���������� � ������������� ������:\n";
        cout << "\t1. ����������� ������\n";
        cout << "\t2. ����������� ������ (� ������� ������������� ��������)\n";
        cout << "\t3. ������������ ������\n";
        cout << "\t4. ������������ ������ (� ������� ������������� ��������)\n";
        cout << "\t5. �����\n";
        cout << "\t�������� ��������: ";
        cin >> choice;

        switch (static_cast<String_Menu>(choice)) 
        {
            case String_Menu::Encrypt: 
            {
                str_encrypted = encrypt_string(str);
                cout << "\n������������� ������: " << str_encrypted << endl;
                break;
            }
            case String_Menu::Encrypt_By_Values: 
            {
                string ciphertext = ""; cout << endl;
                for (bit_8_t c : str) {
                    bit_8_t cipherchar = encrypt_char(bit_8_t(c));
                    cout << "������������� �������� ��� ������� '" << c << "': " << static_cast<char>(cipherchar.to_ulong()) << endl;
                    ciphertext += static_cast<char>(cipherchar.to_ulong());
                }
                cout << "\n������������� ������: " << ciphertext << endl;
                break;
            }
            case String_Menu::Decrypt: 
            {
                str = decrypt_string(str_encrypted);
                cout << "\n�������������� ������: " << str << endl;
                break;
            }
            case String_Menu::Decrypt_By_Values: 
            {
                string plaintext = ""; cout << endl;
                for (char c : str) {
                    bit_8_t plainchar = decrypt_char(bit_8_t(c));
                    cout << "������������� �������� ��� ������� '" << c << "': " << static_cast<char>(plainchar.to_ulong()) << endl;
                    plaintext += static_cast<char>(plainchar.to_ulong());
                }
                cout << "\n�������������� ������: " << plaintext << endl;
                break;
            }
            case String_Menu::EXIT:
                cout << "\n���� ��� ���������� � ������������� ������ --> ������� ����." << endl;
                break;
            default:
                cout << "\n�������� �����. ���������� �����." << endl;
        }
    } while (choice != 5);
}

void main_menu() {
    int choice;

    do 
    {
        cout << "\n\t������� ����:\n";
        cout << "\t1. ������ � ��������\n";
        cout << "\t2. ������ �� �������\n";
        cout << "\t3. �����\n";
        cout << "\t�������� ��������: ";
        cin >> choice;

        switch (static_cast<Main_Menu>(choice)) 
        {
            case Main_Menu::Symbol_Menu:    symbol_menu();                                              break;
            case Main_Menu::String_Menu:    string_menu();                                              break;
            case Main_Menu::EXIT:           cout << "\n\t����� �� ��������� =(" << endl;                break;
            default:                        cout << "\n\t�������� �����. ���������� �����." << endl;
        }

    } while (choice != 3);
}