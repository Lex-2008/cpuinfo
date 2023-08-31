#include <iostream>
#include <libcpuid.h>

int main()
{
	if (!cpuid_present()) {                                                // check for CPUID presence
		std::cerr << "Sorry, your CPU doesn't support CPUID!\n";
		return -1;
	}

	struct cpu_raw_data_t raw;                                             // contains only raw data
	struct cpu_id_t data;                                                  // contains recognized CPU features data

	if (cpuid_get_raw_data(&raw) < 0) {                                    // obtain the raw CPUID data
		std::cerr << "Sorry, cannot get the CPUID raw data.\n";
		std::cerr << "Error: " << cpuid_error() << "\n";                // cpuid_error() gives the last error description
		return -2;
	}

	if (cpu_identify(&raw, &data) < 0) {                                   // identify the CPU, using the given raw data.
		std::cerr << "Sorrry, CPU identification failed.\n";
		std::cerr << "Error: " << cpuid_error() << "\n";
		return -3;
	}

	std::cout << "Processor model is: " << data.cpu_codename << "\n";
	std::cout << "The processor has "<< data.num_cores <<" cores\n";
	std::cout << "CPU clock is: " << cpu_clock() << " MHz\n";

}
