#include <stdio.h>

int main() {
    int n, choice;

    printf("Enter size (1 - 12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Invalid input. Enter a number between 1 and 12.\n");
        return 0;
    }

    printf("Choose pattern:\n");
    printf("1 - Stars (*)\n");
    printf("2 - Numbers\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    printf("\n");

    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } else {
        printf("Invalid pattern choice.\n");
    }

    return 0;
}  
