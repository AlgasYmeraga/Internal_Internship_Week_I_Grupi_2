#include <stdio.h>

int main() {
    int start, end;
    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    printf("Shkruaj vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruaj vleren perfundimtare: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 0;
    }

    // Loop per analizim
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            countEven++;
            sumEven += i;
        } else {
            countOdd++;
            sumOdd += i;
        }
    }

    int totalNumbers = (end - start) + 1;

    // Output
    printf("\nIntervali: [%d - %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("\nNumra çift: %d\n", countEven);
    printf("Shuma e numrave çift: %d\n", sumEven);

    printf("\nNumra tek: %d\n", countOdd);
    printf("Shuma e numrave tek: %d\n", sumOdd);

    // Krahasimi
    if (countEven > countOdd) {
        printf("\nKa me shume numra çift.\n");
    } else if (countOdd > countEven) {
        printf("\nKa me shume numra tek.\n");
    } else {
        printf("\nNumrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}
