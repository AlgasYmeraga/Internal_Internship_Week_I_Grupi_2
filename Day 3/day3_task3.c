#include <stdio.h>

int main() {
    int start, end;
    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    printf("Shkruani fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruani fundin e intervalit: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 1;
    }

    // For loop per intervalin
    for (int i = start; i <= end; i++) {

        // Kategoria 1: pjesetohet me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }
        // Kategoria 2: pjesetohet me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            sum5 += i;
            count5++;
        }
    }

    // Rezultatet
    printf("\nNumrat qe pjesetohen me 3: %d\n", count3);
    printf("Shuma e tyre: %d\n", sum3);

    printf("\nNumrat qe pjesetohen me 5 por jo me 3: %d\n", count5);
    printf("Shuma e tyre: %d\n", sum5);

    // Krahasimi i shumave
    if (sum3 > sum5) {
        printf("\nShuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("\nShuma e numrave qe pjesetohen me 5 (jo me 3) eshte me e madhe.\n");
    } else {
        printf("\nTe dy shumat jane te barabarta.\n");
    }

    return 0;
}
