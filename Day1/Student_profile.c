#include <stdio.h>

int main() {
    char name[50];
    int age;
    float grade;

    // Input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your grade: ");
    scanf("%f", &grade);

    // Output
    printf("\n--- Student Profile ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Grade: %.2f\n", grade);

    return 0;
}
