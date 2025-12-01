static inline long sys_write(int fd, const void *buf, unsigned long len) {
    long ret;
    asm volatile(
        "mov $1, %%rax\n\t"
        "syscall"
        : "=a"(ret)
        : "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory"
    );
    return ret;
}

void putstr(const char *s) {
    unsigned long len = 0;
    while (s[len]) len++;
    sys_write(1, s, len);
}

void putnum(unsigned long long x) {
    char buf[32];
    int i = 31;
    buf[i] = '\0';
    i--;

    if (x == 0) {
        buf[i] = '0';
        sys_write(1, &buf[i], 1);
        return;
    }

    while (x > 0 && i >= 0) {
        buf[i--] = '0' + (x % 10);
        x /= 10;
    }

    sys_write(1, &buf[i+1], 31 - i);
}

void puthex(unsigned long long x) {
    char buf[32];
    const char *hex = "0123456789abcdef";
    int i = 31;
    buf[i] = '\0';
    i--;

    if (x == 0) {
        buf[i] = '0';
        sys_write(1, &buf[i], 1);
        return;
    }

    while (x > 0 && i >= 0) {
        buf[i--] = hex[x & 0xF];
        x >>= 4;
    }

    sys_write(1, &buf[i+1], 31 - i);
}
