#include <stdio.h>

int main() {
    int mosha;
    float nota;
    char shkronja;
    int zgjedhja;

    // INPUT
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj noten: ");
    scanf("%f", &nota);

    printf("Shkruaj nje shkronje: ");
    scanf(" %c", &shkronja);

    // IF / ELSE
    if(mosha >= 18) {
        printf("Je i rritur\n");
    } else {
        printf("Je i mitur\n");
    }

    // ELSE IF
    if(nota >= 9) {
        printf("Shkelqyeshem\n");
    } else if(nota >= 7) {
        printf("Mire\n");
    } else if(nota >= 5) {
        printf("Kalueshem\n");
    } else {
        printf("Deshtim\n");
    }

    // SWITCH
    printf("\nZgjedh nje numer (1-3): ");
    scanf("%d", &zgjedhja);

    switch(zgjedhja) {
        case 1:
            printf("Ke zgjedhur opsionin 1\n");
            break;
        case 2:
            printf("Ke zgjedhur opsionin 2\n");
            break;
        case 3:
            printf("Ke zgjedhur opsionin 3\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    // PRINT gjitha
    printf("\nTe dhenat e tua:\n");
    printf("Mosha: %d\n", mosha);
    printf("Nota: %.2f\n", nota);
    printf("Shkronja: %c\n", shkronja);

    return 0;
}
