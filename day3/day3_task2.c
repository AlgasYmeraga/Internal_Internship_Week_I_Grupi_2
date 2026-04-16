#include <stdio.h>

int main() {
    int fillimi, fundi;
    int countCift = 0, countTek = 0;
    int shumaCift = 0, shumaTek = 0;
    int total = 0;

    printf("Shkruani vleren fillestare: ");
    scanf("%d", &fillimi);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &fundi);

    // Kontrolli i intervalit
    if (fillimi > fundi) {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 0;
    }

    // For loop për analizë
    for (int i = fillimi; i <= fundi; i++) {
        total++;

        if (i % 2 == 0) {
            countCift++;
            shumaCift += i;
        } else {
            countTek++;
            shumaTek += i;
        }
    }

    // Rezultatet
    printf("\nIntervali: %d - %d\n", fillimi, fundi);
    printf("Totali i numrave: %d\n", total);

    printf("Numra çift: %d\n", countCift);
    printf("Shuma e numrave çift: %d\n", shumaCift);

    printf("Numra tek: %d\n", countTek);
    printf("Shuma e numrave tek: %d\n", shumaTek);

    if (countCift > countTek) {
        printf("Ka me shume numra çift.\n");
    } else if (countTek > countCift) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}
