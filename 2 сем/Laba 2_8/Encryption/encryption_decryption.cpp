#include "encryption_decryption.h"

// Функция для операций замены и перестановки
template<size_t N, size_t M> bitset<M> permute(const bitset<N>& value, const vector<int>& table) 
{
    /*
        N --> M ( из 10 битного ключа делаем 8 битный подключ )
        N - кол-во битов у значения, с которым мы будем работать ( к примеру 10-битный ключ )
        M - кол-во битов выходного значения ( к примеру подключ, у которого 8 бит )
    */

    bitset<M> result;

    // Перестановка каждого символа в соответствии заданной перестановки :)
    /*
        !!! Cамый правый бит(младший бит) имеет индекс 0,
        а самый левый бит(старший бит) имеет индекс N - 1 для std::bitset<N>

        Поэтому используем обратный порядок перебора (справа налево)
    */

    for (int i = 0; i < table.size(); i++) 
    {
        result[M - 1 - i] = value[N - 1 - table[i]];
    }

    return result;
}

template<size_t N> bitset<N> сyclic_shift_left(bitset<N>& key, const int& shift) 
{
    const int bytes = N / 2;

    // Получаем левую половину (первые 5 бит) и выполняем циклический сдвиг влево на одну позицию
    bitset<bytes> key_left_half(key.to_string().substr(0, bytes));

    cout << "\nЛевая половина ключа:   " << key_left_half << endl;

    key_left_half = key_left_half << shift | key_left_half >> (bytes - shift);

    // Получаем левую половину (последние 5 бит) и выполняем циклический сдвиг влево на одну позицию
    bitset<bytes> key_right_half(key.to_string().substr(bytes, bytes));

    cout << "Правая половина ключа:  " << key_right_half << endl;

    key_right_half = key_right_half << shift | key_right_half >> (bytes - shift);

    // Объединяем две половинки в один ключ
    key = (key_left_half.to_ulong() << bytes) | key_right_half.to_ulong();

    return key;
}

// Функция для генерации ключей
vector<bit_8_t> generate_keys() 
{
    vector<bit_8_t> keys(2);    // Два подключа на 8 бит каждый

    cout << "\nЗаданный ключ:\t  " << KEY << endl;


    bit_10_t key = permute<10, 10>(KEY, P10);
    cout << "Перестановка P10: " << key << endl;


    cout << "\n\t *** Циклический свдиг влево на одну позицию (каждой половины ключа) ***\n";

    key = сyclic_shift_left<10>(key, 1);
    cout << "Объединенный ключ: \t" << key << endl;


    cout << "\n\t *** Генерация ключа №1 ***\n\n";

    keys.at(0) = permute<10, 8>(key, P8);
    cout << "Перестановка P8: " << keys.at(0) << endl;

    cout << "\nКлюч №1 = " << keys.at(0) << endl;


    cout << "\n\t *** Генерация ключа №2 ***\n";


    cout << "\n\t *** Циклический свдиг влево на две позицию (каждой половины ключа) ***\n";

    key = сyclic_shift_left<10>(key, 2);
    cout << "Объединенный ключ: \t" << key << endl;


    keys.at(1) = permute<10, 8>(key, P8);
    cout << "Перестановка P8: \t" << keys.at(1) << endl;

    cout << "\nКлюч №2 = " << keys.at(1) << endl;


    return keys;
}

int sbox(bit_4_t value, const int S[4][4]) 
{
    // Получаем двоичную строку (первый бит + последний бит)
    bit_2_t row_2(value.to_string().substr(0, 1) + value.to_string().substr(3, 1));
    cout << "Двоичная строка: " << row_2 << endl;

    // Получаем двоичный столбец (2 бита по-середине)
    bit_2_t col_2(value.to_string().substr(1, 2));
    cout << "Двоичный столбец: " << col_2 << endl;

    int row = row_2.to_ulong();
    int col = col_2.to_ulong();

    return S[row][col];
}

