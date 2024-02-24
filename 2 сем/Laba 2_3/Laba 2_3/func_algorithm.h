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


int get_user_input();
int linear_search(const vector<int>& arr, int target, int& count);
int jump_search(const vector<int>& arr, int target, int& comparisons);
int index_sequential_search(const vector<int>& arr, int step, int key, int& comparisons);
int binary_search(const vector<int>& arr, int number, int& comparisons);
int binary_search_recursive(const vector<int>& arr, int number, int left, int right, int& comparisons);
