#include <stdio.h>

int main() {
    int rezultati;

    /* Marrim rezultatin nga perdoruesi */
    printf("Shkruaj rezultatin (0 - 100): ");
    scanf("%d", &rezultati);

    /* Kontrollojme nese inputi eshte valid */
    if (rezultati < 0 || rezultati > 100) {
        printf("Inputi nuk eshte valid.\n");
    }
    else if (rezultati >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (rezultati >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (rezultati >= 60) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}
