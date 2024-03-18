#pragma once
#include "pack.h"

using vec = vector<int>;
using Sort_func = function<void(vec& main_vector, Actions& result)>;

typedef array<Sort_func, 9> arr;

void bubble_sort(vec& main_vector, int size, Actions& result);
void shaker_sort(vec& main_vector, int size, Actions& result);
void dwarves_sort(vec& main_vector, int size, Actions& result);
void inserts_sort(vec& main_vector, int size, Actions& result);
void selection_sort(vec& main_vector, int size, Actions& result);
void shell_sort(vec& main_vector, int size, Actions& result);
void recursive_sort(vec& main_vector, int left, int right, Actions& result);
void recursive_sort_with_timer(vec& main_vector, int size, Actions& result);
void hoara_sort(vec& main_vector, int first, int last, Actions& result);
void hoara_sort_with_timer(vec& main_vector, int size, Actions& result);
void merge(vec& main_vector, int left, int middle, int right, Actions& result);
void merging_sort(vec& main_vector, int len, Actions& result);

void exit(bool& flag);
void error();
void reset(Actions& result);
steady_clock::time_point start_timer();
steady_clock::time_point end_timer();
long duration_time(steady_clock::time_point start, steady_clock::time_point end);

int get_arr_size();
void fill_arr_with_random(vec& main_vector);
void print_arr(vec& main_vector);
void print_sorted_arr(vec& main_vector);
int get_user_input();
