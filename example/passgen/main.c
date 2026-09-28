#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    int length = 0;
    unsigned int seed;
    char seed_buf[32];

    const char charset[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "01234563456789"
        "!@#$%^&*()_+-=";
    int charset_len = sizeof(charset) - 1;

    while (1) {
        printf("length pass (min 4): ");
        fflush(stdout);

        if (scanf("%d", &length) == 1 && length >= 4) {
            while (getchar() != '\n');
            break;
        }

        printf("Incorrect length! Must be a number >= 4. Try again.\n");
        while (getchar() != '\n');
    }

    printf("Input seed or zero for using time system: ");
    fflush(stdout);

    if (fgets(seed_buf, sizeof(seed_buf), stdin) != NULL) {
        if (seed_buf[0] == '\n' || seed_buf[0] == '\r') {
            seed = (unsigned int)time(NULL);
        } else {
            seed = (unsigned int)strtoul(seed_buf, NULL, 10);
        }
    } else {
        seed = (unsigned int)time(NULL);
    }

    srand(seed);

    printf("Seed: %u\n", seed);
    printf("Password: "); 

    for (int i = 0; i < length; i++) {
        int random_index = rand() % charset_len;
        putchar(charset[random_index]);
    }
    printf("\n");

    return 0;
}
