#include "encryption_decryption.h"

// ������� ��� �������� ������ � ������������
template<size_t N, size_t M> bitset<M> permute(const bitset<N>& value, const vector<int>& table) 
{
    /*
        N --> M ( �� 10 ������� ����� ������ 8 ������ ������� )
        N - ���-�� ����� � ��������, � ������� �� ����� �������� ( � ������� 10-������ ���� )
        M - ���-�� ����� ��������� �������� ( � ������� �������, � �������� 8 ��� )
    */

    bitset<M> result;

    // ������������ ������� ������� � ������������ �������� ������������ :)
    /*
        !!! C���� ������ ���(������� ���) ����� ������ 0,
        � ����� ����� ���(������� ���) ����� ������ N - 1 ��� std::bitset<N>

        ������� ���������� �������� ������� �������� (������ ������)
    */

    for (int i = 0; i < table.size(); i++) 
    {
        result[M - 1 - i] = value[N - 1 - table[i]];
    }

    return result;
}

template<size_t N> bitset<N> �yclic_shift_left(bitset<N>& key, const int& shift) 
{
    const int bytes = N / 2;

    // �������� ����� �������� (������ 5 ���) � ��������� ����������� ����� ����� �� ���� �������
    bitset<bytes> key_left_half(key.to_string().substr(0, bytes));

    cout << "\n����� �������� �����:   " << key_left_half << endl;

    key_left_half = key_left_half << shift | key_left_half >> (bytes - shift);

    // �������� ����� �������� (��������� 5 ���) � ��������� ����������� ����� ����� �� ���� �������
    bitset<bytes> key_right_half(key.to_string().substr(bytes, bytes));

    cout << "������ �������� �����:  " << key_right_half << endl;

    key_right_half = key_right_half << shift | key_right_half >> (bytes - shift);

    // ���������� ��� ��������� � ���� ����
    key = (key_left_half.to_ulong() << bytes) | key_right_half.to_ulong();

    return key;
}

// ������� ��� ��������� ������
vector<bit_8_t> generate_keys() 
{
    vector<bit_8_t> keys(2);    // ��� �������� �� 8 ��� ������

    cout << "\n�������� ����:\t  " << KEY << endl;


    bit_10_t key = permute<10, 10>(KEY, P10);
    cout << "������������ P10: " << key << endl;


    cout << "\n\t *** ����������� ����� ����� �� ���� ������� (������ �������� �����) ***\n";

    key = �yclic_shift_left<10>(key, 1);
    cout << "������������ ����: \t" << key << endl;


    cout << "\n\t *** ��������� ����� �1 ***\n\n";

    keys.at(0) = permute<10, 8>(key, P8);
    cout << "������������ P8: " << keys.at(0) << endl;

    cout << "\n���� �1 = " << keys.at(0) << endl;


    cout << "\n\t *** ��������� ����� �2 ***\n";


    cout << "\n\t *** ����������� ����� ����� �� ��� ������� (������ �������� �����) ***\n";

    key = �yclic_shift_left<10>(key, 2);
    cout << "������������ ����: \t" << key << endl;


    keys.at(1) = permute<10, 8>(key, P8);
    cout << "������������ P8: \t" << keys.at(1) << endl;

    cout << "\n���� �2 = " << keys.at(1) << endl;


    return keys;
}

int sbox(bit_4_t value, const int S[4][4]) 
{
    // �������� �������� ������ (������ ��� + ��������� ���)
    bit_2_t row_2(value.to_string().substr(0, 1) + value.to_string().substr(3, 1));
    cout << "�������� ������: " << row_2 << endl;

    // �������� �������� ������� (2 ���� ��-��������)
    bit_2_t col_2(value.to_string().substr(1, 2));
    cout << "�������� �������: " << col_2 << endl;

    int row = row_2.to_ulong();
    int col = col_2.to_ulong();

    return S[row][col];
}

