#pragma once

#include <iostream>
#include <chrono>


using std::cout;
using namespace std::chrono;


void exit(bool& flag);
void error();
steady_clock::time_point start_timer();
steady_clock::time_point end_timer();
long duration_time(steady_clock::time_point start, steady_clock::time_point end);
