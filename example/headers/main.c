#include <stdlib.h>
#include <stdio.h>
#include "add.h"

int main(void) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    int res = add(5, 3);
    printf("Result: %d\n", res);
    return EXIT_SUCCESS;
}
