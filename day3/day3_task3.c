#include <stdio.h>

int main() {
    int start, end;

    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5Not3 = 0, sumDiv5Not3 = 0;

    // Marrja e input-it
    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    // Loop
    for (int i = start; i <= end; i++) {

        // Numrat qe pjestohet me 3
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        }
        // Numrat qe pjestohet me 5 POR jo me 3
        else if (i % 5 == 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d, %d]\n", start, end);

    printf("\nNumrat qe pjestohet me 3:\n");
    printf("Numerimi: %d\n", countDiv3);
    printf("Shuma: %d\n", sumDiv3);

    printf("\nNumrat qe pjestohet me 5 (jo me 3):\n");
    printf("Numerimi: %d\n", countDiv5Not3);
    printf("Shuma: %d\n", sumDiv5Not3);

    // Krahasimi i shumave
    if (sumDiv3 > sumDiv5Not3) {
        printf("\nShuma e numrave qe pjestohet me 3 eshte me e madhe.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("\nShuma e numrave qe pjestohet me 5 (jo me 3) eshte me e madhe.\n");
    } else {
        printf("\nTe dyja shumat jane te barabarta.\n");
    }

    return 0;
}
