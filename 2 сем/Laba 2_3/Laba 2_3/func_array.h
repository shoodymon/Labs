#pragma once

#include <iostream>
#include <vector>
#include <cstdlib> // Для функций rand() и srand()
#include <ctime>   // Для функции time()
#include <algorithm>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::vector;
using std::min;


int get_arr_size();
vector<int> fill_arr_with_random(int size_arr);
void print_arr(const vector<int>& arr);
int get_user_input();
int get_key();
int get_step();
