#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Marrja e input-it
    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me fundin.\n");
        return 0;
    }

    // Loop per analizimin e numrave
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int totalNumbers = end - start + 1;

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d, %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("\nNumra çift: %d\n", evenCount);
    printf("Shuma e numrave çift: %d\n", evenSum);

    printf("\nNumra tek: %d\n", oddCount);
    printf("Shuma e numrave tek: %d\n", oddSum);

    // Krahasimi
    if (evenCount > oddCount) {
        printf("\nKa me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("\nKa me shume numra tek.\n");
    } else {
        printf("\nNumri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}
