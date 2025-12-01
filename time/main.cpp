#include <iostream>

extern "C" {
    #include "core.h"  
}

int main() {
    unsigned long long n;

    std::cout << "Enter loop count: ";
    std::cin >> n;

    unsigned long long cycles = run_benchmark(n);

    std::cout << "Cycles taken: " << cycles << "\n";
}
