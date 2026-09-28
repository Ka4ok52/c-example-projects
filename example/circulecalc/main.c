#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926535
int main(void) {
    #ifdef DEBUG
        printf("\n[DEBUG] DEBUG Actived...\n");
    #endif
    char *status[] = {
        "RAD",
        "D",
        "C",
        "S"
    };
    char input[10];
    printf("Circule par: \n");
    printf("%s, ", status[0]);
    printf("%s, ", status[1]);
    printf("%s, ", status[2]);
    printf("%s\n", status[3]);
    printf("Enter: ");
    fflush(stdout);
    scanf("%9s", input);
    double rad;
    double dia;
    double line;
    double square;
    if (strcmp(input, status[0]) == 0) {
        printf("RAD: ");
        fflush(stdout);
        scanf("%lf", &rad);
        dia = rad * 2;
        line = 2 * rad * PI;
        square = PI * rad * rad;
    } else if (strcmp(input, status[1]) == 0) {
        printf("D: ");
        fflush(stdout);
        scanf("%lf", &dia);
        rad = dia / 2;
        line = 2 * rad * PI;
        square = PI * rad * rad;
    } else if (strcmp(input, status[2]) == 0) {
        printf("C: ");
        fflush(stdout);
        scanf("%lf", &line);
        rad = (line / PI) / 2;
        dia = rad * 2;
        square = PI * rad * rad;
    } else if (strcmp(input, status[3]) == 0) {
        printf("S: ");
        fflush(stdout);
        scanf("%lf", &square);
        rad = sqrt(square / PI);
        dia = rad * 2;
        line = 2 * rad * PI;
    } else {
        printf("Incorrect answer! Code Exced: 1\n");
        return 1;
    }

    printf("%s : %.3f\n", status[0], rad);
    printf("%s : %.3f\n", status[1], dia);
    printf("%s : %.3f\n", status[2], line);
    printf("%s : %.3f\n", status[3], square);
    return 0;
}
