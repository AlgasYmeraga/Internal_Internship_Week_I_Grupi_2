#include <stdio.h>

int main() {
    int numri;

    /* Marrim nje numer nga perdoruesi */
    printf("Shkruaj nje numer nga 1 deri ne 7: ");
    scanf("%d", &numri);

    /* Perdoret switch per te zgjedhur diten */
    switch (numri) {
        case 1:
            printf("Dita: E hene\n");
            printf("Eshte dite pune.\n");
            break;

        case 2:
            printf("Dita: E marte\n");
            printf("Eshte dite pune.\n");
            break;

        case 3:
            printf("Dita: E merkure\n");
            printf("Eshte dite pune.\n");
            break;

        case 4:
            printf("Dita: E enjte\n");
            printf("Eshte dite pune.\n");
            break;

        case 5:
            printf("Dita: E premte\n");
            printf("Eshte dite pune.\n");
            break;

        case 6:
            printf("Dita: E shtune\n");
            printf("Eshte fundjave.\n");
            break;

        case 7:
            printf("Dita: E diel\n");
            printf("Eshte fundjave.\n");
            break;

        default:
            printf("Input i pavlefshem. Ju lutem shkruani nje numer nga 1 deri ne 7.\n");
    }

    return 0;
}
