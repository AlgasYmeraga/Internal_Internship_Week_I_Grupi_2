#include <stdio.h>

int main() {
    int fillimi, fundi;
    int shumaPjestohenMe3 = 0, numeruesiMe3 = 0;
    int shumaPjestohenMe5Jo3 = 0, numeruesiMe5Jo3 = 0;
    int i, temp;

    printf("Sheno fillimin e intervalit: ");
    if (scanf("%d", &fillimi) != 1) {
        printf("Gabim: duhet te shkruani nje numer te vlefshem.\n");
        return 1;
    }

    printf("Sheno fundin e intervalit: ");
    if (scanf("%d", &fundi) != 1) {
        printf("Gabim: duhet te shkruani nje numer te vlefshem.\n");
        return 1;
    }

    if (fillimi > fundi) {
        temp = fillimi;
        fillimi = fundi;
        fundi = temp;
        printf("Vlerat u nderrun qe intervali te jete i sakte: %d deri %d\n", fillimi, fundi);
    }

    for (i = fillimi; i <= fundi; i++) {
        if (i % 3 == 0) {
            shumaPjestohenMe3 += i;
            numeruesiMe3++;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            shumaPjestohenMe5Jo3 += i;
            numeruesiMe5Jo3++;
        }
    }

    printf("\nRezultatet:\n");
    printf("Numrat qe pjesetohen me 3: %d\n", numeruesiMe3);
    printf("Shuma e numrave qe pjesetohen me 3: %d\n", shumaPjestohenMe3);

    printf("Numrat qe pjesetohen me 5 por jo me 3: %d\n", numeruesiMe5Jo3);
    printf("Shuma e numrave qe pjesetohen me 5 por jo me 3: %d\n", shumaPjestohenMe5Jo3);

    printf("\nKrahasimi i shumave:\n");
    if (shumaPjestohenMe3 > shumaPjestohenMe5Jo3) {
        printf("Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    }
    else if (shumaPjestohenMe5Jo3 > shumaPjestohenMe3) {
        printf("Shuma e numrave qe pjesetohen me 5 por jo me 3 eshte me e madhe.\n");
    }
    else {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}
