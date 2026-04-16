#include <stdio.h>

int main() {
    int n, choice;

    printf("Shkruani nje numer pozitiv (1 - 12): ");
    scanf("%d", &n);

    // Kontrolli i input-it
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem! Numri duhet te jete nga 1 deri ne 12.\n");
        return 1;
    }

    printf("Zgjidh pattern-in:\n");
    printf("1 - Pattern me yje (*)\n");
    printf("2 - Pattern me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    printf("\nRezultati:\n\n");

    // For loop per rreshtat
    for (int i = 1; i <= n; i++) {

        // For loop per elementet brenda rreshtit
        for (int j = 1; j <= i; j++) {
            if (choice == 1) {
                printf("* ");
            } else if (choice == 2) {
                printf("%d ", j);
            } else {
                printf("Zgjedhje e pavlefshme!\n");
                return 1;
            }
        }

        printf("\n");
    }

    return 0;
}
