void putstr(const char *s);
void putnum(unsigned long long x);
int read_uint(unsigned long long *out);

void timer_start(void);
void timer_stop(void);
unsigned long long timer_elapsed_cycles(void);

static inline void exit_sys(int code) {
    asm volatile(
        "mov $60, %%rax\n\t"
        "mov %0, %%rdi\n\t"
        "syscall"
        :
        : "r"((long)code)
        : "rax", "rdi"
    );
}

int main() {
    putstr("Enter loop count: ");

    unsigned long long n = 0;
    if (!read_uint(&n)) {
        putstr("Invalid\n");
        n = 100000000ULL;
    }

    putstr("Running...\n");

    unsigned long long sum = 0;

    timer_start();
    for (unsigned long long i = 0; i < n; i++)
        sum += i;
    timer_stop();

    putstr("Sum: ");
    putnum(sum);
    putstr("\nCycles: ");
    putnum(timer_elapsed_cycles());
    putstr("\n");

    exit_sys(0);
    return 0;
}
