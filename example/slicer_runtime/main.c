#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int slice(const char *str, size_t len) {
    if (str == NULL || len == 0) {
        return 1;
    }
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\0') {
            break;
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    printf("%zu\n", len);
    return 0;
}

int main(void) {
    //The pointer stores only the address where this string is located.
    char *str = "Hello World!"; //strlen does know how to work with pointers and with arry

    slice(str, strlen(str));

    return EXIT_SUCCESS;
}
