#include <stdio.h>

int main() {
    int start, end;
    int sum1 = 0, count1 = 0; // Category 1: Divisible by 3
    int sum2 = 0, count2 = 0; // Category 2: Divisible by 5 (but not 3)

    // Requirement: Handle invalid input 
    printf("Enter the start of the interval: ");
    if (scanf("%d", &start) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    printf("Enter the end of the interval: ");
    if (scanf("%d", &end) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Logical check: ensure start is less than or equal to end 
    if (start > end) {
        printf("Interval error: Start must be less than or equal to End.\n");
        return 1;
    }

    // Requirement: Use for loop to check every number 
    for (int i = start; i <= end; i++) {
        // Category 1: Numbers divisible by 3 [cite: 40]
        if (i % 3 == 0) {
            sum1 += i;
            count1++;
        } 
        // Category 2: Divisible by 5 but NOT by 3 [cite: 41, 42]
        // Using 'else if' ensures a number isn't placed in both categories 
        else if (i % 5 == 0) {
            sum2 += i;
            count2++;
        }
    }

    // Display results for both categories
    printf("\n--- Results ---\n");
    printf("Category 1 (Divisible by 3): Sum = %d, Count = %d\n", sum1, count1);
    printf("Category 2 (Divisible by 5 only): Sum = %d, Count = %d\n", sum2, count2);

    // Requirement: Compare the two sums 
    if (sum1 > sum2) {
        printf("Result: The sum of Category 1 is greater than Category 2.\n");
    } else if (sum2 > sum1) {
        printf("Result: The sum of Category 2 is greater than Category 1.\n");
    } else {
        printf("Result: Both sums are equal.\n");
    }

    return 0;
}
