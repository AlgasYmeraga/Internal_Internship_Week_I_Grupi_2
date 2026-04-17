#include <stdio.h>

int main() {
    int a;
    double b;

    int *pA;
    double *pB;

    printf("Enter an integer value: ");
    scanf("%d", &a);

    printf("Enter a double value: ");
    scanf("%lf", &b);

    pA = &a;
    pB = &b;

    printf("\n--- BEFORE CHANGE ---\n");
    printf("a = %d\n", a);
    printf("Address of a = %p\n", &a);
    printf("Value of a using pointer = %d\n", *pA);

    printf("\nb = %.2lf\n", b);
    printf("Address of b = %p\n", &b);
    printf("Value of b using pointer = %.2lf\n", *pB);

    int oldA = a;
    double oldB = b;

    *pA = *pA + 10;
    *pB = *pB * 2;

    printf("\n--- AFTER CHANGE ---\n");
    printf("a = %d\n", a);
    printf("b = %.2lf\n", b);

    printf("\n--- CHECK (a) ---\n");
    if (a > oldA) {
        printf("a increased\n");
    } else if (a < oldA) {
        printf("a decreased\n");
    } else {
        printf("a stayed the same\n");
    }

    printf("\n--- CHECK (b) ---\n");
    if (b >= 0 && b <= 100) {
        printf("b is in range 0 to 100\n");
    } else {
        printf("b is outside range 0 to 100\n");
    }

    return 0;
}
