#include <stdio.h>

enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    for (int i = 1; i <= 3; i++) {
        printf("\nUser %d\n", i);
        printf("Choose level:\n");
        printf("1 - Beginner\n");
        printf("2 - Intermediate\n");
        printf("3 - Advanced\n");
        printf("4 - Expert\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case BEGINNER:
                printf("Level: Beginner - Start with basics\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Level: Intermediate - Keep improving\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Level: Advanced - Strong skills\n");
                validCount++;
                break;

            case EXPERT:
                printf("Level: Expert - Top level\n");
                validCount++;
                break;

            default:
                printf("Invalid choice\n");
                invalidCount++;
        }
    }

    printf("\n--- STATS ---\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}
