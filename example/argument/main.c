#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_RESET   "\x1b[0m"

void print_help(const char* prog_name) {
    printf("Usage: %s --print=<value>\n\n", prog_name);
    printf("Available options:\n");
    printf("  -h, --help        Show this help\n");
    printf("  --print=<value>   Pass the working value for print\n");
}

int main(int argc, char** argv) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    if (argc == 1) {
        print_help(argv[0]);
        return EXIT_SUCCESS;
    }

    const char* prefix = "--print=";
    size_t prefix_len = strlen(prefix);
    const char* otval_val = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help(argv[0]);
            return EXIT_SUCCESS;
        }

        if (strncmp(argv[i], prefix, prefix_len) == 0) {
            const char* val = argv[i] + prefix_len;
            if (*val == '\0') {
                fprintf(stderr, ANSI_RED "[ERR] --print=<> value cannot be empty" ANSI_RESET "\n");
                return EXIT_FAILURE;
            }
            otval_val = val;
            break;
        }
    }

    if (otval_val) {
        printf(ANSI_GREEN "[INF] print = [%s]" ANSI_RESET "\n", otval_val);
    } else {
        fprintf(stderr, ANSI_RED "[ERR] unknown or missing argument --print=<>" ANSI_RESET "\n\n");
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
