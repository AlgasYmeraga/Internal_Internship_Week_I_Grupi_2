#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 18) {
        printf("Minor\n");
    } else if (age <= 60) {
        printf("Adult\n");
    } else {
        printf("Old\n");
    }

    return 0;
}
