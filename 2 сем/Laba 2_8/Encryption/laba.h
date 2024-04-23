#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "encryption_decryption.h"


using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::bitset;


enum class Symbol_Menu 
{
	VOID, Encrypt, Encrypt_By_Values, Decrypt, Decrypt_By_Values, EXIT
};

enum class String_Menu 
{
	VOID, Encrypt, Encrypt_By_Values, Decrypt, Decrypt_By_Values, EXIT
};

enum class Main_Menu 
{
	VOID, Symbol_Menu, String_Menu, EXIT
};


void symbol_menu();
void string_menu();
void main_menu();