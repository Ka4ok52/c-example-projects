#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>

void* thread_func_1(void* arg) {
    (void)arg;
    int cpu_id = sched_getcpu();
    printf("this thread on CPU #%d\n", cpu_id);
    return NULL;
}

int main(void) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func_1, NULL);
    int cpu_id = sched_getcpu();
    printf("this thread on CPU #%d\n", cpu_id);
    pthread_join(thread_id, NULL);
    return EXIT_SUCCESS;
}
