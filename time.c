static unsigned long long start_t = 0, end_t = 0;

static inline unsigned long long rdtsc_start() {
    unsigned int lo, hi;
    asm volatile(
        "xor %%rax, %%rax\n\t"
        "cpuid\n\t"
        "rdtsc"
        : "=a"(lo), "=d"(hi)
        :
        : "rbx", "rcx"
    );
    return ((unsigned long long)hi << 32) | lo;
}

static inline unsigned long long rdtsc_end() {
    unsigned int lo, hi;
    asm volatile(
        "rdtscp\n\t"
        "mov %%eax, %0\n\t"
        "mov %%edx, %1\n\t"
        "cpuid"
        : "=r"(lo), "=r"(hi)
        :
        : "rax", "rbx", "rcx", "rdx"
    );
    return ((unsigned long long)hi << 32) | lo;
}

void timer_start(void) {
    start_t = rdtsc_start();
}

void timer_stop(void) {
    end_t = rdtsc_end();
}

unsigned long long timer_elapsed_cycles(void) {
    return end_t - start_t;
}
