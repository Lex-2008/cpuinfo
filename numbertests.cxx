#include <iostream>
#include <cassert>
#include "cpuinfo.h"

int main()
{
	assert(format_freq(0) == "0 MHz");
	assert(format_freq(1) == "1 MHz");
	assert(format_freq(999) == "999 MHz");
	assert(format_freq(1000) == "1.00 GHz");
	assert(format_freq(1001) == "1.00 GHz");
	assert(format_freq(1005) == "1.00 GHz");
	assert(format_freq(1006) == "1.01 GHz");
}