// Функция для шифрования символа
bit_8_t encrypt_char(bit_8_t plaintext_8) 
{
    vector<bit_8_t> keys = generate_keys();

    cout << "-----------------";
    cout << "\nИзначальный код символа: " << plaintext_8 << endl;

    plaintext_8 = permute<8, 8>(plaintext_8, IP);
    cout << "Перестановка IP: " << plaintext_8 << endl;


    cout << "\n\t**** Вычисление шифрование f ключа №1 ****\n";

    /*
                                                МЕТОДЫ!
        .to_string(): Преобразует битовую строку в строку символов, представляющую бинарное значение. 
        .substr(0, 4): Берет подстроку из исходной строки, начиная с индекса 0 и длиной 4 символа.
        .to_ulong(): Преобразует значение битового набора в unsigned long int
    */

    // Получаем левую половину (последние 4 бит)
    bit_4_t plaintext_left_IP(plaintext_8.to_string().substr(0, 4));
    // Получаем правую половину (последние 4 бит)
    bit_4_t plaintext_right_IP(plaintext_8.to_string().substr(4, 4));
    plaintext_8 = permute<4, 8>(plaintext_right_IP, EP);
    cout << "\nПерестановка E/P(R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = (plaintext_8 ^ keys[0]);
    cout << "Операция XOR(E/P(R), k1): " << plaintext_8 << '\n' << '\n';


    // Получаем левую половину (последние 4 бит)
    bit_4_t plaintext_left(plaintext_8.to_string().substr(0, 4));
    // Получаем правую половину (последние 4 бит)
    bit_4_t plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << plaintext_left << '\n';
    cout << "Правая часть: " << plaintext_right << '\n' << '\n';


    bit_2_t plaintext_left_2 = sbox(plaintext_left, S0);
    bit_2_t plaintext_right_2 = sbox(plaintext_right, S1);
    bit_4_t plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "\nРезультат работы S-матриц: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "Перестановка P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_IP ^ plaintext_4;
    cout << "Операция XOR(L, P4): " << plaintext_4 << '\n' << '\n';

    plaintext_8 = (plaintext_right_IP.to_ulong() << 4) | plaintext_4.to_ulong();
    cout << "Перестановка SW: " << plaintext_8 << '\n' << '\n';



    cout << "\n\t**** Вычисление шифрование f ключа №2 ****\n";

    bit_4_t plaintext_left_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    bit_4_t plaintext_right_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));

    plaintext_8 = permute<4, 8>(plaintext_right_main, EP);
    cout << "\nПерестановка E/P(R): " << plaintext_8 << '\n' << '\n';

    plaintext_8 = (plaintext_8 ^ keys[1]);
    cout << "Операция XOR(E/P(R), k2): " << plaintext_8 << '\n' << '\n';


    plaintext_left = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << plaintext_left << '\n' << '\n';
    cout << "Правая часть: " << plaintext_right << '\n' << '\n';


    plaintext_left_2 = sbox(plaintext_left, S0);
    plaintext_right_2 = sbox(plaintext_right, S1);
    plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "\nРезультат работы S-матриц: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "Перестановка P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_main ^ plaintext_4;
    cout << "Операция XOR(L, P4): " << plaintext_4 << '\n' << '\n';


    plaintext_8 = (plaintext_4.to_ulong() << 4) | plaintext_right_main.to_ulong();
    cout << "Перестановка SW(XOR(L, P4), R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = permute<8, 8>(plaintext_8, IP_1);
    cout << "Перестановка IP^-1: " << plaintext_8 << '\n' << '\n';

    return plaintext_8;
}

