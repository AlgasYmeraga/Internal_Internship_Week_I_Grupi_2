#include <stdio.h>

int main() {
    /* Variabla per profilin e perdoruesit */
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;

    /* Variabla short dhe long caktohen direkt ne kod */
    short klasa = 11;
    long idPerdoruesi = 2026001;

    /* Marrja e te dhenave nga perdoruesi */
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);   /* Hapesira para %c shmang leximin e Enter-it */

    printf("Shkruaj gjatesine: ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    /* Shfaqja e profilit ne menyre te organizuar */
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Klasa (short): %hd\n", klasa);
    printf("ID e perdoruesit (long): %ld\n", idPerdoruesi);

    return 0;
}