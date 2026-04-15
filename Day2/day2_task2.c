#include <stdio.h>

int main() {
    int score;

    // Marrja e input-it nga përdoruesi
    printf("Shkruani rezultatin (0 - 100): ");
    scanf("%d", &score);

    // Kontrolli i intervalit
    if (score < 0 || score > 100) {
        printf("Input i pavlefshem!\n");
    }
    else if (score >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Shume mire\n");
    }
    else if (score >= 60) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
