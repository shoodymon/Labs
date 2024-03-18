#pragma once
#include "pack.h"

using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::vector;
using std::min;
using std::swap;
using std::array;
using std::function;
using namespace std::chrono;


using vec = vector<int>;
using Sort_func = function<void(vec& main_vector, Actions& result)>;

typedef array<Sort_func, 10> arr;

void bubble_sort(vec& main_vector, Actions& result);
void shaker_sort(vec& main_vector, Actions& result);
void dwarves_sort(vec& main_vector, Actions& result);
void inserts_sort(vec& main_vector,  Actions& result);
void selection_sort(vec& main_vector, Actions& result);
void shell_sort(vec& main_vector, Actions& result);
void recursive_sort(vec& main_vector, int left, int right, Actions& result);
void recursive_sort_with_timer(vec& main_vector, Actions& result);
void hoara_sort(vec& main_vector, int first, int last, Actions& result);
void hoara_sort_with_timer(vec& main_vector,  Actions& result);
void merge(vec& main_vector, int left, int middle, int right, Actions& result);
void merging_sort(vec& main_vector, Actions& result);
void null_sort(vec& main_vector, Actions& result);

void set_sort(arr& sort_array);
void sorting(vec& main_vector, arr& sort_array, Actions actions);

void exit(bool& flag);
void error();
void reset(Actions& result);

steady_clock::time_point end_timer();
steady_clock::time_point start_timer();
long duration_time(steady_clock::time_point start, steady_clock::time_point end);

int get_arr_size();
void fill_arr_with_random(vec& main_vector);
void print_sorted_arr(vec& main_vector);
int get_user_input();

void main_function(vec& main_vector, arr& sort_array);