// ������� ��� ���������� �������
bit_8_t encrypt_char(bit_8_t plaintext_8) 
{
    vector<bit_8_t> keys = generate_keys();

    cout << "-----------------";
    cout << "\n����������� ��� �������: " << plaintext_8 << endl;

    plaintext_8 = permute<8, 8>(plaintext_8, IP);
    cout << "������������ IP: " << plaintext_8 << endl;



    cout << "\n\t**** ���������� ���������� f ����� �1 ****\n";

    // �������� ����� �������� (��������� 4 ���)
    bit_4_t plaintext_left_IP(plaintext_8.to_string().substr(0, 4));
    // �������� ������ �������� (��������� 4 ���)
    bit_4_t plaintext_right_IP(plaintext_8.to_string().substr(4, 4));
    plaintext_8 = permute<4, 8>(plaintext_right_IP, EP);
    cout << "\n������������ E/P(R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = (plaintext_8 ^ keys[0]);
    cout << "�������� XOR(E/P(R), k1): " << plaintext_8 << '\n' << '\n';


    // �������� ����� �������� (��������� 4 ���)
    bit_4_t plaintext_left(plaintext_8.to_string().substr(0, 4));
    // �������� ������ �������� (��������� 4 ���)
    bit_4_t plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "����� �����: " << plaintext_left << '\n';
    cout << "������ �����: " << plaintext_right << '\n' << '\n';


    bit_2_t plaintext_left_2 = sbox(plaintext_left, S0);
    bit_2_t plaintext_right_2 = sbox(plaintext_right, S1);
    bit_4_t plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "\n��������� ������ S-������: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "������������ P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_IP ^ plaintext_4;
    cout << "�������� XOR(L, P4): " << plaintext_4 << '\n' << '\n';

    plaintext_8 = (plaintext_right_IP.to_ulong() << 4) | plaintext_4.to_ulong();
    cout << "������������ SW: " << plaintext_8 << '\n' << '\n';



    cout << "\n\t**** ���������� ���������� f ����� �2 ****\n";

    bit_4_t plaintext_left_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    bit_4_t plaintext_right_main = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));

    plaintext_8 = permute<4, 8>(plaintext_right_main, EP);
    cout << "\n������������ E/P(R): " << plaintext_8 << '\n' << '\n';

    plaintext_8 = (plaintext_8 ^ keys[1]);
    cout << "�������� XOR(E/P(R), k2): " << plaintext_8 << '\n' << '\n';


    plaintext_left = static_cast<bit_4_t>(plaintext_8.to_string().substr(0, 4));
    plaintext_right = static_cast<bit_4_t>(plaintext_8.to_string().substr(4, 4));
    cout << "����� �����: " << plaintext_left << '\n' << '\n';
    cout << "������ �����: " << plaintext_right << '\n' << '\n';


    plaintext_left_2 = sbox(plaintext_left, S0);
    plaintext_right_2 = sbox(plaintext_right, S1);
    plaintext_4 = (plaintext_left_2.to_ulong() << 2) | plaintext_right_2.to_ulong();
    cout << "\n��������� ������ S-������: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = permute<4, 4>(plaintext_4, P4);
    cout << "������������ P4: " << plaintext_4 << '\n' << '\n';


    plaintext_4 = plaintext_left_main ^ plaintext_4;
    cout << "�������� XOR(L, P4): " << plaintext_4 << '\n' << '\n';


    plaintext_8 = (plaintext_4.to_ulong() << 4) | plaintext_right_main.to_ulong();
    cout << "������������ SW(XOR(L, P4), R): " << plaintext_8 << '\n' << '\n';


    plaintext_8 = permute<8, 8>(plaintext_8, IP_1);
    cout << "������������ IP^-1: " << plaintext_8 << '\n' << '\n';

    return plaintext_8;
}


