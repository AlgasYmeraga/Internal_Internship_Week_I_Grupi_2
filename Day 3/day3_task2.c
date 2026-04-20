#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    printf("Shkruani vleren fillestare te intervalit: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare te intervalit: ");
    scanf("%d", &end);

    // Kontrolli i intervalit valid
    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare eshte me e madhe se vlera perfundimtare.\n");
        return 0;
    }

    // For loop per analizimin e numrave
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

    printf("\n--- REZULTATI ---\n");
    printf("Intervali: %d - %d\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);
    printf("Numra çift: %d | Shuma: %d\n", evenCount, evenSum);
    printf("Numra tek: %d | Shuma: %d\n", oddCount, oddSum);

    if (evenCount > oddCount) {
        printf("Ka me shume numra çift ne kete interval.\n");
    } else if (oddCount > evenCount) {
        printf("Ka me shume numra tek ne kete interval.\n");
    } else {
        printf("Numri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}
