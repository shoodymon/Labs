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


void saving(Game* game, const int SIZE);
void reading(Game* game, const int SIZE);