bit_8_t decrypt_char(bit_8_t ciphertext_8)
{
    vector<bit_8_t> keys = generate_keys();

    cout << "����������� ��� �������������� �������: " << ciphertext_8 << '\n' << '\n';

    cout << "\n\t**** ���������� ������������� f ����� �2 ****\n\n";

    ciphertext_8 = permute<8, 8>(ciphertext_8, IP);
    cout << "������������ IP: " << ciphertext_8 << '\n' << '\n';

    // �������� ����� �������� (��������� 4 ���)
    bit_4_t ciphertext_left_IP(ciphertext_8.to_string().substr(0, 4));
    // �������� ������ �������� (��������� 4 ���)
    bit_4_t ciphertext_right_IP(ciphertext_8.to_string().substr(4, 4));

    cout << "����� �����: " << ciphertext_left_IP << '\n';
    cout << "������ �����: " << ciphertext_right_IP << '\n' << '\n';

    ciphertext_8 = permute<4, 8>(ciphertext_right_IP, EP);
    cout << "������������ E/P(R): " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = (ciphertext_8 ^ keys.at(1));
    cout << "�������� XOR(E/P(R), k2): " << ciphertext_8 << '\n' << '\n';

    // �������� ����� �������� (��������� 4 ���)
    bit_4_t ciphertext_left(ciphertext_8.to_string().substr(0, 4));
    // �������� ������ �������� (��������� 4 ���)
    bit_4_t ciphertext_right = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));
    cout << "����� �����: " << ciphertext_left << '\n' << '\n';
    cout << "������ �����: " << ciphertext_right << '\n' << '\n';

    bit_2_t ciphertext_left_2 = sbox(ciphertext_left, S0);
    bit_2_t ciphertext_right_2 = sbox(ciphertext_right, S1);
    bit_4_t ciphertext_4 = (ciphertext_left_2.to_ulong() << 2) | ciphertext_right_2.to_ulong();
    cout << "\n��������� ������ S-������: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = permute<4, 4>(ciphertext_4, P4);
    cout << "������������ P4: " << ciphertext_4 << '\n' << '\n';


    ciphertext_4 = ciphertext_left_IP ^ ciphertext_4;
    cout << "�������� XOR(L, P4): " << ciphertext_4 << '\n' << '\n';

    ciphertext_8 = (ciphertext_right_IP.to_ulong() << 4) | ciphertext_4.to_ulong();
    cout << "������������ SW: " << ciphertext_8 << '\n' << '\n';


    cout << "\n\t**** ���������� ������������ f ����� �1 ****\n\n";

    bit_4_t ciphertext_left_main = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    bit_4_t ciphertext_right_main = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));

    ciphertext_8 = permute<4, 8>(ciphertext_right_main, EP);
    cout << "������������ E/P(R): " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = (ciphertext_8 ^ keys.at(0));
    cout << "�������� XOR(E/P(R), k1): " << ciphertext_8 << '\n' << '\n';

    ciphertext_left = static_cast<bit_4_t>(ciphertext_8.to_string().substr(0, 4));
    ciphertext_right = static_cast<bit_4_t>(ciphertext_8.to_string().substr(4, 4));
    cout << "����� �����: " << ciphertext_left << '\n' << '\n';
    cout << "������ �����: " << ciphertext_right << '\n' << '\n';

    ciphertext_left_2 = sbox(ciphertext_left, S0);
    ciphertext_right_2 = sbox(ciphertext_right, S1);
    ciphertext_4 = (ciphertext_left_2.to_ulong() << 2) | ciphertext_right_2.to_ulong();
    cout << "��������� ������ S-������: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = permute<4, 4>(ciphertext_4, P4);
    cout << "������������ P4: " << ciphertext_4 << '\n' << '\n';

    ciphertext_4 = ciphertext_left_main ^ ciphertext_4;
    cout << "�������� XOR(L, P4): " << ciphertext_4 << '\n' << '\n';

    // ����������� 8-������� ����� �� ���� 4-������
    ciphertext_8 = (ciphertext_4.to_ulong() << 4) | ciphertext_right_main.to_ulong();
    cout << "������������ SW(XOR(L, P4), R): " << ciphertext_8 << '\n' << '\n';

    ciphertext_8 = permute<8, 8>(ciphertext_8, IP_1);
    cout << "������������ IP^-1: " << ciphertext_8 << '\n' << '\n';

    return ciphertext_8;
}

// ������� ��� ���������� ������
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

// ������� ��� ������������� ������
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