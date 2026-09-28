#define _GNU_SOURCE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <pthread.h>

int main(void) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    struct rlimit limit;

    if (getrlimit(RLIMIT_STACK, &limit) != 0) {
        perror("getrlimit failed");
        return 1;
    }

    pthread_t self = pthread_self();
    pthread_attr_t attr;
    void *stack_addr;
    size_t stack_size;

    pthread_getattr_np(self, &attr);
    pthread_attr_getstack(&attr, &stack_addr, &stack_size);
    pthread_attr_destroy(&attr);

    uintptr_t stack_bottom = (uintptr_t)stack_addr;
    uintptr_t stack_top = stack_bottom + stack_size;

    int current_var = 0;
    uintptr_t current_addr = (uintptr_t)&current_var;

    double size_kb = (double)stack_size / 1024.0;
    double size_mb = size_kb / 1024.0;

    printf("= Info about sys SP =\n");
    printf("Start SP          : 0x%lx\n", (unsigned long)stack_top);
    printf("Current vertex SP : 0x%lx\n", (unsigned long)current_addr);
    printf("End SP            : 0x%lx\n", (unsigned long)stack_bottom);
    printf("-------------------------------------------\n");
    printf("Value Byte        : %zu Byte\n", stack_size);
    printf("Value KB/MB       : %.2f KB / %.2f MB\n", size_kb, size_mb);
    printf("-------------------------------------------\n");
    if (limit.rlim_cur == RLIM_INFINITY) {
        printf("SP by limited : Unlimited\n");
    } else {
        printf("SP by limited : %.2f MB\n", (double)limit.rlim_cur / (1024.0 * 1024.0));
    }

    return 0;
}
