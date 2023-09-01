namespace libcpuid {
#include <libcpuid.h>
}

class cpuinfo {
	public:
		virtual int cpuid_present(void);
		virtual int cpuid_get_raw_data(struct libcpuid::cpu_raw_data_t *data);
		virtual int cpu_identify(struct libcpuid::cpu_raw_data_t *raw, struct libcpuid::cpu_id_t *data);
		virtual int cpu_clock(void);
};

int get_cpuinfo(cpuinfo *actor);
