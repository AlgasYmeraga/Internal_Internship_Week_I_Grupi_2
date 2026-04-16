#include <stdio.h>

// krijimi i enum
enum Niveli {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int zgjedhja;
    int valide = 0, pavlefshme = 0;

    // loop për 3 raste testimi
    for(int i = 1; i <= 3; i++) {
        printf("\nZgjedh nivelin (1-BEGINNER, 2-INTERMEDIATE, 3-ADVANCED, 4-EXPERT): ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case BEGINNER:
                printf("Niveli fillestar. Fillo me bazat.\n");
                valide++;
                break;

            case INTERMEDIATE:
                printf("Niveli mesatar. Praktiko me ushtrime.\n");
                valide++;
                break;

            case ADVANCED:
                printf("Niveli avancuar. Zgjidh probleme te veshtira.\n");
                valide++;
                break;

            case EXPERT:
                printf("Niveli ekspert. Je shume i avancuar.\n");
                valide++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                pavlefshme++;
        }
    }

    // statistikat
    printf("\n--- STATISTIKA ---\n");
    printf("Zgjedhje valide: %d\n", valide);
    printf("Zgjedhje pavlefshme: %d\n", pavlefshme);

    return 0;
}
