#include <sys/types.h>

// Note: RCX and R11 are clobbered by Intel, see SYSCALL mnemonic manual.

#define CARRY_FLAG_BIT 1
#define RETURN_SYSCALL_RESULT(result, flags) return (flags & CARRY_FLAG_BIT) ? -result : result;

static inline int64_t syscall_6(int64_t num, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5, int64_t arg6) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x8, %2;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (num)                   // Inputs
        : "x8", "x11"                 // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}

static inline int64_t syscall_5(int64_t num, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x8, %2;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (num)                   // Inputs
        : "x8", "x11"                 // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}

static inline int64_t syscall_4(int64_t num, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x8, %2;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (num)                   // Inputs
        : "x8", "x11"                 // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}

static inline int64_t syscall_3(int64_t num, int64_t arg1, int64_t arg2, int64_t arg3) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x0, %2;\n"               // Move first syscall argument into x0
        "mov x1, %3;\n"               // Move second syscall argument into x1
        "mov x2, %4;\n"               // Move second syscall argument into x1
        "mov x8, %5;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (arg1), "r" (arg2), "r" (arg3), "r" (num) // Inputs
        : "x0", "x1", "x2", "x8", "x11"    // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}

static inline int64_t syscall_2(int64_t num, int64_t arg1, int64_t arg2) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x0, %2;\n"               // Move first syscall argument into x0
        "mov x1, %3;\n"               // Move second syscall argument into x1
        "mov x8, %4;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (arg1), "r" (arg2), "r" (num) // Inputs
        : "x0", "x1", "x8", "x11"    // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}

static inline int64_t syscall_1(int64_t num, int64_t arg1) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x0, %3;\n"               // Move first syscall argument into x0
        "mov x8, %2;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (num), "r" (arg1)       // Inputs
        : "x0", "x8", "x11"           // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}

static inline int64_t syscall_0(int64_t num) {
    int64_t result;
    int64_t flags;

    __asm__ __volatile__ (
        "mov x8, %2;\n"               // Move syscall number into x8
        "svc #0;\n"                   // Perform system call
        "mov %1, x11;\n"              // Assuming we want to preserve a specific register's state post-syscall
        : "=r" (result), "=r" (flags) // Outputs
        : "r" (num)                   // Inputs
        : "x8", "x11"                 // Clobber list
    );

    RETURN_SYSCALL_RESULT(result, flags);
}
