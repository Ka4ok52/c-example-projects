#include <stdlib.h>
#include <stdio.h>

int slice(const char *str, size_t len) {

    if (str == NULL) {
        return 1;
    }
    if(len == 0) {
        printf("This string empty!\n");
        return 0;
    }
    size_t str_len = 0;
    while (str_len < len && str[str_len] != '\0') {
        str_len++;
    }
    fwrite(str, 1, str_len, stdout);
    printf("\n%zu\n", str_len);
    return 0;
}

int main(void) {
    //In this case, the compiler will determine the size of `str` at compile time.
    char str[] = "Hello World!"; //sizeof doesn't know how to work with pointers, only arry

    slice(str, sizeof(str));

    return EXIT_SUCCESS;
}
