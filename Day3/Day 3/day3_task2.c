#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    printf("Enter start value: ");
    scanf("%d", &start);

    printf("Enter end value: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval. Start must be smaller or equal to end.\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int total = (end - start) + 1;

    printf("\n--- RESULT ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Total numbers: %d\n", total);

    printf("Even count: %d\n", evenCount);
    printf("Odd count: %d\n", oddCount);

    printf("Even sum: %d\n", evenSum);
    printf("Odd sum: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Category: More even numbers\n");
    } else if (oddCount > evenCount) {
        printf("Category: More odd numbers\n");
    } else {
        printf("Category: Equal even and odd numbers\n");
    }

    return 0;
}