// Функция для расшифрования символа
bit_8_t decrypt_char(bit_8_t ciphertext_8)
{
    vector<bit_8_t> keys = generate_keys();

    cout << "Изначальный код зашифрованного символа: " << ciphertext_8 << '\n' << '\n';

    cout << "\n\t**** Вычисление расшифрования f ключа №2 ****\n\n";

    ciphertext_8 = permute<8, 8>(ciphertext_8, IP);
    cout << "Перестановка IP: " << ciphertext_8 << '\n' << '\n';

    // Получаем левую половину (последние 4 бит)
    bit_4_t ciphertext_left_IP(ciphertext_8.to_string().substr(0, 4));
    // Получаем правую половину (последние 4 бит)
    bit_4_t ciphertext_right_IP(ciphertext_8.to_string().substr(4, 4));

    cout << "Левая часть: " << ciphertext_left_IP << '\n';
    cout << "Правая часть: " << ciphertext_right_IP << '\n' << '\n';

    ciphertext_8 = permute<4, 8>(ciphertext_right_IP, EP);
    cout << "Перестановка E/P(R): " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = (ciphertext_8 ^ keys.at(1));
    cout << "Операция XOR(E/P(R), k2): " << ciphertext_8 << '\n' << '\n';

    // Получаем левую половину (последние 4 бит)
    bit_4_t ciphertext_left(ciphertext_8.to_string().substr(0, 4));
    // Получаем правую половину (последние 4 бит)
    bit_4_t ciphertext_right = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << ciphertext_left << '\n' << '\n';
    cout << "Правая часть: " << ciphertext_right << '\n' << '\n';

    bit_2_t ciphertext_left_2 = sbox(ciphertext_left, S0);
    bit_2_t ciphertext_right_2 = sbox(ciphertext_right, S1);
    bit_4_t ciphertext_4 = (ciphertext_left_2.to_ulong() << 2) | ciphertext_right_2.to_ulong();
    cout << "\nРезультат работы S-матриц: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = permute<4, 4>(ciphertext_4, P4);
    cout << "Перестановка P4: " << ciphertext_4 << '\n' << '\n';


    ciphertext_4 = ciphertext_left_IP ^ ciphertext_4;
    cout << "Операция XOR(L, P4): " << ciphertext_4 << '\n' << '\n';

    ciphertext_8 = (ciphertext_right_IP.to_ulong() << 4) | ciphertext_4.to_ulong();
    cout << "Перестановка SW: " << ciphertext_8 << '\n' << '\n';


    cout << "\n\t**** Вычисление дешифрования f ключа №1 ****\n\n";

    bit_4_t ciphertext_left_main = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    bit_4_t ciphertext_right_main = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));

    ciphertext_8 = permute<4, 8>(ciphertext_right_main, EP);
    cout << "Перестановка E/P(R): " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = (ciphertext_8 ^ keys.at(0));
    cout << "Операция XOR(E/P(R), k1): " << ciphertext_8 << '\n' << '\n';

    ciphertext_left = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    ciphertext_right = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));
    cout << "Левая часть: " << ciphertext_left << '\n' << '\n';
    cout << "Правая часть: " << ciphertext_right << '\n' << '\n';

    ciphertext_left_2 = sbox(ciphertext_left, S0);
    ciphertext_right_2 = sbox(ciphertext_right, S1);
    ciphertext_4 = (ciphertext_left_2.to_ulong() << 2) | ciphertext_right_2.to_ulong();
    cout << "Результат работы S-матриц: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = permute<4, 4>(ciphertext_4, P4);
    cout << "Перестановка P4: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = ciphertext_left_main ^ ciphertext_4;
    cout << "Операция XOR(L, P4): " << ciphertext_4 << '\n' << '\n';

    // Объединение 8-битного ключа из двух 4-битных
    ciphertext_8 = (ciphertext_4.to_ulong() << 4) | ciphertext_right_main.to_ulong();
    cout << "Перестановка SW(XOR(L, P4), R): " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = permute<8, 8>(ciphertext_8, IP_1);
    cout << "Перестановка IP^-1: " << ciphertext_8 << '\n' << '\n';

    return ciphertext_8;
}

// Функция для шифрования строки
string encrypt_string(string plaintext) 
{
    string ciphertext = "";
    for (bit_8_t c : plaintext)
    {
        bit_8_t cipherchar = encrypt_char(c);
        ciphertext += static_cast<char>(cipherchar.to_ulong());
    }
    return ciphertext;
}

// Функция для расшифрования строки
string decrypt_string(string ciphertext) 
{
    string plaintext = "";
    for (char c : ciphertext)
    {
        bit_8_t plainchar = decrypt_char(c);
        plaintext += static_cast<char>(plainchar.to_ulong());
    }
    return plaintext;
}