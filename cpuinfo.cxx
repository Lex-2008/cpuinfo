#include <iostream>

namespace libcpuid {
#include <libcpuid.h>
}

class cpuinfo {
	// wrapper class for libcpuid functions. Useful for testing -
	// descendant classes can override individual methods and see how
	// your program reacts to various return values. See tests.cxx
	public:
		virtual int cpuid_present(void);
		virtual int cpuid_get_raw_data(struct libcpuid::cpu_raw_data_t *data);
		virtual int cpu_identify(struct libcpuid::cpu_raw_data_t *raw, struct libcpuid::cpu_id_t *data);
		virtual int cpu_clock(void);
};

// at least one of virtual methods must be non-inline to link on gcc, https://stackoverflow.com/a/57504289
// all virtual methods must be non-inline to link on Windows

int cpuinfo::cpuid_present(void){
	return libcpuid::cpuid_present();
}

int cpuinfo::cpuid_get_raw_data(struct libcpuid::cpu_raw_data_t *data){
	return libcpuid::cpuid_get_raw_data(data);
}

int cpuinfo::cpu_identify(struct libcpuid::cpu_raw_data_t *raw, struct libcpuid::cpu_id_t *data){
	return libcpuid::cpu_identify(raw, data);
}

int cpuinfo::cpu_clock(void){
	return libcpuid::cpu_clock();
}

// main function to get information about CPU and print to to stdout. Use it like this:
// 	cpuinfo actor;
// 	return get_cpuinfo(&actor);
int get_cpuinfo(cpuinfo *actor)
{
	if (!actor->cpuid_present()) {                                                // check for CPUID presence
		std::cerr << "Sorry, your CPU doesn't support CPUID!\n";
		return -1;
	}

	struct libcpuid::cpu_raw_data_t raw;                                          // contains only raw data
	struct libcpuid::cpu_id_t data;                                               // contains recognized CPU features data

	if (actor->cpuid_get_raw_data(&raw) < 0) {                                    // obtain the raw CPUID data
		std::cerr << "Sorry, cannot get the CPUID raw data.\n";
		std::cerr << "Error: " << libcpuid::cpuid_error() << "\n";            // cpuid_error() gives the last error description
		return -2;
	}

	if (actor->cpu_identify(&raw, &data) < 0) {                                   // identify the CPU, using the given raw data.
		std::cerr << "Sorrry, CPU identification failed.\n";
		std::cerr << "Error: " << libcpuid::cpuid_error() << "\n";
		return -3;
	}

	std::cout << "Processor model is: " << data.cpu_codename << "\n";
	std::cout << "The processor has "<< data.num_cores <<" cores\n";

	int cpu_freq = actor->cpu_clock();
	if(cpu_freq < 2) {
		std::cerr << "CPU frequency is bogus, sorry.\n";
		return -4;
	}

	std::cout << "CPU clock is: " << cpu_freq << " MHz\n";

	return 0;
}
