#include <stdio.h>

int slice(const char *str, size_t len) {
    if (str == NULL || len == 0) {
        return 1;
    }
    size_t str_len = 0;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\0') {
            break;
        } else {
            printf("%c", str[i]);
            str_len++;
        }
    }
    printf("\n");
    printf("%zu\n", str_len);
    return 0;
}

int main(void) {
    //In this case, the compiler will determine the size of `str` at compile time.
    char str[] = "Hello World!"; //sizeof doesn't know how to work with pointers, only arry

    slice(str, sizeof(str));

    return 0;
}
