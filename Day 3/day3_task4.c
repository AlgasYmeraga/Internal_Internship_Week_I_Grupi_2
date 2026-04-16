#include <stdio.h>

int main() {
    int a;
    float b;

    int *pa;
    float *pb;

    printf("Shkruaj nje numer int: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer float: ");
    scanf("%f", &b);

    // lidhja e pointerave me adresat
    pa = &a;
    pb = &b;

    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("Vlera e a: %d\n", a);
    printf("Adresa e a: %p\n", &a);
    printf("Vlera nga pointer pa: %d\n", *pa);

    printf("\nVlera e b: %.2f\n", b);
    printf("Adresa e b: %p\n", &b);
    printf("Vlera nga pointer pb: %.2f\n", *pb);

    // ruaj vleren fillestare
    int a_old = a;

    // ndryshim permes pointer
    *pa = *pa + 10;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("Vlera e re e a: %d\n", a);

    // kontroll me if/else
    if (a > a_old) {
        printf("Vlera eshte rritur.\n");
    } else if (a < a_old) {
        printf("Vlera eshte zvogeluar.\n");
    } else {
        printf("Vlera ka mbetur e njejte.\n");
    }

    // kontroll intervali
    if (a >= 0 && a <= 50) {
        printf("Vlera eshte ne intervalin 0 - 50.\n");
    } else {
        printf("Vlera eshte jashte intervalit 0 - 50.\n");
    }

    return 0;
}
