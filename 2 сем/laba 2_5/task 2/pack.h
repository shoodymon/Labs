#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <cstdlib> // rand() � srand()
#include <ctime>   // time()
#include <algorithm>
#include <cmath>
#include <functional>
#include <chrono>
#include <string>
#include <Windows.h>

#include "prototypes.h"
#include "struct.h"

using std::cin;
using std::cout;
using std::endl;
using std::rand;
using std::vector;
using std::min;
using std::sort;
using std::swap;
using std::array;
using std::function;
using namespace std::chrono;

using vec = vector<int>;
using Sort_func = function<void(vec& main_vector, Actions& result)>;

typedef array<Sort_func, 9> arr;