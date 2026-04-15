#include <stdio.h>

int main() {
    char grade;

    printf("Enter grade (A, B, C): ");
    scanf(" %c", &grade);

    switch(grade) {
        case 'A':
            printf("Excellent\n");
            break;
        case 'B':
            printf("Good\n");
            break;
        case 'C':
            printf("Average\n");
            break;
        default:
            printf("Invalid grade\n");
    }

    return 0;
}
