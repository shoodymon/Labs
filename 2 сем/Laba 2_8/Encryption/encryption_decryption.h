#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>


using std::vector;
using std::string;
using std::cout;
using std::bitset;
using std::endl;

using bit_10_t = bitset<10>;
using bit_8_t = bitset<8>;
using bit_5_t = bitset<5>;
using bit_4_t = bitset<4>;
using bit_2_t = bitset<2>;


// Таблицы для операций замены и перестановки
const vector<int> IP = { 1, 5, 2, 0, 3, 7, 4, 6 };		// Таблица начальной перестановки (IP)
const vector<int> IP_1 = { 3, 0, 2, 4, 6, 1, 7, 5 };		// Таблица обратной начальной перестановки (IP_1)
const vector<int> P10 = { 2, 4, 1, 6, 3, 9, 0, 8, 7, 5 }; // Таблица перестановки 10 бит ключа (P10)
const vector<int> P8 = { 5, 2, 6, 3, 7, 4, 9, 8 };		// Таблица перестановки 8 бит подключа (P8)
const vector<int> P4 = { 1, 3, 2, 0 };					// таблица перестановки, применяемая к 4-битному выходу S-блоков (P4)
const vector<int> EP = { 3, 0, 1, 2, 1, 2, 3, 0 };		// Таблица перестановки 4 бит в расширенном перестановочном блоке (EP)
const int S0[4][4] = { {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2} }; // Таблица замен S0
const int S1[4][4] = { {0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3} }; // Таблица замен S1

// Статический ключ
const bit_10_t KEY("0000010101");

vector<bit_8_t> generate_keys();	
template <size_t N, size_t M> bitset<M> permute(const bitset<N>& value, const vector<int>& table);
template<size_t N> bitset<N> сyclic_shift_left(bitset<N>& key, const int& shift);
int sbox(bit_4_t value, const int S[4][4]);
bit_8_t encrypt_char(bit_8_t plaintext);	
bit_8_t decrypt_char(bit_8_t ciphertext_8);
string encrypt_string(string plaintext);	
string decrypt_string(string ciphertext);	