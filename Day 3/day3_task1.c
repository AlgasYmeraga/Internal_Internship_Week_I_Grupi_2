#include <stdio.h>

int main() {
    int madhesia, zgjedhja;
    int i, j;

    printf("Zgjedh llojin e pattern-it:\n");
    printf("1. Pattern me yje\n");
    printf("2. Pattern me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &zgjedhja);

    if (zgjedhja != 1 && zgjedhja != 2) {
        printf("Gabim: duhet te zgjedhesh vetem 1 ose 2.\n");
        return 1;
    }

    printf("Shkruaj nje numer pozitiv nga 1 deri ne 12: ");
    scanf("%d", &madhesia);

    if (madhesia < 1 || madhesia > 12) {
        printf("Gabim: numri duhet te jete nga 1 deri ne 12.\n");
        return 1;
    }

    printf("\nPattern-i i kerkuar:\n\n");

    if (zgjedhja == 1) {
        /* Pattern me yje */
        for (i = 1; i <= madhesia; i++) {
            for (j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else {
        /* Pattern me numra */
        for (i = 1; i <= madhesia; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }

    return 0;
}
