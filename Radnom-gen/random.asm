section .text
global get_secure_random

; Function: get_secure_random
; Arguments:
;   rdi - Pointer to the buffer where random bytes will be stored
;   rsi - Number of bytes to generate (length)
; Returns:
;   rax - Number of bytes written, or negative error code on failure
get_secure_random:
    ; Syscall arguments for x86_64 Linux:
    ; rax = syscall number (318 for getrandom)
    ; rdi = char *buf (already in rdi from C caller)
    ; rsi = size_t buflen (already in rsi from C caller)
    ; rdx = unsigned int flags (0 = default, block until entropy is available)

    mov rax, 318        ; Syscall number for getrandom
    mov rdx, 0          ; Flags: 0 ensures we wait for enough entropy (safe)
    syscall             ; Invoke the kernel
    ret                 ; Return value acts as the result
