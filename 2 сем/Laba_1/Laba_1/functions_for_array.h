#pragma once	/*директива для предотвращения многократного включения заголовочных файлов*/
#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"


using std::cin;
using std::cout;
using std::fstream;
using std::ios;
using std::string;
using std::endl;


void input(Game* game, const int SIZE);
void remove_element(Game* game, const int& SIZE);
void output(Game* game, const int SIZE);
void output_arr(Game* game, const int SIZE);