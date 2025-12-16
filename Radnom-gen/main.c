#include <stdio.h>
#include <stdint.h>
#include <errno.h>

// Declare the external assembly function
// Returns: number of bytes read (ssize_t)
extern long get_secure_random(void *buf, size_t len);

int main() {
    uint64_t my_random_number;
    
    // Call the assembly function
    // We pass the address of our variable and its size
    long result = get_secure_random(&my_random_number, sizeof(my_random_number));

    // Check for errors (syscall returns negative on error)
    if (result < 0) {
        // In assembly, the negative error code is returned directly in RAX.
        // To print it nicely with errno, we technically need to negate it,
        // but printing the raw code is sufficient for debugging here.
        printf("Error generating random number. Error code: %ld\n", result);
        return 1;
    }

    printf("Successfully generated %ld bytes of entropy.\n", result);
    printf("Random uint64: %lu\n", my_random_number);
    printf("Random Hex:    0x%lx\n", my_random_number);

    return 0;
}
