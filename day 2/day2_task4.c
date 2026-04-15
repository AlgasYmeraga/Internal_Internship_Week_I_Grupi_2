#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double pikeParaprake;
    int opsioniPunetorise;

    /* Variabla per rezultatet finale */
    char *niveli;
    char *punetoria;
    char *statusiMoshes;

    /* Marrja e input-it */
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &pikeParaprake);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioniPunetorise);

    /* Kontrolli i moshes per pjesemarrje */
    if (mosha >= 14 && mosha <= 19) {
        statusiMoshes = "Mosha eshte brenda kufirit per pjesemarrje.";
    } else {
        statusiMoshes = "Mosha nuk eshte brenda kufirit per pjesemarrje.";
    }

    /* Klasifikimi sipas pikeve */
    if (pikeParaprake < 50) {
        niveli = "Nevojitet me shume ushtrim";
    } else if (pikeParaprake < 80) {
        niveli = "Gati per vazhdim";
    } else {
        niveli = "Gati per sfide";
    }

    /* Zgjedhja e punetorise me switch */
    switch (opsioniPunetorise) {
        case 1:
            punetoria = "Programim bazik";
            break;
        case 2:
            punetoria = "Web bazik";
            break;
        case 3:
            punetoria = "Databaza bazike";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
    }

    /* Permbledhja finale */
    printf("\n--- Permbledhja e regjistrimit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket paraprake: %.2lf\n", pikeParaprake);
    printf("Punetoria e zgjedhur: %s\n", punetoria);
    printf("Statusi sipas pikeve: %s\n", niveli);
    printf("Kontrolli i moshes: %s\n", statusiMoshes);

    return 0;
}
