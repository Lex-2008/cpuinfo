#include <iostream>
#include "cpuinfo.h"

int main()
{
	cpuinfo actor;
	return get_cpuinfo(&actor);
}
