#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;

    short vitiLindjes = 2008;   // vlerë e caktuar në kod
    long popullsia = 1800000;   // vlerë e caktuar në kod

    // Input nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin e emrit: ");
    scanf(" %c", &iniciali);  // hapësira para %c është e rëndësishme

    printf("Shkruaj gjatesine (p.sh. 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Output
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d vjec\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Viti i lindjes (short): %hd\n", vitiLindjes);
    printf("Popullsia (long): %ld\n", popullsia);

    return 0;
}
