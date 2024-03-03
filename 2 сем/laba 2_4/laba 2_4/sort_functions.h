#pragma once

#include <iostream>
#include <vector>
#include <cstdlib> // rand() è srand()
#include <ctime>   // time()
#include <algorithm>
#include <cmath>
#include "enum.h"
#include "additional_functions.h"
#include "struct.h"
#include "array_functions.h"



using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::vector;
using std::min;
using std::sort;
using std::swap;


void bubble_sort(vector<int>& arr, int size, Actions& result);
void shaker_sort(vector<int>& arr, int size, Actions& result);
void dwarves_sort(vector<int>& arr, int size, Actions& result);
void inserts_sort(vector<int>& arr, int size, Actions& result);
void selection_sort(vector<int>& arr, int size, Actions& result);
void shell_sort(vector<int>& arr, int size, Actions& result);
// void recursive_sort(vector<int>& arr, int left, int right);
int find_min_index(vector<int>& arr, int left, int right, Actions& result);
void recursive_sort(vector<int>& arr, int size, bool is_sorted, int index, Actions& result);
void recursive_sort_with_timer(vector<int>& arr, int size, Actions& result);
void hoara_sort(vector<int>& arr, int first, int last, Actions& result);
void hoara_sort_with_timer(vector<int>& arr, Actions& result);
void merge(vector<int>& arr, int left, int middle, int right, Actions& result);
void merging_sort(vector<int>& arr, int len, Actions& result);
