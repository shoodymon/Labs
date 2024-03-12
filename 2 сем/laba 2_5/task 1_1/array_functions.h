#pragma once

#include <iostream>
#include <vector>
#include <cstdlib> // rand() и srand()
#include <ctime>   // time()
#include <algorithm>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::vector;
using std::min;


int get_arr_size();
void fill_arr_with_random(vector<int>& arr);
void print_arr(vector<int>& arr);
void print_sorted_arr(vector<int>& arr);
int get_user_input();