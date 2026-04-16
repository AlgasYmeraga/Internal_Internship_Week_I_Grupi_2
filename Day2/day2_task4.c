#include <stdio.h>

int main() {
    int age, workshop;
    char initial;
    double points;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial); // space fixes input bug

    printf("Enter your points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1, 2, or 3): ");
    scanf("%d", &workshop);

    int validAge = 0;
    if (age >= 15 && age <= 25) {
        validAge = 1;
    }

    char *status;
    if (points < 50) {
        status = "Needs more practice";
    } else if (points < 80) {
        status = "Ready to continue";
    } else {
        status = "Ready for challenge";
    }

    char *workshopName;
    switch (workshop) {
        case 1:
            workshopName = "Web Development";
            break;
        case 2:
            workshopName = "Programming Basics";
            break;
        case 3:
            workshopName = "Data Analysis";
            break;
        default:
            workshopName = "Invalid option";
    }

    printf("\n--- SUMMARY ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Points: %.2lf\n", points);
    printf("Workshop: %s\n", workshopName);
    printf("Status: %s\n", status);

    if (validAge) {
        printf("Age check: Allowed to participate\n");
    } else {
        printf("Age check: Not allowed to participate\n");
    }

    return 0;
}
