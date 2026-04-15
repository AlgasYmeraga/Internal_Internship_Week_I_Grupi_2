#include <stdio.h>

int main() {
    int dita;

    printf("Shkruaj nje numer nga 1 deri ne 7: ");
    scanf("%d", &dita);

    switch(dita) {
        case 1:
            printf("E hene - Dite pune");
            break;
        case 2:
            printf("E marte - Dite pune");
            break;
        case 3:
            printf("E merkure - Dite pune");
            break;
        case 4:
            printf("E enjte - Dite pune");
            break;
        case 5:
            printf("E premte - Dite pune");
            break;
        case 6:
            printf("E shtune - Fundjave");
            break;
        case 7:
            printf("E diel - Fundjave");
            break;
        default:
            printf("Input i pavlefshem!");
    }

    return 0;
}
