#include <stdio.h>

int main() {
    int dita;

    printf("Shkruaj nje numer nga 1 deri 7: ");
    scanf("%d", &dita);

    switch(dita) {
        case 1:
            printf("E Hene - Dite pune");
            break;
        case 2:
            printf("E Marte - Dite pune");
            break;
        case 3:
            printf("E Merkure - Dite pune");
            break;
        case 4:
            printf("E Enjte - Dite pune");
            break;
        case 5:
            printf("E Premte - Dite pune");
            break;
        case 6:
            printf("E Shtune - Fundjave");
            break;
        case 7:
            printf("E Diele - Fundjave");
            break;
        default:
            printf("Input i pavlefshem!");
    }

    return 0;
}
