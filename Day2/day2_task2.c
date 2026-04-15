#include <stdio.h>

int main() {
    int rezultati;

    // Marrja e input-it
    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &rezultati);

    // Kontrolli i intervalit
    if (rezultati < 0 || rezultati > 100) {
        printf("Input i pavlefshem!\n");
    }
    // Klasifikimi me if / else if / else
    else if (rezultati >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (rezultati >= 75) {
        printf("Shume mire\n");
    }
    else if (rezultati >= 60) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
