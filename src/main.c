#include <stdio.h>

int main(void) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    printf("This program on C!\n");
    return 0;
}