#include <stdio.h>

int main() {
    int start, end;
    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    // Marrja e intervalit nga perdoruesi
    printf("Shkruani fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruani fundin e intervalit: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel se fundi.\n");
        return 0;
    }

    // Loop ne interval
    for (int i = start; i <= end; i++) {

        // Numrat qe pjestohen me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }
        // Numrat qe pjestohen me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            sum5 += i;
            count5++;
        }
    }

    // Rezultatet
    printf("\nRezultatet:\n");
    printf("Shuma e numrave qe pjestohen me 3: %d (Gjithsej: %d)\n", sum3, count3);
    printf("Shuma e numrave qe pjestohen me 5 por jo me 3: %d (Gjithsej: %d)\n", sum5, count5);

    // Krahasimi
    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjestohen me 5 por jo me 3 eshte me e madhe.\n");
    } else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}
