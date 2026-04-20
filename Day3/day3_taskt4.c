#include <stdio.h>

int main() {
    int a;
    float b;

    int *pA;
    float *pB;

    int oldA;
    float oldB;

    // Marrja e input-it
    printf("Shkruaj nje numer integer: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer float: ");
    scanf("%f", &b);

    // Ruaj vlerat fillestare
    oldA = a;
    oldB = b;

    // Pointerat marrin adresat
    pA = &a;
    pB = &b;

    // Shfaqje e vlerave dhe adresave
    printf("\n--- VLERA DHE ADRESA ---\n");
    printf("a = %d, adresa = %p, nga pointer = %d\n", a, pA, *pA);
    printf("b = %.2f, adresa = %p, nga pointer = %.2f\n", b, pB, *pB);

    // Ndryshimi përmes pointerave
    *pA = *pA + 10;
    *pB = *pB * 2;

    // Shfaqje pas ndryshimit
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a (para) = %d, a (pas) = %d\n", oldA, a);
    printf("b (para) = %.2f, b (pas) = %.2f\n", oldB, b);

    // Kontroll me if/else për a
    printf("\n--- KONTROLLI PER 'a' ---\n");
    if (a > oldA) {
        printf("Vlera e a eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera e a eshte zvogeluar.\n");
    } else {
        printf("Vlera e a ka mbetur e njejte.\n");
    }

    // Kontroll intervali për b
    printf("\n--- KONTROLLI PER 'b' ---\n");
    if (b >= 0 && b <= 50) {
        printf("b eshte ne intervalin [0, 50].\n");
    } else if (b > 50) {
        printf("b eshte me e madhe se 50.\n");
    } else {
        printf("b eshte negative.\n");
    }

    return 0;
}
