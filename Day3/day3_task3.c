#include <stdio.h>

int main() {
    int start, end;

    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5 = 0, sumDiv5 = 0;

    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    // Kontrolli i input-it
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete <= fundi.\n");
        return 0;
    }

    // Loop
    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        } 
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5++;
            sumDiv5 += i;
        }
    }

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);

    printf("\nNumra qe pjestohen me 3: %d\n", countDiv3);
    printf("Shuma e tyre: %d\n", sumDiv3);

    printf("\nNumra qe pjestohen me 5 (jo me 3): %d\n", countDiv5);
    printf("Shuma e tyre: %d\n", sumDiv5);

    // Krahasimi
    if (sumDiv3 > sumDiv5) {
        printf("\nShuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } else if (sumDiv5 > sumDiv3) {
        printf("\nShuma e numrave qe pjestohen me 5 eshte me e madhe.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}
