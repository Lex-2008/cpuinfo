#include <iostream>
#include <cassert>
#include "cpuinfo.h"

class test1:public cpuinfo {
	public:
		virtual int cpuid_present(void){
			return 0;
		}
};

class test2:public cpuinfo {
	public:
		virtual int cpuid_get_raw_data(struct libcpuid::cpu_raw_data_t *data){
			return -1;
		}
};

class test3:public cpuinfo {
	public:
		virtual int cpu_identify(struct libcpuid::cpu_raw_data_t *raw, struct libcpuid::cpu_id_t *data){
			return -1;
		}
};

class test4:public cpuinfo {
	public:
		virtual int cpu_clock(void){
			return 1;
		}
};

int main()
{
	test1 t1;
	assert( get_cpuinfo(&t1) == -1 );
	std::cout << "Test 1 pass\n";

	test2 t2;
	assert( get_cpuinfo(&t2) == -2 );
	std::cout << "Test 2 pass\n";

	test3 t3;
	assert( get_cpuinfo(&t3) == -3 );
	std::cout << "Test 3 pass\n";

	test4 t4;
	assert( get_cpuinfo(&t4) == -4 );
	std::cout << "Test 4 pass\n";

	std::cout << "All tests pass!\n";
}
