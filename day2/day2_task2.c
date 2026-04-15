#include <stdio.h>

int main() {
    int rezultat;

    printf("Shkruani rezultatin (0 - 100): ");
    scanf("%d", &rezultat);

    // Kontrolli i intervalit
    if (rezultat < 0 || rezultat > 100) {
        printf("Input-i nuk eshte valid.\n");
    }
    else if (rezultat >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (rezultat >= 75) {
        printf("Shume mire\n");
    }
    else if (rezultat >= 50) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
