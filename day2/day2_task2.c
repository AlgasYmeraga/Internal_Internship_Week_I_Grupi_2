#include <stdio.h>

int main() {
    int rezultati;

    printf("Shkruani rezultatin (0 - 100): ");
    scanf("%d", &rezultati);

    // Kontrolli i intervalit
    if (rezultati < 0 || rezultati > 100) {
        printf("Input-i nuk eshte valid!\n");
    }
    // Klasifikimi nga me i larti tek me i ulti
    else if (rezultati >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (rezultati >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (rezultati >= 50) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}
