#include "pack.h"
#include "prototypes.h"


void reset(Actions& result) {
	result.comparisons = 0;
	result.swaps = 0;
}

steady_clock::time_point start_timer() {
	return steady_clock::now();
}

steady_clock::time_point end_timer() {
	return steady_clock::now();
}

long duration_time(steady_clock::time_point start, steady_clock::time_point end) {
	return duration_cast<microseconds>(end - start).count();
}
