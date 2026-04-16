#include <stdio.h>

int main() {
    int start, end;

    int count3 = 0, count5 = 0;
    int sum3 = 0, sum5 = 0;

    printf("Enter start value: ");
    scanf("%d", &start);

    printf("Enter end value: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {

        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }

        if (i % 5 == 0 && i % 3 != 0) {
            sum5 += i;
            count5++;
        }
    }

    printf("\nRESULT\n");
    printf("Interval: %d - %d\n", start, end);

    printf("Divisible by 3 -> count: %d sum: %d\n", count3, sum3);
    printf("Divisible by 5 (not 3) -> count: %d sum: %d\n", count5, sum5);

    if (sum3 > sum5) {
        printf("Bigger sum: divisible by 3\n");
    } else if (sum5 > sum3) {
        printf("Bigger sum: divisible by 5\n");
    } else {
        printf("Equal sums\n");
    }

    return 0;
}
