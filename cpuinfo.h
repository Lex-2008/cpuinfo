namespace libcpuid {
#include <libcpuid.h>
}

class cpuinfo {
	public:
		int cpuid_present(void);
		int cpuid_get_raw_data(struct libcpuid::cpu_raw_data_t *data);
		int cpu_identify(struct libcpuid::cpu_raw_data_t *raw, struct libcpuid::cpu_id_t *data);
};

int get_cpuinfo(cpuinfo *actor);
