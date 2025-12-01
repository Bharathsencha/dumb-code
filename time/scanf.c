static inline long sys_read(int fd, void *buf, unsigned long len) {
    long ret;
    asm volatile(
        "mov $0, %%rax\n\t"
        "syscall"
        : "=a"(ret)
        : "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory"
    );
    return ret;
}

int read_uint(unsigned long long *out) {
    char buf[64];
    long n = sys_read(0, buf, sizeof(buf));
    if (n <= 0) return 0;

    unsigned long long val = 0;
    int seen = 0;

    for (long i = 0; i < n; i++) {
        char c = buf[i];
        if (c >= '0' && c <= '9') {
            seen = 1;
            val = val * 10 + (c - '0');
        } else if (seen) break;
    }

    if (!seen) return 0;
    *out = val;
    return 1;
}
