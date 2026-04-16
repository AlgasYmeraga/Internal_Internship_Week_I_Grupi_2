#include <stdio.h>

int main() {
    int fillimi, fundi;
    int i;
    int totalVlera = 0;
    int nrCift = 0, nrTek = 0;
    long long shumaCift = 0, shumaTek = 0;

    printf("Shkruaj vleren fillestare te intervalit: ");
    scanf("%d", &fillimi);

    printf("Shkruaj vleren perfundimtare te intervalit: ");
    scanf("%d", &fundi);

    if (fillimi > fundi) {
        printf("Gabim: intervali nuk eshte valid. Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    for (i = fillimi; i <= fundi; i++) {
        totalVlera++;

        if (i % 2 == 0) {
            nrCift++;
            shumaCift += i;
        } else {
            nrTek++;
            shumaTek += i;
        }
    }

    printf("\n----- REZULTATI -----\n");
    printf("Intervali: nga %d deri ne %d\n", fillimi, fundi);
    printf("Totali i vlerave: %d\n", totalVlera);
    printf("Numrat cift: %d\n", nrCift);
    printf("Numrat tek: %d\n", nrTek);
    printf("Shuma e numrave cift: %lld\n", shumaCift);
    printf("Shuma e numrave tek: %lld\n", shumaTek);

    if (nrCift > nrTek) {
        printf("Kategoria me me shume numra: numrat cift\n");
    } else if (nrTek > nrCift) {
        printf("Kategoria me me shume numra: numrat tek\n");
    } else {
        printf("Te dy kategorite kane numer te barabarte.\n");
    }

    return 0;
}
