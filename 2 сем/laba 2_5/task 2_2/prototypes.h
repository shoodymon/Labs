#pragma once

#include <iostream>
#include <vector>

#include "struct.h"


void bubble_sort(vector<int>& arr, int size, Actions& result);
void shaker_sort(vector<int>& arr, int size, Actions& result);
void dwarves_sort(vector<int>& arr, int size, Actions& result);
void inserts_sort(vector<int>& arr, int size, Actions& result);
void selection_sort(vector<int>& arr, int size, Actions& result);
void shell_sort(vector<int>& arr, int size, Actions& result);
void recursive_sort(vector<int>& arr, int left, int right, Actions& result);
void recursive_sort_with_timer(vector<int>& arr, int size, Actions& result);
void hoara_sort(vector<int>& arr, int first, int last, Actions& result);
void hoara_sort_with_timer(vector<int>& arr, int size, Actions& result);
void merge(vector<int>& arr, int left, int middle, int right, Actions& result);
void merging_sort(vector<int>& arr, int len, Actions& result);
sort_function get_function();

void exit(bool& flag);
void error();
void reset(Actions& result);
steady_clock::time_point start_timer();
steady_clock::time_point end_timer();
long duration_time(steady_clock::time_point start, steady_clock::time_point end);

int get_arr_size();
void fill_arr_with_random(vector<int>& arr);
void print_arr(const vector<int>& arr);
void print_sorted_arr(vector<int>& arr);
int get_user_input();

