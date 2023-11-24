#ifndef ZEPHYR_INCLUDE_CPUMASK_H_
#define ZEPHYR_INCLUDE_CPUMASK_H_

// extern const unsigned long
// 	cpu_bit_bitmap[BITS_PER_LONG+1][BITS_TO_LONGS(NR_CPUS)];

// static inline const struct cpumask *get_cpu_mask(unsigned int cpu)
// {
// 	const unsigned long *p = cpu_bit_bitmap[1 + cpu % BITS_PER_LONG];
// 	p -= cpu / BITS_PER_LONG;
// 	return to_cpumask(p);
// }

void set_bit(uint64_t *bitmap, int bit_position) {
    *bitmap |= (1u << bit_position);

}

# endif