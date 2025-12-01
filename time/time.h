#ifndef TIME_H
#define TIME_H

typedef unsigned long long u64;

void timer_start(void);
void timer_stop(void);
u64 timer_elapsed_cycles(void);

#endif
