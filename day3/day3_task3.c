#include <stdio.h>

int main() {
    int start, end;

    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5 = 0, sumDiv5 = 0;

    // Input
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    // Validimi
    if (start > end) {
        printf("Gabim: Intervali nuk eshte valid (fillimi > fundi).\n");
        return 0;
    }

    // Loop
    for (int i = start; i <= end; i++) {

        // Numrat qe pjestohen me 3
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        }
        // Numrat qe pjestohen me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5++;
            sumDiv5 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d deri %d\n", start, end);

    printf("\nNumrat qe pjesetohen me 3:\n");
    printf("Numeruesi: %d\n", countDiv3);
    printf("Shuma: %d\n", sumDiv3);

    printf("\nNumrat qe pjesetohen me 5 (jo me 3):\n");
    printf("Numeruesi: %d\n", countDiv5);
    printf("Shuma: %d\n", sumDiv5);

    // Krahasimi i shumave
    if (sumDiv3 > sumDiv5) {
        printf("\nShuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sumDiv5 > sumDiv3) {
        printf("\nShuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}
