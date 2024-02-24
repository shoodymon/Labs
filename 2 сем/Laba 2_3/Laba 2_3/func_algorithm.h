#pragma once

#include <iostream>
#include <vector>
#include <cstdlib> // Для функций rand() и srand()
#include <ctime>   // Для функции time()
#include <algorithm>
#include <cmath>
#include "enum.h"


using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::vector;
using std::min;
using std::sort;


int linear_search(const vector<int>& arr, int &target);
int jump_search(vector<int>& arr, int &target);
int index_sequential_search(vector<int>& arr, int &step, int &key);
int binary_search(vector<int>& arr, int &number);
int binary_search_recursive(vector<int>& arr, int &number, const int &left, const int &right, bool &flag2);
