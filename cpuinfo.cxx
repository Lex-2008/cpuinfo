#include <iostream>

namespace libcpuid {
#include <libcpuid.h>
}

class cpuinfo {
	public:
		int cpuid_present(void){
			return libcpuid::cpuid_present();
		}
		int cpuid_get_raw_data(struct libcpuid::cpu_raw_data_t *data){
			return libcpuid::cpuid_get_raw_data(data);
		}
		int cpu_identify(struct libcpuid::cpu_raw_data_t *raw, struct libcpuid::cpu_id_t *data){
			return libcpuid::cpu_identify(raw, data);
		}
		int cpu_clock(void){
			return libcpuid::cpu_clock();
		}
};

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
	std::cout << "CPU clock is: " << actor->cpu_clock() << " MHz\n";

	return 0;
}
